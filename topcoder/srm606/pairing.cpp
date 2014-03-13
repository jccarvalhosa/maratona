#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

struct EllysPairing {
	int getMax(int M, vector<int> count, vector<int> first, vector<int> mult, vector<int> add) {
		srand(time(NULL));
		int n=0;
		for(int i=0;i<count.size();i++) n += count[i];
		int pos[10], val[10];
		for(int i=0;i<10;i++) pos[i] = (1ll * rand() * rand()) % n;
		sort(pos, pos+10);
		int p=-1, pp=0;
		for(int i=0;i<count.size();i++) {
			int num=first[i];
			p++;
			while(pp!=10 && p==pos[pp]) val[pp++]=num; 
			for(int j=1;j<count[i];j++) {
				num = (1ll*num * mult[i] + add[i]) & (M - 1);
				p++;
				while(pp!=10 && p==pos[pp]) val[pp++]=num;
			}
		}
		for(int test=0;test<10;test++) {
			int c=0;
			for(int i=0;i<count.size();i++) {
				int num=first[i];
				if(num == val[test]) c++; 
				for(int j=1;j<count[i];j++) {
					num = (1ll*num * mult[i] + add[i]) & (M - 1);
					if(num == val[test]) c++;
				}
			}
			if(c > n/2) {
				return n-c;
			}
		}
		return n/2;
	}
};
