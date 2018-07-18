#include "Player.h"

using namespace DirectX::SimpleMath;
using namespace DirectX;
using namespace DX;
using namespace Microsoft::WRL;
using namespace std;

// コンストラクタ Constructor
Player::Player(Air* air) : air(air) {
}

// Playerオブジェクトを初期化する Initialize Player object
void Player::Initialize(Vector2& position, float angle, float turretAngle, Vector4& color) {
	// Keyboardオブジェクトを生成する Create Keyboard object
	this->keyboard = make_unique<Keyboard>();
	// KeyboardStateTrackerオブジェクトを生成する Create KeyboardStateTracker object
	this->keyboardTracker = make_unique<Keyboard::KeyboardStateTracker>();

	// TankFactoryオブジェクトを生成する Create TankFactory object
	TankFactory tankFactory(position, angle, turretAngle, color);
	// Bodyオブジェクトを生成する Create Body object
	this->tank = tankFactory.Create(Tank::PARTS_ID::BODY);
	// Turretオブジェクを生成する Create Turret object
	unique_ptr<Tank> turret = tankFactory.Create(Tank::PARTS_ID::TURRET);
	// Cannonオブジェクを生成する Create Cannon object
	unique_ptr<Tank> cannon = tankFactory.Create(Tank::PARTS_ID::CANNON);

	// TurretオブジェクトにCannonオブジェクトを追加する
	turret->Add(move(cannon));
	// BodyオブジェクトにTurretオブジェクトを追加する
	this->tank->Add(move(turret));

	// 位置を設定する
	this->tank->Position(position);
	// 回転角を設定する
	this->tank->Angle(angle);
	bulletNum = new int(0);

	command = new TankCommand(this->tank->Position(), this->tank->Angle(), this->tank->TurretAngle(), this->tank->Color());
	command->Initialize();
	bCommand = new BulletCommand(this->tank->Position(), this->tank->Angle(), this->tank->TurretAngle(), this->tank->Color(), air,bulletNum);
	bCommand->Initialize();
}

// Playerオブジェクトを更新する
bool Player::Update(const StepTimer& timer) {
	// 経過時間を取得する
	float elapsedTime = float(timer.GetElapsedSeconds());
	// キーボードを取得する
	Keyboard& kb = Keyboard::Get();

	command->Execute(timer, &kb, this->tank.get());
	bCommand->Execute(timer, &kb, this->tank.get());

	return true;
}

// スプライトを描画する Render Sprite object
void Player::Render(const StepTimer& timer, SpriteBatch* spriteBatch) {
	// Tankオブジェクトを描画する Render Tank objects
	this->tank->Render(spriteBatch);

	// AirオブジェクトのBulletオブジェクトを描画する
	this->air->Render(timer, spriteBatch, *this->bulletNum);
}

// 後処理をおこなう
void Player::Finalize() {

	// 再帰的にTankオブジェクトの後処理をおこなう Finalize Tank object
	this->tank->Finalize();	
	// Tankオブジェクトを破棄する Delete Tank object
	if(this->tank != nullptr)
		this->tank.reset();
	// Keyboardオブジェクトをリセットする
	this->keyboard.reset();
	// KeyboardTrackerオブジェクトをリセットする
	this->keyboardTracker.reset();
	//コマンドの削除
	if (this->command != nullptr)
	{
		delete this->command;
		this->command = nullptr;
	}
	if (this->bCommand != nullptr)
	{
		delete this->bCommand;
		this->bCommand = nullptr;
	}
}
