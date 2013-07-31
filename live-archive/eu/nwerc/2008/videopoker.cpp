#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long ll;

string ranks = "23456789TJQKA";
string suits = "cdhs";

long long cards[7777777];
int result[7777777];
int rank[13], suit[4], cnt[5];

int eval () {
	for(int i=0;i<13;i++) cnt[rank[i]]++;
	int flush=0;
	for(int i=0;i<4;i++) if (suit[i]==5) flush=1;
	int straight=0;
	for(int i=0;i<9;i++) if(rank[i] && rank[i+1] && rank[i+2] && rank[i+3] && rank[i+4]) straight=1;
	if(rank[0] && rank[1] && rank[2] && rank[3] && rank[12]) straight=1;
	if(straight && flush && rank[11] && rank[12]) return 9;
	if(straight && flush) return 8;
	if(cnt[4]) return 7;
	if(cnt[3] && cnt[2]) return 6;
	if(flush) return 5;
	if(straight) return 4;
	if(cnt[3]) return 3;
	if(cnt[2]==2) return 2;
	if(cnt[2]) return 1;
	return 0;
}

int n=0;
void precalc() {
	for(int a=0;a<52;a++) for(int b=a+1;b<52;b++) for(int c=b+1;c<52;c++) for(int d=c+1;d<52;d++) for(int e=d+1;e<52;e++) {
		ll mask=(1ll<<a) + (1ll<<b) + (1ll<<c) + (1ll<<d) + (1ll<<e);
		memset(rank, 0, sizeof(rank));
		memset(suit, 0, sizeof(suit));
		memset(cnt, 0, sizeof(cnt));
		rank[a/4]++, suit[a%4]++;
		rank[b/4]++, suit[b%4]++;
		rank[c/4]++, suit[c%4]++;
		rank[d/4]++, suit[d%4]++;
		rank[e/4]++, suit[e%4]++;
		cards[n] = mask;
		result[n] = eval();
		n++;
	}
}

int main() {
	int T;
	ll sum[32];
	int total[32];
	cin>>T;
	precalc();
	while(T--) {
		int pay[10];
		pay[0]=0;
		for(int i=1;i<10;i++) cin>>pay[i];
		int Q;
		cin>>Q;
		while(Q--) {
			ll hand[5];
			for(int i=0;i<5;i++) {
				string s;
				cin>>s;
				hand[i] = 1LL << (4*ranks.find(s[0]) + suits.find(s[1]));
			}
			memset(sum, 0, sizeof(sum));
			memset(total, 0, sizeof(total));
			for(int i=0;i<n;i++) {
				int id=0;
				for(int j=0;j<5;j++) if(cards[i] & hand[j]) id+=1<<j;
				sum[id] += pay[result[i]];
				total[id]++;
			}
			double ans=0;
			for(int i=0;i<32;i++) if(total[i]) ans = max(ans, 1.0*sum[i]/total[i]);
			printf("%.9lf\n", ans);
		}
	}
	return 0;
}
