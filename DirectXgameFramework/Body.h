#pragma once
#ifndef TANK_BODY
#define TANK_BODY

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

// �ԑ̃N���X
class Body : public Tank {
public:
	// �R���X�g���N�^ Constructor
	Body(DirectX::SimpleMath::Vector2& position, float angle, float turretAngle, DirectX::SimpleMath::Vector4& color);
	// Turret�I�u�W�F�N�g��ǉ�����
	void Add(unique_ptr<Tank>&& turret) override;
	// Body�I�u�W�F�N�g������������ Initialize Body object
	void Initialize() override;
	// Body�I�u�W�F�N�g���X�V���� Update Body object
	void Update(const DX::StepTimer& timer, DirectX::SimpleMath::Vector2& position, float angle, float turretAngle) override;
	// Body�I�u�W�F�N�g��`�悷�� Render Body object
	void Render(DirectX::SpriteBatch* spriteBatch) override;
	// Body�I�u�W�F�N�g�̌㏈���������Ȃ� Finalize Body object
	void Finalize() override;

private:
	// �q�p�[�c���i�[����z�� vector store child part of tank
	std::vector<std::unique_ptr<Tank>> children;
	// �e�N�X�`�� Texture
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> texture;
};

#endif // TANK_BODY
