// Ac

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int N,Q;
  cin >> N >> Q;
  vector<vector<int> > a(N);
  rep(i,N) {
    int L;
    cin >> L;
    a[i].resize(L);
    rep(j,L) cin >> a[i][j];
  }
  rep(i,Q) {
    int s,t;
    cin >> s >> t;
    s--; t--;
    cout << a[s][t] << endl;
  }
}