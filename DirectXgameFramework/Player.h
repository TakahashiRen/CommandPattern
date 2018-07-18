#pragma once
#ifndef PLAYER_DEFINED
#define PLAYER_DEFINED

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
#include "StepTimer.h"
#include "dx.h"

#include "Graphics.h"
#include "TankFactory.h"
#include "Tank.h"
#include "Turret.h"
#include "Body.h"

#include "BulletFactory.h"
#include "Air.h"
#include "Command.h"
#include "Weapon.h"


// プレイヤクラス
class Player {
public:
	// コンストラクタ
	Player(Air* air);
	// プレイヤを初期化する
	void Initialize(DirectX::SimpleMath::Vector2& position, float angle, float turretAngle, DirectX::SimpleMath::Vector4& color);
	// プレイヤを更新する
	bool Update(const DX::StepTimer& timer);
	// プレイヤを描画する
	void Render(const DX::StepTimer& timer, DirectX::SpriteBatch* spriteBatch);
	// プレイヤの後処理をおこなう
	void Finalize();

private:
	// テクスチャ Texture
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> texture;

	// キーボード Keyboard
	std::unique_ptr<DirectX::Keyboard> keyboard;
	// キーボードステートトラッカオブジェクト KeyboardStateTracker
	std::unique_ptr<DirectX::Keyboard::KeyboardStateTracker> keyboardTracker;
	// Tankオブジェクトへのポインタ Tank object
	std::unique_ptr<Tank> tank;

	// Moveオブジェクトへのポインタ Move object
	//std::unique_ptr<Move> move;
	// Turnオブジェクトへのポインタ Turn object
	//std::unique_ptr<Turn> turn;
	Air* air;
	// Bulletの飛行弾数
	int* bulletNum;

	TankCommand* command;
	BulletCommand* bCommand;
};

#endif // PLAYER_DEFINED
