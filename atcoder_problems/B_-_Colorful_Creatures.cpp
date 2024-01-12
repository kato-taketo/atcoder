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
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  vector<bool> ok(n,true);
  sort(a.begin(), a.end());
  rep(i,n) {
    if(i!=n-1) {
      if(a[i]*2<a[i+1]) ok[i]=false;
      a[i+1] += a[i];
    }
  }
  int cnt=0;
  for(int i=n-1; i>=0; i--) {
    if(!ok[i]) {
      cout << cnt << endl; return 0;
    }
    cnt++;
  }
  cout << cnt << endl;
}