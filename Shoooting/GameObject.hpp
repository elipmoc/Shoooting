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

		GameObject(Vec2 pos=Vec2()):m_pos(pos){}

		//�����o�ϐ���ύX���Ȃ����Ƃ𖾎����邽�߂�
		//const��t����
		Vec2 GetPos()const noexcept { return m_pos; }

		virtual void Update()=0;

		virtual ~GameObject(){}
	};
}