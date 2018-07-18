#pragma once
#ifndef TANK_BODY
#define TANK_BODY

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

// 車体クラス
class Body : public Tank {
public:
	// コンストラクタ Constructor
	Body(DirectX::SimpleMath::Vector2& position, float angle, float turretAngle, DirectX::SimpleMath::Vector4& color);
	// Turretオブジェクトを追加する
	void Add(unique_ptr<Tank>&& turret) override;
	// Bodyオブジェクトを初期化する Initialize Body object
	void Initialize() override;
	// Bodyオブジェクトを更新する Update Body object
	void Update(const DX::StepTimer& timer, DirectX::SimpleMath::Vector2& position, float angle, float turretAngle) override;
	// Bodyオブジェクトを描画する Render Body object
	void Render(DirectX::SpriteBatch* spriteBatch) override;
	// Bodyオブジェクトの後処理をおこなう Finalize Body object
	void Finalize() override;

private:
	// 子パーツを格納する配列 vector store child part of tank
	std::vector<std::unique_ptr<Tank>> children;
	// テクスチャ Texture
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> texture;
};

#endif // TANK_BODY
