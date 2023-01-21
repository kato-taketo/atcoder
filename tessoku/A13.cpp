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
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  ll res=0;
  rep(i,n) {
    // one pair is a[i]
    int it = upper_bound(a.begin()+i, a.end(), a[i]+k)-a.begin();
    //printf("a[%d] = %d, it = %d, cnt=%d\n", i, a[i], it, it-i-1);
    res += (it-i-1);
  }

  cout << res << endl;
}