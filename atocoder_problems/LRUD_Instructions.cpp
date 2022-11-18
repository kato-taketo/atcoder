#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007
using P = pair<int,int>;

int main(void) {
  int H,W,rs,cs;
  cin >> H >> W >> rs >> cs;
  rs--; cs--;
  int N;
  cin >> N;
  vector<P> rc(N);
  rep(i,N) cin >> rc[i].first >> rc[i].second;
  rep(i,N) rc[i].first--, rc[i].second--;
  int Q;
  cin >> Q;
  vector<pair<char,int> > dl(Q);
  rep(i,Q) cin >> dl[i].first >> dl[i].second;

  // make # indexs vector
  vector<vector<int> > tate(W),yoko(H),in_tate(W),in_yoko(H);
  rep(i,N) {
    yoko[rc[i].first].push_back(rc[i].second);
    tate[rc[i].second].push_back(rc[i].first);
    in_yoko[rc[i].first].push_back(rc[i].second*(-1));
    in_tate[rc[i].second].push_back(rc[i].first*(-1));
  }
  rep(i,W) sort(tate[i].begin(), tate[i].end());
  rep(i,H) sort(yoko[i].begin(), yoko[i].end());
  rep(i,W) sort(in_tate[i].begin(),in_tate[i].end());
  rep(i,H) sort(in_yoko[i].begin(),in_yoko[i].end());

  // binary search
  rep(i,Q) {
    int index=-1;
    if(dl[i].first=='R') {
      if(yoko[rs].size() != 0) index = lower_bound(yoko[rs].begin(), yoko[rs].end(), cs) - yoko[rs].begin();
      if(index==(int)yoko[rs].size() || index==-1) cs = min(cs + dl[i].second, W-1);
      else cs = min(cs+dl[i].second, yoko[rs][index]-1);
    } else if(dl[i].first=='D') {
      if(tate[cs].size() != 0) index = lower_bound(tate[cs].begin(), tate[cs].end(), rs) - tate[cs].begin();
      if(index==(int)tate[cs].size() || index==-1) rs = min(rs+dl[i].second,H-1);
      else rs=min(rs+dl[i].second, tate[cs][index]-1);
    } else if(dl[i].first=='L') {
      if(in_yoko[rs].size() != 0) index = lower_bound(in_yoko[rs].begin(), in_yoko[rs].end(), -cs) - in_yoko[rs].begin();
      if(index==(int)in_yoko[rs].size() || index==-1) cs = max(cs-dl[i].second,0);
      else cs=max(cs-dl[i].second,(-1)*(in_yoko[rs][index]-1));
    } else {
      if(in_tate[cs].size() != 0) index = lower_bound(in_tate[cs].begin(), in_tate[cs].end(), -rs) - in_tate[cs].begin();
      if(index==(int)in_tate[cs].size() || index==-1) rs = max(rs-dl[i].second,0);
      else rs=max(rs-dl[i].second, (-1)*(in_tate[cs][index]-1));
    }
    printf("%d %d\n", rs+1,cs+1);
  }
}