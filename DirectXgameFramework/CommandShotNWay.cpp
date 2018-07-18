#include "Command.h"
#include <SimpleMath.h>

using namespace DirectX::SimpleMath;
using namespace DirectX;

// コンストラクタ
CommandShotNWay::CommandShotNWay(Air* air, BulletFactory* bul)
	:air(air), bulletFactory(bul)
{
	nway = std::make_unique<NWay>(air);
	nway->Initialize(bulletFactory);
}
// 初期化する
void CommandShotNWay::Initialize()
{
}
// 実行する
void CommandShotNWay::Execute(const DX::StepTimer& timer, DirectX::Keyboard* keyboard, Tank* tank)
{
	nway->Shoot(timer, tank->Position(), tank->TurretAngle());
}
// 後始末をする
void CommandShotNWay::Finalize()
{
	nway.reset();
}