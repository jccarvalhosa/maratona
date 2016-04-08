#include <algorithm>
#include <cstdio>

using namespace std;

int M = 99;
int N = 99;

int randomIntByMod(int n) { return rand() % n; }

char randomCell()
{
    int x = randomIntByMod(11111);
    if(x < 10000) return '.';
    if(x < 11080) return '#';
    return 'D';
}

int main() {
    int i, j, k, n, m;
	srand(time(NULL));
	for(i=1;i<=15;i++) {
        char name[55];
		sprintf(name, "testcases/run.in%d", i);
		freopen(name, "w", stdout);
		if(i==1)
		{
            printf("2 2\n");
            printf("..\n");
            printf("..\n");
        }
		else if(i==2)
		{
            printf("3 3\n");
            printf("...\n");
            printf(".D.\n");
            printf("...\n");
        }
		else if(i==3)
		{
            printf("5 5\n");
            printf("....#\n");
            printf("...#.\n");
            printf("..#..\n");
            printf(".#...\n");
            printf("#....\n");
        }
		else if(i==4)
		{
            printf("9 8\n");
            printf("........\n");
            printf("....#D..\n");
            printf(".#...#..\n");
            printf("#D#.....\n");
            printf(".#....#.\n");
            printf(".....#D.\n");
            printf(".#....#.\n");
            printf(".D#.....\n");
            printf("........\n");
        }
        else if(i==5)
		{
            printf("10 20\n");
            printf(".#DDDDDDDDDDDDDDDDDD\n");
            printf(".#DDDDDDDDDDDDDDDDDD\n");
            printf(".#DDDDDDDDDDDDDDDDDD\n");
            printf(".#DDDDDDDDDDDDDDDDDD\n");
            printf(".#DDDDDDDDDDDDDDDDDD\n");
            printf(".#DDDDDDDDDDDDDDDDDD\n");
            printf(".#DDDDDDDDDDDDDDDDDD\n");
            printf(".#DDDDDDDDDDDDDDDDDD\n");
            printf(".###################\n");
            printf("....................\n");
        }
        else if(i==6)
		{
            printf("21 10\n");
            printf("..........\n");
            printf("#########.\n");
            printf("DDDDDDDD#.\n");
            printf("#########.\n");
            printf("..........\n");
            printf(".#########\n");
            printf(".#DDDDDDDD\n");
            printf(".#########\n");
            printf("..........\n");
            printf("#########.\n");
            printf("DDDDDDDD#.\n");
            printf("#########.\n");
            printf("..........\n");
            printf(".#########\n");
            printf(".#DDDDDDDD\n");
            printf(".#########\n");
            printf("..........\n");
            printf("#########.\n");
            printf("DDDDDDDD#.\n");
            printf("........#.\n");
            printf("..........\n");
        }
        else if(i==7)
		{
            printf("21 10\n");
            printf("..........\n");
            printf("#########.\n");
            printf("DDDDDDDD#.\n");
            printf("#########.\n");
            printf("..........\n");
            printf(".#########\n");
            printf(".#DDDDDDDD\n");
            printf(".#########\n");
            printf("..........\n");
            printf("#########.\n");
            printf("DDDDDDDD#.\n");
            printf("#########.\n");
            printf("..........\n");
            printf(".#########\n");
            printf(".#DDDDDDDD\n");
            printf(".###.#####\n");
            printf("..........\n");
            printf("#########.\n");
            printf("DDDDDDDD#.\n");
            printf("........#.\n");
            printf("..........\n");
        }
		else if(i<12)
		{
            n=randomIntByMod(N)+2, m=randomIntByMod(M)+2;
            printf("%d %d\n", n, m);
            for(j=0; j<n; j++)
            {
                for(k=0; k<m; k++)
                {
                    if((!j && !k) || (j==n-1 && k==m-1)) printf(".");
                    else printf("%c", randomCell());
                }
                printf("\n");
            }
        }
		else
		{
            n=100, m=100;
            printf("%d %d\n", n, m);
            for(j=0; j<n; j++)
            {
                for(k=0; k<m; k++)
                {
                    if((!j && !k) || (j==n-1 && k==m-1)) printf(".");
                    else printf("%c", randomCell());
                }
                printf("\n");
            }
        }
		fclose(stdout);
	}
}
