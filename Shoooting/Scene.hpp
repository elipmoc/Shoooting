#pragma once
namespace game {

	//シーンクラスだよ
	//こいつを継承して、
	//GameSceneとか
	//TitleSceneとかを作るよ。
	class Scene {
	public:
		//毎フレーム呼ばれる、更新関数
		virtual void Update() = 0;

		//継承して使う場合
		//デストラクタにvirtualを付けよう
		//ただし、必ずしも付けるのが正解ではないので
		//詳しくは調べてください
		virtual ~Scene() = default;//このdefaultの説明は・・・べつのとこでやるわ。
	};
}