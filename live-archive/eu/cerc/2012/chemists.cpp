#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string symbols[] = { 
	"h", "he", 
	"li", "be", "b", "c", "n", "o", "f", "ne", 
	"na", "mg", "al", "si", "p", "s", "cl", "ar",
	"k", "ca", "sc", "ti", "v", "cr", "mn", "fe", "co", "ni", "cu", "zn", "ga", "ge", "as", "se", "br", "kr",
	"rb", "sr", "y", "zr", "nb", "mo", "tc", "ru", "rh", "pd", "ag", "cd", "in", "sn", "sb", "te", "i", "xe",
	"cs", "ba",      "hf", "ta", "w", "re", "os", "ir", "pt", "au", "hg", "tl", "pb", "bi", "po", "at", "rn",
	"fr", "ra",      "rf", "db", "sg", "bh", "hs", "mt", "ds", "rg", "cn", "fl", "lv",
	"la", "ce", "pr", "nd", "pm", "sm", "eu", "gd", "tb", "dy", "ho", "er", "tm", "yb", "lu",
	"ac", "th", "pa", "u", "np", "pu", "am", "cm", "bk", "cf", "es", "fm", "md", "no", "lr", "end"
};

int valid[1111111];

int main() {
	int T, total;
	cin>>T;
	for(int i=0;;i++) if(symbols[i] == "end") {
		total = i;
		break;
	}
	while(T--) {
		string word;
		cin>>word;
		int n = word.size();
		valid[n] = valid[n+1] = 1;
		for(int i=n-1;i>=0;i--) {
			valid[i]=0;
			if((find(symbols, symbols+total, word.substr(i, 1)) - symbols != total) && valid[i+1]) valid[i]=1;
			if(i!=n-1 && (find(symbols, symbols+total, word.substr(i, 2)) - symbols != total) && valid[i+2]) valid[i]=1;
		}
		if(valid[0]) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
