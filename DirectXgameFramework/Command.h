#pragma once
#ifndef COMMAND_DEFINED
#define COMMAND_DEFINED

#include <d3d11_1.h>
#include <DirectXMath.h>
#include <SimpleMath.h>
#include <Keyboard.h>

#include "Tank.h"
#include "Turret.h"
#include "Cannon.h"
#include "TankFactory.h"
#include "Air.h"
#include "Weapon.h"
#include "BulletFactory.h"

class ICommand {
public:
	// ����������
	virtual void Initialize() = 0;
	// ���s����
	virtual void Execute(const DX::StepTimer& timer, DirectX::Keyboard* keyboard, Tank* tank) = 0;
	// ��n��������
	virtual void Finalize() = 0;
};

class Command : public ICommand {
public:
	// �R���X�g���N�^
	Command(DirectX::SimpleMath::Vector2& position, float angle, float turretAngle, DirectX::SimpleMath::Vector4& color) :
	position(position), angle(angle), turretAngle(turretAngle), color(color) {
	}

	// ����������
	virtual void Initialize() {
		// TankFactory�I�u�W�F�N�g�𐶐����� Create TankFactory object
		TankFactory tankFactory(this->position, this->angle, this->turretAngle, this->color);
		// Body�I�u�W�F�N�g�𐶐����� Create Body object
		this->tank = tankFactory.Create(Tank::PARTS_ID::BODY);
		// Turret�I�u�W�F�N�𐶐����� Create Turret object
		unique_ptr<Tank> turret = tankFactory.Create(Tank::PARTS_ID::TURRET);
		// Cannon�I�u�W�F�N�𐶐����� Create Cannon object
		unique_ptr<Tank> cannon = tankFactory.Create(Tank::PARTS_ID::CANNON);

		// Turret�I�u�W�F�N�g��Cannon�I�u�W�F�N�g��ǉ�����
		turret->Add(move(cannon));
		// Body�I�u�W�F�N�g��Turret�I�u�W�F�N�g��ǉ�����
		this->tank->Add(move(turret));

		// �ʒu��ݒ肷��
		this->tank->Position(position);
		// ��]�p��ݒ肷��
		this->tank->Angle(angle);
	}

	// ��n��������
	virtual void Finalize() {

	}

private:
	DirectX::SimpleMath::Vector2 position;
	float angle;
	float turretAngle;
	DirectX::SimpleMath::Vector4 color;
	// Tank�I�u�W�F�N�g�ւ̃|�C���^ Tank object
	std::unique_ptr<Tank> tank;
};

class TankCommand : public Command {
public:
	// �R���X�g���N�^
	TankCommand(DirectX::SimpleMath::Vector2& position, float angle, float turretAngle, DirectX::SimpleMath::Vector4& color);
	// ����������
	virtual void Initialize();
	// ���s����
	virtual void Execute(const DX::StepTimer& timer, DirectX::Keyboard* keyboard, Tank* tank) override;
	// ��n��������
	virtual void Finalize();
};

class BulletCommand : public Command
{
private:
	Air* air;
	// Normal�I�u�W�F�N�g�ւ̃|�C���^ Normal object
	std::unique_ptr<Normal> normal;
	// nWay�I�u�W�F�N�g�ւ̃|�C���^ Bomb object
	std::unique_ptr<NWay> nway;
	// Bomb�I�u�W�F�N�g�ւ̃|�C���^ Bomb object
	std::unique_ptr<Bomb> bomb;
	// BulletFactory�I�u�W�F�N�g BulletFactory object
	std::unique_ptr<BulletFactory> bulletFactory;
	// Bullet�̔�s�e��
	int* bulletNum;

public:
	// �R���X�g���N�^
	BulletCommand(DirectX::SimpleMath::Vector2& position, float angle, float turretAngle, DirectX::SimpleMath::Vector4& color,Air* air,int* bulletnum);
	// ����������
	virtual void Initialize();
	// ���s����
	virtual void Execute(const DX::StepTimer& timer, DirectX::Keyboard* keyboard, Tank* tank) override;
	// ��n��������
	virtual void Finalize();

};

#endif	// COMMAND_DEFINED

