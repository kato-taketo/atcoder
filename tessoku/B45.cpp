#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  vector<ll> a(3);
  rep(i,3) cin >> a[i];

  sort(a.begin(),a.end());
  a[1] += a[0];
  if(a[1]+a[2]==0) cout << "Yes" << endl;
  else cout << "No" << endl;

}