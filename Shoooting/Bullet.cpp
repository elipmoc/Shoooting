#include "Bullet.hpp"
#include "define.hpp"
#include "UseDxLib.hpp"


namespace game {
	void Bullet::Update()
	{
		//�G���A�͈͊O�`�F�b�N
		AreaCheck();

		//���W�X�V
		SetPos(GetPos() + GetAddPos());

		//�e�����\��
		DxLib::DrawString(GetPos().x, GetPos().y, "�e", DxLib::GetColor(255, 255, 255));

	}
	void Bullet::AreaCheck()
	{
		//�e���͈͊O�ɏo�������
		if (
			GetPos().x > WINDOW_W ||
			GetPos().x <-16 ||
			GetPos().y > WINDOW_H ||
			GetPos().y < -16
			)
			Delete();
	}
}