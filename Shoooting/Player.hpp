#pragma once
#include "GameObject.hpp"

namespace game {

	//���@
	class Player:public GameObject {

		//�̗�
		int m_hp = 5;
	public:
		Player();
		virtual void Update()final override;
	};
}