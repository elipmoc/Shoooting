#pragma once

//本来、ヘッダにインクルードするのはだめだが
//継承する場合は防げない
//これが継承のだめなところ
#include"Scene.hpp"

namespace game {
	//タイトル画面のシーン
	class TitleScene:public Scene{
	public:
		//Updateをオーバーライドする
		//overrideは付けなくても動くが
		//付けたほうが美味しい
		//理由はhttps://www.google.co.jpを参照
		virtual void Update()final override;
	};
}