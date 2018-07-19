#include "Weapon.h"

// コンストラクタ
Bomb::Bomb(Air* air) : air(air) {}

// 初期化する
void Bomb::Initialize(BulletFactory* bulletFactory) 
{
	// Playerオブジェクトで生成されたBulletFactoryオブジェクトのアドレスをメンバー変数に格納する
	this->bulletFactory = bulletFactory;
}

// ボム弾を発射する
void Bomb::Shoot(const DX::StepTimer& timer, DirectX::SimpleMath::Vector2& position, float angle) {
	// 経過時間を取得する
	float elapsedTime = float(timer.GetElapsedSeconds());

	Bullet* bullet = nullptr;
	// 20フレーム毎に弾を発射する
	if (timer.GetFrameCount() % 20 == 0) 
	{
		// 60発 弾を発射する	
		for (int times = 0; times < 60; times++) 
		{
			for (int index = 0; index < BulletFactory::BULLET_NUM; index++) 
			{
				// 回転角を変更する
				angle += DirectX::XMConvertToRadians(6.0f);
				// 弾を発射する
				bullet = bulletFactory->Create(position, angle);
				if (bullet == nullptr)continue;

				// Bulletオブジェクトを配列に格納する
				this->air->BulletPool(bullet);
				break;
			}
		}
	}
}

// 後始末をする
void Bomb::Finalize()
{
	this->air = nullptr;
	this->bulletFactory = nullptr;
}