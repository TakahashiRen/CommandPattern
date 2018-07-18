#include "Command.h"

#include <SimpleMath.h>

using namespace DirectX::SimpleMath;
using namespace DirectX;

// �R���X�g���N�^
CommandMoveBackward::CommandMoveBackward()
{

}
// ����������
void CommandMoveBackward::Initialize()
{
}

// ���s����
void CommandMoveBackward::Execute(const DX::StepTimer& timer, DirectX::Keyboard* keyboard, Tank* tank)
{
	// �X�s�[�h��ݒ肷�� Set speed
	Vector2 speed(2.0f, 0.0f);
	// ���x��ݒ肷�� Reset velocity
	tank->Velocity(Vector2(0.0f, 0.0f));

	Matrix rotation = Matrix::CreateRotationZ(-tank->Angle());
	tank->Velocity(-Vector2::Transform(speed, rotation));

	// �ړ����� Move position
	tank->Position(tank->Position() + tank->Velocity());

	tank->Update(timer, tank->Position(), tank->Angle(), tank->TurretAngle());
}
// ��n��������
void CommandMoveBackward::Finalize()
{

}