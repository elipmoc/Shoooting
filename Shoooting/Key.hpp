#pragma once
#include <array>

namespace game {

	//キーの押してるかどうか情報を取得するクラス
	//こいつもシングルトンクラスにした
	class Key {
		
		static Key instance;

		Key()=default;

	public:

		static Key& GetInstance(){return instance;}

		//キーの数を定数で定義しておく
		//定数はconstexprが最高
		static constexpr size_t KEY_MAX = 256;

	private:

		//キーの配列
		std::array<int, KEY_MAX> keys;

	public:

		//キーの情報を更新
		void UpdateKey();

		//キーの状態を取得
		int GetKey(size_t keyCode)const noexcept {
			if (KEY_MAX <= keyCode)return -1;
			return keys[keyCode];
		}

	};
}