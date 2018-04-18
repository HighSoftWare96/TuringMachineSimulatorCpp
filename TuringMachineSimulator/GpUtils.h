#ifndef GP_UTILS
#define GP_UTILS
#include <string>
#include <vector>
using namespace std;

namespace gpUtils {
	bool arrayContains(vector<int> array, int item);
	int checkInput(string stringa, int inRange, int outRange);
	string toLower(string item);
}
#endif

