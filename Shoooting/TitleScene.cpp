#include "Central.hpp"
#include "TitleScene.hpp"
#include "Key.hpp"
#include "UseDxLib.hpp"

namespace game {

	void TitleScene::Update()
	{
		//タイトル文字描画
		DxLib::DrawString(50, 50,"文字シューティング", DxLib::GetColor(255, 255, 255));
		if (Key::GeInstance().GetKey(KEY_INPUT_RETURN) == 1)
			Central::GetInstance().ChangeScene(nullptr);
	}
}