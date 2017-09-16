#pragma once
#include <memory>
#include <vector>
namespace game {

	//クラス前方宣言
	class CollisionData;

	//あたり判定管理クラス
	//シングルトンにした

	class CollisionControl {
		CollisionControl()=default;
		~CollisionControl();
		static CollisionControl m_instance;

		//あたり判定のリスト
		std::vector<std::unique_ptr<CollisionData>> m_collisions;
	public:
		

		static CollisionControl& GetInstance()noexcept { return m_instance; }

		void PushCollisionData(CollisionData& colliData);

		void Update();

	};
}