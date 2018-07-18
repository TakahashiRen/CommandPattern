#include "BulletFactory.h"

// 2018/06/25	Fix memory leaks of bullet texture
// 2018/06/25	Fix memory leaks of calling Turret Finalize 

using namespace DirectX;

// コンストラクタ Constructor 
BulletFactory::BulletFactory() 
{
}

// 初期化する Initialize BulletFactory
void BulletFactory::Initialize() 
{
	// Turretテクスチャをロードする
	CreateWICTextureFromFile(Graphics::Get().Device().Get(),
		L"bullet.png", nullptr, this->texture.ReleaseAndGetAddressOf());

	// 配列のサイズを設定する resize vector array
	this->bulletArray.resize(BULLET_NUM);
	// Bulletオブジェクトを生成し配列に格納する Create Bullet objects and assign Bullet object
	for (int i = 0; i < BULLET_NUM; i++) 
	{
		// Bulletオブジェクトを生成する Create Bullet object
		this->bulletArray[i] = new Bullet();
		// 弾を「使用可」にする Set false to alive flag
		this->bulletArray[i]->Alive(false);
		// 初期化する Initialize 
		this->bulletArray[i]->Initialize(this->texture.Get());
	}
}

// 弾を生成する Create Bullet objects
Bullet* BulletFactory::Create(DirectX::SimpleMath::Vector2& position, float angle ) 
{
	for (int i = 0; i < BULLET_NUM; i++) 
	{
		if (this->bulletArray[i]->Alive() == false) 
		{
			// 弾は「使用中」を設定する
			this->bulletArray[i]->Alive(true);
			// 弾に飛行角度を設定する
			this->bulletArray[i]->Angle(angle);
			// 飛行開始位置を設定する
			this->bulletArray[i]->Position(position);
			// Bulletオブジェクトを返す
			return this->bulletArray[i];
		}
	}
	return nullptr;
}

// 後始末をする
void BulletFactory::Finalize() 
{
	// Bulletオブジェクトを破棄する生成し配列に格納する Delete Bullet objects
	for (int i = 0; i < BULLET_NUM; i++) 
	{
		this->bulletArray[i]->Finalize();
		// Bulletオブジェクトを破棄する Delete Bullet object
		if (bulletArray[i] != nullptr)
		{
			delete this->bulletArray[i];
			this->bulletArray[i] = nullptr;
		}
	}
	// 配列を破棄する Delete bulletArray
	this->bulletArray.clear();
	// 領域を解放する
	this->bulletArray.shrink_to_fit();

	// テクスチャをリセットする
	this->texture.Reset();
}
