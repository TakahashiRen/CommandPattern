#include "BulletFactory.h"

// 2018/06/25	Fix memory leaks of bullet texture
// 2018/06/25	Fix memory leaks of calling Turret Finalize 

using namespace DirectX;

// �R���X�g���N�^ Constructor 
BulletFactory::BulletFactory() 
{
}

// ���������� Initialize BulletFactory
void BulletFactory::Initialize() 
{
	// Turret�e�N�X�`�������[�h����
	CreateWICTextureFromFile(Graphics::Get().Device().Get(),
		L"bullet.png", nullptr, this->texture.ReleaseAndGetAddressOf());

	// �z��̃T�C�Y��ݒ肷�� resize vector array
	this->bulletArray.resize(BULLET_NUM);
	// Bullet�I�u�W�F�N�g�𐶐����z��Ɋi�[���� Create Bullet objects and assign Bullet object
	for (int i = 0; i < BULLET_NUM; i++) 
	{
		// Bullet�I�u�W�F�N�g�𐶐����� Create Bullet object
		this->bulletArray[i] = new Bullet();
		// �e���u�g�p�v�ɂ��� Set false to alive flag
		this->bulletArray[i]->Alive(false);
		// ���������� Initialize 
		this->bulletArray[i]->Initialize(this->texture.Get());
	}
}

// �e�𐶐����� Create Bullet objects
Bullet* BulletFactory::Create(DirectX::SimpleMath::Vector2& position, float angle ) 
{
	for (int i = 0; i < BULLET_NUM; i++) 
	{
		if (this->bulletArray[i]->Alive() == false) 
		{
			// �e�́u�g�p���v��ݒ肷��
			this->bulletArray[i]->Alive(true);
			// �e�ɔ�s�p�x��ݒ肷��
			this->bulletArray[i]->Angle(angle);
			// ��s�J�n�ʒu��ݒ肷��
			this->bulletArray[i]->Position(position);
			// Bullet�I�u�W�F�N�g��Ԃ�
			return this->bulletArray[i];
		}
	}
	return nullptr;
}

// ��n��������
void BulletFactory::Finalize() 
{
	// Bullet�I�u�W�F�N�g��j�����鐶�����z��Ɋi�[���� Delete Bullet objects
	for (int i = 0; i < BULLET_NUM; i++) 
	{
		this->bulletArray[i]->Finalize();
		// Bullet�I�u�W�F�N�g��j������ Delete Bullet object
		if (bulletArray[i] != nullptr)
		{
			delete this->bulletArray[i];
			this->bulletArray[i] = nullptr;
		}
	}
	// �z���j������ Delete bulletArray
	this->bulletArray.clear();
	// �̈���������
	this->bulletArray.shrink_to_fit();

	// �e�N�X�`�������Z�b�g����
	this->texture.Reset();
}
