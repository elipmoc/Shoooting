#pragma once
#include "Vec2.hpp"
#include "CollisionData.hpp"
#include <vector>

namespace game {

	//円のあたり判定
	class CollisionCircle {

		//
		CollisionData& m_colliData;

		//あたり判定の座標を参照で紐づけ
		const Vec2& bind_pos;

		//円の半径
		double m_r;

		//位置調整のためのずらす座標
		Vec2 m_offsetPos;

		//衝突バッファ
		std::vector<CollisionID> m_colliBuf;

		CollisionID m_collisionID;

		//CollisionControlに登録する
		void RegisterCollision();
	public:
		CollisionID GetCollisionID()const noexcept { return m_collisionID; }
		void SetCollisionID(const CollisionID collisionID)noexcept { m_collisionID = collisionID; }

		Vec2 GetBindPos()const noexcept { return bind_pos; }

		Vec2 GetPos()const noexcept { return bind_pos + m_offsetPos; }

		Vec2 GetOffsetPos()const noexcept { return m_offsetPos; }
		void SetOffsetPos(const Vec2& offsetPos) noexcept { m_offsetPos = offsetPos; }

		double GetR()const noexcept { return m_r; }
		void SetR(const double r) noexcept { m_r = r; }

		//あたり判定計算
		void HitCheck(CollisionCircle& cc){
			const auto&& temp = ((bind_pos + m_offsetPos) - (cc.bind_pos + cc.m_offsetPos));
			if ((temp.x*temp.x + temp.y*temp.y) <= (m_r + cc.m_r)*(m_r + cc.m_r)) {
				m_colliBuf.emplace_back(cc.m_collisionID);
				cc.m_colliBuf.emplace_back(m_collisionID);
			}
		}


		//衝突判定した結果を取得
		template<class Func>
		void GetColliID(Func&& func) {
			for (const auto& id : m_colliBuf) {
				func(id);
			}
			m_colliBuf.clear();
		}

		//座標をバインドする
		template<class F>
		CollisionCircle(const Vec2& pos)
			:bind_pos(pos), m_colliData(*(new CollisionData(*this))) {
			RegisterCollision();
		}


		//デストラクタ
		~CollisionCircle() noexcept {
			m_colliData.Delete();
		}

	};

}