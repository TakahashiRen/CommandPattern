#include "Command.h"

using namespace DirectX::SimpleMath;
using namespace DirectX;

// コンストラクタ
TankCommand::TankCommand(DirectX::SimpleMath::Vector2& position, float angle, float turretAngle, DirectX::SimpleMath::Vector4& color) :
	Command(position, angle, turretAngle, color) {
}

// 初期化する
void TankCommand::Initialize() {
}

// 実行する
void TankCommand::Execute(const DX::StepTimer& timer, DirectX::Keyboard* keyboard, Tank* tank) {
	// キーボードの状態を取得する
	Keyboard::State key = keyboard->GetState();

	// スピードを設定する Set speed
	Vector2 speed(2.0f, 0.0f);
	// 速度を設定する Reset velocity
	tank->Velocity(Vector2(0.0f, 0.0f));

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

	// 前進する Go forward
	if (key.IsKeyDown(Keyboard::Keys::Up)) {
		Matrix rotation = Matrix::CreateRotationZ(-tank->Angle());
		tank->Velocity(Vector2::Transform(speed, rotation));
	}
	// 後退する Go backward
	else if (key.IsKeyDown(Keyboard::Keys::Down)) {
		Matrix rotation = Matrix::CreateRotationZ(-tank->Angle());
		tank->Velocity(-Vector2::Transform(speed, rotation));
	}

	// 移動する Move position
	tank->Position(tank->Position() + tank->Velocity());
	// Tankオブジェクトを更新する Update Tank objects
	tank->Update(timer, tank->Position(), tank->Angle(), tank->TurretAngle());
}

// 後始末をする
void TankCommand::Finalize() {

}