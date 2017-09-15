#pragma once

//自分の作ったプログラムはオリジナルの名前空間で包もう！
//名前衝突が少なくなるぞ！

namespace game {
	//全ての中心的な感じのクラス
	//ただ一つしか作ることはないため
	//シングルトンパターンにしてある
	//あまり良くないとは言われているが
	//ひとつしか存在しないことを証明できるのは素晴らしいことだと思う
	class Central {

		//ただ一つの実体（Central.cppで実体を生成してるよっ）
		static Central instance;

		//コンストラクタをprivateにして外部から生成できないようにする
		Central()=default;

		bool m_endFlag = false;
	public:

		//実体を渡す
		static Central& GetInstance() {
			return instance;
		};

		//シーン更新処理
		//返り値でwhileループを抜けるかどうかを制御しているよっ
		bool Update();

		//ゲームを終了させる
		void End()noexcept{ m_endFlag = true; }
	};
}