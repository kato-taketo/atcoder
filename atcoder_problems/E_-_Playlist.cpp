// 16:00~
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007
#define mod 998244353
ll N,X;
vector<ll> t;
vector<ll> dp;
ll r,res;

long long modinv(long long a, long long m) {
  long long b = m, u = 1, v = 0;
  while (b) {
    long long t = a / b;
    a -= t * b; swap(a, b);
    u -= t * v; swap(u, v);
  }
  u %= m;
  if (u < 0) u += m;
  return u;
}
int main(void) {
  
  cin >> N >> X;
  t.resize(N+1);
  rep2(i,1,N+1) cin >> t[i];
  dp.resize(X+1,0);
  dp[0]=1;
  r = modinv(N,mod);

  // calculate dp
  for(int i=1; i<=X; i++) {
    for(int j=1; j<=N; j++) {
      // 時刻iにおいて、t[j]の曲が切り終わる確率
      if(i-t[j]>=0) dp[i] += dp[i-t[j]], dp[i] %= mod;
    }
    dp[i] *= r, dp[i] %= mod;
  }

  // 
  res=0;
  if(t[1]<=X+1) {
    for(int i=X-t[1]+1; i<=X; i++) {
      res += dp[i], res %= mod;
    }
    res *= r, res %= mod;
  } else {
    for(int i=0; i<=X; i++) {
      res += dp[i], res %= mod;
    }
    res *= r, res %= mod;
  }
  cout << res << endl;
}