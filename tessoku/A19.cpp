#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int n,W;
  cin >> n >> W;
  vector<ll> w(n),v(n);
  rep(i,n) cin >> w[i] >> v[i];

  vector<vector<ll> > dp(n,vector<ll>(W+1,-1));
  dp[0][0]=0;
  for(int i=0; i<n; i++) {
    if(i==0) dp[i][w[i]]=v[i];
    else {
      for(int j=0; j<W+1; j++) {
        if(dp[i-1][j]!=-1) dp[i][j]=max(dp[i][j],dp[i-1][j]);
        if(j-w[i]>=0) dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+v[i]);
      }
    }
  }
  ll res=0;
  for(int j=0; j<W+1; j++) res = max(res, dp[n-1][j]);
  cout << res << endl;
}