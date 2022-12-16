#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007
#define inf 2e9

int main(void) {
  int n;
  cin >> n;
  vector<int> t(n), x(n), a(n);
  rep(i,n) cin >> t[i] >> x[i] >> a[i];

  vector<vector<ll> > dp(10005, vector<ll>(5,-inf));
  int index=0;
  dp[0][0]=0;
  for(int i=1; i<=t[n-1]; i++) {
    // isたった時
    int loc=-1;
    ll value=0;
    if(t[index]==i) loc=x[index],value=a[index],index++;
    for(int j=0; j<5; j++) {
      ll tmp = (loc==j?value:0);
      if(dp[i-1][j]==-inf) dp[i][j]=dp[i][j];
      else dp[i][j] = max(dp[i][j], dp[i-1][j]+tmp);
      if(j!=0) {
        if(dp[i-1][j-1]!=-inf) dp[i][j] = max(dp[i][j],dp[i-1][j-1]+tmp);
      } 
      if(j!=4) {
        if(dp[i-1][j+1]!=-inf) dp[i][j] = max(dp[i][j], dp[i-1][j+1]+tmp);
      }
    }
  }
  ll res=0;
  rep(j,5) res = max(res, dp[t[n-1]][j]);
  cout << res << endl;
}