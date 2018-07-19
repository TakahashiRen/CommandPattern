#pragma once
#include "Command.h"

#include <queue>

#include "Tank.h"
#include "Air.h"
#include "BulletFactory.h"

class InputHandler
{
public:
	void Initialize();
	//コマンド実行に必要なものをここで渡す
	void SetCommandState(Air* air, BulletFactory* bulletFac);
	//実行コマンドを取得し、返す
	std::queue<ICommand*> HandleInput(const DX::StepTimer& timer,DirectX::Keyboard* keyboard,Tank* tank);
	//終了処理
	void Finalize();
private:
	//プレイヤーから渡される情報
	//基本的にそのまま各種コマンドに渡される
	Air* air;
	BulletFactory* bulletFac;
	//入力に割り当てるコマンドメソッドなど
	ICommand* command_W;
	ICommand* command_A;
	ICommand* command_S;
	ICommand* command_D;
	ICommand* command_Z;
	ICommand* command_X;
	ICommand* command_SPACE;
};