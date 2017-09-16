#pragma once
#include "GameObject.hpp"
#include <memory>

namespace game {

	class CollisionCircle;
	class Barrage;

	//���@
	class Player:public GameObject {

		//���@�̂����蔻��I�u�W�F�N�g
		std::unique_ptr<CollisionCircle> m_collision;

		//�e���X�g
		std::unique_ptr<Barrage> m_barrage;

		//�̗�
		int m_hp = 5;

		//�e�V���b�g
		void PlayerShot();

	public:

		Player();

		~Player();
		virtual void Update()final override;
	};
}