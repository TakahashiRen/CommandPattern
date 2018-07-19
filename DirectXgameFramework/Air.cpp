#include "Air.h"

using namespace DirectX::SimpleMath;
using namespace DirectX;
using namespace DX;
using namespace Microsoft::WRL;
using namespace std;

// �R���X�g���N�^
Air::Air() {}

// ����������
void Air::Initialize() 
{
	// ��e���Ǘ�����z��������Ŋm�ۂ���
	/*bullets.resize(BulletFactory::BULLET_NUM);*/
}

// �X�V����
void Air::Update(const StepTimer& timer)
{
	// �A�N�e�B�u�Ȓe���X�V����
	for (list<Bullet*>::iterator ite = bullets.begin();ite != bullets.end();ite++) 
	{		
		if ((*ite)->Position().x < -BulletFactory::BULLET_SIZE / 2 ||
			(*ite)->Position().y < -BulletFactory::BULLET_SIZE / 2 ||
			(*ite)->Position().x > Graphics::Get().Width() + BulletFactory::BULLET_SIZE / 2 ||
			(*ite)->Position().y > Graphics::Get().Height() + BulletFactory::BULLET_SIZE / 2) 
		{
			// �`�拫�E���z������e���ė��p�ɂ���
			(*ite)->Alive(false);
			ite = bullets.erase((ite));
			if (ite == bullets.end()) break;
		}
		// ��e�����������ꍇ
		if ((*ite)->Alive())
		{
			// ��e�̈ʒu���X�V����
			(*ite)->Update(timer);
		}
	}
}

// �`�悷��
void Air::Render(const StepTimer& timer, SpriteBatch* spriteBatch)
{
	// �ŏ��̍X�V�̑O�͉����`�悵�Ȃ��悤�ɂ��� Don't try to render anything before the first Update.
	if (timer.GetFrameCount() == 0)return;

	for (list<Bullet*>::iterator ite = bullets.begin(); ite != bullets.end(); ite++)
	{
		if ((*ite)->Alive())
		{
			// ��e��`�悷��
			(*ite)->Render(spriteBatch);
		}
	}
}

// ��n��������
void Air::Finalize() 
{
	// bullets�I�u�W�F�N�g���N���A����
	this->bullets.clear();
}
