#include "TankFactory.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace DX;
using namespace std;
using namespace Microsoft::WRL;

// コンストラクタ
TankFactory::TankFactory(Vector2& position, float angle, float turretAngle, Vector4& color) 
	: position(position), angle(angle), turretAngle(turretAngle), color(color) {
}

// 戦車のパーツを生成する Create Tank parts
std::unique_ptr<Tank> TankFactory::Create(Tank::PARTS_ID id) {
	std::unique_ptr<Tank> tank;
	switch (id) {
		case Tank::PARTS_ID::CANNON:
			// Cannonオブジェクトを生成する Create Cannon object
			tank = std::make_unique<Cannon>(position, angle, turretAngle, color);
			break;
		case Tank::PARTS_ID::TURRET:
			// Turretオブジェクトを生成する Create Turret object
			tank = std::make_unique<Turret>(position, angle, turretAngle, color);
			break;
		case Tank::PARTS_ID::BODY:
			// Bodyオブジェクトを生成する Create Body object
			tank = std::make_unique<Body>(position, angle, turretAngle, color);
			break;
		default:
			return nullptr;
	}
	// パーツを初期kする Initialize part of tank
	tank->Initialize();
	// 所有権を移動する
	return move(tank);
}
