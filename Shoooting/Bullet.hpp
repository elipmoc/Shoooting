#pragma once
#include "GameObject.hpp"
namespace game {

	class Bullet:public GameObject {
	public:

		//弾の更新処理
		virtual void Update()final override;
	};

}