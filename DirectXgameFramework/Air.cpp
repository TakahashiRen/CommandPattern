#include "Air.h"

using namespace DirectX::SimpleMath;
using namespace DirectX;
using namespace DX;
using namespace Microsoft::WRL;
using namespace std;

// コンストラクタ
Air::Air() {}

// 初期化する
void Air::Initialize() 
{
	// 飛弾を管理する配列をここで確保する
	/*bullets.resize(BulletFactory::BULLET_NUM);*/
}

// 更新する
void Air::Update(const StepTimer& timer)
{
	// アクティブな弾を更新する
	for (list<Bullet*>::iterator ite = bullets.begin();ite != bullets.end();ite++) 
	{		
		if ((*ite)->Position().x < -BulletFactory::BULLET_SIZE / 2 ||
			(*ite)->Position().y < -BulletFactory::BULLET_SIZE / 2 ||
			(*ite)->Position().x > Graphics::Get().Width() + BulletFactory::BULLET_SIZE / 2 ||
			(*ite)->Position().y > Graphics::Get().Height() + BulletFactory::BULLET_SIZE / 2) 
		{
			// 描画境界を越えた飛弾を再利用にする
			(*ite)->Alive(false);
			ite = bullets.erase((ite));
			if (ite == bullets.end()) break;
		}
		// 飛弾が生存した場合
		if ((*ite)->Alive())
		{
			// 飛弾の位置を更新する
			(*ite)->Update(timer);
		}
	}
}

// 描画する
void Air::Render(const StepTimer& timer, SpriteBatch* spriteBatch)
{
	// 最初の更新の前は何も描画しないようにする Don't try to render anything before the first Update.
	if (timer.GetFrameCount() == 0)return;

	for (list<Bullet*>::iterator ite = bullets.begin(); ite != bullets.end(); ite++)
	{
		if ((*ite)->Alive())
		{
			// 飛弾を描画する
			(*ite)->Render(spriteBatch);
		}
	}
}

// 後始末をする
void Air::Finalize() 
{
	// bulletsオブジェクトをクリアする
	this->bullets.clear();
}
