#include "Weapon.h"

// �R���X�g���N�^
Bomb::Bomb(Air* air) : air(air) {
}

// ����������
void Bomb::Initialize(BulletFactory* bulletFactory) {
	// Player�I�u�W�F�N�g�Ő������ꂽBulletFactory�I�u�W�F�N�g�̃A�h���X�������o�[�ϐ��Ɋi�[����
	this->bulletFactory = bulletFactory;
}

// �{���e�𔭎˂���
void Bomb::Shoot(const DX::StepTimer& timer, int& bulletNum, DirectX::SimpleMath::Vector2& position, float angle) {
	// �o�ߎ��Ԃ��擾����
	float elapsedTime = float(timer.GetElapsedSeconds());

	Bullet* bullet = nullptr;
	// 20�t���[�����ɒe�𔭎˂���
	if (timer.GetFrameCount() % 20 == 0) {
		// 60�� �e�𔭎˂���	
		for (int times = 0; times < 60; times++) {
			for (int index = 0; index < BulletFactory::BULLET_NUM; index++) {
				// �z��̗v�f��nullptr�܂��� Alive��false�̏ꍇ
				if (this->air->BulletPool()[index] == nullptr ||
					this->air->BulletPool()[index]->Alive() == false) {
					// ��]�p��ύX����
					angle += DirectX::XMConvertToRadians(6.0f);
					// �e�𔭎˂���
					bullet = bulletFactory->Create(position, angle);
					if (bullet == nullptr)
						continue;
					if (this->air->BulletPool()[index] == nullptr) {
						// �e���𑝂₷
						if (bulletNum < BulletFactory::BULLET_NUM - 1)
							bulletNum++;
					}
					// Bullet�I�u�W�F�N�g��z��Ɋi�[����
					this->air->BulletPool()[index] = bullet;
				}
			}
		}
	}
}

// ��n��������
void Bomb::Finalize() {
	// BulletFactory�I�u�W�F�N�g�̌�n��������
	bulletFactory->Finalize();
}