#include "Command.h"

using namespace DirectX::SimpleMath;
using namespace DirectX;

// �R���X�g���N�^
TankCommand::TankCommand(DirectX::SimpleMath::Vector2& position, float angle, float turretAngle, DirectX::SimpleMath::Vector4& color) :
	Command(position, angle, turretAngle, color) {
}

// ����������
void TankCommand::Initialize() {
}

// ���s����
void TankCommand::Execute(const DX::StepTimer& timer, DirectX::Keyboard* keyboard, Tank* tank) {
	// �L�[�{�[�h�̏�Ԃ��擾����
	Keyboard::State key = keyboard->GetState();

	// �X�s�[�h��ݒ肷�� Set speed
	Vector2 speed(2.0f, 0.0f);
	// ���x��ݒ肷�� Reset velocity
	tank->Velocity(Vector2(0.0f, 0.0f));

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

	// �O�i���� Go forward
	if (key.IsKeyDown(Keyboard::Keys::Up)) {
		Matrix rotation = Matrix::CreateRotationZ(-tank->Angle());
		tank->Velocity(Vector2::Transform(speed, rotation));
	}
	// ��ނ��� Go backward
	else if (key.IsKeyDown(Keyboard::Keys::Down)) {
		Matrix rotation = Matrix::CreateRotationZ(-tank->Angle());
		tank->Velocity(-Vector2::Transform(speed, rotation));
	}

	// �ړ����� Move position
	tank->Position(tank->Position() + tank->Velocity());
	// Tank�I�u�W�F�N�g���X�V���� Update Tank objects
	tank->Update(timer, tank->Position(), tank->Angle(), tank->TurretAngle());
}

// ��n��������
void TankCommand::Finalize() {

}