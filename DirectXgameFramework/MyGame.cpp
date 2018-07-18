//  開発履歴
// 2018/06/01	砲塔が回転できるようにする 

#include "MyGame.h"

using namespace Microsoft;
using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace std;

// コンストラクタ Constructor
MyGame::MyGame(int width, int height) : Game(width, height){
}

// MyGameオブジェクトを初期する Initialize MyGame object
void MyGame::Initialize() {
	// 基本クラスのInitializeを呼び出す 
	Game::Initialize();

	// Airオブジェクトを生成する
	this->air = make_unique<Air>();
	// Airを初期化する
	this->air->Initialize();

	// Playerオブジェクトを生成する Create Player object
	this->player = make_unique<Player>(air.get());
	// Playerオブジェクトを初期化する Initialize Player object
	this->player->Initialize(Vector2(200.0f, 384.0f), XMConvertToRadians(0.0f), XMConvertToRadians(0.0f), Vector4(Colors::BlanchedAlmond));
}

// ゲームを更新する Update game
void MyGame::Update(const DX::StepTimer& timer) {
	float elapsedTime = float(timer.GetElapsedSeconds());

	// TODO: 更新処理を追加する Add your update process here

	// プレイヤを更新する Update Player object
	this->player->Update(timer);
}

// シーンを描画する Draws scene
void MyGame::Render(const DX::StepTimer& timer) {
	// 最初の更新の前は何も描画しないようにする Don't try to render anything before the first Update.
	if (timer.GetFrameCount() == 0) {
		return;
	}

	// TODO: レンダリングコードを追加する Add your rendering code here
	// 画面をクリアする Clear Screen
	Clear();
	// 描画を始める Begin rendering
	spriteBatch->Begin(SpriteSortMode_Deferred, commonStates->NonPremultiplied());

	// Playerオブジェクトを描画する Render Player object
	this->player->Render(timer, spriteBatch.get());

	// 描画を終える Finish rendering
	spriteBatch->End();
	// バックバッファをスクリーンに送る Presents the back buffer contents to the screen
	Present();
}

// 終了処理をおこなう Finalize Game
void MyGame::Finalize() {
	// Playerオブジェクトの後処理をおこなう
	this->player->Finalize();
	// Playerオブジェクトをリセットする
	this->player.reset();
	// Airオブジェクトの後処理をする
	air->Finalize();
	// Airオブジェクトをリセットする
	this->air.reset();

	// 基本クラスのFinalizeを呼び出す
	Game::Finalize();
}
