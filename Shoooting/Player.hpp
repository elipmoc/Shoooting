#pragma once
#include "GameObject.hpp"

namespace game {

	//���@
	class Player:public GameObject {

	public:
		Player();
		virtual void Update()final override;
	};
}