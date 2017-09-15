#pragma once
#include "BattleScene.hpp"
#include "Player.hpp"
#include "UseDxLib.hpp"

namespace game {
	BattleScene::BattleScene()
		:m_player(std::make_unique<Player>())
	{
	}
	BattleScene::~BattleScene()
	{
	}
	void BattleScene::Update()
	{
		//���@�X�V����
		m_player->Update();
	}
}