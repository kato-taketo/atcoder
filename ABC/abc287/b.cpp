#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int n,m;
  cin >> n >> m;
  vector<string> s(n);
  rep(i,n) cin >> s[i];
  vector<string> t(m);
  rep(i,m) cin >> t[i];

  int cnt=0;
  rep(i,n) {
    rep(j,m) {
      if(s[i][3]==t[j][0]&&s[i][4]==t[j][1]&&s[i][5]==t[j][2]) {
        cnt++; break;
      }
    }
  }
  cout << cnt << endl;
}