#include "Body.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace DX;
using namespace std;
using namespace Microsoft::WRL;

// コンストラクタ Constructor
Body::Body(DirectX::SimpleMath::Vector2& position, float angle, float turretAngle, DirectX::SimpleMath::Vector4& color)
	: Tank(position, angle, turretAngle, color) {
}

// Turretオブジェクトを追加する
void Body::Add(unique_ptr<Tank>&& turret) {
	// Turretオブジェクトを追加する
	children.emplace_back(move(turret));
}

// Bodyオブジェクトを初期化する Initialize Body object
void Body::Initialize(){
	// Bodyテクスチャをロードする
	CreateWICTextureFromFile(Graphics::Get().Device().Get(),
	L"tank1.png", nullptr, this->texture.ReleaseAndGetAddressOf());
}

// Bodyオブジェクトを更新する Update Body object
void Body::Update(const DX::StepTimer& timer, DirectX::SimpleMath::Vector2& position, float angle, float turretAngle){
	// 位置を設定する
	Tank::Position(position);
	// 本体回転角を設定する
	Tank::Angle(angle);
	// 砲塔回転角を設定する
	Tank::TurretAngle(turretAngle);

	for (unique_ptr<Tank>& part : children) {
		if (part != nullptr) {
			// 再帰的にUpdate()を呼び出す
			part->Update(timer, position, angle, turretAngle);
		}
	}
}

// Bodyオブジェクトを描画する Render Body object
void Body::Render(SpriteBatch* spriteBatch) {
	// スプライトを描画する
	spriteBatch->Draw(this->texture.Get(), Tank::Position(), nullptr, Tank::Color(), -Tank::Angle() + XMConvertToRadians(90.0f), Vector2(64.0f, 64.0f));
	for (auto& part : children) {
		if (part != nullptr) {
			// 再帰的にRender関数を呼び出す
			part->Render(spriteBatch);
		}
	}
}

// Bodyオブジェクトの後処理をおこなう
void Body::Finalize() {
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