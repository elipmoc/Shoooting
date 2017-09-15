#pragma once
namespace game {

	//いわゆるxとｙの構造体みたいな
	class Vec2 {
		double m_x;
		double m_y;
	public:

		//:m_x(0)みたいに初期値を設定するのを
		//初期化子と呼ぶ
		Vec2() :m_x(0), m_y(0) {};

		Vec2(double x, double y) 
			:m_x(x),m_y(y)
		{}

		//メンバ変数を変更しないことを明示するために
		//constを付ける
		double GetX()const noexcept { return m_x; }
		double GetY()const noexcept { return m_y; }

		void SetX(double x) noexcept { m_x = x; }
		void SetY(double y) noexcept{ m_y = y; }
		void SetXY(double x, double y)noexcept { m_x = x; m_y = y; }
	};
}