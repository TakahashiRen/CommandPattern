#pragma once
#ifndef TANK_DEFINED
#define TANK_DEFINED

#include <windows.h>
#include <wrl/client.h>
#include <d3d11_1.h>
#include <DirectXMath.h>
#include <SimpleMath.h>
#include <SpriteBatch.h>
#include <DirectXColors.h>
#include <WICTextureLoader.h>
#include <algorithm>
#include <Memory>
#include <Keyboard.h>
#include <wrl.h>

#include "StepTimer.h"
#include "dx.h"
#include "Graphics.h"

class Tank;

// ��ԃC���^�[�t�F�[�X
class ITank {
	// �������z�֐�(pure virtual function)��錾����
public:
	// Tank�p�[�c�I�u�W�F�N�g��ǉ����� Add Tank parts object
	virtual void Add(unique_ptr<Tank>&& parts) = 0;
	// Tank�I�u�W�F�N�g������������ Initiaize Tank objects
	virtual void Initialize() = 0;
	// Tank�I�u�W�F�N�g���X�V���� Update Tank objects
	virtual void Update(const DX::StepTimer& timer, DirectX::SimpleMath::Vector2& position, float angle, float turretAngle) = 0;
	// Tank�I�u�W�F�N�g��`�悷�� Render Tank objects
	virtual void Render(DirectX::SpriteBatch* spriteBatch) = 0;
	// �㏈���������Ȃ� Finalize Tank objects
	virtual void Finalize() = 0;
};

// ��ԃN���X
class Tank : public ITank {
public:
	// �p�[�cID
	enum PARTS_ID { CANNON, TURRET, BODY };

	// �ʒu���擾���� Get position
	DirectX::SimpleMath::Vector2 Position() {
		return position;
	}

	// �ʒu��ݒ肷�� Set position
	void Position(DirectX::SimpleMath::Vector2 position) {
		this->position = position;
	}

	// ���x���擾���� Get velocity
	DirectX::SimpleMath::Vector2 Velocity() {
		return velocity;
	}
	// ���x��ݒ肷�� Set velocity
	void Velocity(DirectX::SimpleMath::Vector2 velocity) {
		this->velocity = velocity;
	}

	// �p�x���擾���� Get angle
	float Angle() {
		return this->angle;
	}
	// �p�x��ݒ肷�� Set angle
	void Angle(float angle) {
		this->angle = angle;
	}

	// �C���p�x���擾���� Get turret angle
	float TurretAngle() {
		return turretAngle;
	}
	// �C���p�x��ݒ肷�� Set turret angle
	void TurretAngle(float headAngle) {
		this->turretAngle = headAngle;
	}

	// �F���擾���� Get color
	DirectX::SimpleMath::Vector4 Color() {
		return this->color;
	}
	// �F��ݒ肷�� Set color
	void Color(DirectX::SimpleMath::Vector4 color) {
		this->color = color;
	}

	// �R���X�g���N�^ Constructor
	Tank() : position(DirectX::SimpleMath::Vector2(0.0f, 0.0f)), angle(0.0f), turretAngle(0.0f), color(DirectX::SimpleMath::Vector4(0.0f, 0.0f, 0.0f, 0.0f)) {
	}
	// �R���X�g���N�^ Constructor
	Tank(DirectX::SimpleMath::Vector2& position, float angle, float turretAngle, DirectX::SimpleMath::Vector4& color)
		: position(position), angle(angle), turretAngle(turretAngle), color(color) {

	}

private:
	// �ʒu Position
	DirectX::SimpleMath::Vector2 position;
	// ���x Velocity
	DirectX::SimpleMath::Vector2 velocity;
	// �ԑ̉�]�p Body angle
	float angle;
	// �C����]�p Turret angle
	float turretAngle;
	// �F Color
	DirectX::SimpleMath::Vector4 color;
};

#endif // TANK_DEFINED
