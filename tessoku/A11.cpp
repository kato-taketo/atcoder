#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int n,x;
  cin >> n >> x;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  int it=lower_bound(a.begin(), a.end(), x)-a.begin();
  cout << it+1 << endl;
}