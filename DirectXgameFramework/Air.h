#pragma once
#ifndef AIR_DEFINED
#define AIR_DEFINED

#include <vector>
#include <SpriteBatch.h>
#include "Bullet.h"
#include "BulletFactory.h"

using namespace std;

class Air {
public:
	// Bullet�I�u�W�F�N�g�ւ̃|�C���^�z���Ԃ�
	std::vector<Bullet*>& BulletPool() {
		return bullets;
	}
public:
	// �R���X�g���N�^
	Air();
	// ����������
	void Initialize();
	// �X�V����
	void Update(const DX::StepTimer& timer, int bulletNum);
	// �`�悷��
	void Render(const DX::StepTimer& timer, DirectX::SpriteBatch* spriteBatch, int bulletNum);
	// ��n��������
	void Finalize();
private:
	// Bullet�I�u�W�F�N�g�ւ̃|�C���^�z��
	vector<Bullet*> bullets;
};

#endif	// AIR_DEFINED
