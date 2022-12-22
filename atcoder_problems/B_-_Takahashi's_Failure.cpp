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
  vector<int> b(k);
  rep(i,k) cin >> b[i];

  int max_value=-1;
  rep(i,n) if(max_value<a[i]) max_value=a[i];
  bool key=false;
  rep(i,n) {
    if(a[i]==max_value) {
      rep(j,k) {
        if(i==b[j]-1) key=true;
      }
    }
  }
  if(key) cout << "Yes" << endl;
  else cout << "No" << endl;
}