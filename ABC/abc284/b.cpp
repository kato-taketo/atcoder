#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int t;
  cin >> t;

  vector<int> res(t);
  rep(i,t) {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(j,n) cin >> a[j];
    int cnt=0;
    rep(j,n) if(a[j]%2!=0) cnt++;
    res[i]=cnt;
  }

  rep(i,t) cout << res[i] << endl;
}