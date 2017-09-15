#include "Central.hpp"
#include "Scene.hpp"
#include "Key.hpp"

namespace game {
	//実体を生成
	Central Central::instance;

	Central::Central()
	{
	}

	Central::~Central()
	{
	}

	//シーン変更処理
	void Central::ChangeScene(std::unique_ptr<Scene> newScene)
	{
		//ムーブキャストを行いnewSceneの所有権がm_nowSceneに渡されたことを明示する
		//こういう考え方をムーブセマンティクスと言う。はず。
		m_nowScene = std::move(newScene);
	}

	//更新処理
	bool Central::Update()
	{
		//キー情報更新
		Key::GeInstance().UpdateKey();

		//シーン更新
		if(m_nowScene!=nullptr)
			m_nowScene->Update();

		return m_endFlag==false;
	}


}