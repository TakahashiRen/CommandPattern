#pragma once
#include "Command.h"

#include <queue>

#include "Tank.h"
#include "Air.h"
#include "BulletFactory.h"

class InputHandler
{
public:
	void Initialize();
	//�R�}���h���s�ɕK�v�Ȃ��̂������œn��
	void SetCommandState(Air* air, BulletFactory* bulletFac);
	//���s�R�}���h���擾���A�Ԃ�
	std::queue<ICommand*> HandleInput(const DX::StepTimer& timer,DirectX::Keyboard* keyboard,Tank* tank);
	//�I������
	void Finalize();
private:
	//�v���C���[����n�������
	//��{�I�ɂ��̂܂܊e��R�}���h�ɓn�����
	Air* air;
	BulletFactory* bulletFac;
	//���͂Ɋ��蓖�Ă�R�}���h���\�b�h�Ȃ�
	ICommand* command_W;
	ICommand* command_A;
	ICommand* command_S;
	ICommand* command_D;
	ICommand* command_Z;
	ICommand* command_X;
	ICommand* command_SPACE;
};