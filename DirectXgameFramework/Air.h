#pragma once
#ifndef AIR_DEFINED
#define AIR_DEFINED

#include <list>
#include <SpriteBatch.h>
#include "Bullet.h"
#include "BulletFactory.h"


class Air 
{
public:
	// �R���X�g���N�^
	Air();
	// ����������
	void Initialize();
	// �X�V����
	void Update(const DX::StepTimer& timer);
	// �`�悷��
	void Render(const DX::StepTimer& timer, DirectX::SpriteBatch* spriteBatch);
	// ��n��������
	void Finalize();

public:
	// Bullet�I�u�W�F�N�g�ւ̃|�C���^�z���Ԃ�
	std::list<Bullet*>& BulletPool() { return bullets; }
	//�v�f�̒ǉ�
	void BulletPool(Bullet* bul) { bullets.push_back(bul); }

private:
	// Bullet�I�u�W�F�N�g�ւ̃|�C���^�z��
	std::list<Bullet*> bullets;
};

#endif	// AIR_DEFINED
