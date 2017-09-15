#pragma once
#include "Player.hpp"
#include "define.hpp"
#include "UseDxLib.hpp"
#include <string>

namespace game {
	Player::Player()
		:GameObject(Vec2(WINDOW_W/2,WINDOW_H-20))
	{
	}
	void Player::Update()
	{
		//プレイヤーHP表示     
		//std::to_stringで整数をstringに変換
		std::string str =("HP:" + std::to_string(m_hp));
		DxLib::DrawString(10, 400, str.c_str(), DxLib::GetColor(255, 255, 255));

		//プレイヤー表示
		DxLib::DrawString(GetPos().x, GetPos().y, "自", DxLib::GetColor(255, 255, 255));
	}
}