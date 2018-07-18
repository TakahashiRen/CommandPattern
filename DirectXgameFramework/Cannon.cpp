#include "Cannon.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace DX;
using namespace Microsoft::WRL;
using namespace std;

// コンストラクタ Constructor
Cannon::Cannon(DirectX::SimpleMath::Vector2& position, float angle, float turretAngle, DirectX::SimpleMath::Vector4& color)
	//: position(position), angle(angle), turretAngle(turretAngle), color(color) {
	: Tank(position, angle, turretAngle, color) {
}

// オブジェクトを追加する
void Cannon::Add(unique_ptr<Tank>&& object) {
}

// Cannonオブジェクトを初期化する Initialize Cannon object
void Cannon::Initialize() {
	// Cannonテクスチャをロードする
	CreateWICTextureFromFile(Graphics::Get().Device().Get(),
	L"tank3.png", nullptr, this->texture.ReleaseAndGetAddressOf());
}

// Cannonオブジェクトを更新する Update Cannon object
void Cannon::Update(const DX::StepTimer& timer, DirectX::SimpleMath::Vector2& position, float angle, float turretAngle) {
	// 位置を設定する
	Tank::Position(position);
	// 回転角を設定する
	Tank::Angle(angle);
	// 砲塔回転角を設定する
	Tank::TurretAngle(turretAngle);
}

// Cannonオブジェクトを描画する Render Cannon object
void Cannon::Render(SpriteBatch* spriteBatch) {
	// スプライトを描画する Draw sprite
	spriteBatch->Draw(this->texture.Get(), Tank::Position(), nullptr, Tank::Color(), -Tank::Angle() + Tank::TurretAngle() + XMConvertToRadians(90.0f), Vector2(64.0f, 64.0f));
}

// Cannonオブジェクトの後処理をおこなう Finalize Turret object
void Cannon::Finalize() {
	// テクスチャをリセットする
	this->texture.Reset();
}

