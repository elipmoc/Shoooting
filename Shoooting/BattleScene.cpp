#pragma once
#include "BattleScene.hpp"
#include "UseDxLib.hpp"

namespace game {

	void BattleScene::Update()
	{
		DxLib::DrawString(50, 50, "ƒoƒgƒ‹‚·‚é‚æ‚ñ", DxLib::GetColor(255, 255, 255));
	}
}