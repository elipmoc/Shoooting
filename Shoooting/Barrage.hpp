#pragma once
#include <vector>
namespace game {
	//ƒNƒ‰ƒX‘O•ûéŒ¾
	class Bullet;

	//’e–‹§Œä
	class Barrage {
		std::vector<Bullet> bullets;
	public:
		Barrage(size_t size);
		~Barrage();
		void AddBullet(const Bullet&);
		void Update();
	};

}