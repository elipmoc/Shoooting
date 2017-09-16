#pragma once
#include "GameObject.hpp"
#include "CollisionData.hpp"
#include <memory>

namespace game {

	//前方宣言
	class CollisionCircle;

	struct BulletInfo {
		Vec2 pos;
		Vec2 addPos;
		double speed;
		CollisionID id;
	};

	class Bullet :public GameObject {

		//あたり判定オブジェクト
		std::unique_ptr<CollisionCircle>m_collision;

		//削除フラグ
		bool m_deleteFlag = false;

		//エリア内に弾があるかチェック
		void AreaCheck();

	public:

		Bullet& operator=(Bullet&&);
		Bullet(Bullet&&);
		Bullet(CollisionID);
		~Bullet();

		//削除フラグを立てる
		void Delete()noexcept{m_deleteFlag = true;}

		//削除フラグが立っているか調べる
		bool IsDelete()const noexcept { return m_deleteFlag; }

		//弾の更新処理
		virtual void Update()final override;


	};

}