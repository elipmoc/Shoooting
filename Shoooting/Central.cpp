#include "Central.hpp"

namespace game {
	//���̂𐶐�
	Central Central::instance;

	//�V�[���X�V����
	bool Central::Update()
	{
		return m_endFlag==false;
	}


}