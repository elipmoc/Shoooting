#pragma once
#include "Player.hpp"
#include "Key.hpp"
#include "Barrage.hpp"
#include "Bullet.hpp"
#include "CollisionCircle.hpp"
#include "define.hpp"
#include "UseDxLib.hpp"
#include <string>

namespace game {


	void Player::PlayerShot()
	{
		//弾の発射頻度を調整する用
		static int count = 0;
		count++;
		if (count % 15 != 0)return;

		BulletInfo bullet1;
		BulletInfo bullet2;

		//弾のあたり判定IDを設定
		bullet1.id = CollisionID::PlayerBulletID;
		bullet2.id = CollisionID::PlayerBulletID;

		//弾の位置設定
		bullet1.pos = (GetPos() + Vec2(16, 0));
		bullet2.pos = (GetPos() + Vec2(-16, 0));

		//弾の進み具合を設定
		bullet1.addPos = { 0, -7 };
		bullet2.addPos = { 0, -7 };

		//弾リストに新しい弾を追加してやる
		m_barrage->AddMakeBullet(bullet1);
		m_barrage->AddMakeBullet(bullet2);

	}


	Player::Player()
		:GameObject(Vec2(WINDOW_W/2,WINDOW_H-20)),
		m_barrage(std::make_unique<Barrage>(30)),
		m_collision(std::make_unique<CollisionCircle>(GetRefPos()))
	{
		//あたり判定の設定
		m_collision->SetCollisionID(CollisionID::PlayerID);
		m_collision->SetR(3);
		m_collision->SetOffsetPos(Vec2(8,8));

		SetSpeed(5);
	}

	Player::~Player()
	{
	}

	void Player::Update()
	{

		//衝突したオブジェクトの処理(ラムダ式)
		m_collision->GetColliBuf(
			[&hp=m_hp](CollisionID id) {
			if (id == CollisionID::TekiBulletID || id == CollisionID::TekiID) {
				hp--;
			}
		}
		);

		//Key::GetInstance()長いから一度変数に入れとく
		auto& key = Key::GetInstance();

		SetAddPos(0, 0);

		//移動
		if (key.GetKey(KEY_INPUT_UP) != 0)SetAddPosY(-1);
		if (key.GetKey(KEY_INPUT_DOWN) != 0)SetAddPosY(1);
		if (key.GetKey(KEY_INPUT_LEFT) != 0)SetAddPosX(-1);
		if (key.GetKey(KEY_INPUT_RIGHT) != 0)SetAddPosX(1);

		//addPosベクトルの長さをGetSpeedにする
		if (GetAddPos().x != 0 || GetAddPos().y != 0) {
			double distance = sqrt(GetAddPos().x*GetAddPos().x + GetAddPos().y*GetAddPos().y);
			SetAddPosX(GetAddPos().x / distance*GetSpeed());
			SetAddPosY(GetAddPos().y / distance*GetSpeed());

			//Vec2は+演算子がオーバーロードされてるので足し算できる！
			SetPos(GetPos() + GetAddPos());

			if (GetPos().x > WINDOW_W - 16)SetPosX( WINDOW_W - 16);
			if (GetPos().x < 0)SetPosX(0);
			if (GetPos().y > WINDOW_H - 16)SetPosY( WINDOW_H - 16);
			if (GetPos().y < 0)SetPosY(0);

		}


		//弾ショット！！
		if(key.GetKey(KEY_INPUT_Z)!=0)PlayerShot();


		//プレイヤーHP表示     
		//std::to_stringで整数をstringに変換
		std::string str =("HP:" + std::to_string(m_hp));
		DxLib::DrawString(10, 400, str.c_str(), DxLib::GetColor(255, 255, 255));

		//プレイヤー表示
		DxLib::DrawString(GetPos().x, GetPos().y, "自", DxLib::GetColor(255, 255, 255));

		//弾リスト更新
		m_barrage->Update();
	}
}