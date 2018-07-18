#include "Cannon.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace DX;
using namespace Microsoft::WRL;
using namespace std;

// �R���X�g���N�^ Constructor
Cannon::Cannon(DirectX::SimpleMath::Vector2& position, float angle, float turretAngle, DirectX::SimpleMath::Vector4& color)
	//: position(position), angle(angle), turretAngle(turretAngle), color(color) {
	: Tank(position, angle, turretAngle, color) {
}

// �I�u�W�F�N�g��ǉ�����
void Cannon::Add(unique_ptr<Tank>&& object) {
}

// Cannon�I�u�W�F�N�g������������ Initialize Cannon object
void Cannon::Initialize() {
	// Cannon�e�N�X�`�������[�h����
	CreateWICTextureFromFile(Graphics::Get().Device().Get(),
	L"tank3.png", nullptr, this->texture.ReleaseAndGetAddressOf());
}

// Cannon�I�u�W�F�N�g���X�V���� Update Cannon object
void Cannon::Update(const DX::StepTimer& timer, DirectX::SimpleMath::Vector2& position, float angle, float turretAngle) {
	// �ʒu��ݒ肷��
	Tank::Position(position);
	// ��]�p��ݒ肷��
	Tank::Angle(angle);
	// �C����]�p��ݒ肷��
	Tank::TurretAngle(turretAngle);
}

// Cannon�I�u�W�F�N�g��`�悷�� Render Cannon object
void Cannon::Render(SpriteBatch* spriteBatch) {
	// �X�v���C�g��`�悷�� Draw sprite
	spriteBatch->Draw(this->texture.Get(), Tank::Position(), nullptr, Tank::Color(), -Tank::Angle() + Tank::TurretAngle() + XMConvertToRadians(90.0f), Vector2(64.0f, 64.0f));
}

// Cannon�I�u�W�F�N�g�̌㏈���������Ȃ� Finalize Turret object
void Cannon::Finalize() {
	// �e�N�X�`�������Z�b�g����
	this->texture.Reset();
}

