#pragma once
#include "BattleScene.hpp"
#include "Player.hpp"
#include "Teki.hpp"
#include "UseDxLib.hpp"

namespace game {
	BattleScene::BattleScene()
		:m_player(std::make_unique<Player>()),
		m_teki(std::make_unique<Teki>())
	{
	}
	BattleScene::~BattleScene()
	{
	}
	void BattleScene::Update()
	{
		//���@�X�V����
		m_player->Update();
		//�G�X�V����
		m_teki->Update();
	}
}