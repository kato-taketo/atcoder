#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  ll h,w,k;
  cin >> h >> w >> k;

  if(k==1) {
    cout << 1 << endl; return 0;
  }
  rep2(i,1,h+1) {
    rep2(j,1,w+1) {
      // i * jの長方形がスコア
      ll score=i*j;
      if(k>i*j) continue;
      
    }
  }
}