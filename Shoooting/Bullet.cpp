#include "Bullet.hpp"
#include "UseDxLib.hpp"

namespace game {
	void Bullet::Update()
	{
		//座標更新
		SetPos(GetPos() + GetAddPos());

		//弾文字表示
		DxLib::DrawString(GetPos().x, GetPos().y, "弾", DxLib::GetColor(255, 255, 255));

	}
}