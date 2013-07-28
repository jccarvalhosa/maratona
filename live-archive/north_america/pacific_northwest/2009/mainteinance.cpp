#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int g[55][55];
	
int n;

void print() {
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(g[i][j]) printf("%3d", j);
	cout<<endl;
}

void rotate() {
	int aux[55][55];
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) aux[j][n-i-1] = g[i][j];
	memcpy(g, aux, sizeof(g));
}

void vertical() {
	int aux[55][55];
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) aux[i][n-j-1] = g[i][j];
	memcpy(g, aux, sizeof(g));
}

void horizontal() {
	int aux[55][55];
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) aux[n-i-1][j] = g[i][j];
	memcpy(g, aux, sizeof(g));
}

void antidiagonal() {
	int aux[55][55];
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) aux[n-j-1][n-i-1] = g[i][j];
	memcpy(g, aux, sizeof(g));
}

void diagonal() {
	int aux[55][55];
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) aux[j][i] = g[i][j];
	memcpy(g, aux, sizeof(g));
}

int main() {
	while(1) {
		cin>>n;
		if(n==0) break;
		memset(g, 0, sizeof(g));
		for(int i=0;i<n;i++) {
			int j;
			cin>>j;
			g[i][j]=1;
		}
		print();rotate();
		print();rotate();
		print();rotate();
		print();rotate();
		vertical();print();vertical();
		antidiagonal();print();antidiagonal();
		horizontal();print();horizontal();
		diagonal();print();diagonal();
		cout<<endl;
	}
	return 0;
}
