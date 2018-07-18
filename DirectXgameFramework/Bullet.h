#pragma once
#ifndef BULLET_DEFINED
#define BULLET_DEFINED

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
#include "Graphics.h"
#include "StepTimer.h"
#include "dx.h"

// �e�N���X
class Bullet {
public:
	// �u�g�p�v���ǂ������擾����
	bool Alive() {
		return this->alive;
	}
	// �u�g�p�v�u�g�p�s�v��ݒ肷��
	void Alive(bool alive) {
		this->alive = alive;
	}

	// �ʒu���擾���� Get position
	DirectX::SimpleMath::Vector2 Position() {
		return position;
	}
	// �ʒu��ݒ肷�� Set position
	void Position(DirectX::SimpleMath::Vector2 position) {
		this->position = position;
	}

	// �e��]�p���擾���� Get angle
	float Angle() {
		return this->angle;
	}
	// �e��]�p��ݒ肷�� Set angle
	void Angle(float angle) {
		this->angle = angle;
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
	Bullet();
	// ���������� Initialize Bullet object
	void Initialize(Microsoft::WRL::ComPtr<ID3D11ShaderResourceView>& texture);
	// Bullet�I�u�W�F�N�g���X�V���� Update Bullet object
	void Update(const DX::StepTimer& timer);
	// Bullet�I�u�W�F�N�g��`�悷�� Render Bullet object
	void Render(DirectX::SpriteBatch* spriteBatch);
	// Bullet�I�u�W�F�N�g�̌㏈���������Ȃ� Finalize Bullet object
	void Finalize();

private:
	// �e�X�s�[�h���`���� Set speed
	static const DirectX::SimpleMath::Vector2 SPEED;
	// ���� alive
	bool alive;
	// �p�x Angle
	float angle;
	// �ʒu Position
	DirectX::SimpleMath::Vector2 position;
	// �F Color
	DirectX::SimpleMath::Vector4 color;
	// �e�N�X�`�� texture
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> texture;
};

#endif	// BULLET_DEFINED
