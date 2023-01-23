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

  vector<ll> a(n+1);
  a[1]=1; a[2]=1;
  for(int i=3; i<=n; i++) {
    a[i] = a[i-1]+a[i-2];
    a[i] %= MOD;
  }
  cout << a[n] << endl;
}