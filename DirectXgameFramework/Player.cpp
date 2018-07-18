#include "Player.h"

using namespace DirectX::SimpleMath;
using namespace DirectX;
using namespace DX;
using namespace Microsoft::WRL;
using namespace std;

// �R���X�g���N�^ Constructor
Player::Player(Air* air) : air(air) {
}

// Player�I�u�W�F�N�g������������ Initialize Player object
void Player::Initialize(Vector2& position, float angle, float turretAngle, Vector4& color) {
	// Keyboard�I�u�W�F�N�g�𐶐����� Create Keyboard object
	this->keyboard = make_unique<Keyboard>();
	// KeyboardStateTracker�I�u�W�F�N�g�𐶐����� Create KeyboardStateTracker object
	this->keyboardTracker = make_unique<Keyboard::KeyboardStateTracker>();

	// TankFactory�I�u�W�F�N�g�𐶐����� Create TankFactory object
	TankFactory tankFactory(position, angle, turretAngle, color);
	// Body�I�u�W�F�N�g�𐶐����� Create Body object
	this->tank = tankFactory.Create(Tank::PARTS_ID::BODY);
	// Turret�I�u�W�F�N�𐶐����� Create Turret object
	unique_ptr<Tank> turret = tankFactory.Create(Tank::PARTS_ID::TURRET);
	// Cannon�I�u�W�F�N�𐶐����� Create Cannon object
	unique_ptr<Tank> cannon = tankFactory.Create(Tank::PARTS_ID::CANNON);

	// Turret�I�u�W�F�N�g��Cannon�I�u�W�F�N�g��ǉ�����
	turret->Add(move(cannon));
	// Body�I�u�W�F�N�g��Turret�I�u�W�F�N�g��ǉ�����
	this->tank->Add(move(turret));

	// �ʒu��ݒ肷��
	this->tank->Position(position);
	// ��]�p��ݒ肷��
	this->tank->Angle(angle);
	bulletNum = new int(0);

	command = new TankCommand(this->tank->Position(), this->tank->Angle(), this->tank->TurretAngle(), this->tank->Color());
	command->Initialize();
	bCommand = new BulletCommand(this->tank->Position(), this->tank->Angle(), this->tank->TurretAngle(), this->tank->Color(), air,bulletNum);
	bCommand->Initialize();
}

// Player�I�u�W�F�N�g���X�V����
bool Player::Update(const StepTimer& timer) {
	// �o�ߎ��Ԃ��擾����
	float elapsedTime = float(timer.GetElapsedSeconds());
	// �L�[�{�[�h���擾����
	Keyboard& kb = Keyboard::Get();

	command->Execute(timer, &kb, this->tank.get());
	bCommand->Execute(timer, &kb, this->tank.get());

	return true;
}

// �X�v���C�g��`�悷�� Render Sprite object
void Player::Render(const StepTimer& timer, SpriteBatch* spriteBatch) {
	// Tank�I�u�W�F�N�g��`�悷�� Render Tank objects
	this->tank->Render(spriteBatch);

	// Air�I�u�W�F�N�g��Bullet�I�u�W�F�N�g��`�悷��
	this->air->Render(timer, spriteBatch, *this->bulletNum);
}

// �㏈���������Ȃ�
void Player::Finalize() {

	// �ċA�I��Tank�I�u�W�F�N�g�̌㏈���������Ȃ� Finalize Tank object
	this->tank->Finalize();	
	// Tank�I�u�W�F�N�g��j������ Delete Tank object
	if(this->tank != nullptr)
		this->tank.reset();
	// Keyboard�I�u�W�F�N�g�����Z�b�g����
	this->keyboard.reset();
	// KeyboardTracker�I�u�W�F�N�g�����Z�b�g����
	this->keyboardTracker.reset();
	//�R�}���h�̍폜
	if (this->command != nullptr)
	{
		delete this->command;
		this->command = nullptr;
	}
	if (this->bCommand != nullptr)
	{
		delete this->bCommand;
		this->bCommand = nullptr;
	}
}
