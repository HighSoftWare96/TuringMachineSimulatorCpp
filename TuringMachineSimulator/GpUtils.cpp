#include "GpUtils.h"
#include <vector>
#include <algorithm>
#include <string>

bool gpUtils::arrayContains(vector<int> array, int item) {
	for (int i : array) {
		if (item == i)
			return true;
	}
	return false;
}
int gpUtils::checkInput(string stringa, int inRange, int outRange)
{
	int result = stoi(stringa);
	if (result < inRange || result > outRange)
		throw "EXC: Input scorretto!";
	return result;
}

string gpUtils::toLower(string item)
{
	std::transform(item.begin(), item.end(), item.begin(), ::tolower);
	return item;
}
