#pragma once
#include "Scene.hpp"
#include <memory>

namespace game {
	//前方宣言
	class Player;
	class Teki;

	//ゲーム戦闘シーン
	class BattleScene :public Scene {

		//自機
		std::unique_ptr<Player> m_player;

		//敵
		std::unique_ptr<Teki> m_teki;

	public:
		BattleScene();
		~BattleScene();
		virtual void Update()final override;
	};
}