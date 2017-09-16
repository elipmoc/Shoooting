#pragma once
#include "GameObject.hpp"
#include <memory>

namespace game {

	//�O���錾
	class Barrage;
	class CollisionCircle;

	//�G�̃N���X
	class Teki :public GameObject {

		int beforMode = 0;
		int mode = 0;
		int cont = 0;

		//�����蔻��I�u�W�F�N�g
		std::unique_ptr<CollisionCircle>m_collision;

		//�e���X�g
		std::unique_ptr<Barrage> m_barrage;

		//�̗�
		int m_hp=50;

		void ModeCheck()noexcept;
	public:
		void TekiBarrage1();
		void TekiBarrage2();
		void TekiBarrage3();
		void TekiBarrage4();
		void TekiBarrage5();
		void TekiBarrage6();
		void TekiBarrage7();
		Teki();
		~Teki();
		virtual void Update()final override;
	};
}