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

class ICommand {
public:
	// 初期化する
	virtual void Initialize() = 0;
	// 実行する
	virtual void Execute(const DX::StepTimer& timer, DirectX::Keyboard* keyboard, Tank* tank) = 0;
	// 後始末をする
	virtual void Finalize() = 0;
};

class Command : public ICommand {
public:
	// コンストラクタ
	Command(DirectX::SimpleMath::Vector2& position, float angle, float turretAngle, DirectX::SimpleMath::Vector4& color) :
	position(position), angle(angle), turretAngle(turretAngle), color(color) {
	}

	// 初期化する
	virtual void Initialize() {
		// TankFactoryオブジェクトを生成する Create TankFactory object
		TankFactory tankFactory(this->position, this->angle, this->turretAngle, this->color);
		// Bodyオブジェクトを生成する Create Body object
		this->tank = tankFactory.Create(Tank::PARTS_ID::BODY);
		// Turretオブジェクを生成する Create Turret object
		unique_ptr<Tank> turret = tankFactory.Create(Tank::PARTS_ID::TURRET);
		// Cannonオブジェクを生成する Create Cannon object
		unique_ptr<Tank> cannon = tankFactory.Create(Tank::PARTS_ID::CANNON);

		// TurretオブジェクトにCannonオブジェクトを追加する
		turret->Add(move(cannon));
		// BodyオブジェクトにTurretオブジェクトを追加する
		this->tank->Add(move(turret));

		// 位置を設定する
		this->tank->Position(position);
		// 回転角を設定する
		this->tank->Angle(angle);
	}

	// 後始末をする
	virtual void Finalize() {

	}

private:
	DirectX::SimpleMath::Vector2 position;
	float angle;
	float turretAngle;
	DirectX::SimpleMath::Vector4 color;
	// Tankオブジェクトへのポインタ Tank object
	std::unique_ptr<Tank> tank;
};

class TankCommand : public Command {
public:
	// コンストラクタ
	TankCommand(DirectX::SimpleMath::Vector2& position, float angle, float turretAngle, DirectX::SimpleMath::Vector4& color);
	// 初期化する
	virtual void Initialize();
	// 実行する
	virtual void Execute(const DX::StepTimer& timer, DirectX::Keyboard* keyboard, Tank* tank) override;
	// 後始末をする
	virtual void Finalize();
};

class BulletCommand : public Command
{
private:
	Air* air;
	// Normalオブジェクトへのポインタ Normal object
	std::unique_ptr<Normal> normal;
	// nWayオブジェクトへのポインタ Bomb object
	std::unique_ptr<NWay> nway;
	// Bombオブジェクトへのポインタ Bomb object
	std::unique_ptr<Bomb> bomb;
	// BulletFactoryオブジェクト BulletFactory object
	std::unique_ptr<BulletFactory> bulletFactory;
	// Bulletの飛行弾数
	int* bulletNum;

public:
	// コンストラクタ
	BulletCommand(DirectX::SimpleMath::Vector2& position, float angle, float turretAngle, DirectX::SimpleMath::Vector4& color,Air* air,int* bulletnum);
	// 初期化する
	virtual void Initialize();
	// 実行する
	virtual void Execute(const DX::StepTimer& timer, DirectX::Keyboard* keyboard, Tank* tank) override;
	// 後始末をする
	virtual void Finalize();

};

#endif	// COMMAND_DEFINED

