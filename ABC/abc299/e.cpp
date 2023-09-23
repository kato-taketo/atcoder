#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007
ll N,M;
ll A[2009],B[2009],C[2009];
//グラフ、最短距離
ll dist[2009],dist1[2009],distn[2009];
vector<pair<ll,int> > G[2009];
void dijkstra(int stt) {
  priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > Q;
  for(int i=1;i<=N;i++) dist[i]=(1LL<<60);
  dist[stt]=0;
  Q.push(make_pair(0,stt));
  while(!(Q.empty())) {
    int pos=Q.top().second; Q.pop();
    rep(i,G[pos].size()) {
      int to = G[pos][i].first;
      ll cost = G[pos][i].second;
      if(dist[to]>dist[pos]+cost) {
        dist[to]=dist[pos]+cost;
        Q.push(make_pair(dist[to],to));
      }
    }
  }
}
int main(void) {
  cin >> N >> M;
  //vector<vector<int> > graph(N);
  vector<int> color(N+1,-1); // o = white, 1 = black
  rep(i,M) {
    int u,v;
    cin >> u >> v;
    G[u].push_back(make_pair(v,1));
    G[v].push_back(make_pair(u,1));
  }
  int k;
  cin >> k;
  if(k==0) {
    cout << "Yes" << endl; 
    rep(i,N) cout << "1";
    cout << endl;
  } else {
    vector<vector<int> > tmp(k); // blackの候補
    rep(i,k) {
      int p,d;
      cin >> p >> d;

      //dijkstra
      dijkstra(p);
      //rep2(x,1,N+1) cout << dist[x] << " ";
      //cout << endl;
      rep2(j,1,N+1) {
        if(dist[j]<d) { // white
          if(color[j]==1) {
            cout << "No" << endl; return 0;
          } else {
            color[j]=0;
          }
        } else if(dist[j]==d) {  // black
          if(color[j]==0) {
            cout << "No" << endl; return 0;
          } else {
            tmp[i].push_back(j);
          }
        }
      }
    }

    // black
    rep(i,k) {
      bool key=false;
      rep(j,tmp[i].size()) {
        int index = tmp[i][j];
        if(color[index]==0) continue;
        else key=true, color[index]=1;
      }
      if(!key) {
        cout << "No" << endl; return 0;
      }
    }
    cout << "Yes" << endl;
    rep2(i,1,N+1) {
      if(color[i]==-1) cout << 0;
      else cout << color[i];
    }
    cout << endl;
  }
}