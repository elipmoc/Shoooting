#pragma once
//�K�͂��������w�b�_�Ȃ̂�
//�w�b�_�ŃC���N���[�h�����Ⴆ�[
//�݂����ȁB
#include "Vec2.hpp"

namespace game {
	//�v���C���[,�e,�G�̋��ʂ��镔�����`
	class GameObject {
		//���W
		Vec2 m_pos;
	public:

		virtual void Update()=0;

		virtual ~GameObject(){}
	};
}