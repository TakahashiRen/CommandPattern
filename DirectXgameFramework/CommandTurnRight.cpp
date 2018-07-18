#include "Command.h"
#include <SimpleMath.h>

using namespace DirectX::SimpleMath;
using namespace DirectX;

// �R���X�g���N�^
CommandTurnRight::CommandTurnRight()
{

}
// ����������
void CommandTurnRight::Initialize()
{
}
// ���s����
void CommandTurnRight::Execute(const DX::StepTimer& timer, DirectX::Keyboard* keyboard, Tank* tank)
{
	tank->TurretAngle(tank->TurretAngle() + XMConvertToRadians(1.0f));
	tank->Update(timer, tank->Position(), tank->Angle(), tank->TurretAngle());
}
// ��n��������
void CommandTurnRight::Finalize()
{

}