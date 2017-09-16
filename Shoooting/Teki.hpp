#pragma once
#include "GameObject.hpp"
#include <memory>

namespace game {

	//前方宣言
	class Barrage;
	class CollisionCircle;

	//敵のクラス
	class Teki :public GameObject {
		//あたり判定オブジェクト
		std::unique_ptr<CollisionCircle>m_collision;

		//弾リスト
		std::unique_ptr<Barrage> m_barrage;

		//体力
		int m_hp=200;

	public:
		Teki();
		~Teki();
		virtual void Update()final override;
	};
}