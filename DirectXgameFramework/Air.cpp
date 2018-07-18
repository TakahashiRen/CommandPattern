#include "Air.h"

using namespace DirectX::SimpleMath;
using namespace DirectX;
using namespace DX;
using namespace Microsoft::WRL;
using namespace std;

// �R���X�g���N�^
Air::Air() {
}

// ����������
void Air::Initialize() {
	// ��e���Ǘ�����z��������Ŋm�ۂ���
	bullets.resize(BulletFactory::BULLET_NUM);
}

// �X�V����
void Air::Update(const StepTimer& timer, int bulletNum){
	// ��e���X�V����
	for (int i = 0; i < bulletNum; i++) {
		if (this->bullets[i] == nullptr) {
			continue;
		}
		if (this->bullets[i]->Position().x < -BulletFactory::BULLET_SIZE / 2 ||
			this->bullets[i]->Position().y < -BulletFactory::BULLET_SIZE / 2 ||
			this->bullets[i]->Position().x > Graphics::Get().Width() + BulletFactory::BULLET_SIZE / 2 ||
			this->bullets[i]->Position().y > Graphics::Get().Height() + BulletFactory::BULLET_SIZE / 2) {
			// �`�拫�E���z������e���ė��p�ɂ���
			this->bullets[i]->Alive(false);
		}
		// ��e�����������ꍇ
		if (this->bullets[i]->Alive()) {
			// ��e�̈ʒu���X�V����
			this->bullets[i]->Update(timer);
		}
	}
}

// �`�悷��
void Air::Render(const StepTimer& timer, SpriteBatch* spriteBatch, int bulletNum){
	// �ŏ��̍X�V�̑O�͉����`�悵�Ȃ��悤�ɂ��� Don't try to render anything before the first Update.
	if (timer.GetFrameCount() == 0) {
		return;
	}
	for (int i = 0; i < bulletNum; i++) {
		if (this->bullets[i]->Alive()) {
			// ��e��`�悷��
			this->bullets[i]->Render(spriteBatch);
		}
	}
}

// ��n��������
void Air::Finalize() {
	// bullets�I�u�W�F�N�g���N���A����
	this->bullets.clear();
	// ��e�z����������
	this->bullets.shrink_to_fit();
}
