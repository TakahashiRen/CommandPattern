#pragma once
#ifndef COMMAND_DEFINED
#define COMMAND_DEFINED

#include <d3d11_1.h>
#include <DirectXMath.h>
#include <SimpleMath.h>
#include <Keyboard.h>

#include "Tank.h"
#include "Turret.h"
#include "Cannon.h"
#include "TankFactory.h"
#include "Air.h"
#include "Weapon.h"
#include "BulletFactory.h"

class ICommand 
{
public:
	// ����������
	virtual void Initialize() = 0;
	// ���s����
	virtual void Execute(const DX::StepTimer& timer, DirectX::Keyboard* keyboard, Tank* tank) = 0;
	// ��n��������
	virtual void Finalize() = 0;
};


class CommandMoveForward : public ICommand
{
public:
	// �R���X�g���N�^
	CommandMoveForward();
	// ����������
	virtual void Initialize();
	// ���s����
	virtual void Execute(const DX::StepTimer& timer, DirectX::Keyboard* keyboard, Tank* tank) override;
	// ��n��������
	virtual void Finalize();
};


class CommandMoveBackward : public ICommand
{
public:
	// �R���X�g���N�^
	CommandMoveBackward();
	// ����������
	virtual void Initialize();
	// ���s����
	virtual void Execute(const DX::StepTimer& timer, DirectX::Keyboard* keyboard, Tank* tank) override;
	// ��n��������
	virtual void Finalize();
};

class CommandTurnRight : public ICommand
{
public:
	// �R���X�g���N�^
	CommandTurnRight();
	// ����������
	virtual void Initialize();
	// ���s����
	virtual void Execute(const DX::StepTimer& timer, DirectX::Keyboard* keyboard, Tank* tank) override;
	// ��n��������
	virtual void Finalize();
};

class CommandTurnLeft : public ICommand
{
public:
	// �R���X�g���N�^
	CommandTurnLeft();
	// ����������
	virtual void Initialize();
	// ���s����
	virtual void Execute(const DX::StepTimer& timer, DirectX::Keyboard* keyboard, Tank* tank) override;
	// ��n��������
	virtual void Finalize();
};

class CommandShotNormal : public ICommand
{
private:
	//�e�Ǘ��N���X�̃|�C���^
	Air* air;
	// BulletFactory�I�u�W�F�N�g BulletFactory object
	BulletFactory* bulletFactory;
	//
	std::unique_ptr<Normal> normal;
public:
	// �R���X�g���N�^
	CommandShotNormal(Air* air, BulletFactory* bul);
	// ����������
	virtual void Initialize();
	// ���s����
	virtual void Execute(const DX::StepTimer& timer, DirectX::Keyboard* keyboard, Tank* tank) override;
	// ��n��������
	virtual void Finalize();

};

class CommandShotNWay : public ICommand
{
private:
	//�e�Ǘ��N���X�̃|�C���^
	Air* air;
	// BulletFactory�I�u�W�F�N�g BulletFactory object
	BulletFactory* bulletFactory;
	//
	std::unique_ptr<NWay> nway;
public:
	// �R���X�g���N�^
	CommandShotNWay(Air* air, BulletFactory* bul);
	// ����������
	virtual void Initialize();
	// ���s����
	virtual void Execute(const DX::StepTimer& timer, DirectX::Keyboard* keyboard, Tank* tank) override;
	// ��n��������
	virtual void Finalize();

};

class CommandShotBomb : public ICommand
{
private:
	//�e�Ǘ��N���X�̃|�C���^
	Air* air;
	// BulletFactory�I�u�W�F�N�g BulletFactory object
	BulletFactory* bulletFactory;
	//
	std::unique_ptr<Bomb> bomb;
public:
	// �R���X�g���N�^
	CommandShotBomb(Air* air, BulletFactory* bul);
	// ����������
	virtual void Initialize();
	// ���s����
	virtual void Execute(const DX::StepTimer& timer, DirectX::Keyboard* keyboard, Tank* tank) override;
	// ��n��������
	virtual void Finalize();

};
#endif	// COMMAND_DEFINED

