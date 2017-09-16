#include "Teki.hpp"
#include "Barrage.hpp"
#include "Bullet.hpp"
#include "define.hpp"
#include "UseDxLib.hpp"

namespace game {

	Teki::Teki()
		:m_barrage(std::make_unique<Barrage>(200))
	{
		SetPos( WINDOW_W / 2,30);
		SetSpeed(2);
		SetAddPos(GetSpeed(), 0);
	}
	Teki::~Teki()
	{
	}
	void Teki::Update()
	{

		//ˆÚ“®
		SetPos(GetPos()+GetAddPos());
		if (GetPos().x > WINDOW_W - 16 || GetPos().x < 0)SetAddPos(-GetAddPos().x,0);

		//’eƒŠƒXƒgXV
		m_barrage->Update();

		//“G•¶Žš•`‰æ
		DxLib::DrawString(GetPos().x,GetPos().y,"“G",DxLib::GetColor(255,255,255));
	}
}