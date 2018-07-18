#include "Body.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace DX;
using namespace std;
using namespace Microsoft::WRL;

// �R���X�g���N�^ Constructor
Body::Body(DirectX::SimpleMath::Vector2& position, float angle, float turretAngle, DirectX::SimpleMath::Vector4& color)
	: Tank(position, angle, turretAngle, color) {
}

// Turret�I�u�W�F�N�g��ǉ�����
void Body::Add(unique_ptr<Tank>&& turret) {
	// Turret�I�u�W�F�N�g��ǉ�����
	children.emplace_back(move(turret));
}

// Body�I�u�W�F�N�g������������ Initialize Body object
void Body::Initialize(){
	// Body�e�N�X�`�������[�h����
	CreateWICTextureFromFile(Graphics::Get().Device().Get(),
	L"tank1.png", nullptr, this->texture.ReleaseAndGetAddressOf());
}

// Body�I�u�W�F�N�g���X�V���� Update Body object
void Body::Update(const DX::StepTimer& timer, DirectX::SimpleMath::Vector2& position, float angle, float turretAngle){
	// �ʒu��ݒ肷��
	Tank::Position(position);
	// �{�̉�]�p��ݒ肷��
	Tank::Angle(angle);
	// �C����]�p��ݒ肷��
	Tank::TurretAngle(turretAngle);

	for (unique_ptr<Tank>& part : children) {
		if (part != nullptr) {
			// �ċA�I��Update()���Ăяo��
			part->Update(timer, position, angle, turretAngle);
		}
	}
}

// Body�I�u�W�F�N�g��`�悷�� Render Body object
void Body::Render(SpriteBatch* spriteBatch) {
	// �X�v���C�g��`�悷��
	spriteBatch->Draw(this->texture.Get(), Tank::Position(), nullptr, Tank::Color(), -Tank::Angle() + XMConvertToRadians(90.0f), Vector2(64.0f, 64.0f));
	for (auto& part : children) {
		if (part != nullptr) {
			// �ċA�I��Render�֐����Ăяo��
			part->Render(spriteBatch);
		}
	}
}

// Body�I�u�W�F�N�g�̌㏈���������Ȃ�
void Body::Finalize() {
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