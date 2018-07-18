#pragma once
#ifndef WEAPON_DEFINED
#define WEAPON_DEFINED
#include <memory>
#include <d3d11_1.h>
#include <DirectXMath.h>
#include <SimpleMath.h>

#include "StepTimer.h"
#include "Bullet.h"
#include "BulletFactory.h"
#include "Air.h"

class Weapon {
public:
	enum ID { NORMAL, NWAY, BOMB };
	// 初期化する
	virtual void Initialize(BulletFactory* bulletFactory) = 0;
	// 発射する
	virtual void Shoot(const DX::StepTimer& timer, int& bulletNum, DirectX::SimpleMath::Vector2& position, float angle) = 0;
	// 後始末をする
	virtual void Finalize() = 0;
};

class Normal : public Weapon {
public:
	// コンストラクタ
	Normal(Air* air);
	// 初期化する
	void Initialize(BulletFactory* bulletFactory) override;
	// 弾を発射する
	void Shoot(const DX::StepTimer& timer, int& bulletNum, DirectX::SimpleMath::Vector2& position, float angle) override ;
	// 後始末をする
	void Finalize() override;

private:
	// Airオブジェクトへのポインタ
	Air* air;
	// BulletFactoryオブジェクトへのポインタ BulletFactory object
	BulletFactory* bulletFactory;
};

class NWay : public Weapon {
public:
	// コンストラクタ
	NWay(Air* air);
	// 初期化する
	void Initialize(BulletFactory* bulletFactory) override;
	// 弾を発射する
	void Shoot(const DX::StepTimer& timer, int& bulletNum, DirectX::SimpleMath::Vector2& position, float angle) override;
	// 後始末をする
	void Finalize() override;

private:
	// Airオブジェクトへのポインタ
	Air* air;
	// BulletFactoryオブジェクト BulletFactory object
	BulletFactory* bulletFactory;
};


class Bomb : public Weapon {
public:
	// コンストラクタ
	Bomb(Air* air);
	// 初期化する
	void Initialize(BulletFactory* bulletFactory) override;
	// 弾を発射する
	void Shoot(const DX::StepTimer& timer, int& bulletNum, DirectX::SimpleMath::Vector2& position, float angle) override;
	// 後始末をする
	void Finalize() override;

private:
	// Airオブジェクトへのポインタ
	Air* air;
	// BulletFactoryオブジェクト BulletFactory object
	BulletFactory* bulletFactory;
};

#endif	// WEAPON_DEFINED

