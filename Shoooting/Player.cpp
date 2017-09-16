#pragma once
#include "Player.hpp"
#include "Key.hpp"
#include "Barrage.hpp"
#include "Bullet.hpp"
#include "define.hpp"
#include "UseDxLib.hpp"
#include <string>

namespace game {


	void Player::PlayerShot()
	{
		//�e�̔��˕p�x�𒲐�����p
		static int count = 0;
		count++;
		if (count % 15 != 0)return;

		Bullet bullet[2];

		//�e�̈ʒu�ݒ�
		bullet[0].SetPos(GetPos() + Vec2(16, 0));
		bullet[1].SetPos(GetPos() + Vec2(-16, 0));

		//�e�̐i�݋��ݒ�
		bullet[0].SetAddPos(0, -7);
		bullet[1].SetAddPos(0, -7);

		//�e���X�g�ɐV�����e��ǉ����Ă��
		m_barrage->AddBullet(bullet[0]);
		m_barrage->AddBullet(bullet[1]);

	}


	Player::Player()
		:GameObject(Vec2(WINDOW_W/2,WINDOW_H-20)),
		m_barrage(std::make_unique<Barrage>(30))
	{
		SetSpeed(5);
	}

	Player::~Player()
	{
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


		//�e�V���b�g�I�I
		if(key.GetKey(KEY_INPUT_Z)!=0)PlayerShot();


		//�v���C���[HP�\��     
		//std::to_string�Ő�����string�ɕϊ�
		std::string str =("HP:" + std::to_string(m_hp));
		DxLib::DrawString(10, 400, str.c_str(), DxLib::GetColor(255, 255, 255));

		//�v���C���[�\��
		DxLib::DrawString(GetPos().x, GetPos().y, "��", DxLib::GetColor(255, 255, 255));

		//�e���X�g�X�V
		m_barrage->Update();
	}
}