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
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  sort(a.begin(), a.end());
  ll pre=a[0],tmp=0;
  ll res=0;
  rep(i,n) {
    if(pre==a[i]) tmp++;
    else if(pre!=a[i]) res += tmp*(tmp-1)/2, tmp=1, pre=a[i];
    //cout << i << " " << tmp << " " << res << endl;
  }
  if(tmp>1) res += tmp*(tmp-1)/2;
  cout << res << endl;
}