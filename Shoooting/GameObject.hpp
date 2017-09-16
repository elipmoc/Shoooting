#pragma once
//規模が小さいヘッダなので
//ヘッダでインクルードしちゃえー
//みたいな。
#include "Vec2.hpp"

namespace game {
	//プレイヤー,弾,敵の共通する部分を定義
	class GameObject {
		//座標
		Vec2 m_pos;
		//移動スピード
		double m_speed;
		//加算座標
		Vec2 m_addPos;
	public:

		GameObject(Vec2 pos=Vec2()):m_pos(pos){}

		//メンバ変数を変更しないことを明示するために
		//constを付ける
		Vec2 GetPos()const noexcept { return m_pos; }

		//m_Posの参照を渡す。あたり判定のとこで使用してたりする
		const Vec2& GetRefPos()const noexcept { return m_pos; }

		//セッター作るときは引数をconst参照渡しにしたほうが速い
		void SetPos(const Vec2& pos)noexcept { m_pos=pos; }
		void SetPos(double x, double y)noexcept { m_pos.SetXY(x, y); }
		void SetPosX(double x) noexcept { m_pos.x = x; }
		void SetPosY(double y) noexcept { m_pos.y = y; }

		double GetSpeed()const noexcept { return m_speed; };
		void SetSpeed(double speed) { m_speed = speed; }

		Vec2 GetAddPos()const noexcept { return m_addPos; }
		void SetAddPos(const Vec2& addPos)noexcept { m_addPos = addPos; }
		void SetAddPos(double x, double y)noexcept { m_addPos.SetXY(x, y); }
		void SetAddPosX(double x) noexcept { m_addPos.x = x; }
		void SetAddPosY(double y) noexcept { m_addPos.y = y; }

		virtual void Update()=0;

		virtual ~GameObject(){}
	};
}