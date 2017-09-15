#pragma once
namespace game {

	//‚¢‚í‚ä‚éx‚Æ‚™‚Ì\‘¢‘Ì‚İ‚½‚¢‚È
	class Vec2 {

	public:
		double x;
		double y;
		//:m_x(0)‚İ‚½‚¢‚É‰Šú’l‚ğİ’è‚·‚é‚Ì‚ğ
		//‰Šú‰»q‚ÆŒÄ‚Ô
		Vec2() :x(0), y(0) {};

		Vec2(double _x, double _y) 
			:x(_x),y(_y)
		{}
		void SetXY(double _x, double _y)noexcept { x = _x; y = _y; }
	};
}