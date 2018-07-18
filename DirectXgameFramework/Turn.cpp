#include "Command.h"

using namespace DirectX;

// コンストラクタ
Turn::Turn(DirectX::SimpleMath::Vector2& position, float angle, float turretAngle, DirectX::SimpleMath::Vector4& color) :
	Command(position, angle, turretAngle, color) {
} 

void Turn::Initialize() {

}

void Turn::Execute(DirectX::Keyboard* keyboard, Tank* tank) {
	// キーボードの状態を取得する
	Keyboard::State key = keyboard->GetState();

	// BodyとTurretを右に回転する Rotate body and turret object right
	if (key.IsKeyDown(Keyboard::Keys::Right)) {
		tank->Angle(tank->Angle() - XMConvertToRadians(1.0f));
	}
	// BodyとTurretを左に回転する Rotate body and turret object left
	else if (key.IsKeyDown(Keyboard::Keys::Left)) {
		tank->Angle(tank->Angle() + XMConvertToRadians(1.0f));
	}

	// Turretを右に回転する Rotate turret object right
	if (key.IsKeyDown(Keyboard::Keys::D)) {
		tank->TurretAngle(tank->TurretAngle() + XMConvertToRadians(1.0f));
	}
	// Turretを左に回転する Rotate turret object left
	else if (key.IsKeyDown(Keyboard::Keys::A)) {
		tank->TurretAngle(tank->TurretAngle() - XMConvertToRadians(1.0f));
	}
}