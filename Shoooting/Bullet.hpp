#pragma once
#include "GameObject.hpp"
namespace game {

	class Bullet:public GameObject {
	public:

		//’e‚ÌXVˆ—
		virtual void Update()final override;
	};

}