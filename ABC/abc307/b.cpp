#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

bool check(string tmp) {
  bool key=true;
  for(int i=0; i<tmp.length()/2; i++) {
    if(tmp[i]!=tmp[tmp.length()-1-i]) return false;
  }
  return true;
}
int main(void) {
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i,n) cin >> s[i];
  rep(i,n) {
    rep(j,n) {
      if(i==j) continue;
      string tmp=s[i]+s[j];
      if(check(tmp)) {
        cout << "Yes" << endl; return 0;
      }
    }
  }
  cout << "No" << endl;
}