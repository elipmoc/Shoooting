#pragma once
#include "GameObject.hpp"

namespace game {

	//Ž©‹@
	class Player:public GameObject {

	public:
		Player();
		virtual void Update()final override;
	};
}