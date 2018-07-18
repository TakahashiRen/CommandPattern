#pragma once
#ifndef TURRET_DEFINED
#define TURRET_DEFINED

#include <vector>
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

// �C���N���X
class Turret : public Tank {
public:
	// �R���X�g���N�^ Constructor
	Turret(DirectX::SimpleMath::Vector2& position, float angle, float turretAngle, DirectX::SimpleMath::Vector4& color);
	// Cannon�I�u�W�F�N�g��ǉ�����
	void Add(unique_ptr<Tank>&& cannon) override;
	// Turret�I�u�W�F�N�g������������ Initialize Turret object
	void Initialize() override;
	// Turret�I�u�W�F�N�g���X�V���� Update Turret object
	void Update(const DX::StepTimer& timer, DirectX::SimpleMath::Vector2& position, float angle, float turretAngle) override;
	// Turret�I�u�W�F�N�g��`�悷�� Render Turret object
	void Render(DirectX::SpriteBatch* spriteBatch) override;
	// Turret�I�u�W�F�N�g�̌㏈���������Ȃ� Finalize Turret object
	void Finalize() override;

private:
	// �q�p�[�c���i�[����z�� vector store child part of tank
	std::vector<std::unique_ptr<Tank>> children;
	// �e�N�X�`�� texture
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> texture;
};

#endif // TURRET_DEFINED

