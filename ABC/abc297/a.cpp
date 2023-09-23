#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int n,d;
  cin >> n >> d;
  vector<int> t(n);
  rep(i,n) cin >> t[i];

  rep(i,n) {
    if(i+1<n&&(t[i+1]-t[i])<=d) {
      cout << t[i+1] << endl; return 0;
    }
  }
  cout << -1 << endl;
}