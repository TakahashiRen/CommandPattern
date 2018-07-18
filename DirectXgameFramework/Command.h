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
	// 初期化する
	virtual void Initialize() = 0;
	// 実行する
	virtual void Execute(const DX::StepTimer& timer, DirectX::Keyboard* keyboard, Tank* tank) = 0;
	// 後始末をする
	virtual void Finalize() = 0;
};


class CommandMoveForward : public ICommand
{
public:
	// コンストラクタ
	CommandMoveForward();
	// 初期化する
	virtual void Initialize();
	// 実行する
	virtual void Execute(const DX::StepTimer& timer, DirectX::Keyboard* keyboard, Tank* tank) override;
	// 後始末をする
	virtual void Finalize();
};


class CommandMoveBackward : public ICommand
{
public:
	// コンストラクタ
	CommandMoveBackward();
	// 初期化する
	virtual void Initialize();
	// 実行する
	virtual void Execute(const DX::StepTimer& timer, DirectX::Keyboard* keyboard, Tank* tank) override;
	// 後始末をする
	virtual void Finalize();
};

class CommandTurnRight : public ICommand
{
public:
	// コンストラクタ
	CommandTurnRight();
	// 初期化する
	virtual void Initialize();
	// 実行する
	virtual void Execute(const DX::StepTimer& timer, DirectX::Keyboard* keyboard, Tank* tank) override;
	// 後始末をする
	virtual void Finalize();
};

class CommandTurnLeft : public ICommand
{
public:
	// コンストラクタ
	CommandTurnLeft();
	// 初期化する
	virtual void Initialize();
	// 実行する
	virtual void Execute(const DX::StepTimer& timer, DirectX::Keyboard* keyboard, Tank* tank) override;
	// 後始末をする
	virtual void Finalize();
};

class CommandShotNormal : public ICommand
{
private:
	//弾管理クラスのポインタ
	Air* air;
	// BulletFactoryオブジェクト BulletFactory object
	BulletFactory* bulletFactory;
	//
	std::unique_ptr<Normal> normal;
public:
	// コンストラクタ
	CommandShotNormal(Air* air, BulletFactory* bul);
	// 初期化する
	virtual void Initialize();
	// 実行する
	virtual void Execute(const DX::StepTimer& timer, DirectX::Keyboard* keyboard, Tank* tank) override;
	// 後始末をする
	virtual void Finalize();

};

class CommandShotNWay : public ICommand
{
private:
	//弾管理クラスのポインタ
	Air* air;
	// BulletFactoryオブジェクト BulletFactory object
	BulletFactory* bulletFactory;
	//
	std::unique_ptr<NWay> nway;
public:
	// コンストラクタ
	CommandShotNWay(Air* air, BulletFactory* bul);
	// 初期化する
	virtual void Initialize();
	// 実行する
	virtual void Execute(const DX::StepTimer& timer, DirectX::Keyboard* keyboard, Tank* tank) override;
	// 後始末をする
	virtual void Finalize();

};

class CommandShotBomb : public ICommand
{
private:
	//弾管理クラスのポインタ
	Air* air;
	// BulletFactoryオブジェクト BulletFactory object
	BulletFactory* bulletFactory;
	//
	std::unique_ptr<Bomb> bomb;
public:
	// コンストラクタ
	CommandShotBomb(Air* air, BulletFactory* bul);
	// 初期化する
	virtual void Initialize();
	// 実行する
	virtual void Execute(const DX::StepTimer& timer, DirectX::Keyboard* keyboard, Tank* tank) override;
	// 後始末をする
	virtual void Finalize();

};
#endif	// COMMAND_DEFINED

