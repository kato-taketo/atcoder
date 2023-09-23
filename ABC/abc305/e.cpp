#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int N,M,K;
  cin >> N >> M >> K;
  vector<vector<int> > graph(N);
  vector<int> heavy(N,-1);
  //map<int,int> heavy_mp;
  //vecot<pair<int,int> > hp(K);
  priority_queue<pair<int,int> > pq;
  rep(i,M) {
    int a,b; cin >> a >> b; a--; b--;
    graph[a].push_back(b); graph[b].push_back(a);
  }
  rep(i,K) {
    int p,h; cin >> p >> h; p--;
    pq.push(make_pair(h,p));
    //hp[i] = make_pair(h,p);
    heavy[p]=h;
    //heavy_mp[p]=h;
  }
  //sort(hp.begin(),hp.end());

  while(!pq.empty()) {
    pair<int,int> P = pq.top();
    int h=P.first, p=P.second;
    pq.pop();
    for(auto np: graph[p]) {
      if(heavy[np]<h-1) heavy[np]=h-1, pq.push(make_pair(h-1,np));
    }
  }
  int cnt=0;
  rep(i,N) if(heavy[i]>-1) cnt++;
  cout << cnt << endl;
  rep(i,N) if(heavy[i]>-1) cout << i+1 << " ";
  cout << endl;
}