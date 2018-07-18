#include "TankFactory.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace DX;
using namespace std;
using namespace Microsoft::WRL;

// �R���X�g���N�^
TankFactory::TankFactory(Vector2& position, float angle, float turretAngle, Vector4& color) 
	: position(position), angle(angle), turretAngle(turretAngle), color(color) {
}

// ��Ԃ̃p�[�c�𐶐����� Create Tank parts
std::unique_ptr<Tank> TankFactory::Create(Tank::PARTS_ID id) {
	std::unique_ptr<Tank> tank;
	switch (id) {
		case Tank::PARTS_ID::CANNON:
			// Cannon�I�u�W�F�N�g�𐶐����� Create Cannon object
			tank = std::make_unique<Cannon>(position, angle, turretAngle, color);
			break;
		case Tank::PARTS_ID::TURRET:
			// Turret�I�u�W�F�N�g�𐶐����� Create Turret object
			tank = std::make_unique<Turret>(position, angle, turretAngle, color);
			break;
		case Tank::PARTS_ID::BODY:
			// Body�I�u�W�F�N�g�𐶐����� Create Body object
			tank = std::make_unique<Body>(position, angle, turretAngle, color);
			break;
		default:
			return nullptr;
	}
	// �p�[�c������k���� Initialize part of tank
	tank->Initialize();
	// ���L�����ړ�����
	return move(tank);
}
