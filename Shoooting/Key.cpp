#include "Key.hpp"
#include "UseDxLib.hpp"

namespace game{

	//実体生成
	Key Key::instance;

	void Key::UpdateKey()
	{
		char GetHitkey[256];
		DxLib::GetHitKeyStateAll(GetHitkey);

		//対象のキーが押されていたら1加算
		//押されていなかったら0にする
		//例えばkeys[0]にあたるキーを
		//60フレーム押し続けると
		//keys[0]は60になる
		for (size_t i = 0;i<KEY_MAX;i++) {
			if (GetHitkey[i] == 1)
				keys[i]++;
			else              
				keys[i] = 0;
		}
	}
}


