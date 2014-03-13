#include <iostream>
#include <string>
#include <set>
using namespace std;
typedef pair<string, string> pss;
typedef pair<pss, string> pp;

set<pp> s;

string conv(string p1, string ps1, string p2, string ps2) {
	string sign;
	if(ps1==ps2) sign=ps1;
	else sign="+";
	if(p1+p2=="AA") return "A"+sign;

	if(p1+p2=="BB") return "B"+sign;

	if(p1+p2=="AB") return "AB"+sign;
	if(p1+p2=="BA") return "AB"+sign;

	if(p1+p2=="OO") return "O"+sign;

	if(p1+p2=="AO") return "A"+sign;
	if(p1+p2=="OA") return "A"+sign;

	if(p1+p2=="BO") return "B"+sign;
	if(p1+p2=="OB") return "B"+sign;
}

void gen(string p1, string p2, string ps1, string ps2, string m1, string m2, string ms1, string ms2) {
	pss par(conv(p1, ps1, p2, ps2), conv(m1,ms1,m2,ms2));

	s.insert(pp(
				par,
				conv(p1, ps1, m1, ms1)
			   ));

	s.insert(pp(
				par,
				conv(p1, ps2, m1, ms1)
			   ));

	s.insert(pp(
				par,
				conv(p2, ps1, m1, ms1)
			   ));

	s.insert(pp(
				par,
				conv(p2, ps2, m1, ms1)
			   ));

	s.insert(pp(
				par,
				conv(p1, ps1, m2, ms1)
			   ));

	s.insert(pp(
				par,
				conv(p1, ps2, m2, ms1)
			   ));

	s.insert(pp(
				par,
				conv(p2, ps1, m2, ms1)
			   ));

	s.insert(pp(
				par,
				conv(p2, ps2, m2, ms1)
			   ));

	s.insert(pp(
				par,
				conv(p1, ps1, m1, ms2)
			   ));

	s.insert(pp(
				par,
				conv(p1, ps2, m1, ms2)
			   ));

	s.insert(pp(
				par,
				conv(p2, ps1, m1, ms2)
			   ));

	s.insert(pp(
				par,
				conv(p2, ps2, m1, ms2)
			   ));

	s.insert(pp(
				par,
				conv(p1, ps1, m2, ms2)
			   ));

	s.insert(pp(
				par,
				conv(p1, ps2, m2, ms2)
			   ));

	s.insert(pp(
				par,
				conv(p2, ps1, m2, ms2)
			   ));

	s.insert(pp(
				par,
				conv(p2, ps2, m2, ms2)
			   ));
}

int match(string a, string b) {
	if(a==b) return 1;
	if(a=="?") return 1;
	if(b=="?") return 1;
	return 0;
}

string print(set<string> s, string str) {
	if(s.size()==1) return *s.begin();
	if(s.size()==0) {
		if(str == "?") return "IMPOSSIBLE";
		return str;
	}
	string ret="{";
	for(set<string>::iterator it=s.begin();it!=s.end();it++) {
		if(it!=s.begin()) ret+=", ";
		ret += *it;
	}
	return ret+"}";
}

int main() {
	string types[] = {"A", "B", "O"};
	string signs[] = {"+", "-"};
	for(int i=0;i<3;i++)
		for(int ii=0;ii<3;ii++)
			for(int si1=0;si1<2;si1++)
				for(int si2=0;si2<2;si2++)
					for(int j=0;j<3;j++)
						for(int jj=0;jj<3;jj++)
							for(int sj1=0;sj1<2;sj1++)
								for(int sj2=0;sj2<2;sj2++)
									gen(types[i], types[ii], signs[si1], signs[si2], types[j], types[jj], signs[sj1], signs[sj2]);

	//cout<<s.size() << endl;

	string p, m, f;
	int t=1;

	while(cin>>p>>m>>f && p != "E") {
		set<string> ps, ms, fs;

		for(set<pp>::iterator it=s.begin();it!=s.end();it++) {
			string pp, mm, ff;
			pp = (*it).first.first;
			mm = (*it).first.second;
			ff = (*it).second;
			if(match(p, pp) && match(m, mm) && match(f, ff)) {
				ps.insert(pp);
				ms.insert(mm);
				fs.insert(ff);
			}
		}

		cout<<"Case "<<t++<<": "<<print(ps, p)<<" "<<print(ms, m)<<" "<<print(fs, f)<<endl;
	}

	return 0;
}
