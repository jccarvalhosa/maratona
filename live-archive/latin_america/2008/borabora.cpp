#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#define fori(i, N) for(int i=0;i<(N);i++)
#define sz size()
#define pb push_back
#define all(x) (x).begin(), (x).end()
using namespace std;

int ord[300];
char suits[] = {'C', 'D', 'H', 'S'};

struct card {
    int r;
    char s;
    card(int r=1, char s='C'): r(r), s(s) {}
    bool operator<(const card &c)const { return r*13 + ord[s] < c.r*13 + ord[c.s]; }
};

queue<card> deck;
card pile;
vector<card> hand[10];

int J, M, N;

struct game {
    int dir, miss, draw, winner;
    
    game() {}

    void check_penalty() {
        if(pile.r == 12) dir *= -1;
        if(pile.r == 7) draw=2, miss=1;
        if(pile.r == 1) draw=1, miss=1;
        if(pile.r == 11) miss=1;
    }

    void buy(int j) { 
        hand[j].pb(deck.front()); 
        deck.pop();
    } 

    void init() {
        dir = 1;
        miss = draw = 0;
        fori(i, J) {
            hand[i].clear();
            fori(j, M) buy(i);
        }
        pile = deck.front();
        deck.pop();
        check_penalty();
    }

    int next(int j) { return (J + j + dir) % J; }

    void discard(int j, int i) {
        pile = hand[j][i];
        hand[j][i] = hand[j][hand[j].sz-1];
        hand[j].pop_back();
    }

    bool move(int j, int i) {
        card c = pile;
        card n = hand[j][i];
        if(n.r == c.r || n.s == c.s) {
            discard(j, i);
            check_penalty();
            return true;
        }
        return false;
    }

    int play(int j) {
        fori(i, draw) buy(j);
        draw = 0;
        if(miss) miss = 0;
        else {
            sort(all(hand[j]));
            reverse(all(hand[j]));
            fori(i, hand[j].sz) if(move(j, i)) {
                if(hand[j].empty()) return winner = j+1;
                return play(next(j));
            }
            buy(j);
            move(j, hand[j].sz-1);
        }
        return play(next(j));
    }
};

int main()
{
    int r; char s;
    game G;
    fori(i, 4) ord[suits[i]] = i;
    while(scanf("%d%d%d", &J, &M, &N) && J) {
        while(!deck.empty()) deck.pop();
        fori(i, N) {
            scanf("%d %c ", &r, &s);
            deck.push(card(r, s));
        }
        G.init();
        G.play(0);
        printf("%d\n", G.winner);
    }
    return 0;
}
