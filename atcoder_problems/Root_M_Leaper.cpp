// AC

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int N,M;
vector<pair<int,int> > move_xy;
vector<vector<int> > vec;
queue<pair<int,int> > que;
int cx[4] = {1, 1, -1, -1};
int cy[4] = {1, -1, 1, -1};

bool check(int x, int y) {
  if(x>=0&&x<N&&y>=0&&y<N) return true;
  else return false;
}
void func(int x, int y) {
  int nx,ny;
  rep(i,move_xy.size()) {
    rep(j,4) {
      nx = x + move_xy[i].first*cx[j];
      ny = y + move_xy[i].second*cy[j];
      if(check(nx,ny) && vec[nx][ny]==-1) vec[nx][ny]=vec[x][y]+1, func(nx,ny);
    }
    rep(j,4) {
      nx = x + move_xy[i].second*cx[j];
      ny = y + move_xy[i].first*cy[j];
      if(check(nx,ny) && vec[nx][ny]==-1) vec[nx][ny]=vec[x][y]+1, func(nx,ny);
    }
  }
}
int main(void) {
  cin >> N >> M;

  // make square vec
  map<int,int> mp;
  rep(i,1001) mp[i*i] = i;

  // make move (x,y) | x <= y
  //vector<pair<int,int> > move_xy;
  for(int i=0; 2*i*i<=M ; i++) {
    if(mp.count(M-i*i)!=0) move_xy.push_back(make_pair(i,mp[M-i*i]));
  }
  //rep(i,move_xy.size()) {
  //  printf("(x,y) = (%d,%d)\n", move_xy[i].first, move_xy[i].second);
  //}

  // search from (0,0)
  vec.resize(N, vector<int>(N,-1));
  vec[0][0] = 0;
  //func(0,0);

  que.push(make_pair(0,0));
  while(!que.empty()) {
    int nx,ny;
    nx = que.front().first; ny = que.front().second;
    que.pop();
    int nex, ney;
    rep(i,move_xy.size()) {
      rep(j,4) {
        nex = nx + move_xy[i].first*cx[j];
        ney = ny + move_xy[i].second*cy[j];
        if(check(nex,ney) && vec[nex][ney]==-1) vec[nex][ney]=vec[nx][ny]+1, que.push(make_pair(nex,ney));
        nex = nx + move_xy[i].second*cx[j];
        ney = ny + move_xy[i].first*cy[j];
        if(check(nex,ney) && vec[nex][ney]==-1) vec[nex][ney]=vec[nx][ny]+1, que.push(make_pair(nex,ney));
      }
    }
  }

  // output
  rep(i,N) {
    rep(j,N) {
      if(j!=N-1) printf("%d ", vec[i][j]);
      else printf("%d\n", vec[i][j]);
    }
  }
}