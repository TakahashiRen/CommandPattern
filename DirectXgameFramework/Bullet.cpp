#include "Bullet.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace DX;
using namespace std;
using namespace Microsoft::WRL;

// �e�X�s�[�h���`����
const Vector2 Bullet::SPEED(4.0f, 0.0f);

// �R���X�g���N�^ Constructor
Bullet::Bullet() : alive(false), angle(0.0f), position(0.0f, 0.0f){}

// ����������
void Bullet::Initialize(ID3D11ShaderResourceView* texture) 
{
	this->texture = texture;
}

// Bullet�I�u�W�F�N�g���X�V���� Update Bullet object 
void Bullet::Update(const DX::StepTimer& timer) 
{
	// �e����]���� Rotate bullet object
	Matrix rotation = Matrix::CreateRotationZ(this->angle);
	// ���x���v�Z���� Calculate bullet velocity
	Vector2 velocity = Vector2::TransformNormal(SPEED, rotation);
	// �ړ����� Move position
	this->position += velocity;
}

// Bullet�I�u�W�F�N�g��`�悷�� Render Bullet object 
void Bullet::Render(DirectX::SpriteBatch* spriteBatch) 
{
	// �X�v���C�g��`�悷��
	spriteBatch->Draw(this->texture, this->position, nullptr, Colors::Orange, angle + XMConvertToRadians(90.0f), Vector2(8.0f, 8.0f));
}

// Bullet�I�u�W�F�N�g�̌㏈���������Ȃ� Finalize Bullet object
void Bullet::Finalize() {}

