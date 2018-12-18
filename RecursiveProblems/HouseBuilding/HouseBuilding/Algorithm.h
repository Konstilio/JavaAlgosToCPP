#pragma once
#include <iostream>
using std::cout;

namespace Algorithm
{
	void buildLayers(int height) {

		if (height == 0) return;
		
		buildLayers(height - 1);
		cout << height << '\n';
	}
}
