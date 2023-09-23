#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  vector<string> S(8);
  rep(i,8) cin >> S[i];
  string f="abcdefgh", s="87654321";
  rep(i,8) {
    rep(j,8) {
      if(S[i][j]=='*') {
        cout << f[j] << s[i] << endl; return 0;
      }
    }
  }
}