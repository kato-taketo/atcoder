#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007
#define inf 1000000000000000000LL

int main(void) {
  ll n,m;
  cin >> n >> m;

  ll b;
  ll tmp=inf;
  for(ll a=1; a<=min(1000000LL,n); a++) {
    if(m%a==0) b=m/a;
    else b=m/a+1;

    if(b<=n) tmp=min(tmp,a*b);
  }
  if(tmp==inf) cout << -1 << endl;
  else cout << tmp << endl;
}