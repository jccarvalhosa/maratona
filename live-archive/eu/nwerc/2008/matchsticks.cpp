#include <iostream>
#include <string>
#include <map>
using namespace std;

string mul(string s, int n) {
    string ret="";
    for(int i=0;i<n;i++) ret += s;
    return ret;
}

string findmax(int n) {
    if(n%2==0) return mul("1", n/2);
    else return "7" + mul("1", n/2-1);
}

string findmin(int n) {
    if(n==2) return "1";
    if(n==3) return "7";
    if(n==4) return "4";
    if(n==5) return "2";
    if(n==6) return "6";
    if(n%7==0) return mul("8", n/7);
    string ans="";
    if(n%7<=2) {
        ans="1";
        n -= 2;
    }
    else if(n%7<=5) {
        ans = "2";
        n -= 5;
    }
    else if(n%7==6) {
        ans = "6";
        n -= 6;
    }
    while(1) {
        if(n%7==0) return ans + mul("8", n/7);
        else if(n>=6) {
            ans += "0";
            n -= 6;
        }
        else {
            if(n==2) return ans + "1";
            if(n==3) return ans + "7";
            if(n==4) return ans + "4";
            if(n==5) return ans + "2";
        }
    }
}

int main() {
    int T, n;
    cin>>T;
    /*
    for(n=2;n<=T;n++) {
        cout<<n<<": "<<findmin(n) << " " << findmax(n)<<endl;
    }
    */
    while(T--) {
        cin>>n;
        cout<<findmin(n) << " " << findmax(n)<<endl;
    }
    return 0;
}
