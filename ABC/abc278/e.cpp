#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int H,W,N,h,w;
  cin >> H >> W >> N >> h >> w;
  vector<vector<int> > A(H, vector<int>(W));
  rep(i,H) rep(j,W) cin >> A[i][j];

  // make number
  vector<int> cnt(N+1,0);
  set<int> sets;
  int all_num;
  rep(i,H) {
    rep(j,W) {
      cnt[A[i][j]]++;
      sets.insert(A[i][j]);
    }
  }
  all_num=sets.size();

  // search
  for(int i=0; i<=H-h; i++) {
    for(int j=0; j<=W-w; j++) {
      vector<int> tmp(N+1,0);
      int res=all_num;
      for(int k=0; k<h; k++) {
        for(int l=0; l<w; l++) {
          tmp[A[i+k][j+l]]++;
        }
      }
      rep(i,N+1) {
        if(tmp[i]==0) continue;
        if(tmp[i]==cnt[i]) res--;
      }
      if(j!=W-w) printf("%d ", res);
      else printf("%d\n", res);
    }
  }
}