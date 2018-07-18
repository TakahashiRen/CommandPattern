#pragma once

#ifndef MYGAME 
#define MYGAME

#include "Game.h"
#include "Player.h"
#include "Air.h"

class MyGame : public Game {
public:
	std::unique_ptr<Air>& Get() {
		return air;
	}
public:
	// �R���X�g���N�^ Constructor
	MyGame(int width, int height);
	// �Q�[���I�u�W�F�N�g���������� Initialize game object
	void Initialize() override;
	// �Q�[�����X�V���� Update game
	void Update(const DX::StepTimer& timer) override;
	// �Q�[���V�[����`�悷�� Draws the scene
	void Render(const DX::StepTimer& timer) override;
	// �I�������������Ȃ� Finalize game
	void Finalize() override;

protected:
	// �v���C�� Player
	std::unique_ptr<Player> player;
	// ���
	std::unique_ptr<Air> air;
};

#endif	// MYGAME
