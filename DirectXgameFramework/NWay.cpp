#include "Weapon.h"

// �R���X�g���N�^
NWay::NWay(Air* air) : air(air) {}

// ����������
void NWay::Initialize(BulletFactory* bulletFactory) 
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
void NWay::Shoot(const DX::StepTimer& timer,DirectX::SimpleMath::Vector2& position, float angle) {
	// �o�ߎ��Ԃ��擾����
	float elapsedTime = float(timer.GetElapsedSeconds());

	Bullet* bullet = nullptr;

	// 5�t���[�����ɒe�𔭎˂���
	if (timer.GetFrameCount() % 5 == 0) 
	{
		// �e�𔭎˂���	
		for (int index = 0; index < BulletFactory::BULLET_NUM; index++) 
		{
			if (timer.GetFrameCount() % 3 == 1)
			{
				// ��]�p��ύX����
				angle -= DirectX::XMConvertToRadians(5.0f);
			}
			else if (timer.GetFrameCount() % 3 == 2)
			{
				// ��]�p��ύX����
				angle += DirectX::XMConvertToRadians(5.0f);
				// �e�𔭎˂���
				bullet = bulletFactory->Create(position, angle);
			}
			if (bullet == nullptr)continue;

			// Bullet�I�u�W�F�N�g��z��Ɋi�[����
			this->air->BulletPool(bullet);

			break;
		}
	}
}

// ��n��������
void NWay::Finalize() {}