#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int vis[11][11];
char t[1111][1111];
int r, c;

int sr(int x) { return 1+x*2; }
int sc(int y) { return 1+y*3; }

void rect(int xi, int yi, int sx, int sy)
{
	int pix = sr(xi);
	int piy = sc(yi);
	int pfx = sr(xi+sx-1)+1;
	int pfy = sc(yi+sy-1)+2;
	for(int i=0;i<sx;i++) for(int j=0;j<sy;j++) vis[xi+i][yi+j] = 1;
	for(int i=pix;i<=pfx;i++) for(int j=piy;j<=pfy;j++) t[i][j] = ' ';
	t[pix][piy] = '0'+xi+1;
	t[pix][piy+1] = '0'+yi+1;
	for(int i=pix;i<pfx;i++) t[i][pfy] = (i%2 ? '|' : ' ');
	for(int i=piy;i<pfy;i++) t[pfx][i] = (i%3 ? '-' : ' ');
}

int main()
{
	while(cin>>r && r)
	{
		t[0][0] = ' ';
		memset(vis,0,sizeof(vis));
		memset(t,'\0',sizeof(t));
		int tc=0;
		for(int i=1;i<=2*r;i++) t[i][0] = (i%2 ? '|' : ' ');
		for(int i=0;i<r;i++)
		{
			cin >> c;
			int k=0;
			for(int j=0;j<c;j++)
			{
				int rs, cs;
				cin >> rs >> cs;
				if(!i) tc += cs;
				while(vis[i][k]) k++;
				rect(i,k,rs,cs);
				k++;
			}
		}
		for(int i=0;i<=3*tc;i++) t[0][i] = (i%3 ? '-' : ' ');
		for(int i=0;i<=2*r;i++) cout << t[i] << endl;
		cout << endl;
	}
	return 0;
}
