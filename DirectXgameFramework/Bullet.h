#pragma once
#ifndef BULLET_DEFINED
#define BULLET_DEFINED

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
#include <Keyboard.h>
#include <wrl.h>
#include "Graphics.h"
#include "StepTimer.h"
#include "dx.h"

// 弾クラス
class Bullet {
public:
	// 「使用可」かどうかを取得する
	bool Alive() {
		return this->alive;
	}
	// 「使用可」「使用不可」を設定する
	void Alive(bool alive) {
		this->alive = alive;
	}

	// 位置を取得する Get position
	DirectX::SimpleMath::Vector2 Position() {
		return position;
	}
	// 位置を設定する Set position
	void Position(DirectX::SimpleMath::Vector2 position) {
		this->position = position;
	}

	// 弾回転角を取得する Get angle
	float Angle() {
		return this->angle;
	}
	// 弾回転角を設定する Set angle
	void Angle(float angle) {
		this->angle = angle;
	}

	// 色を取得する Get color
	DirectX::SimpleMath::Vector4 Color() {
		return this->color;
	}
	// 色を設定する Set color
	void Color(DirectX::SimpleMath::Vector4 color) {
		this->color = color;
	}
	// コンストラクタ Constructor
	Bullet();
	// 初期化する Initialize Bullet object
	void Initialize(Microsoft::WRL::ComPtr<ID3D11ShaderResourceView>& texture);
	// Bulletオブジェクトを更新する Update Bullet object
	void Update(const DX::StepTimer& timer);
	// Bulletオブジェクトを描画する Render Bullet object
	void Render(DirectX::SpriteBatch* spriteBatch);
	// Bulletオブジェクトの後処理をおこなう Finalize Bullet object
	void Finalize();

private:
	// 弾スピードを定義する Set speed
	static const DirectX::SimpleMath::Vector2 SPEED;
	// 生死 alive
	bool alive;
	// 角度 Angle
	float angle;
	// 位置 Position
	DirectX::SimpleMath::Vector2 position;
	// 色 Color
	DirectX::SimpleMath::Vector4 color;
	// テクスチャ texture
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> texture;
};

#endif	// BULLET_DEFINED
