#pragma once
#ifndef CANNON_DEFINED
#define CANNON_DEFINED

#include <windows.h>
#include <wrl/client.h>
#include <d3d11_1.h>
#include <DirectXMath.h>
#include <SimpleMath.h>

#include <SpriteBatch.h>
#include <DirectXColors.h>
#include <WICTextureLoader.h>
#include <algorithm>
#include <Memory>
#include <wrl.h>

#include "Graphics.h"
#include "Tank.h"

// 大砲クラス
class Cannon : public Tank {
public:
	// コンストラクタ Constructor
	Cannon(DirectX::SimpleMath::Vector2& position, float angle, float turretAngle, DirectX::SimpleMath::Vector4& color);
	// オブジェクトを追加する
	void Add(unique_ptr<Tank>&& object) override;
	// Cannonオブジェクトを初期化する Initialize Cannon object
	void Initialize() override;
	// Cannonオブジェクトを更新する Update Cannon object
	void Update(const DX::StepTimer& timer, DirectX::SimpleMath::Vector2& position, float angle, float turretAngle) override;
	// Cannonオブジェクトを描画する Render Cannon object
	void Render(DirectX::SpriteBatch* spriteBatch) override;
	// Cannonオブジェクトの後処理をおこなう Finalize Turret object
	void Finalize() override;

private:
	// テクスチャ texture
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> texture;
};

#endif // CANNON_DEFINED

