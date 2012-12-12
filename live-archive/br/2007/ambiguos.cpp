#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <map>
#include <algorithm>
#include <queue>
#define INF 1000000
#define MAXE 5000

using namespace std;

vector<string> v, query;
vector<int> grafo[MAXE], peso[MAXE];
map<string, int> m;
string sufstr;
int resp, sufdis, vis[MAXE], tam[MAXE], d[MAXE];

struct trie
{
    vector<string> values;
    map<char, trie> children;

    void insert(string s, int pos)
    {
        if(pos == s.size() || pos == 5) values.push_back(s);
        else children[s[pos]].insert(s, pos+1);
    }

    void match(string s, int pos)
    {
        map<char, trie>::iterator it;
        if(pos < s.size()) {
            if(children.count(s[pos]) > 0) children[s[pos]].match(s, pos+1);
        }
        else for(it=children.begin(); it!=children.end(); it++) (*it).second.match(s, pos);
        for(int i=0;i<values.size();i++) query.push_back(values[i]);
    }
};

trie t;

bool sufix(string x, string y)
{
    int i;
	if(y.size() > x.size())
	{
		for(i=0;i<x.size();i++) if(x[i] != y[i]) return false;
		sufstr = y.substr(x.size());
		sufdis = y.size() - x.size();
		return true;
	}
	else
	{
		for(i=0;i<y.size();i++) if(x[i] != y[i]) return false;
		sufstr = x.substr(y.size());
		sufdis = 0;
		return true;
	}
}

void generate(string s, int val)
{
	queue<string> q;
	int i, h, pai, filho;
	if(m.count(s) == 0)
	{
		m[s] = m.size() - 1;
		q.push(s);
	}
	pai = m[s];
	tam[pai] = val;
	while(!q.empty())
	{
		s = q.front();
		pai = m[s];
		q.pop();
		if(tam[pai] > resp) continue;
        query.clear();
        t.match(s, 0); 
        for(i=0;i<query.size();i++)
		{
			if(!sufix(s, query[i])) continue;
            if(m.count(sufstr) == 0)
            {
                m[sufstr] = m.size() - 1;
                filho = m.size() - 1;
                q.push(sufstr);
            }
            else filho = m[sufstr];
            tam[filho] = tam[pai] + sufdis;
            grafo[pai].push_back(filho);
            peso[pai].push_back(sufdis);
		}
	}
}

int shortest_path(string s, int val)
{
	priority_queue<pair<int, int> > q;
	int v, u, i, src, des;
	generate(s, val);
	for(i=0;i<m.size();i++)
	{
		vis[i] = 0;
		d[i] = INF;
	}
	src = m[s];
	des = 0;
	d[src] = val;
	q.push(make_pair(-d[src], src));
	while(!q.empty())
	{
		v = q.top().second;
		if(v == des) return d[v];
		q.pop();
		if(vis[v]) continue;
		vis[v] = 1;
		for(i=0;i<grafo[v].size();i++)
		{
			u = grafo[v][i];
			if(d[v] + peso[v][i] < d[u])
			{
				d[u] = d[v] + peso[v][i];
				q.push(make_pair(-d[u], u));
			}
		}
	}
	return INF;
}

int main()
{
	int N, i, j, k;
	vector<string> init;
	vector<int> start;
    string str;
	char s[100];
	while(scanf("%d", &N) != EOF && N)
	{
		v.clear();
		init.clear();
		start.clear();
        t.children.clear();
		for(i=0;i<m.size();i++)
		{
			grafo[i].clear();
			peso[i].clear();
			tam[i] = INF;
		}
		m.clear();
		m[""] = 0;
		for(i=0;i<N;i++)
		{
			scanf("%s", s);
            t.insert(s, 0);
            v.push_back(s);
		}
		for(i=0;i<v.size();i++)
        {
            query.clear();
            t.match(v[i], 0);
            for(j=0;j<query.size();j++) if(query[j] != v[i])
            {
                if(!sufix(v[i], query[j])) continue;
                init.push_back(sufstr);
                start.push_back(max(v[i].size(), query[j].size()));
            }
		}
		resp = INF;
		for(i=0;i<init.size();i++) if(start[i] < resp) resp = min(resp, shortest_path(init[i], start[i]));
		if(resp == INF) printf("-1\n");
		else printf("%d\n", resp);
	}
	return 0;
}
