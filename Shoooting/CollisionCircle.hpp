#pragma once
#include "Vec2.hpp"
#include "CollisionData.hpp"
#include <vector>

namespace game {

	//�~�̂����蔻��
	class CollisionCircle {

		//
		CollisionData& m_colliData;

		//�����蔻��̍��W���Q�ƂŕR�Â�
		const Vec2& bind_pos;

		//�~�̔��a
		double m_r;

		//�ʒu�����̂��߂̂��炷���W
		Vec2 m_offsetPos;

		//�Փ˃o�b�t�@
		std::vector<CollisionID> m_colliBuf;

		CollisionID m_collisionID;

		//CollisionControl�ɓo�^����
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

		//�����蔻��v�Z
		void HitCheck(CollisionCircle& cc){
			const auto&& temp = ((bind_pos + m_offsetPos) - (cc.bind_pos + cc.m_offsetPos));
			if ((temp.x*temp.x + temp.y*temp.y) <= (m_r + cc.m_r)*(m_r + cc.m_r)) {
				m_colliBuf.emplace_back(cc.m_collisionID);
				cc.m_colliBuf.emplace_back(m_collisionID);
			}
		}


		//�Փ˔��肵�����ʂ��擾
		template<class Func>
		void GetColliID(Func&& func) {
			for (const auto& id : m_colliBuf) {
				func(id);
			}
			m_colliBuf.clear();
		}

		//���W���o�C���h����
		template<class F>
		CollisionCircle(const Vec2& pos)
			:bind_pos(pos), m_colliData(*(new CollisionData(*this))) {
			RegisterCollision();
		}


		//�f�X�g���N�^
		~CollisionCircle() noexcept {
			m_colliData.Delete();
		}

	};

}