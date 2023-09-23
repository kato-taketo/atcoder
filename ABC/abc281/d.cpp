#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007
#define inf 2e9

int n,k,d;
ll f(ll x) {
  x %= d;
  if (x<0) x+=d;
  else if(x>=d) x-=d;
  return x;
}
ll func(ll x, ll y) {
  if(x==-inf) return -inf;
  else return x+y;
}
int main(void) {
  
  cin >> n >> k >> d;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  sort(a.begin(), a.end());
  vector<vector<vector<ll> > > dp(102, vector<vector<ll> >(102, vector<ll>(102,-inf)));
  for(int i=0; i<=n ;i++) {
    //i番目まで見た
    for(int j=0; j<=min(i,k); j++) {
      //j個使用した
      for(int k=0;k<d; k++) {
        //mod(d)
        if(i==0||j==0) {
          if(k==0) dp[i][j][k]=0;
        }
        else {
          dp[i][j][k]=max(dp[i-1][j][k], func(dp[i-1][j-1][f(k-a[i-1])],a[i-1]));
        }
        //printf("dp[%d][%d][%d] = %lld\n",i,j,k,dp[i][j][k]);
      }
    }
  }
  if(dp[n][k][0]==-inf) cout << -1 << endl;
  else cout << dp[n][k][0] << endl;
}