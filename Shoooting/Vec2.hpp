#pragma once
namespace game {

	//������x�Ƃ��̍\���݂̂�����
	class Vec2 {

	public:
		double x;
		double y;
		//:m_x(0)�݂����ɏ����l��ݒ肷��̂�
		//�������q�ƌĂ�
		Vec2() :x(0), y(0) {};

		Vec2(double _x, double _y) 
			:x(_x),y(_y)
		{}
		void SetXY(double _x, double _y)noexcept { x = _x; y = _y; }
	};
}