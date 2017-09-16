#pragma once
#include "GameObject.hpp"
#include <memory>

namespace game {

	//�O���錾
	class Barrage;

	//�G�̃N���X
	class Teki :public GameObject {

		//�e���X�g
		std::unique_ptr<Barrage> m_barrage;

		//�̗�
		int m_hp=200;

	public:
		Teki();
		~Teki();
		virtual void Update()final override;
	};
}