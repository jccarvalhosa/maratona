#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/* Head ends here */

void print(vector<int> ar) { for(int j=0;j<ar.size()-1;j++) cout<<ar[j]<<" "; cout<<ar.back()<<endl; }
void insertionSort(vector <int>  ar) { 
	for(int i=1;i<ar.size();i++) if(ar[i]<ar[i-1]) {
		int x = ar[i];    
		ar[i] = ar[i-1];
		print(ar);
		ar[i-1] = x;
		insertionSort(ar);
		return;
	}
	print(ar);
}
/* Tail starts here */
int main(void) {
	vector <int>  _ar;
	int _ar_size;
	cin >> _ar_size;
	for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
		int _ar_tmp;
		cin >> _ar_tmp;
		_ar.push_back(_ar_tmp); 
	}

	insertionSort(_ar);

	return 0;
}
