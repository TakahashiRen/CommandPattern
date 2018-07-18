#include "Command.h"
#include <SimpleMath.h>

using namespace DirectX::SimpleMath;
using namespace DirectX;

// �R���X�g���N�^
CommandShotNormal::CommandShotNormal(Air* air, BulletFactory* bul)
	:air(air),bulletFactory(bul)
{
	normal = std::make_unique<Normal>(air);
	normal->Initialize(bulletFactory);
}
// ����������
void CommandShotNormal::Initialize()
{
}
// ���s����
void CommandShotNormal::Execute(const DX::StepTimer& timer, DirectX::Keyboard* keyboard, Tank* tank)
{
	normal->Shoot(timer, tank->Position(), tank->TurretAngle());
}
// ��n��������
void CommandShotNormal::Finalize()
{
	normal.reset();
}