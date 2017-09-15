#pragma once
namespace game {

	//������x�Ƃ��̍\���݂̂�����
	class Vec2 {
		double m_x;
		double m_y;
	public:

		//:m_x(0)�݂����ɏ����l��ݒ肷��̂�
		//�������q�ƌĂ�
		Vec2() :m_x(0), m_y(0) {};

		Vec2(double x, double y) 
			:m_x(x),m_y(y)
		{}

		//�����o�ϐ���ύX���Ȃ����Ƃ𖾎����邽�߂�
		//const��t����
		double GetX()const noexcept { return m_x; }
		double GetY()const noexcept { return m_y; }

		void SetX(double x) noexcept { m_x = x; }
		void SetY(double y) noexcept{ m_y = y; }
		void SetXY(double x, double y)noexcept { m_x = x; m_y = y; }
	};
}