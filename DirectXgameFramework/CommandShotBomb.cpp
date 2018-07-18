#include "Command.h"
#include <SimpleMath.h>

using namespace DirectX::SimpleMath;
using namespace DirectX;

// �R���X�g���N�^
CommandShotBomb::CommandShotBomb(Air* air, BulletFactory* bul)
	:air(air), bulletFactory(bul)
{
	bomb = std::make_unique<Bomb>(air);
	bomb->Initialize(bulletFactory);
}
// ����������
void CommandShotBomb::Initialize()
{
}
// ���s����
void CommandShotBomb::Execute(const DX::StepTimer& timer, DirectX::Keyboard* keyboard, Tank* tank)
{
	bomb->Shoot(timer, tank->Position(), tank->TurretAngle());
}
// ��n��������
void CommandShotBomb::Finalize()
{
	bomb.reset();
}