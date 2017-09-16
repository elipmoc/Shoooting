#pragma once

namespace game {

	//�R���W�������ʔԍ�
	enum class CollisionID {
		TekiID,
		TekiBulletID,
		PlayerID,
	};

	class CollisionCircle;

	//CollisionCircle�̒�����̂悤�Ȃ���
	class CollisionData {
		//�R�Â����Ă���CollisionCircle�I�u�W�F�N�g
		CollisionCircle& m_collision;

		//�폜�t���O
		bool deleteFlag = false;

	public:

		CollisionData(CollisionCircle& collision) noexcept:m_collision(collision) {

		}

		CollisionCircle& GetCollision() { return m_collision; }

		//�폜�v��������
		void Delete() noexcept { deleteFlag = true; }

		//�폜�ł��邩�ǂ���
		bool IsDelete() const noexcept { return deleteFlag; }
		
	};

}