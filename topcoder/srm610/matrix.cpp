#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;

int l[111][111], u[111][111];

int calc(int i, int j, int ii, int jj) {
	return l[ii][jj] - l[i-1][jj] - l[ii][j] + l[i-1][j] + u[ii][jj] - u[i][jj] - u[ii][j-1] + u[i][j-1];
}

struct TheMatrix {
	int MaxArea(vector <string> b) {
		int n = b.size();
		int m = b[0].size();
		for(int i=0;i<n;i++) {
			int su=0, sl=0;
			for(int j=0;j<m;j++) {
				if(i!=0 && b[i][j] == b[i-1][j]) su++;
				if(j!=0 && b[i][j] == b[i][j-1]) sl++; 
				u[i+1][j+1] = u[i][j+1] + su;
				l[i+1][j+1] = l[i][j+1] + sl;
			}
		}
		int ans=0;
		for(int i=0;i<n;i++) for(int ii=i;ii<n;ii++) for(int j=0;j<m;j++) for(int jj=j;jj<m;jj++) {
			if(calc(i+1, j+1, ii+1, jj+1) == 0) ans = max(ans, (ii-i+1)*(jj-j+1));
		}
		return ans;
	}
};
