#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int k,g,m;
  cin >> k >> g >> m;
  int gl=0,ml=0;
  rep(i,k) {
    if(gl==g) gl=0;
    else if(ml==0) ml=m;
    else {
      gl += ml;
      ml = 0;
      if(gl>g) ml += gl-g;
      gl = min(gl,g);
    }
  }
  cout << gl << " " << ml << endl;
}