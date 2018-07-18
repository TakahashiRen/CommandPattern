#pragma once
#ifndef AIR_DEFINED
#define AIR_DEFINED

#include <vector>
#include <SpriteBatch.h>
#include "Bullet.h"
#include "BulletFactory.h"

using namespace std;

class Air {
public:
	// Bulletオブジェクトへのポインタ配列を返す
	std::vector<Bullet*>& BulletPool() {
		return bullets;
	}
public:
	// コンストラクタ
	Air();
	// 初期化する
	void Initialize();
	// 更新する
	void Update(const DX::StepTimer& timer, int bulletNum);
	// 描画する
	void Render(const DX::StepTimer& timer, DirectX::SpriteBatch* spriteBatch, int bulletNum);
	// 後始末をする
	void Finalize();
private:
	// Bulletオブジェクトへのポインタ配列
	vector<Bullet*> bullets;
};

#endif	// AIR_DEFINED
