#include <string>
using namespace std;

struct FoxAndFencingEasy {
	string WhoCanWin(int mov1, int mov2, int d) {
		if(d <= mov1) return "Ciel";
		if(mov1 > mov2) {
			if(mov1 >= mov2 + mov2 + 1) return "Ciel";
			return "Draw";
		}
		else {
			if(mov2 >= mov1 + mov1 + 1) return "Liss";
			return "Draw";
		}
	}
};
