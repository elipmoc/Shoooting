#pragma once
#include "GameObject.hpp"
#include <memory>

namespace game {

	class CollisionCircle;
	class Barrage;

	//自機
	class Player:public GameObject {

		//自機のあたり判定オブジェクト
		std::unique_ptr<CollisionCircle> m_collision;

		//弾リスト
		std::unique_ptr<Barrage> m_barrage;

		//体力
		int m_hp = 5;

		//弾ショット
		void PlayerShot();

	public:

		Player();

		~Player();
		virtual void Update()final override;
	};
}