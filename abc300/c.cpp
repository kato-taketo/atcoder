#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int movex[4]={1,1,-1,-1};
int movey[4]={1,-1,1,-1};
int main(void) {
  int h,w;
  cin >> h >> w;
  vector<string> C(h);
  rep(i,h) cin >> C[i];
  int n=min(h,w);
  vector<int> res(n, 0);

  rep(i,h) {
    rep(j,w) {
      if(C[i][j]=='.') continue;
      int size=0;
      //if(i==1&j==1) cout << "i==1,j==1" << endl;
      rep2(k,1,n) {
        bool key=true;
        rep(l,4) {
          int x=i+movex[l]*k, y=j+movey[l]*k;
          //if(i==1&j==1) cout << "x" << x << "y" << y << endl;
          if(x>=0 && x<h && y>=0 && y<w) {
            if(C[x][y]!='#') key=false;
          } else {
            key=false;
          }
        }
        if(key) size++;
        else break;
      }
      //if(i==1&j==1) cout << "size " << size << endl;
      if(size>0) res[size-1]++;
    }
  }
  rep(i,n) {
    if(i==0) cout << res[i];
    else cout << " " << res[i];
  }
  cout << endl;
}