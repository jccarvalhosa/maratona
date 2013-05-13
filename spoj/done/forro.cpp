#include <stdio.h>
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct
{
	int cidA;
	int cidB;
	int cidIn;
	int pai;
	int v;
	bool vis;
} estrada;

vector<estrada> e;
vector<int> lista[1000];
int cidcomp;

struct classcomp {
	  bool operator() (const estrada& lhs, const estrada& rhs) const
	    {
			if(lhs.cidA != rhs.cidA) return lhs.cidA < rhs.cidA;
			if(lhs.cidB != rhs.cidB) return lhs.cidB < rhs.cidB;
			return lhs.v < rhs.v;
		}
};

struct myclass {
	  bool operator() (const int& i, const int& j) const
	    {	
			int a, b;
			estrada lhs, rhs;
			lhs = e[i];
			rhs = e[j];
			if(lhs.cidA == cidcomp)	a = lhs.cidB;
			else a = lhs.cidA;
			if(rhs.cidA == cidcomp)	b = rhs.cidB;
			else b = rhs.cidA;
			return  a < b;
		}
} myobject;


void marca_oposto(int i, int cid)
{
	if(e[i].cidA == cid) e[i].cidIn = e[i].cidB;
	if(e[i].cidB == cid) e[i].cidIn = e[i].cidA;
}

int main()
{
	int N, dist;
	string str1, str2;
	int vel, cini, cdest, i, j, eind, etop;
	estrada eaux;
	map<string, int> mapcid;
	map<int, string> nomecid;
	map<estrada, int, classcomp> mapest;
	vector<int> caminho;
	queue<int> q;
	bool chegou;
	while(scanf("%d", &N) != EOF)
	{
		for(i=0;i<mapcid.size();i++) lista[i].clear();
		mapcid.clear();
		nomecid.clear();
		mapest.clear();
		caminho.clear();
		e.clear();
		for(i=0;i<N;i++)
		{
			cin >> str1 >> str2 >> vel;
			if(mapcid.count(str1) == 0) mapcid[str1] = mapcid.size() - 1;
			if(mapcid.count(str2) == 0) mapcid[str2] = mapcid.size() - 1;
			eaux.cidA = mapcid[str1];
			eaux.cidB = mapcid[str2];
			nomecid[mapcid[str1]] = str1;
			nomecid[mapcid[str2]] = str2;
			eaux.v = vel;
			eaux.vis = 0;
			if(mapest.count(eaux) == 0)
			{
				mapest[eaux] = mapest.size() - 1;
				e.push_back(eaux);
			}
			lista[eaux.cidA].push_back(mapest[eaux]);
			lista[eaux.cidB].push_back(mapest[eaux]);
		}
		cin >> str1 >> str2;
		if(mapcid.count(str1) == 0) mapcid[str1] = mapcid.size() - 1;
		if(mapcid.count(str2) == 0) mapcid[str2] = mapcid.size() - 1;
		cini = mapcid[str1];
		cdest = mapcid[str2];
		if(cini == cdest)
		{
			cout << nomecid[cini] << endl;
			continue;
		}
		for(cidcomp=0;cidcomp<mapcid.size();cidcomp++) sort(lista[cidcomp].begin(), lista[cidcomp].end(), myobject);
		chegou = false;
		for(j=0;j<lista[cini].size();j++)
		{
			i = lista[cini][j];
			e[i].pai = -1;
			e[i].vis = 1;
			marca_oposto(i, cini);
			if(e[i].cidIn == cdest) chegou = true;
			q.push(i);
		}
		while(!q.empty())
		{
			etop = q.front();
			q.pop();
			if(chegou) continue;
			for(j=0;j<lista[e[etop].cidIn].size();j++)
			{
				eind = lista[e[etop].cidIn][j];
				if(e[eind].vis) continue;
				if(e[eind].v >= e[etop].v)
				{
					e[eind].vis = 1;
					e[eind].pai = etop;
					marca_oposto(eind, e[etop].cidIn);
					q.push(eind);
					if(e[eind].cidIn == cdest)
					{
						chegou = true;
						break;
					}
				}
			}
		}
		if(!chegou) printf("No valid route.\n");
		else
		{
			cout << nomecid[cini] << " ";
			for(i=eind;i!=-1;i=e[i].pai) caminho.push_back(i);
			for(i=caminho.size()-1;i>=0;i--) cout << nomecid[e[caminho[i]].cidIn] << " ";
			printf("\n");
		}
	}
	return 0;
}
