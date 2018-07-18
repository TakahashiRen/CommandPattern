//  �J������
// 2018/06/01	�C������]�ł���悤�ɂ��� 

#include "MyGame.h"

using namespace Microsoft;
using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace std;

// �R���X�g���N�^ Constructor
MyGame::MyGame(int width, int height) : Game(width, height){
}

// MyGame�I�u�W�F�N�g���������� Initialize MyGame object
void MyGame::Initialize() {
	// ��{�N���X��Initialize���Ăяo�� 
	Game::Initialize();

	// Air�I�u�W�F�N�g�𐶐�����
	this->air = make_unique<Air>();
	// Air������������
	this->air->Initialize();

	// Player�I�u�W�F�N�g�𐶐����� Create Player object
	this->player = make_unique<Player>(air.get());
	// Player�I�u�W�F�N�g������������ Initialize Player object
	this->player->Initialize(Vector2(200.0f, 384.0f), XMConvertToRadians(0.0f), XMConvertToRadians(0.0f), Vector4(Colors::BlanchedAlmond));
}

// �Q�[�����X�V���� Update game
void MyGame::Update(const DX::StepTimer& timer) {
	float elapsedTime = float(timer.GetElapsedSeconds());

	// TODO: �X�V������ǉ����� Add your update process here

	// �v���C�����X�V���� Update Player object
	this->player->Update(timer);
}

// �V�[����`�悷�� Draws scene
void MyGame::Render(const DX::StepTimer& timer) {
	// �ŏ��̍X�V�̑O�͉����`�悵�Ȃ��悤�ɂ��� Don't try to render anything before the first Update.
	if (timer.GetFrameCount() == 0) {
		return;
	}

	// TODO: �����_�����O�R�[�h��ǉ����� Add your rendering code here
	// ��ʂ��N���A���� Clear Screen
	Clear();
	// �`����n�߂� Begin rendering
	spriteBatch->Begin(SpriteSortMode_Deferred, commonStates->NonPremultiplied());

	// Player�I�u�W�F�N�g��`�悷�� Render Player object
	this->player->Render(timer, spriteBatch.get());

	// �`����I���� Finish rendering
	spriteBatch->End();
	// �o�b�N�o�b�t�@���X�N���[���ɑ��� Presents the back buffer contents to the screen
	Present();
}

// �I�������������Ȃ� Finalize Game
void MyGame::Finalize() {
	// Player�I�u�W�F�N�g�̌㏈���������Ȃ�
	this->player->Finalize();
	// Player�I�u�W�F�N�g�����Z�b�g����
	this->player.reset();
	// Air�I�u�W�F�N�g�̌㏈��������
	air->Finalize();
	// Air�I�u�W�F�N�g�����Z�b�g����
	this->air.reset();

	// ��{�N���X��Finalize���Ăяo��
	Game::Finalize();
}
