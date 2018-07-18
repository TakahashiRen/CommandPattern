#include "Turret.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace DX;
using namespace Microsoft::WRL;
using namespace std;

// �R���X�g���N�^ Constructor
Turret::Turret(DirectX::SimpleMath::Vector2& position, float angle, float turretAngle, DirectX::SimpleMath::Vector4& color)
	//: position(position), angle(angle), turretAngle(turretAngle), color(color) {
	: Tank(position, angle, turretAngle, color) {
}

// Cannon�I�u�W�F�N�g��ǉ�����
void Turret::Add(unique_ptr<Tank>&& cannon) {
	// �I�u�W�F�N�g��ǉ�����
	children.emplace_back(move(cannon));
}

// Turret�I�u�W�F�N�g������������ Initialize Turret object
void Turret::Initialize() {
	// Turret�e�N�X�`�������[�h����
	CreateWICTextureFromFile(Graphics::Get().Device().Get(),
	L"tank2.png", nullptr, this->texture.ReleaseAndGetAddressOf());
}

// Turret�I�u�W�F�N�g���X�V���� Update Turret object
void Turret::Update(const DX::StepTimer& timer, DirectX::SimpleMath::Vector2& position, float angle, float turretAngle) {
	// �ʒu��ݒ肷��
	Tank::Position(position);
	// �{�̉�]�p��ݒ肷��
	Tank::Angle(angle);
	// �C����]�p��ݒ肷��
	Tank::TurretAngle(turretAngle);

	for (auto& part : children) {
		if (part != nullptr) {
			// �ċA�I��Update()���Ăяo��
			part->Update(timer, position, angle, turretAngle);
		}
	}
}

// Turret�I�u�W�F�N�g��`�悷�� Render Turret object
void Turret::Render(SpriteBatch* spriteBatch) {
	// �X�v���C�g��`�悷�� Draw sprite
	spriteBatch->Draw(this->texture.Get(), Tank::Position(), nullptr, Tank::Color(), -Tank::Angle() + Tank::TurretAngle() + XMConvertToRadians(90.0f), Vector2(64.0f, 64.0f));
	for (auto& part : children) {
		if (part != nullptr) {
			// �ċA�I��Render�֐����Ăяo��
			part->Render(spriteBatch);
		}
	}
}

// Turret�I�u�W�F�N�g�̌㏈���������Ȃ� Finalize Turret object
void Turret::Finalize() {
	// �e�N�X�`�������Z�b�g����
	this->texture.Reset();
	// �ċA�I��Finalize���Ăяo��
	for (auto& part : children) {
		if (part != nullptr) {
			part->Finalize();
			// �ċA�I�ɃI�u�W�F�N�g��j������
			part.reset();
		}
	}
	// �̈���������
	this->children.shrink_to_fit();
}
