#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007
int h,w,a,b;
int main(void) {
  cin >> h >> w >> a >> b;
  rep(i,h) {
    rep(j,w) {
      if(0<=i && i<b) {
        if(0<=j && j<a) cout << 0;
        else cout << 1;
      } else {
        if(0<=j && j<a) cout << 1;
        else cout << 0;
      }
      if(j==w-1) cout << endl;
    }
  }
}