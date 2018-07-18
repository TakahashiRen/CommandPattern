#pragma once
#ifndef TANK_FACTORY
#define TANK_FACTORY

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

#include "Tank.h"
#include "Cannon.h"
#include "Turret.h"
#include "Body.h"

// 戦車ファクトリクラス
class TankFactory {
public:
	// コンストラクタ Constractor
	TankFactory(DirectX::SimpleMath::Vector2& position, float angle, float turreAngle, DirectX::SimpleMath::Vector4& color);
	// 戦車のパーツを生成する Create Tank parts
	std::unique_ptr<Tank> Create(Tank::PARTS_ID id);

private:
	// 位置 Position
	DirectX::SimpleMath::Vector2 position;
	// 速度 Velocity
	DirectX::SimpleMath::Vector2 velocity;
	// 車体角度 Angle
	float angle;
	// 砲塔角度 Turret Angle
	float turretAngle;
	// 色 Color
	DirectX::SimpleMath::Vector4 color;
	// テクスチャ texture
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> texture;
};

#endif	// TANK_FACTORY
