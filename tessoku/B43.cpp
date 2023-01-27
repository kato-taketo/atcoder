#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int n,m;
  cin >> n >> m;
  vector<int> a(m);
  rep(i,m) cin >> a[i];

  vector<int> miss(n,0);
  rep(i,m) miss[a[i]-1]++;
  rep(i,n) cout << m-miss[i] << endl;
}