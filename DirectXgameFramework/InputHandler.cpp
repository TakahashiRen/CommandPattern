#include "InputHandler.h"

#include <Keyboard.h>


using namespace DirectX::SimpleMath;
using namespace DirectX;


void InputHandler::Initialize()
{
	command_A = new CommandTurnLeft();
	command_D = new CommandTurnRight();
	command_S = new CommandMoveBackward();
	command_W = new CommandMoveForward();
	command_Z = new CommandShotBomb(this->air,this->bulletFac);
	command_X = new CommandShotNWay(this->air, this->bulletFac);
	command_SPACE = new CommandShotNormal(this->air, this->bulletFac);
}

void InputHandler::SetCommandState(Air * air, BulletFactory * bulletFac)
{
	this->air = air;
	this->bulletFac = bulletFac;
}

std::queue<ICommand*> InputHandler::HandleInput(const DX::StepTimer & timer, DirectX::Keyboard * keyboard, Tank * tank)
{
	std::queue<ICommand*> que;

	// キーボードの状態を取得する
	Keyboard::State key = keyboard->GetState();

	if (key.IsKeyDown(Keyboard::Keys::W))
	{
		que.push(command_W);
	}
	if (key.IsKeyDown(Keyboard::Keys::A))
	{
		que.push(command_A);
	}
	if (key.IsKeyDown(Keyboard::Keys::S))
	{
		que.push(command_S);
	}
	if (key.IsKeyDown(Keyboard::Keys::D))
	{
		que.push(command_D);
	}
	if (key.IsKeyDown(Keyboard::Keys::Z))
	{
		que.push(command_Z);
	}
	if (key.IsKeyDown(Keyboard::Keys::X))
	{
		que.push(command_X);
	}
	if (key.IsKeyDown(Keyboard::Keys::Space))
	{
		que.push(command_SPACE);
	}

	return que;
}

void InputHandler::Finalize()
{
	command_A->Finalize();
	delete command_A;
	command_A = nullptr;
	command_D->Finalize();
	delete command_D;
	command_D = nullptr;
	command_S->Finalize();
	delete command_S;
	command_S = nullptr;
	command_W->Finalize();
	delete command_W;
	command_W = nullptr;
	command_Z->Finalize();
	delete command_Z;
	command_Z = nullptr;
	command_X->Finalize();
	delete command_X;
	command_X = nullptr;
	command_SPACE->Finalize();
	delete command_SPACE;
	command_SPACE = nullptr;
}
