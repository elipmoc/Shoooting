#include "CollisionCircle.hpp"
#include "CollisionControl.hpp"

#include <algorithm>

namespace game {

	//インスタンス実体化
	CollisionControl CollisionControl::m_instance;

	CollisionControl::~CollisionControl()
	{
	}

	void CollisionControl::PushCollisionData(CollisionData & colliData)
	{
		m_collisions.emplace_back(std::unique_ptr<CollisionData>(&colliData));
	}

	void CollisionControl::Update()
	{
		//無効なCollisionDataをerase-removeイディオムで削除する
		auto itr = 
			std::remove_if(m_collisions.begin(), m_collisions.end(), [](std::unique_ptr<CollisionData>& colliData) {
			return colliData->IsDelete();
		});
		m_collisions.erase(itr, m_collisions.end());

		//あたり判定する
		for (size_t i = 0; i < m_collisions.size(); i++) {
			for (size_t j = i + 1; j < m_collisions.size(); j++) {
				m_collisions[i]->GetCollision().HitCheck(m_collisions[j]->GetCollision());
			}
		}
	}
}