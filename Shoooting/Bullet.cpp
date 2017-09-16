#include "Bullet.hpp"
#include "CollisionCircle.hpp"
#include "define.hpp"
#include "UseDxLib.hpp"


namespace game {

	void Bullet::Update()
	{
		//衝突したオブジェクトの処理
		m_collision->GetColliBuf(
			[this] (CollisionID id){
			//主人公の弾なら、敵と衝突してたら、削除する
			if (m_collision->GetCollisionID() == CollisionID::PlayerBulletID) {
				if (id == CollisionID::TekiID)
					Delete();
			}
			//敵の弾なら、自機と衝突してたら、削除する
			if (m_collision->GetCollisionID() == CollisionID::TekiBulletID) {
				if (id == CollisionID::PlayerID)
					Delete();
			}
		}
		);

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

	Bullet & Bullet::operator=(Bullet &&) = default;

	Bullet::Bullet(Bullet &&) = default;

	Bullet::Bullet(CollisionID id)
		:m_collision(std::make_unique<CollisionCircle>(GetRefPos()))
	{
		m_collision->SetCollisionID(id);
		m_collision->SetOffsetPos(Vec2(8, 8));
		m_collision->SetR(7);

	}
	Bullet::~Bullet()
	{
	}
}