#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007
#define inf 2e9

int mx[4]={1,0,-1,0};
int my[4]={0,1,0,-1};
int main(void) {
  int r,c;
  cin >> r >> c;
  int sy,sx,gy,gx;
  cin >> sy >> sx >> gy >> gx;
  sy--; sx--; gy--; gx--;
  vector<vector<char> > vec(r,vector<char>(c));
  rep(i,r) rep(j,c) cin >> vec[i][j];

  queue<pair<int,int> > que;
  vector<vector<int> > res(r,vector<int>(c,inf));
  res[sy][sx]=0;
  que.push(make_pair(sy,sx));
  while(!que.empty()) {
    int ny=que.front().first, nx=que.front().second;
    int tmpy,tmpx;
    int cost = res[ny][nx];
    que.pop();
    rep(i,4) {
      tmpy = ny + my[i];
      tmpx = nx + mx[i];
      if(tmpy<=0||tmpy>=r-1||tmpx<=0||tmpx>=c-1) continue;
      if(vec[tmpy][tmpx]=='#') continue;
      if(res[tmpy][tmpx]>cost+1) {
        res[tmpy][tmpx] = cost+1;
        que.push(make_pair(tmpy,tmpx));
      }
    }
  }
  cout << res[gy][gx] << endl;
}