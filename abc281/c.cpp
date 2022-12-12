#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int n;
  ll t;
  cin >> n >> t;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  ll sum=0;
  rep(i,n) sum+=a[i];
  t %= sum;
  rep(i,n) {
    if(t>a[i]) t-=a[i];
    else {
      printf("%d %d\n", i+1, int(t));
      return 0;
    }
  }
}