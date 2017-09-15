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
	public:

		GameObject(Vec2 pos=Vec2()):m_pos(pos){}

		//メンバ変数を変更しないことを明示するために
		//constを付ける
		Vec2 GetPos()const noexcept { return m_pos; }

		virtual void Update()=0;

		virtual ~GameObject(){}
	};
}