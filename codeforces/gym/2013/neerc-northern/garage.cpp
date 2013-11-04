#include <fstream>
using namespace std;

int main() {
	int W, H, w, h;
	ifstream in("garage.in");
	ofstream out("garage.out");
	in >> W >> H >> w >> h;
	out << ((W/w+1)/2)*((H/h+1)/2) << endl;
	return 0;
}
