#include "Command.h"

#include <SimpleMath.h>

using namespace DirectX::SimpleMath;
using namespace DirectX;

// コンストラクタ
CommandMoveBackward::CommandMoveBackward()
{

}
// 初期化する
void CommandMoveBackward::Initialize()
{
}

// 実行する
void CommandMoveBackward::Execute(const DX::StepTimer& timer, DirectX::Keyboard* keyboard, Tank* tank)
{
	// スピードを設定する Set speed
	Vector2 speed(2.0f, 0.0f);
	// 速度を設定する Reset velocity
	tank->Velocity(Vector2(0.0f, 0.0f));

	Matrix rotation = Matrix::CreateRotationZ(-tank->Angle());
	tank->Velocity(-Vector2::Transform(speed, rotation));

	// 移動する Move position
	tank->Position(tank->Position() + tank->Velocity());

	tank->Update(timer, tank->Position(), tank->Angle(), tank->TurretAngle());
}
// 後始末をする
void CommandMoveBackward::Finalize()
{

}