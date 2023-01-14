#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int n,q;
  cin >> n >> q;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  vector<int> emos(n);
  vector<int> res(q);
  emos[0]=a[0];
  rep2(i,1,n) emos[i]=emos[i-1]+a[i];
  rep(i,q) {
    int l,r;
    cin >> l >> r;
    l--, r--;
    if(l==0) res[i]=emos[r];
    else res[i] = emos[r]-emos[l-1];
  }

  rep(i,q) cout << res[i] << endl;
}