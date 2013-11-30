#include <string>
using namespace std;

struct ErasingCharacters {
	string simulate(string s) {
		while(s.size() >= 2) {
			int ok=0;
			for(int i=0;i<s.size()-1;i++) if(s[i]==s[i+1]) {
				s = s.substr(0, i) + s.substr(i+2);
				ok=1;
				break;
			}
			if(!ok) return s;
		} 
		return s;
	}
};
