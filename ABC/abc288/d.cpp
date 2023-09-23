#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int n,k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  int q;
  cin >> q;
  vector<int> l(q),r(q);
  rep(i,q) cin >> l[i] >> r[i];

  vector<vector<int> > vec(n,vector<int>(min(10,n), 0));
  

}