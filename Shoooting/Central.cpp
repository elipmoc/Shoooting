#include "Central.hpp"

namespace game {
	//実体を生成
	Central Central::instance;

	//シーン更新処理
	bool Central::Update()
	{
		return m_endFlag==false;
	}


}