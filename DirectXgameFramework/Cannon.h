#pragma once
#ifndef CANNON_DEFINED
#define CANNON_DEFINED

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

#include "Graphics.h"
#include "Tank.h"

// ��C�N���X
class Cannon : public Tank {
public:
	// �R���X�g���N�^ Constructor
	Cannon(DirectX::SimpleMath::Vector2& position, float angle, float turretAngle, DirectX::SimpleMath::Vector4& color);
	// �I�u�W�F�N�g��ǉ�����
	void Add(unique_ptr<Tank>&& object) override;
	// Cannon�I�u�W�F�N�g������������ Initialize Cannon object
	void Initialize() override;
	// Cannon�I�u�W�F�N�g���X�V���� Update Cannon object
	void Update(const DX::StepTimer& timer, DirectX::SimpleMath::Vector2& position, float angle, float turretAngle) override;
	// Cannon�I�u�W�F�N�g��`�悷�� Render Cannon object
	void Render(DirectX::SpriteBatch* spriteBatch) override;
	// Cannon�I�u�W�F�N�g�̌㏈���������Ȃ� Finalize Turret object
	void Finalize() override;

private:
	// �e�N�X�`�� texture
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> texture;
};

#endif // CANNON_DEFINED

