#pragma once
#include <vector>
#include <memory>

namespace game {
	//�N���X�O���錾
	struct BulletInfo;
	class Bullet;

	//�e������
	class Barrage {
		std::vector<std::unique_ptr<Bullet>> bullets;
	public:
		Barrage(size_t size);
		~Barrage();
		void AddMakeBullet(const BulletInfo&);
		void Update();
	};

}