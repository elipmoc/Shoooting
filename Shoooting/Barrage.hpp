#pragma once
#include <vector>
namespace game {
	//�N���X�O���錾
	class Bullet;

	//�e������
	class Barrage {
		std::vector<Bullet> bullets;
	public:
		Barrage(size_t size);
		~Barrage();
		void AddBullet(const Bullet&);
		void Update();
	};

}