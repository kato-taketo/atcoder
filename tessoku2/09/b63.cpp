#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int R,C;
int sy, sx, gy, gx;
vector<vector<int> > dist;
vector<string> c;
int mx[] = {1,0,-1,0};
int my[] = {0,-1,0,1};
int main(void) {
  cin >> R >> C;
  cin >> sy >> sx >> gy >> gx;
  c.resize(R);
  rep(i,R) cin >> c[i];
  dist.resize(R);
  rep(i,R) dist[i].resize(C,-1);

  // bfs
  queue<pair<int,int> > que;
  que.push(make_pair(--sy, --sx));
  dist[sy][sx]=0;
  gy--, gx--;
  while(!que.empty()) {
    pair<int,int> nyx = que.front();
    que.pop();
    for (int i=0; i<4; i++) {
      pair<int,int> nnyx = make_pair(nyx.first+my[i], nyx.second+mx[i]);
      if(nnyx.first>=0 && nnyx.first<R) {
        if(nnyx.second>=0 && nnyx.second<C) {
          if(c[nnyx.first][nnyx.second]=='.') {
            if(dist[nnyx.first][nnyx.second]!=-1) 
            continue;
            else {
              dist[nnyx.first][nnyx.second] = dist[nyx.first][nyx.second]+1;
              que.push(nnyx);
            }
          }
        }
      }
    }
  }
  cout << dist[gy][gx] << endl;
}