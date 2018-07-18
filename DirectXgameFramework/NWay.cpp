#include "Weapon.h"

// コンストラクタ
NWay::NWay(Air* air) : air(air) {}

// 初期化する
void NWay::Initialize(BulletFactory* bulletFactory) 
{
	// BulletFactoryオブジェクトを生成する Create BulletFactory object
	// 事前に弾を配列分生成するため、コンストラクタに発射する弾の位置、本体回転角、砲塔回転角を設定できない
	// bulletFactory = make_unique<BulletFactory>();
	// BulletFactoryオブジェクトを更新する
	// bulletFactory->Initialize();
	// Playerオブジェクトで生成されたBulletFactoryオブジェクトのアドレスをメンバー変数に格納する
	this->bulletFactory = bulletFactory;
}

// 弾を発射する
void NWay::Shoot(const DX::StepTimer& timer,DirectX::SimpleMath::Vector2& position, float angle) {
	// 経過時間を取得する
	float elapsedTime = float(timer.GetElapsedSeconds());

	Bullet* bullet = nullptr;

	// 5フレーム毎に弾を発射する
	if (timer.GetFrameCount() % 5 == 0) 
	{
		// 弾を発射する	
		for (int index = 0; index < BulletFactory::BULLET_NUM; index++) 
		{
			if (timer.GetFrameCount() % 3 == 1)
			{
				// 回転角を変更する
				angle -= DirectX::XMConvertToRadians(5.0f);
			}
			else if (timer.GetFrameCount() % 3 == 2)
			{
				// 回転角を変更する
				angle += DirectX::XMConvertToRadians(5.0f);
				// 弾を発射する
				bullet = bulletFactory->Create(position, angle);
			}
			if (bullet == nullptr)continue;

			// Bulletオブジェクトを配列に格納する
			this->air->BulletPool(bullet);

			break;
		}
	}
}

// 後始末をする
void NWay::Finalize() {}