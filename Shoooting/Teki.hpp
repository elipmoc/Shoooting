#pragma once
#include "GameObject.hpp"
#include <memory>

namespace game {

	//前方宣言
	class Barrage;
	class CollisionCircle;

	//敵のクラス
	class Teki :public GameObject {

		int beforMode = 0;
		int mode = 0;
		int cont = 0;

		//あたり判定オブジェクト
		std::unique_ptr<CollisionCircle>m_collision;

		//弾リスト
		std::unique_ptr<Barrage> m_barrage;

		//体力
		int m_hp=50;

		void ModeCheck()noexcept;
	public:
		void TekiBarrage1();
		void TekiBarrage2();
		void TekiBarrage3();
		void TekiBarrage4();
		void TekiBarrage5();
		void TekiBarrage6();
		void TekiBarrage7();
		Teki();
		~Teki();
		virtual void Update()final override;
	};
}