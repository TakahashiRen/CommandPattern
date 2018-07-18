#include "Command.h"
#include <SimpleMath.h>

using namespace DirectX::SimpleMath;
using namespace DirectX;

// �R���X�g���N�^
CommandShotNWay::CommandShotNWay(Air* air, BulletFactory* bul)
	:air(air), bulletFactory(bul)
{
	nway = std::make_unique<NWay>(air);
	nway->Initialize(bulletFactory);
}
// ����������
void CommandShotNWay::Initialize()
{
}
// ���s����
void CommandShotNWay::Execute(const DX::StepTimer& timer, DirectX::Keyboard* keyboard, Tank* tank)
{
	nway->Shoot(timer, tank->Position(), tank->TurretAngle());
}
// ��n��������
void CommandShotNWay::Finalize()
{
	nway.reset();
}