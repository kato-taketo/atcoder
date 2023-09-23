#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int n,x,y;
  cin >> n >> x >> y;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  // every mountain true or not
  rep(i,n) {
    if(a[i]%5==0 | a[i]%5==1) a[i]=0;
    else a[i]=1;
  }
  // all mountain
  ll res=0;
  rep(i,n) res ^= a[i];
  if(res==0) cout << "Second" << endl;
  else cout << "First" << endl;
}