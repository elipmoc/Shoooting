#include "Teki.hpp"
#include "Barrage.hpp"
#include "Bullet.hpp"
#include "CollisionCircle.hpp"
#include "define.hpp"
#include "Central.hpp"
#include "TitleScene.hpp"
#include "UseDxLib.hpp"


namespace game {

	Teki::Teki()
		:m_barrage(std::make_unique<Barrage>(200)),
		m_collision(std::make_unique<CollisionCircle>(GetRefPos()))
	{

		//あたり判定の設定
		m_collision->SetCollisionID(CollisionID::TekiID);
		m_collision->SetR(7);
		m_collision->SetOffsetPos(Vec2(8, 8));

		SetPos( WINDOW_W / 2,30);
		SetSpeed(2);
		SetAddPos(GetSpeed(), 0);
	}
	Teki::~Teki()
	{
	}
	void Teki::Update()
	{

		//衝突したオブジェクトの処理
		m_collision->GetColliBuf([&hp=m_hp](CollisionID id) {
			if (id == CollisionID::PlayerBulletID)
				hp--;
		});

		if (m_hp <= 0)
			Central::GetInstance().ChangeScene(std::make_unique<TitleScene>());

		//移動
		SetPos(GetPos()+GetAddPos());
		if (GetPos().x > WINDOW_W - 16 || GetPos().x < 0)SetAddPos(-GetAddPos().x,0);

		//弾リスト更新
		m_barrage->Update();

		//敵文字描画
		DxLib::DrawString(GetPos().x,GetPos().y,"敵",DxLib::GetColor(255,255,255));
	}
}