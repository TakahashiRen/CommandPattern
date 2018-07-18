#include "Bullet.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace DX;
using namespace std;
using namespace Microsoft::WRL;

// 弾スピードを定義する
const Vector2 Bullet::SPEED(4.0f, 0.0f);

// コンストラクタ Constructor
Bullet::Bullet() : alive(false), angle(0.0f), position(0.0f, 0.0f){}

// 初期化する
void Bullet::Initialize(ID3D11ShaderResourceView* texture) 
{
	this->texture = texture;
}

// Bulletオブジェクトを更新する Update Bullet object 
void Bullet::Update(const DX::StepTimer& timer) 
{
	// 弾を回転する Rotate bullet object
	Matrix rotation = Matrix::CreateRotationZ(this->angle);
	// 速度を計算する Calculate bullet velocity
	Vector2 velocity = Vector2::TransformNormal(SPEED, rotation);
	// 移動する Move position
	this->position += velocity;
}

// Bulletオブジェクトを描画する Render Bullet object 
void Bullet::Render(DirectX::SpriteBatch* spriteBatch) 
{
	// スプライトを描画する
	spriteBatch->Draw(this->texture, this->position, nullptr, Colors::Orange, angle + XMConvertToRadians(90.0f), Vector2(8.0f, 8.0f));
}

// Bulletオブジェクトの後処理をおこなう Finalize Bullet object
void Bullet::Finalize() {}

