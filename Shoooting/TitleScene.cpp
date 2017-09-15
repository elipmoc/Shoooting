#include "TitleScene.hpp"
#include "UseDxLib.hpp"

namespace game {

	void TitleScene::Update()
	{
		//タイトル文字描画
		DxLib::DrawString(50, 50,"文字シューティング", DxLib::GetColor(255, 255, 255));
	}
}