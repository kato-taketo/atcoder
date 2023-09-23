#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int H,W;
  cin >> H >> W;
  vector<string> S(H);
  rep(i,H) cin >> S[i];

  //vector<int> cnt(H,0), cnt2(W,0);
  int a=501,b=-1,c=501,d=-1;
  rep(i,H) {
    rep(j,W) if(S[i][j]=='#') {
      if(i<c) c=i;
      if(i>d) d=i;
      if(j>b) b=j;
      if(j<a) a=j;
    }
  }
  for(int i=c; i<=d; i++) {
    for(int j=a; j<=b; j++) if(S[i][j]=='.') {
      cout << i+1 << " " << j+1 << endl; 
      return 0;
      }
  }
}