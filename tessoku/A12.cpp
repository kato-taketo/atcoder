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

  int left=0, right=1e9;  // left:=k枚以上印刷されてない, right:=k枚以上印刷されている

  while(right-left>1) {
    int middle=left+(right-left)/2;
    ll tmp=0;
    rep(i,n) tmp += middle/a[i];
    if(tmp >= k) right=middle;
    else left = middle;
  }

  cout << right << endl;
}