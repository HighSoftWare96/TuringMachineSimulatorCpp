#include "GpUtils.h"

bool gpUtils::arrayContains(int size, int *array, int item) {
	for (int i = 0; i < size; i++) {
		if (item == array[i])
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
