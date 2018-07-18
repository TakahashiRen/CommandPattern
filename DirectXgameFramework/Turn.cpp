#include "Command.h"

using namespace DirectX;

// �R���X�g���N�^
Turn::Turn(DirectX::SimpleMath::Vector2& position, float angle, float turretAngle, DirectX::SimpleMath::Vector4& color) :
	Command(position, angle, turretAngle, color) {
} 

void Turn::Initialize() {

}

void Turn::Execute(DirectX::Keyboard* keyboard, Tank* tank) {
	// �L�[�{�[�h�̏�Ԃ��擾����
	Keyboard::State key = keyboard->GetState();

	// Body��Turret���E�ɉ�]���� Rotate body and turret object right
	if (key.IsKeyDown(Keyboard::Keys::Right)) {
		tank->Angle(tank->Angle() - XMConvertToRadians(1.0f));
	}
	// Body��Turret�����ɉ�]���� Rotate body and turret object left
	else if (key.IsKeyDown(Keyboard::Keys::Left)) {
		tank->Angle(tank->Angle() + XMConvertToRadians(1.0f));
	}

	// Turret���E�ɉ�]���� Rotate turret object right
	if (key.IsKeyDown(Keyboard::Keys::D)) {
		tank->TurretAngle(tank->TurretAngle() + XMConvertToRadians(1.0f));
	}
	// Turret�����ɉ�]���� Rotate turret object left
	else if (key.IsKeyDown(Keyboard::Keys::A)) {
		tank->TurretAngle(tank->TurretAngle() - XMConvertToRadians(1.0f));
	}
}