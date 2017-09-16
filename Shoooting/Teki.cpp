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

		//‚ ‚½‚è”»’è‚ÌÝ’è
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


		//’e–‹‚Ìˆ—
		if (m_hp > 20) { TekiBarrage1(); mode = 0; }
		else if (m_hp > 0) { mode = 1; ModeCheck(); TekiBarrage2(); }
		//Õ“Ë‚µ‚½ƒIƒuƒWƒFƒNƒg‚Ìˆ—
		m_collision->GetColliBuf([&hp=m_hp](CollisionID id) {
			if (id == CollisionID::PlayerBulletID)
				hp--;
		});

		if (m_hp <= 0)
			Central::GetInstance().ChangeScene(std::make_unique<TitleScene>());

		//ˆÚ“®
		SetPos(GetPos()+GetAddPos());
		if (GetPos().x > WINDOW_W - 16 || GetPos().x < 0)SetAddPos(-GetAddPos().x,0);

		//’eƒŠƒXƒgXV
		m_barrage->Update();

		//“G•¶Žš•`‰æ
		DxLib::DrawString(GetPos().x,GetPos().y,"“G",DxLib::GetColor(255,255,255));
	}

	void Teki::ModeCheck() noexcept
	{
		if (beforMode != mode) {cont = 0; beforMode = mode; }
	}

	void Teki::TekiBarrage1()
	{
		cont++;
		if (cont % 20 == 0) {
			BulletInfo bInfo;
			bInfo.pos = GetPos();
			bInfo.addPos = { 0,7 };
			bInfo.id = CollisionID::TekiBulletID;
			m_barrage->AddMakeBullet(bInfo);
		}
	}
	void Teki::TekiBarrage2()
	{
		cont++;
		if (cont % 28 == 0) {
			BulletInfo bInfo[3];
			bInfo[0].addPos = {0,2.5};
			bInfo[1].addPos = { cos(120.0 / 180 * PI)*2.5,sin(120.0 / 180 * PI)*2.5 };
			bInfo[2].addPos = { cos(60.0 / 180 * PI)*2.5,sin(60.0 / 180 * PI)*2.5 };
			for (int i = 0; i < 3; i++) {
				bInfo[i].id = CollisionID::TekiBulletID;
				bInfo[i].pos = GetPos();
				m_barrage->AddMakeBullet(bInfo[i]);
			}
		}
	}
}