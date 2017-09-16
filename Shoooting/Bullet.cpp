#include "Bullet.hpp"
#include "define.hpp"
#include "UseDxLib.hpp"


namespace game {
	void Bullet::Update()
	{
		//エリア範囲外チェック
		AreaCheck();

		//座標更新
		SetPos(GetPos() + GetAddPos());

		//弾文字表示
		DxLib::DrawString(GetPos().x, GetPos().y, "弾", DxLib::GetColor(255, 255, 255));

	}
	void Bullet::AreaCheck()
	{
		//弾が範囲外に出たら消す
		if (
			GetPos().x > WINDOW_W ||
			GetPos().x <-16 ||
			GetPos().y > WINDOW_H ||
			GetPos().y < -16
			)
			Delete();
	}
}