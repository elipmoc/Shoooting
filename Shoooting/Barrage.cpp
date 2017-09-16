#include "Barrage.hpp"
#include "Bullet.hpp"
#include <algorithm>

namespace game {

	Barrage::Barrage(size_t size)
	{
		//前もってメモリを確保して、高速化を図る
		bullets.reserve(size);
	}

	Barrage::~Barrage()
	{
	}

	void Barrage::AddBullet(const Bullet& bullet)
	{
		//bulletのリストに新しいbulletを追加する
		bullets.emplace_back(bullet);
	}

	void Barrage::Update()
	{
		//削除するbulletをリストの後ろにソートする
		//itrでその削除するbullet達の先頭のイテレータを得る
		auto itr = 
			std::remove_if(bullets.begin(), bullets.end(), [](Bullet& b) {return b.IsDelete(); });

		//itrからリストの末尾まで削除する
		//こうすることで削除対象のbulletを削除できる
		bullets.erase(itr, bullets.end());

		//このように一度remove_ifで削除対象をソートしてから
		//eraseで実際に削除するテクニックを
		//erase-removeイディオムとか言う
		//効率よく削除できるよ



		//range based forでリストを回す
		for (auto& bullet : bullets) {
			bullet.Update();
		}



	}



}