#pragma once
#include "Scene.hpp"
#include <memory>

namespace game {
	//前方宣言
	class Player;

	//ゲーム戦闘シーン
	class BattleScene :public Scene {

		//自機
		std::unique_ptr<Player> m_player;

	public:
		BattleScene();
		~BattleScene();
		virtual void Update()final override;
	};
}