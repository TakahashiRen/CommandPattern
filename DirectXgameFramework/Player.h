#pragma once
#ifndef PLAYER_DEFINED
#define PLAYER_DEFINED

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
#include <queue>
#include "StepTimer.h"
#include "dx.h"

#include "Graphics.h"
#include "TankFactory.h"
#include "Tank.h"
#include "Turret.h"
#include "Body.h"

#include "BulletFactory.h"
#include "Air.h"
#include "Weapon.h"
#include "InputHandler.h"
#include "Command.h"

// �v���C���N���X
class Player 
{
public:
	// �R���X�g���N�^
	Player(Air* air);
	// �v���C��������������
	void Initialize(DirectX::SimpleMath::Vector2& position, float angle, float turretAngle, DirectX::SimpleMath::Vector4& color);
	// �v���C�����X�V����
	bool Update(const DX::StepTimer& timer);
	// �v���C����`�悷��
	void Render(const DX::StepTimer& timer, DirectX::SpriteBatch* spriteBatch);
	// �v���C���̌㏈���������Ȃ�
	void Finalize();

private:
	// �L�[�{�[�h Keyboard
	std::unique_ptr<DirectX::Keyboard> keyboard;
	// �L�[�{�[�h�X�e�[�g�g���b�J�I�u�W�F�N�g KeyboardStateTracker
	std::unique_ptr<DirectX::Keyboard::KeyboardStateTracker> keyboardTracker;

	// Tank�I�u�W�F�N�g�ւ̃|�C���^ Tank object
	std::unique_ptr<Tank> tank;

	//�e�̃t�@�N�g���[
	std::unique_ptr<BulletFactory> bulletFactory;

	//�e�Ǘ��N���X�̃|�C���^
	Air* air;

	//���͊Ǘ��N���X
	std::unique_ptr<InputHandler> inputHandler;

	//���s�R�}���h�̃L���[
	std::queue<ICommand*> command;
};

#endif // PLAYER_DEFINED
