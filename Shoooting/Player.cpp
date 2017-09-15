#pragma once
#include "Player.hpp"
#include "define.hpp"
#include "UseDxLib.hpp"

namespace game {
	Player::Player()
		:GameObject(Vec2(WINDOW_W/2,WINDOW_H-20))
	{
	}
	void Player::Update()
	{
		//プレイヤー表示
		DxLib::DrawString(GetPos().x, GetPos().y, "自", DxLib::GetColor(255, 255, 255));
	}
}