#pragma once

namespace game {

	//コリジョン識別番号
	enum class CollisionID {
		TekiID,
		TekiBulletID,
		PlayerID,
	};

	class CollisionCircle;

	//CollisionCircleの仲介役のようなもの
	class CollisionData {
		//紐づけられているCollisionCircleオブジェクト
		CollisionCircle& m_collision;

		//削除フラグ
		bool deleteFlag = false;

	public:

		CollisionData(CollisionCircle& collision) noexcept:m_collision(collision) {

		}

		CollisionCircle& GetCollision() { return m_collision; }

		//削除要求をだす
		void Delete() noexcept { deleteFlag = true; }

		//削除できるかどうか
		bool IsDelete() const noexcept { return deleteFlag; }
		
	};

}