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
  vector<vector<int> > x(h,vector<int>(w));
  rep(i,h) rep(j,w) cin >> x[i][j];

  vector<vector<int> > emos(h,vector<int>(w+1,0));
  rep(i,h) {
    rep(j,w) {
      emos[i][j+1] = emos[i][j] + x[i][j];
    }
  }

  int q;
  cin >> q;
  vector<int> res(q);
  rep(i,q) {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    rep2(j,a-1,c) {
      res[i] += emos[j][d]-emos[j][b-1];
    }
  }

  rep(i,q) cout << res[i] << endl;
}