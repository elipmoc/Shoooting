#pragma once
#include "GameObject.hpp"

namespace game {

	//Ž©‹@
	class Player:public GameObject {

		//‘Ì—Í
		int m_hp = 5;
	public:
		Player();
		virtual void Update()final override;
	};
}