#include "CollisionCircle.hpp"
#include "CollisionControl.hpp"

namespace game {

	void CollisionCircle::RegisterCollision()
	{
		CollisionControl::GetInstance().PushCollisionData(m_colliData);
	}
}
