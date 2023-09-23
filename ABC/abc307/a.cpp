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
  vector<int> a(7*n);
  rep(i,7*n) cin >> a[i];
  int cnt=0, res=0;
  rep(i,7*n) {
    res += a[i]; cnt++;
    if(cnt%7==0) {
      cout << res << " ";
      res=0; cnt=0;
    }
  }
  cout << endl;
}