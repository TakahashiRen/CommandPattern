#pragma once
#ifndef TANK_DEFINED
#define TANK_DEFINED

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

#include "StepTimer.h"
#include "dx.h"
#include "Graphics.h"

class Tank;

// 戦車インターフェース
class ITank {
	// 純粋仮想関数(pure virtual function)を宣言する
public:
	// Tankパーツオブジェクトを追加する Add Tank parts object
	virtual void Add(unique_ptr<Tank>&& parts) = 0;
	// Tankオブジェクトを初期化する Initiaize Tank objects
	virtual void Initialize() = 0;
	// Tankオブジェクトを更新する Update Tank objects
	virtual void Update(const DX::StepTimer& timer, DirectX::SimpleMath::Vector2& position, float angle, float turretAngle) = 0;
	// Tankオブジェクトを描画する Render Tank objects
	virtual void Render(DirectX::SpriteBatch* spriteBatch) = 0;
	// 後処理をおこなう Finalize Tank objects
	virtual void Finalize() = 0;
};

// 戦車クラス
class Tank : public ITank {
public:
	// パーツID
	enum PARTS_ID { CANNON, TURRET, BODY };

	// 位置を取得する Get position
	DirectX::SimpleMath::Vector2 Position() {
		return position;
	}

	// 位置を設定する Set position
	void Position(DirectX::SimpleMath::Vector2 position) {
		this->position = position;
	}

	// 速度を取得する Get velocity
	DirectX::SimpleMath::Vector2 Velocity() {
		return velocity;
	}
	// 速度を設定する Set velocity
	void Velocity(DirectX::SimpleMath::Vector2 velocity) {
		this->velocity = velocity;
	}

	// 角度を取得する Get angle
	float Angle() {
		return this->angle;
	}
	// 角度を設定する Set angle
	void Angle(float angle) {
		this->angle = angle;
	}

	// 砲塔角度を取得する Get turret angle
	float TurretAngle() {
		return turretAngle;
	}
	// 砲塔角度を設定する Set turret angle
	void TurretAngle(float headAngle) {
		this->turretAngle = headAngle;
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
	Tank() : position(DirectX::SimpleMath::Vector2(0.0f, 0.0f)), angle(0.0f), turretAngle(0.0f), color(DirectX::SimpleMath::Vector4(0.0f, 0.0f, 0.0f, 0.0f)) {
	}
	// コンストラクタ Constructor
	Tank(DirectX::SimpleMath::Vector2& position, float angle, float turretAngle, DirectX::SimpleMath::Vector4& color)
		: position(position), angle(angle), turretAngle(turretAngle), color(color) {

	}

private:
	// 位置 Position
	DirectX::SimpleMath::Vector2 position;
	// 速度 Velocity
	DirectX::SimpleMath::Vector2 velocity;
	// 車体回転角 Body angle
	float angle;
	// 砲塔回転角 Turret angle
	float turretAngle;
	// 色 Color
	DirectX::SimpleMath::Vector4 color;
};

#endif // TANK_DEFINED
