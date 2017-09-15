#pragma once
#include "Scene.hpp"
#include <memory>

namespace game {
	//�O���錾
	class Player;

	//�Q�[���퓬�V�[��
	class BattleScene :public Scene {

		//���@
		std::unique_ptr<Player> m_player;

	public:
		BattleScene();
		~BattleScene();
		virtual void Update()final override;
	};
}