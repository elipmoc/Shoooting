#pragma once
#include "Scene.hpp"
#include <memory>

namespace game {
	//�O���錾
	class Player;
	class Teki;

	//�Q�[���퓬�V�[��
	class BattleScene :public Scene {

		//���@
		std::unique_ptr<Player> m_player;

		//�G
		std::unique_ptr<Teki> m_teki;

	public:
		BattleScene();
		~BattleScene();
		virtual void Update()final override;
	};
}