#pragma once
#include "Player.hpp"
#include "Key.hpp"
#include "define.hpp"
#include "UseDxLib.hpp"
#include <string>

namespace game {
	Player::Player()
		:GameObject(Vec2(WINDOW_W/2,WINDOW_H-20))
	{
		SetSpeed(5);
	}
	void Player::Update()
	{

		//Key::GetInstance()���������x�ϐ��ɓ���Ƃ�
		auto& key = Key::GetInstance();

		SetAddPos(0, 0);

		//�ړ�
		if (key.GetKey(KEY_INPUT_UP) != 0)SetAddPosY(-1);
		if (key.GetKey(KEY_INPUT_DOWN) != 0)SetAddPosY(1);
		if (key.GetKey(KEY_INPUT_LEFT) != 0)SetAddPosX(-1);
		if (key.GetKey(KEY_INPUT_RIGHT) != 0)SetAddPosX(1);

		//addPos�x�N�g���̒�����GetSpeed�ɂ���
		if (GetAddPos().x != 0 || GetAddPos().y != 0) {
			double distance = sqrt(GetAddPos().x*GetAddPos().x + GetAddPos().y*GetAddPos().y);
			SetAddPosX(GetAddPos().x / distance*GetSpeed());
			SetAddPosY(GetAddPos().y / distance*GetSpeed());

			//Vec2��+���Z�q���I�[�o�[���[�h����Ă�̂ő����Z�ł���I
			SetPos(GetPos() + GetAddPos());

			if (GetPos().x > WINDOW_W - 16)SetPosX( WINDOW_W - 16);
			if (GetPos().x < 0)SetPosX(0);
			if (GetPos().y > WINDOW_H - 16)SetPosY( WINDOW_H - 16);
			if (GetPos().y < 0)SetPosY(0);

		}

		//�v���C���[HP�\��     
		//std::to_string�Ő�����string�ɕϊ�
		std::string str =("HP:" + std::to_string(m_hp));
		DxLib::DrawString(10, 400, str.c_str(), DxLib::GetColor(255, 255, 255));

		//�v���C���[�\��
		DxLib::DrawString(GetPos().x, GetPos().y, "��", DxLib::GetColor(255, 255, 255));
	}
}