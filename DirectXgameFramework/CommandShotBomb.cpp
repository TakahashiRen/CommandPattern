#include "Command.h"
#include <SimpleMath.h>

using namespace DirectX::SimpleMath;
using namespace DirectX;

// コンストラクタ
CommandShotBomb::CommandShotBomb(Air* air, BulletFactory* bul)
	:air(air), bulletFactory(bul)
{
	bomb = std::make_unique<Bomb>(air);
	bomb->Initialize(bulletFactory);
}
// 初期化する
void CommandShotBomb::Initialize()
{
}
// 実行する
void CommandShotBomb::Execute(const DX::StepTimer& timer, DirectX::Keyboard* keyboard, Tank* tank)
{
	bomb->Shoot(timer, tank->Position(), tank->TurretAngle());
}
// 後始末をする
void CommandShotBomb::Finalize()
{
	bomb.reset();
}