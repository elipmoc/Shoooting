#pragma once
#include <vector>
#include <memory>

namespace game {
	//ƒNƒ‰ƒX‘O•ûéŒ¾
	struct BulletInfo;
	class Bullet;

	//’e–‹§Œä
	class Barrage {
		std::vector<std::unique_ptr<Bullet>> bullets;
	public:
		Barrage(size_t size);
		~Barrage();
		void AddMakeBullet(const BulletInfo&);
		void Update();
	};

}