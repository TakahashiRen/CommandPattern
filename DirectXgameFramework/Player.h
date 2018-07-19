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
#include <queue>
#include "StepTimer.h"
#include "dx.h"

#include "Graphics.h"
#include "TankFactory.h"
#include "Tank.h"
#include "Turret.h"
#include "Body.h"

#include "BulletFactory.h"
#include "Air.h"
#include "Weapon.h"
#include "InputHandler.h"
#include "Command.h"

// プレイヤクラス
class Player 
{
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
	// キーボード Keyboard
	std::unique_ptr<DirectX::Keyboard> keyboard;
	// キーボードステートトラッカオブジェクト KeyboardStateTracker
	std::unique_ptr<DirectX::Keyboard::KeyboardStateTracker> keyboardTracker;

	// Tankオブジェクトへのポインタ Tank object
	std::unique_ptr<Tank> tank;

	//弾のファクトリー
	std::unique_ptr<BulletFactory> bulletFactory;

	//弾管理クラスのポインタ
	Air* air;

	//入力管理クラス
	std::unique_ptr<InputHandler> inputHandler;

	//実行コマンドのキュー
	std::queue<ICommand*> command;
};

#endif // PLAYER_DEFINED
