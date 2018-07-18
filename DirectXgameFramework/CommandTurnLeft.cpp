#include "Command.h"
#include <SimpleMath.h>

using namespace DirectX::SimpleMath;
using namespace DirectX;

// コンストラクタ
CommandTurnLeft::CommandTurnLeft()
{

}
// 初期化する
void CommandTurnLeft::Initialize()
{
}
// 実行する
void CommandTurnLeft::Execute(const DX::StepTimer& timer, DirectX::Keyboard* keyboard, Tank* tank)
{
	tank->TurretAngle(tank->TurretAngle() - XMConvertToRadians(1.0f));
	tank->Update(timer, tank->Position(), tank->Angle(), tank->TurretAngle());
}
// 後始末をする
void CommandTurnLeft::Finalize()
{

}