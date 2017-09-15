#pragma once
//標準ライブラリはヘッダでインクルードしてもよい

//<memory>はスマートポインタ系を使うときのヘッダだよん
#include<memory>

//自分の作ったプログラムはオリジナルの名前空間で包もう！
//名前衝突が少なくなるぞ！

namespace game {

	//前方宣言
	class Scene;

	//全ての中心的な感じのクラス
	//ただ一つしか作ることはないため
	//シングルトンパターンにしてある
	//あまり良くないとは言われているが
	//ひとつしか存在しないことを証明できるのは素晴らしいことだと思う
	class Central {

		//ただ一つの実体（Central.cppで実体を生成してるよっ）
		static Central instance;

		//コンストラクタをprivateにして外部から生成できないようにする
		//std::unique_ptr<Scene>のせいで実装をcppに書かなくてはいけない
		//説明は省略させてくれ（Sceneの定義がこの時点でわかっていればやらなくてもよい）
		Central();
		~Central();

		//現在のシーンを入れる変数
		//スマートポインタで包んでるので
		//削除は自動的にやってくれる
		std::unique_ptr<Scene> m_nowScene;

		//なぜ m_ を付けるか？
		//member変数のｍという意味さ
		bool m_endFlag = false;
	public:

		//実体を渡す
		static Central& GetInstance() {
			return instance;
		};

		void ChangeScene(std::unique_ptr<Scene>);

		//シーン更新処理
		//返り値でwhileループを抜けるかどうかを制御しているよっ
		bool Update();

		//ゲームを終了させる
		//noexceptは例外を吐かない関数に付けよう！
		//コンパイラが最適化しやすくなるぞい！
		void End()noexcept{ m_endFlag = true; }
	};
}