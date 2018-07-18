#pragma once
#ifndef AIR_DEFINED
#define AIR_DEFINED

#include <list>
#include <SpriteBatch.h>
#include "Bullet.h"
#include "BulletFactory.h"


class Air 
{
public:
	// コンストラクタ
	Air();
	// 初期化する
	void Initialize();
	// 更新する
	void Update(const DX::StepTimer& timer);
	// 描画する
	void Render(const DX::StepTimer& timer, DirectX::SpriteBatch* spriteBatch);
	// 後始末をする
	void Finalize();

public:
	// Bulletオブジェクトへのポインタ配列を返す
	std::list<Bullet*>& BulletPool() { return bullets; }
	//要素の追加
	void BulletPool(Bullet* bul) { bullets.push_back(bul); }

private:
	// Bulletオブジェクトへのポインタ配列
	std::list<Bullet*> bullets;
};

#endif	// AIR_DEFINED
