#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int h,w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i,h) cin >> s[i];

  rep(i,h) {
    rep(j,w) {
      if(j+1<w) {
        if(s[i][j]=='T'&&s[i][j+1]=='T') s[i][j]='P',s[i][j+1]='C';
      }
    }
  }

  rep(i,h) rep(j,w) {
    if(j==w-1) cout << s[i][j] << endl;
    else cout << s[i][j];
  }
}