#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

inline int conv(int x) { return x+(x-1)/8; }
inline int mabs(int x) { return x>0?x:-x; }
inline bool isred(char c) { return c=='R' || c=='r'; }
inline bool isking(char c) { return c=='R' || c=='W'; }
inline bool ispiece(char c) { return c!=0; }
inline char make_king(char c) { 
	if(c=='r') return 'R';
	if(c=='w') return 'W';
	return c;
}
inline bool inrange(int i) { return i>=1 && i<=35 && i%9; }

char board[36];
bool can_jump(int i,int dir) {
	if(inrange(i+10*dir)) {
		if(ispiece(board[i+5*dir]) && isred(board[i]) != isred(board[i+5*dir]) && !ispiece(board[i+10*dir])) return true;
	}
	if(inrange(i+8*dir)) {
		if(ispiece(board[i+4*dir]) && isred(board[i]) != isred(board[i+4*dir]) && !ispiece(board[i+8*dir])) return true;
	}
	return false;
}
bool can_jump(int i) {
	int dir=isred(board[i])?1:-1;
	if(can_jump(i,dir)) return true;
	if(isking(board[i]) && can_jump(i,-dir)) return true;
	return false;
}

int solve() {
	for(int i=0;i<36;i++) board[i]=0;
	int r=0, w=0; scanf("%d%d",&r,&w);
	if(r==0 && w==0) exit(0);
	for(int i=0;i<r;i++) {
		int a; scanf("%d",&a);
		if(a<0) board[conv(-a)]='R';
		else board[conv(a)]='r';
	}
	for(int i=0;i<w;i++) {
		int a; scanf("%d",&a);
		if(a<0) board[conv(-a)]='W';
		else board[conv(a)]='w';
	}
	int qq; char cm; scanf("%d %c",&qq,&cm);
	bool move=isred(cm);
	int movd=move?1:-1;
	vector<vector<int> > moves(qq);
	for(int q=0;q<qq;q++) {
		while(1) {
			int a; scanf("%d",&a);
			moves[q].push_back(conv(a));
			char c=getchar();
			if(c!='-') break;
		}
	}
	for(int q=0;q<qq;q++) {
		if(moves[q].size() == 1) return q;
		int st=moves[q][0];
		if(!ispiece(board[st])) return q;
		if(isred(board[st]) != move) return q;
		bool can_short = true;
		for(int i=1;i<=35;i++) {
			if(ispiece(board[i]) && (isred(board[i])==move)) {
				if(can_jump(i)) {
					can_short = false;
					break;
				}
			}
		}
		for(int zz=1;zz<moves[q].size();zz++) {
			int dest=moves[q][zz];
			if(ispiece(board[dest])) return q;
			if((dest-st)*movd<=0 && !isking(board[st])) return q;
			int dist = mabs(dest-st);
			if(dist!=5 && dist!=4 && dist!=10 && dist!=8) return q;
			if(dist==5 || dist==4) {
				if(!can_short) return q;
				if(zz!=moves[q].size()-1) return q;
				board[dest]=board[st];
				board[st]=0;
				st=dest;
			} else {
				can_short=false;
				dist=dest-st;
				if(!ispiece(board[st+dist/2]) || isred(board[st+dist/2])==move) return q;
				board[dest]=board[st];
				board[st+dist/2]=0;
				board[st]=0;
				st=dest;
				if(zz==moves[q].size()-1) {
					/*puts("can_stop?");
					  printf("[%d]%c ", st,board[st]);
					  printf("[%d]%c ", st-4,board[st-4]);
					  printf("[%d]%c ", st-5,board[st-5]);
					  printf("[%d]%c ", st+4,board[st+4]);
					  printf("[%d]%c\n",st+5,board[st+5]);
					 */
					if(can_jump(st)) return q;
				}
			}
		}
		if(isred(board[st])&&st>=32) board[st] = make_king(board[st]);
		if(!isred(board[st])&&st<=4) board[st] = make_king(board[st]);
		move^=true;
		movd*=-1;
	}
	return -1;
}

int main() {
	while(1) {
		int x=solve();
		if(x==-1) puts("All moves valid");
		else printf("Move %d is invalid\n", x+1);
	}
	return 0; 
}
