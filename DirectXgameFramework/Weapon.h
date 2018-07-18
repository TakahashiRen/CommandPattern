#pragma once
#ifndef WEAPON_DEFINED
#define WEAPON_DEFINED
#include <memory>
#include <d3d11_1.h>
#include <DirectXMath.h>
#include <SimpleMath.h>

#include "StepTimer.h"
#include "Bullet.h"
#include "BulletFactory.h"
#include "Air.h"

class Weapon {
public:
	enum ID { NORMAL, NWAY, BOMB };
	// ����������
	virtual void Initialize(BulletFactory* bulletFactory) = 0;
	// ���˂���
	virtual void Shoot(const DX::StepTimer& timer, int& bulletNum, DirectX::SimpleMath::Vector2& position, float angle) = 0;
	// ��n��������
	virtual void Finalize() = 0;
};

class Normal : public Weapon {
public:
	// �R���X�g���N�^
	Normal(Air* air);
	// ����������
	void Initialize(BulletFactory* bulletFactory) override;
	// �e�𔭎˂���
	void Shoot(const DX::StepTimer& timer, int& bulletNum, DirectX::SimpleMath::Vector2& position, float angle) override ;
	// ��n��������
	void Finalize() override;

private:
	// Air�I�u�W�F�N�g�ւ̃|�C���^
	Air* air;
	// BulletFactory�I�u�W�F�N�g�ւ̃|�C���^ BulletFactory object
	BulletFactory* bulletFactory;
};

class NWay : public Weapon {
public:
	// �R���X�g���N�^
	NWay(Air* air);
	// ����������
	void Initialize(BulletFactory* bulletFactory) override;
	// �e�𔭎˂���
	void Shoot(const DX::StepTimer& timer, int& bulletNum, DirectX::SimpleMath::Vector2& position, float angle) override;
	// ��n��������
	void Finalize() override;

private:
	// Air�I�u�W�F�N�g�ւ̃|�C���^
	Air* air;
	// BulletFactory�I�u�W�F�N�g BulletFactory object
	BulletFactory* bulletFactory;
};


class Bomb : public Weapon {
public:
	// �R���X�g���N�^
	Bomb(Air* air);
	// ����������
	void Initialize(BulletFactory* bulletFactory) override;
	// �e�𔭎˂���
	void Shoot(const DX::StepTimer& timer, int& bulletNum, DirectX::SimpleMath::Vector2& position, float angle) override;
	// ��n��������
	void Finalize() override;

private:
	// Air�I�u�W�F�N�g�ւ̃|�C���^
	Air* air;
	// BulletFactory�I�u�W�F�N�g BulletFactory object
	BulletFactory* bulletFactory;
};

#endif	// WEAPON_DEFINED

