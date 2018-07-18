#include "Command.h"
#include <SimpleMath.h>

using namespace DirectX::SimpleMath;
using namespace DirectX;

// コンストラクタ
CommandTurnRight::CommandTurnRight()
{

}
// 初期化する
void CommandTurnRight::Initialize()
{
}
// 実行する
void CommandTurnRight::Execute(const DX::StepTimer& timer, DirectX::Keyboard* keyboard, Tank* tank)
{
	tank->TurretAngle(tank->TurretAngle() + XMConvertToRadians(1.0f));
	tank->Update(timer, tank->Position(), tank->Angle(), tank->TurretAngle());
}
// 後始末をする
void CommandTurnRight::Finalize()
{

}