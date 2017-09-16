#pragma once
#include "GameObject.hpp"
namespace game {

	class Bullet :public GameObject {
		//削除フラグ
		bool m_deleteFlag = false;

		//エリア内に弾があるかチェック
		void AreaCheck();

	public:

		//削除フラグを立てる
		void Delete()noexcept{m_deleteFlag = true;}

		//削除フラグが立っているか調べる
		bool IsDelete()const noexcept { return m_deleteFlag; }

		//弾の更新処理
		virtual void Update()final override;


	};

}