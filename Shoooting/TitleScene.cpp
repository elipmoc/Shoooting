#include "TitleScene.hpp"
#include "UseDxLib.hpp"

namespace game {

	void TitleScene::Update()
	{
		//�^�C�g�������`��
		DxLib::DrawString(50, 50,"�����V���[�e�B���O", DxLib::GetColor(255, 255, 255));
	}
}