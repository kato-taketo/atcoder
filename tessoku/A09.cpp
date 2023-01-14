#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int h,w,n;
  cin >> h >> w >> n;
  vector<int> a(n),b(n),c(n),d(n);
  rep(i,n) cin >> a[i] >> b[i] >> c[i] >> d[i];

  vector<vector<int> > emos(h+2, vector<int>(w+2,0));
  rep(i,n) {
    emos[a[i]][b[i]]++;
    emos[a[i]][d[i]+1]--;
    emos[c[i]+1][b[i]]--;
    emos[c[i]+1][d[i]+1]++;
  }
  rep(i,h+2) {
    rep(j,w+1) {
      emos[i][j+1] += emos[i][j];
    }
  }
  rep(i,h+1) {
    rep(j,w+2) {
      emos[i+1][j] += emos[i][j];
    }
  }
  rep2(i,1,h+1) {
    rep2(j,1,w+1) printf("%d ", emos[i][j]);
    cout << endl;
  }
}