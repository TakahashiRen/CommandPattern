#pragma once
#ifndef BULLET_FACTORY_DEFINED
#define BULLET_FACTORY_DEFINED

#include <vector>
#include <WICTextureLoader.h>
#include "Bullet.h"

class BulletFactory {
public:
	// �e�� Bullet number
	static const int BULLET_NUM = 1000;
	static const int BULLET_SIZE = 16;

	// �R���X�g���N�^ Constructor
	BulletFactory();
	// ���������� Initialize
	void Initialize();
	// �e�𔭎˂��� Shoot bullet
	Bullet* Create(DirectX::SimpleMath::Vector2& position, float angle);
	// ��n�������� Finalize
	void Finalize();

private:
	// �e�z�� Bullet array
	std::vector<Bullet*> bulletArray;
	// �e�N�X�`�� texture
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> texture;
};

#endif	// BULLET_FACTORY_DEFINED
