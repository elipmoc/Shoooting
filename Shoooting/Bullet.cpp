#include "Bullet.hpp"
#include "UseDxLib.hpp"

namespace game {
	void Bullet::Update()
	{
		//�e�����\��
		DxLib::DrawString(GetPos().x, GetPos().y, "�e", DxLib::GetColor(255, 255, 255));
	}
}