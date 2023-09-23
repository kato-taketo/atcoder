#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int n;
  cin >> n;
  vector<ll> x(n), y(n);
  rep(i,n) cin >> x[i] >> y[i];

  vector<ll> dp1(n+1,-2e18), dp2(n+1,-2e18);
  dp1[0]=0, dp2[0]=0;
  rep(i,n) {
    if(x[i]==1) {
      dp2[i+1] = max(dp1[i] + y[i], dp2[i]);
      dp1[i+1] = dp1[i];
    } else {
      dp1[i+1] = max(max(dp2[i],dp1[i]) + y[i], dp1[i]);
      dp2[i+1] = dp2[i];
    }
  }
  cout << max(dp1[n], dp2[n]) << endl;
}