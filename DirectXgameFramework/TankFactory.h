#pragma once
#ifndef TANK_FACTORY
#define TANK_FACTORY

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
#include <wrl.h>

#include "Tank.h"
#include "Cannon.h"
#include "Turret.h"
#include "Body.h"

// ��ԃt�@�N�g���N���X
class TankFactory {
public:
	// �R���X�g���N�^ Constractor
	TankFactory(DirectX::SimpleMath::Vector2& position, float angle, float turreAngle, DirectX::SimpleMath::Vector4& color);
	// ��Ԃ̃p�[�c�𐶐����� Create Tank parts
	std::unique_ptr<Tank> Create(Tank::PARTS_ID id);

private:
	// �ʒu Position
	DirectX::SimpleMath::Vector2 position;
	// ���x Velocity
	DirectX::SimpleMath::Vector2 velocity;
	// �ԑ̊p�x Angle
	float angle;
	// �C���p�x Turret Angle
	float turretAngle;
	// �F Color
	DirectX::SimpleMath::Vector4 color;
	// �e�N�X�`�� texture
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> texture;
};

#endif	// TANK_FACTORY
