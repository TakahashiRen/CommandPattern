#include "Weapon.h"

using namespace DirectX;
using namespace DX;


// �R���X�g���N�^
Normal::Normal(Air* air) : air(air) {}

// ����������
void Normal::Initialize(BulletFactory* bulletFactory) 
{
	// BulletFactory�I�u�W�F�N�g�𐶐����� Create BulletFactory object
	// ���O�ɒe��z�񕪐������邽�߁A�R���X�g���N�^�ɔ��˂���e�̈ʒu�A�{�̉�]�p�A�C����]�p��ݒ�ł��Ȃ�
	// bulletFactory = make_unique<BulletFactory>();
	// BulletFactory�I�u�W�F�N�g���X�V����
	// bulletFactory->Initialize();
	// Player�I�u�W�F�N�g�Ő������ꂽBulletFactory�I�u�W�F�N�g�̃A�h���X�������o�[�ϐ��Ɋi�[����
	this->bulletFactory = bulletFactory;
}

// �e�𔭎˂���
void Normal::Shoot(const DX::StepTimer& timer, DirectX::SimpleMath::Vector2& position, float angle ) 
{
	// �o�ߎ��Ԃ��擾����
	float elapsedTime = float(timer.GetElapsedSeconds());

	Bullet* bullet = nullptr;

	// 3�t���[�����ɒe�𔭎˂���
	if (timer.GetFrameCount() % 3 == 0) 
	{
		for (int index = 0; index < BulletFactory::BULLET_NUM; index++)
		{
			// �e�𔭎˂���
  			bullet = bulletFactory->Create(position, angle);
			if (bullet == nullptr)continue;

			// Bullet�I�u�W�F�N�g��z��Ɋi�[����
			this->air->BulletPool(bullet);
			break;
		}
	}
}

// ��n��������
void Normal::Finalize() {}

