#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007
#define inf 2e8

int main(void) {
  int n;
  cin >> n;
  vector<int> a(n+1), b(n+1);
  rep2(i,2,n+1) cin >> a[i];
  rep2(i,3,n+1) cin >> b[i];

  vector<int> res(n+1,inf);
  res[1]=0;
  rep2(i,2,n+1) {
    if(i-1>=1) res[i] = min(res[i], res[i-1]+a[i]);
    if(i-2>=1) res[i] = min(res[i], res[i-2]+b[i]);
  }

  cout << res[n] << endl;
}