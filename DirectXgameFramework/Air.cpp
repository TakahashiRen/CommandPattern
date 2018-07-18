#include "Air.h"

using namespace DirectX::SimpleMath;
using namespace DirectX;
using namespace DX;
using namespace Microsoft::WRL;
using namespace std;

// コンストラクタ
Air::Air() {
}

// 初期化する
void Air::Initialize() {
	// 飛弾を管理する配列をここで確保する
	bullets.resize(BulletFactory::BULLET_NUM);
}

// 更新する
void Air::Update(const StepTimer& timer, int bulletNum){
	// 飛弾を更新する
	for (int i = 0; i < bulletNum; i++) {
		if (this->bullets[i] == nullptr) {
			continue;
		}
		if (this->bullets[i]->Position().x < -BulletFactory::BULLET_SIZE / 2 ||
			this->bullets[i]->Position().y < -BulletFactory::BULLET_SIZE / 2 ||
			this->bullets[i]->Position().x > Graphics::Get().Width() + BulletFactory::BULLET_SIZE / 2 ||
			this->bullets[i]->Position().y > Graphics::Get().Height() + BulletFactory::BULLET_SIZE / 2) {
			// 描画境界を越えた飛弾を再利用にする
			this->bullets[i]->Alive(false);
		}
		// 飛弾が生存した場合
		if (this->bullets[i]->Alive()) {
			// 飛弾の位置を更新する
			this->bullets[i]->Update(timer);
		}
	}
}

// 描画する
void Air::Render(const StepTimer& timer, SpriteBatch* spriteBatch, int bulletNum){
	// 最初の更新の前は何も描画しないようにする Don't try to render anything before the first Update.
	if (timer.GetFrameCount() == 0) {
		return;
	}
	for (int i = 0; i < bulletNum; i++) {
		if (this->bullets[i]->Alive()) {
			// 飛弾を描画する
			this->bullets[i]->Render(spriteBatch);
		}
	}
}

// 後始末をする
void Air::Finalize() {
	// bulletsオブジェクトをクリアする
	this->bullets.clear();
	// 飛弾配列を解放する
	this->bullets.shrink_to_fit();
}
