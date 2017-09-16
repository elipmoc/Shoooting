#pragma once
#include "GameObject.hpp"
#include "CollisionData.hpp"
#include <memory>

namespace game {

	//�O���錾
	class CollisionCircle;

	struct BulletInfo {
		Vec2 pos;
		Vec2 addPos;
		double speed;
		CollisionID id;
	};

	class Bullet :public GameObject {

		//�����蔻��I�u�W�F�N�g
		std::unique_ptr<CollisionCircle>m_collision;

		//�폜�t���O
		bool m_deleteFlag = false;

		//�G���A���ɒe�����邩�`�F�b�N
		void AreaCheck();

	public:

		Bullet& operator=(Bullet&&);
		Bullet(Bullet&&);
		Bullet(CollisionID);
		~Bullet();

		//�폜�t���O�𗧂Ă�
		void Delete()noexcept{m_deleteFlag = true;}

		//�폜�t���O�������Ă��邩���ׂ�
		bool IsDelete()const noexcept { return m_deleteFlag; }

		//�e�̍X�V����
		virtual void Update()final override;


	};

}