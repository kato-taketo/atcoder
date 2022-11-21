#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int x,y,z;
  cin >> x >> y >> z;

  // 0 - x の間にYがない場合
  if(x>0 && (x<y||y<0)) {
    cout << x << endl; return 0;
  } else if(x<0 && (y<x||y>0)) {
    cout << -x << endl; return 0;
  }
  // 0 - x の間にyがある場合
  if(x>0 && y>0 && y<x) {
    // z を取れる
    if(y>z) {
      if(z<0) cout << -z*2+x << endl;
      else cout << x << endl;
    } else {
      cout << -1 << endl;
    }
    return 0;
  } else if(x<0 && x<y && y<0) {
    if(y<z) {
      if(z>0) cout << z*2-x << endl;
      else cout << -x << endl;
    } else {
      cout << -1 << endl;
    }
    return 0;
  }

}