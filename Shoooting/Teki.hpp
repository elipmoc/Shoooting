#pragma once
#include "GameObject.hpp"
#include <memory>

namespace game {

	//�O���錾
	class Barrage;
	class CollisionCircle;

	//�G�̃N���X
	class Teki :public GameObject {
		//�����蔻��I�u�W�F�N�g
		std::unique_ptr<CollisionCircle>m_collision;

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