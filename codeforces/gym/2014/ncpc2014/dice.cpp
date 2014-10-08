#include <bits/stdc++.h>
using namespace std;

int main() {
	int a1, b1, a2, b2, a3, b3, a4, b4, cnt1=0, cnt2=0;
	cin>>a1>>b1>>a2>>b2>>a3>>b3>>a4>>b4;
	for(int i1=a1;i1<=b1;i1++) 
		for(int i2=a2;i2<=b2;i2++) 
			for(int i3=a3;i3<=b3;i3++) 
				for(int i4=a4;i4<=b4;i4++) {
					if(i1 + i2 > i3 + i4) cnt1++;
					if(i3 + i4 > i1 + i2) cnt2++;
				}
	if(cnt1 > cnt2) cout << "Gunnar" << endl;
	if(cnt2 > cnt1) cout << "Emma" << endl;
	if(cnt2 == cnt1) cout << "Tie" << endl;
	return 0;
}
