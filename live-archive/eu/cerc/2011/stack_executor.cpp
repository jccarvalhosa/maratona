#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int rel[111111];
vector <string> cmd;

string apply(int n) {
    long long s[1111];
    int t=0;
    s[t] = n;
    for(int i=0;i<cmd.size();i++) {
        if(cmd[i] == "NUM") s[++t] = rel[i];
        else if(t == -1) return "ERROR";
        else if(cmd[i] == "POP") t--;
		else if(cmd[i] == "INV") s[t] *= -1;
		else if(cmd[i] == "DUP") s[t+1] = s[t++];
		else if(t == 0) return "ERROR";
		else if(cmd[i] == "SWP") swap(s[t],s[t-1]);
		else if(cmd[i] == "ADD") s[t-1] = s[t-1]+s[t--];
		else if(cmd[i] == "SUB") s[t-1] = s[t-1]-s[t--];
		else if(cmd[i] == "MUL") s[t-1] = s[t-1]*s[t--];
		else if(s[t] == 0) return "ERROR";
		else if(cmd[i] == "DIV") s[t-1] = s[t-1]/s[t--];
		else if(cmd[i] == "MOD") s[t-1] = s[t-1]%s[t--];
		if(t >= 0 && (s[t] > 1e9 || s[t] < -1e9)) return "ERROR";
    }
    if(t != 0) return "ERROR";
	ostringstream ret;
	ret<<s[t];
    return ret.str();
}

int main() {
    string c;
    int p=0;
    while(cin >> c) {
        if(c == "QUIT") break;
        else if(c != "END") {
            cmd.push_back(c);
            if(c == "NUM") cin >> rel[p];
            p++;
        }
        else {
            int n, q;
            cin >> n;
            for(int i=0;i<n;i++) {
                cin >> q;
                cout<<apply(q)<<endl;
            }
            cmd.clear();
            p = 0;
            cout << endl;
        }
    }
    return 0;
}
