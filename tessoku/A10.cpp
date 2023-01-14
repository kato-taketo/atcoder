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
  int d;
  cin >> d;


  vector<int> left(n+1,0),right(n+1,0);
  vector<int> res(d);
  left[1]=a[0];
  right[n]=a[n-1];
  rep2(i,1,n) {
    left[i+1] = max(a[i],left[i]);
  }
  for(int i=n-1; i>0; i--) {
    right[i] = max(a[i-1], right[i+1]);
  }
  rep(i,d) {
    int l,r;
    cin >> l >> r;
    res[i] = max(left[l-1],right[r+1]);
  }
  rep(i,d) cout << res[i] << endl;
} 