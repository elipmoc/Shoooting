#pragma once
#include "GameObject.hpp"

namespace game {

	//���@
	class Plyer:public GameObject {

	public:
		Plyer();
		virtual void Update()final override;
	};
}