#pragma once
#ifndef BULLET_FACTORY_DEFINED
#define BULLET_FACTORY_DEFINED

#include <vector>
#include <WICTextureLoader.h>
#include "Bullet.h"

class BulletFactory {
public:
	// 弾数 Bullet number
	static const int BULLET_NUM = 1000;
	static const int BULLET_SIZE = 16;

	// コンストラクタ Constructor
	BulletFactory();
	// 初期化する Initialize
	void Initialize();
	// 弾を発射する Shoot bullet
	Bullet* Create(DirectX::SimpleMath::Vector2& position, float angle);
	// 後始末をする Finalize
	void Finalize();

private:
	// 弾配列 Bullet array
	std::vector<Bullet*> bulletArray;
	// テクスチャ texture
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> texture;
};

#endif	// BULLET_FACTORY_DEFINED
