#include "Command.h"

using namespace DirectX::SimpleMath;
using namespace DirectX;

// コンストラクタ
BulletCommand::BulletCommand(DirectX::SimpleMath::Vector2& position, float angle, float turretAngle, DirectX::SimpleMath::Vector4& color,Air* air, int* bulletnum)
	: Command(position, angle, turretAngle, color) ,air(air),bulletNum(bulletnum)
{

}
// 初期化する
void BulletCommand::Initialize()
{
	// BulletFactoryオブジェクトを生成する Create BulletFactory object
	// 事前に弾を配列分生成するため、コンストラクタに発射する弾の位置、本体回転角、砲塔回転角を設定できない
	bulletFactory = make_unique<BulletFactory>();
	// BulletFactoryオブジェクトを更新する
	bulletFactory->Initialize();

	// Normalオブジェクトを生成する
	normal = make_unique<Normal>(air);
	// Normalオブジェクトを初期化する
	normal->Initialize(bulletFactory.get());

	// nWayオブジェクトを生成する
	nway = make_unique<NWay>(air);
	// Bombオブジェクトを初期化する
	nway->Initialize(bulletFactory.get());

	// Bombオブジェクトを生成する
	bomb = make_unique<Bomb>(air);
	// Bombオブジェクトを初期化する
	bomb->Initialize(bulletFactory.get());

	// 飛行弾数を初期化する
	

}
// 実行する
void BulletCommand::Execute(const DX::StepTimer& timer, DirectX::Keyboard* keyboard, Tank* tank)
{
	// キーボードの状態を取得する
	Keyboard::State key = keyboard->GetState();

	// 通常弾を発射する Fire bullet
	if (key.IsKeyDown(Keyboard::Keys::Space)) {
		// 砲塔中心から大砲先端までの距離
		Vector2 offset = Vector2(64, 0);
		// 砲塔の回転角を計算する
		Matrix rotation = Matrix::CreateRotationZ(-tank->Angle() + tank->TurretAngle());
		// 弾が発射される位置を計算する
		Vector2 position = tank->Position() + Vector2::Transform(offset, rotation);
		// 通常弾を発射する
		normal->Shoot(timer, *bulletNum, position, -tank->Angle() + tank->TurretAngle());
	}

	// nWay弾を発射する Fire bullet
	if (key.IsKeyDown(Keyboard::Keys::X)) {
		// 砲塔中心から大砲先端までの距離
		Vector2 offset = Vector2(64, 0);
		// 砲塔の回転角を計算する
		Matrix rotation = Matrix::CreateRotationZ(-tank->Angle() + tank->TurretAngle());
		// nWay弾が発射される位置を計算する
		Vector2 position = tank->Position() + Vector2::Transform(offset, rotation);
		// nWay弾を発射する
		nway->Shoot(timer, *bulletNum, position, -tank->Angle() + tank->TurretAngle());
	}

	// ボムを発射する Fire Bomb bullet
	if (key.IsKeyDown(Keyboard::Keys::Z)) {
		// 砲塔中心から大砲先端までの距離
		Vector2 offset = Vector2(64, 0);
		// 砲塔の回転角を計算する
		Matrix rotation = Matrix::CreateRotationZ(-tank->Angle() + tank->TurretAngle());
		// ボム弾が発射される位置を計算する
		Vector2 position = tank->Position() + Vector2::Transform(offset, rotation);
		// ボムを発射する
		bomb->Shoot(timer, *bulletNum, position, -tank->Angle() + tank->TurretAngle());
	}

	// AirオブジェクトのBulletオブジェクトを更新する
	this->air->Update(timer, *bulletNum);

}
// 後始末をする
void BulletCommand::Finalize()
{
	// ボム弾をリセットする
	this->bomb.reset();
	// nWay弾オブジェクトをリセットする
	this->nway.reset();
	// 通常攻撃オブジェクトをリセットする
	this->normal.reset();
	// BulletFactoryオブジェクトの後始末をする
	this->bulletFactory->Finalize();
	// BulletFactoryオブジェクトをリセットする
	this->bulletFactory.reset();

}
