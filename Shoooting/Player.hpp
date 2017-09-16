#pragma once
#include "GameObject.hpp"
#include <memory>

namespace game {

	class Barrage;

	//���@
	class Player:public GameObject {

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