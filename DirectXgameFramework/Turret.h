#pragma once
#ifndef TURRET_DEFINED
#define TURRET_DEFINED

#include <vector>
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

// 砲塔クラス
class Turret : public Tank {
public:
	// コンストラクタ Constructor
	Turret(DirectX::SimpleMath::Vector2& position, float angle, float turretAngle, DirectX::SimpleMath::Vector4& color);
	// Cannonオブジェクトを追加する
	void Add(unique_ptr<Tank>&& cannon) override;
	// Turretオブジェクトを初期化する Initialize Turret object
	void Initialize() override;
	// Turretオブジェクトを更新する Update Turret object
	void Update(const DX::StepTimer& timer, DirectX::SimpleMath::Vector2& position, float angle, float turretAngle) override;
	// Turretオブジェクトを描画する Render Turret object
	void Render(DirectX::SpriteBatch* spriteBatch) override;
	// Turretオブジェクトの後処理をおこなう Finalize Turret object
	void Finalize() override;

private:
	// 子パーツを格納する配列 vector store child part of tank
	std::vector<std::unique_ptr<Tank>> children;
	// テクスチャ texture
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> texture;
};

#endif // TURRET_DEFINED

