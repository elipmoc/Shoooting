#pragma once
#include "GameObject.hpp"
namespace game {

	class Bullet:public GameObject {
	public:

		//�e�̍X�V����
		virtual void Update()final override;
	};

}