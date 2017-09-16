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
		//�ړ��X�s�[�h
		double m_speed;
		//���Z���W
		Vec2 m_addPos;
	public:

		GameObject(Vec2 pos=Vec2()):m_pos(pos){}

		//�����o�ϐ���ύX���Ȃ����Ƃ𖾎����邽�߂�
		//const��t����
		Vec2 GetPos()const noexcept { return m_pos; }

		//m_Pos�̎Q�Ƃ�n���B�����蔻��̂Ƃ��Ŏg�p���Ă��肷��
		const Vec2& GetRefPos()const noexcept { return m_pos; }

		//�Z�b�^�[���Ƃ��͈�����const�Q�Ɠn���ɂ����ق�������
		void SetPos(const Vec2& pos)noexcept { m_pos=pos; }
		void SetPos(double x, double y)noexcept { m_pos.SetXY(x, y); }
		void SetPosX(double x) noexcept { m_pos.x = x; }
		void SetPosY(double y) noexcept { m_pos.y = y; }

		double GetSpeed()const noexcept { return m_speed; };
		void SetSpeed(double speed) { m_speed = speed; }

		Vec2 GetAddPos()const noexcept { return m_addPos; }
		void SetAddPos(const Vec2& addPos)noexcept { m_addPos = addPos; }
		void SetAddPos(double x, double y)noexcept { m_addPos.SetXY(x, y); }
		void SetAddPosX(double x) noexcept { m_addPos.x = x; }
		void SetAddPosY(double y) noexcept { m_addPos.y = y; }

		virtual void Update()=0;

		virtual ~GameObject(){}
	};
}