#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
//#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007
typedef pair<ll,ll> P;
#define REP(i,n) for(ll i = 0; i<(ll)(n); i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define pb push_back
#define MOD 1000000007 //998244353
#define PI 3.141592653
#define INF 100000000000000 //14
//cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);

int N,M;
vector<vector<pair<ll,bool> > > conn;
vector<ll> checked; // dfs参照
vector<ll> orderList; // dfsで通った順番に登録していく
vector<ll> groupList; // 各nodeにgroupをつけていく
ll cnt = 0;
void dfs(ll now, ll prev) { 
    // 帰り道に通った順に番号をつける, 重複が起きないように行きにcheckedする
    // orderList[i]はi番のnode
    checked[now]=1;
    for (auto v : conn[now]) {
        // すでに見たところ、親、false(逆向きの枝)
        if (checked[v.first]==1 || v.first==prev || v.second==false) continue;
        dfs(v.first,now);
    }
    // 通った順に番号をつける
    orderList[cnt]=now; cnt++;
    return;
}
void dfs2(ll now, ll group) {
    // nowが今見るnode, groupが登録するgroup番号
    groupList[now]=group;
    for (auto v : conn[now]) {
        // すでにgroup番号が付いてるnode、逆向きでない枝はスルー
        if (groupList[v.first]!=-1 || v.second==true) continue;
        // nowから行けるところに、同じgroup番号をつける
        dfs2(v.first,group);
    }
    return;
}
int main(void) {
  cin >> N >> M;
  conn.resize(N);
  checked.resize(N,0);
  orderList.resize(N,-1);
  groupList.resize(N,-1);
  ll cnt = 0;
  vector<int> u(M),v(M);
  rep(i,M) cin >> u[i] >> v[i];
  REP(i,M) {
        // trueで登録するのは元の向きの枝
        // falseは逆向きの枝(dfs2で用いる)
        conn[u[i]].pb(make_pair(v[i],true));
        conn[v[i]].pb(make_pair(u[i],false));
    }
  REP(i,N) if (!checked[i]) {
        // 連結グラフでない場合には開始点が複数個必要
        dfs(i,-1);
  }
  FORD(i,N-1,0) {
      // -1のときはそれ以降も全部-1なのでbreak
      // 単独のnodeがある場合は、orderListにn個全部が登録されないので、あまりの枠が出る
      if (orderList[i]==-1) break;
      // すでに見たnodeの場合はgroupListにgroup番号が登録されているので、スルー
      if (groupList[orderList[i]]!=-1) continue;
      // 始点となるnodeの番号をグループ番号とする
      dfs2(orderList[i],orderList[i]);
  }
  int K;
  cin >> K;
  vector<int> x(K),y(K);
  rep(i,K) cin >> x[i] >> y[i];
  int Q;
  cin >> Q;
  vector<int> p(Q),q(Q);
  rep(i,Q) cin >> p[i] >> q[i];

  //UnionFind uf(N);
  //uf.init(N);
  //rep(i,M) {
  //  u[i]--; v[i]--;
  //  uf.merge(u[i],v[i]);
  //}
  // 事前check
  bool good=true;
  map<pair<int,int>,int> mp;
  rep(i,K) {
    //x[i]--; y[i]--;
    //if(uf.connected(x[i],y[i])) good=false;
    if(groupList[x[i]]==groupList[y[i]]) good=false;
    pair<int,int> P = make_pair(groupList[x[i]], groupList[y[i]]);
    mp[P]=1;
  }

  rep(i,Q) {
    //p[i]--; q[i]--;
    if(good==false) cout << "No" << endl;
    else {
      //if(uf.connected(p[i],q[i])) cout << "Yes" << endl;
      if(groupList[p[i]]==groupList[q[i]]) cout << "Yes" << endl;
      else {
        pair<int,int> P = make_pair(groupList[p[i]], groupList[q[i]]);
        if(mp[P]==1) cout << "No" << endl;
        else cout << "Yes" << endl;
      }
    }
  }
}