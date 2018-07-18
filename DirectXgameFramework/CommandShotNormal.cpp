#include "Command.h"
#include <SimpleMath.h>

using namespace DirectX::SimpleMath;
using namespace DirectX;

// コンストラクタ
CommandShotNormal::CommandShotNormal(Air* air, BulletFactory* bul)
	:air(air),bulletFactory(bul)
{
	normal = std::make_unique<Normal>(air);
	normal->Initialize(bulletFactory);
}
// 初期化する
void CommandShotNormal::Initialize()
{
}
// 実行する
void CommandShotNormal::Execute(const DX::StepTimer& timer, DirectX::Keyboard* keyboard, Tank* tank)
{
	normal->Shoot(timer, tank->Position(), tank->TurretAngle());
}
// 後始末をする
void CommandShotNormal::Finalize()
{
	normal.reset();
}