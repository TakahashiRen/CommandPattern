#include "Weapon.h"

using namespace DirectX;
using namespace DX;


// コンストラクタ
Normal::Normal(Air* air) : air(air) {
}

// 初期化する
void Normal::Initialize(BulletFactory* bulletFactory) {
	// BulletFactoryオブジェクトを生成する Create BulletFactory object
	// 事前に弾を配列分生成するため、コンストラクタに発射する弾の位置、本体回転角、砲塔回転角を設定できない
	// bulletFactory = make_unique<BulletFactory>();
	// BulletFactoryオブジェクトを更新する
	// bulletFactory->Initialize();
	// Playerオブジェクトで生成されたBulletFactoryオブジェクトのアドレスをメンバー変数に格納する
	this->bulletFactory = bulletFactory;
}

// 弾を発射する
void Normal::Shoot(const DX::StepTimer& timer, int& bulletNum, DirectX::SimpleMath::Vector2& position, float angle ) {
	// 経過時間を取得する
	float elapsedTime = float(timer.GetElapsedSeconds());

	Bullet* bullet = nullptr;
	// 3フレーム毎に弾を発射する
	if (timer.GetFrameCount() % 3 == 0) {

		for (int index = 0; index < BulletFactory::BULLET_NUM; index++) {
			// 配列の要素がnullptrの場合
			if (this->air->BulletPool()[index] == nullptr ||
				this->air->BulletPool()[index]->Alive() == false) {
				// 弾を発射する
  				bullet = bulletFactory->Create(position, angle);
				if (bullet == nullptr)
					continue;
				if (this->air->BulletPool()[index] == nullptr) {
					// 弾数を増やす
					if (bulletNum < BulletFactory::BULLET_NUM - 1)
						bulletNum++;
				}
				// Bulletオブジェクトを配列に格納する
				this->air->BulletPool()[index] = bullet;
				break;
			}
		}
	}
}

// 後始末をする
void Normal::Finalize() {
	// BulletFactoryオブジェクトの後始末をする
	bulletFactory->Finalize();
}

