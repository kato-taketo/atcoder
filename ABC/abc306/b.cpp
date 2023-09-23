#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  vector<ll> a(64);
  rep(i,64) cin >> a[i];

  ll res=0LL, two=1LL;
  rep(i,64) {
    if(i!=63) res += two*a[i], two*=2LL;
    else res += two*a[i];
  }
  cout << res << endl;
}