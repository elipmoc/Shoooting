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
		//�v���C���[�\��
		DxLib::DrawString(GetPos().x, GetPos().y, "��", DxLib::GetColor(255, 255, 255));
	}
}