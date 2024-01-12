#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

string abc="atcoder";
bool allkey=true, key=false;
int main(void) {
  string s,t;
  cin >> s >> t;
  rep(i,s.length()) {
    if(s[i]==t[i]) continue;
    else if(s[i]=='@') {
      key=false;
      rep(j,abc.length()) if(t[i]==abc[j]) key=true;
      if(key) continue;
      else allkey=false;
    } else if(t[i]=='@') {
      key=false;
      rep(j,abc.length()) if(s[i]==abc[j]) key=true;
      if(key) continue;
      else allkey=false;
    } else {
      allkey=false;
    }
  }
  if(!allkey) cout << "You will lose" << endl;
  else cout << "You can win" << endl;
}