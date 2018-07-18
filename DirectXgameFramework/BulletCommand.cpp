#include "Command.h"

using namespace DirectX::SimpleMath;
using namespace DirectX;

// �R���X�g���N�^
BulletCommand::BulletCommand(DirectX::SimpleMath::Vector2& position, float angle, float turretAngle, DirectX::SimpleMath::Vector4& color,Air* air, int* bulletnum)
	: Command(position, angle, turretAngle, color) ,air(air),bulletNum(bulletnum)
{

}
// ����������
void BulletCommand::Initialize()
{
	// BulletFactory�I�u�W�F�N�g�𐶐����� Create BulletFactory object
	// ���O�ɒe��z�񕪐������邽�߁A�R���X�g���N�^�ɔ��˂���e�̈ʒu�A�{�̉�]�p�A�C����]�p��ݒ�ł��Ȃ�
	bulletFactory = make_unique<BulletFactory>();
	// BulletFactory�I�u�W�F�N�g���X�V����
	bulletFactory->Initialize();

	// Normal�I�u�W�F�N�g�𐶐�����
	normal = make_unique<Normal>(air);
	// Normal�I�u�W�F�N�g������������
	normal->Initialize(bulletFactory.get());

	// nWay�I�u�W�F�N�g�𐶐�����
	nway = make_unique<NWay>(air);
	// Bomb�I�u�W�F�N�g������������
	nway->Initialize(bulletFactory.get());

	// Bomb�I�u�W�F�N�g�𐶐�����
	bomb = make_unique<Bomb>(air);
	// Bomb�I�u�W�F�N�g������������
	bomb->Initialize(bulletFactory.get());

	// ��s�e��������������
	

}
// ���s����
void BulletCommand::Execute(const DX::StepTimer& timer, DirectX::Keyboard* keyboard, Tank* tank)
{
	// �L�[�{�[�h�̏�Ԃ��擾����
	Keyboard::State key = keyboard->GetState();

	// �ʏ�e�𔭎˂��� Fire bullet
	if (key.IsKeyDown(Keyboard::Keys::Space)) {
		// �C�����S�����C��[�܂ł̋���
		Vector2 offset = Vector2(64, 0);
		// �C���̉�]�p���v�Z����
		Matrix rotation = Matrix::CreateRotationZ(-tank->Angle() + tank->TurretAngle());
		// �e�����˂����ʒu���v�Z����
		Vector2 position = tank->Position() + Vector2::Transform(offset, rotation);
		// �ʏ�e�𔭎˂���
		normal->Shoot(timer, *bulletNum, position, -tank->Angle() + tank->TurretAngle());
	}

	// nWay�e�𔭎˂��� Fire bullet
	if (key.IsKeyDown(Keyboard::Keys::X)) {
		// �C�����S�����C��[�܂ł̋���
		Vector2 offset = Vector2(64, 0);
		// �C���̉�]�p���v�Z����
		Matrix rotation = Matrix::CreateRotationZ(-tank->Angle() + tank->TurretAngle());
		// nWay�e�����˂����ʒu���v�Z����
		Vector2 position = tank->Position() + Vector2::Transform(offset, rotation);
		// nWay�e�𔭎˂���
		nway->Shoot(timer, *bulletNum, position, -tank->Angle() + tank->TurretAngle());
	}

	// �{���𔭎˂��� Fire Bomb bullet
	if (key.IsKeyDown(Keyboard::Keys::Z)) {
		// �C�����S�����C��[�܂ł̋���
		Vector2 offset = Vector2(64, 0);
		// �C���̉�]�p���v�Z����
		Matrix rotation = Matrix::CreateRotationZ(-tank->Angle() + tank->TurretAngle());
		// �{���e�����˂����ʒu���v�Z����
		Vector2 position = tank->Position() + Vector2::Transform(offset, rotation);
		// �{���𔭎˂���
		bomb->Shoot(timer, *bulletNum, position, -tank->Angle() + tank->TurretAngle());
	}

	// Air�I�u�W�F�N�g��Bullet�I�u�W�F�N�g���X�V����
	this->air->Update(timer, *bulletNum);

}
// ��n��������
void BulletCommand::Finalize()
{
	// �{���e�����Z�b�g����
	this->bomb.reset();
	// nWay�e�I�u�W�F�N�g�����Z�b�g����
	this->nway.reset();
	// �ʏ�U���I�u�W�F�N�g�����Z�b�g����
	this->normal.reset();
	// BulletFactory�I�u�W�F�N�g�̌�n��������
	this->bulletFactory->Finalize();
	// BulletFactory�I�u�W�F�N�g�����Z�b�g����
	this->bulletFactory.reset();

}
