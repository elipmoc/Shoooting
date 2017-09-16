#pragma once
namespace game {

	//いわゆるxとｙの構造体みたいな
	class Vec2 {

	public:
		double x;
		double y;
		//:m_x(0)みたいに初期値を設定するのを
		//初期化子と呼ぶ
		Vec2() :x(0), y(0) {};

		Vec2(double _x, double _y) 
			:x(_x),y(_y)
		{}
		void SetXY(double _x, double _y)noexcept { x = _x; y = _y; }

		//演算子の定義
		//これが演算子のオーバーロードだあ
		//これでVec2+Vec2みたいなことができる

		Vec2 operator+(const Vec2& right)const noexcept {
			return Vec2(x + right.x, y + right.y);
		}

		Vec2 operator-(const Vec2& right)const noexcept {
			return Vec2(x - right.x, y - right.y);
		}
	};
}