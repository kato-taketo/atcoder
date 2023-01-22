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
  vector<int> p(n),a(n);
  rep(i,n) cin >> p[i] >> a[i];

  vector<vector<int> > dp(2001, vector<int>(2001,0));
  dp[1][n]=0;
  for(int i=1; i<=n; i++) {
    for(int j=n; j>=1&&i<=j; j--) {
      if(j<n) {
        // erase j+1, target p[j], point a[j]
        dp[i][j]=max(dp[i][j],dp[i][j+1]);
        if(p[j]>=i&&p[j]<=j) dp[i][j]=max(dp[i][j],dp[i][j+1]+a[j]);
      }
      if(i>1) {
        // erase i-1, target p[i-2], point p[i-2]
        dp[i][j]=max(dp[i][j],dp[i-1][j]);
        if(p[i-2]>=i&&p[i-2]<=j) dp[i][j]=max(dp[i][j],dp[i-1][j]+a[i-2]);
      }
    }
  }
  int res=0;
  rep2(i,1,n+1) res = max(res,dp[i][i]);
  cout << res << endl;

}