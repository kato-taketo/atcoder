#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007
#define mod 998244353

int main(void) {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  rep(i,n) cin >> a[i] >> b[i];

  vector<ll> dp_a(n,0), dp_b(n,0);

  rep(i,n) {
    if(i==0) dp_a[i]=1,dp_b[i]=1;
    else {
      if(a[i]!=a[i-1]) dp_a[i]+=dp_a[i-1];
      if(a[i]!=b[i-1]) dp_a[i]+=dp_b[i-1];
      if(b[i]!=a[i-1]) dp_b[i]+=dp_a[i-1];
      if(b[i]!=b[i-1]) dp_b[i]+=dp_b[i-1];
      dp_a[i]%=mod;
      dp_b[i]%=mod;
    }
  }
  ll res=dp_a[n-1]+dp_b[n-1];
  res %= mod;
  cout << res << endl;
}