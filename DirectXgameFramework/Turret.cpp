#include "Turret.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace DX;
using namespace Microsoft::WRL;
using namespace std;

// コンストラクタ Constructor
Turret::Turret(DirectX::SimpleMath::Vector2& position, float angle, float turretAngle, DirectX::SimpleMath::Vector4& color)
	//: position(position), angle(angle), turretAngle(turretAngle), color(color) {
	: Tank(position, angle, turretAngle, color) {
}

// Cannonオブジェクトを追加する
void Turret::Add(unique_ptr<Tank>&& cannon) {
	// オブジェクトを追加する
	children.emplace_back(move(cannon));
}

// Turretオブジェクトを初期化する Initialize Turret object
void Turret::Initialize() {
	// Turretテクスチャをロードする
	CreateWICTextureFromFile(Graphics::Get().Device().Get(),
	L"tank2.png", nullptr, this->texture.ReleaseAndGetAddressOf());
}

// Turretオブジェクトを更新する Update Turret object
void Turret::Update(const DX::StepTimer& timer, DirectX::SimpleMath::Vector2& position, float angle, float turretAngle) {
	// 位置を設定する
	Tank::Position(position);
	// 本体回転角を設定する
	Tank::Angle(angle);
	// 砲塔回転角を設定する
	Tank::TurretAngle(turretAngle);

	for (auto& part : children) {
		if (part != nullptr) {
			// 再帰的にUpdate()を呼び出す
			part->Update(timer, position, angle, turretAngle);
		}
	}
}

// Turretオブジェクトを描画する Render Turret object
void Turret::Render(SpriteBatch* spriteBatch) {
	// スプライトを描画する Draw sprite
	spriteBatch->Draw(this->texture.Get(), Tank::Position(), nullptr, Tank::Color(), -Tank::Angle() + Tank::TurretAngle() + XMConvertToRadians(90.0f), Vector2(64.0f, 64.0f));
	for (auto& part : children) {
		if (part != nullptr) {
			// 再帰的にRender関数を呼び出す
			part->Render(spriteBatch);
		}
	}
}

// Turretオブジェクトの後処理をおこなう Finalize Turret object
void Turret::Finalize() {
	// テクスチャをリセットする
	this->texture.Reset();
	// 再帰的にFinalizeを呼び出す
	for (auto& part : children) {
		if (part != nullptr) {
			part->Finalize();
			// 再帰的にオブジェクトを破棄する
			part.reset();
		}
	}
	// 領域を解放する
	this->children.shrink_to_fit();
}
