#pragma once
#include "GameObject.hpp"
namespace game {

	class Bullet :public GameObject {
		bool m_deleteFlag = false;
	public:

		//�폜�t���O�𗧂Ă�
		void Delete()noexcept{m_deleteFlag = true;}

		//�폜�t���O�������Ă��邩���ׂ�
		bool IsDelete()const noexcept { return m_deleteFlag; }

		//�e�̍X�V����
		virtual void Update()final override;
	};

}