#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int h,w;
  cin >> h >> w;
  vector<string> A(h), B(h);
  rep(i,h) cin >> A[i];
  rep(i,h) cin >> B[i];

  // investigate
  rep(i,h) {
    rep(j,w) {
      // start (i,j)
      bool key=true;
      //if(i==2&&j==1) cout <<"i==2,j==1" << endl;
        rep(k,h) {
          rep(l,w) {
            int x=(i+k)%h, y=(j+l)%w;
            if(A[x][y]!=B[k][l]) {key=false; break;}
          }
          if(!key) break;
        }
        if(key) {cout << "Yes" << endl; return 0;}
    }
  }
  cout << "No" << endl;
}