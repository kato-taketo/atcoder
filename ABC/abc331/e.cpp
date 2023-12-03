#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007
#define inf 2e9
bool compare(int a, int b) {
    return a > b; // 大きい順にソートするための条件
}
int main(void) {
  int n,m,l;
  cin >> n >> m >> l;
  vector<ll> a(n),b(m);
  rep(i,n) cin >> a[i];
  rep(i,m) cin >> b[i];
  vector<ll> c(l),d(l);
  rep(i,l) cin >> c[i] >> d[i];

  map<pair<int,int>, bool> mp;  // ci, di, のペアを格納
  vector<ll> value;
  vector<pair<ll,ll> > aa(n), bb(m);
  vector<pair<ll, pair<ll,ll> > > vec_pair;
  rep(i,l) mp[make_pair(c[i],d[i])]=true;
  rep(i,n) aa[i] = make_pair(a[i],i+1);
  rep(i,m) bb[i] = make_pair(b[i],i+1);
  sort(aa.rbegin(),aa.rend());
  sort(bb.rbegin(),bb.rend());
  int x=0,y=0;
  while(x<n&&y<m) {
    pair<int,int> P=make_pair(aa[x].second,bb[y].second);
    ll value = aa[x].first+bb[y].first;
    if(!mp[P]) {
      cout << value << endl; return 0;
    }
    vec_pair.push_back(make_pair(aa[x].first+bb[y].first, make_pair(x+1,y+1)));
    ll dif_x=inf,dif_y=inf;
    if(x+1<n) dif_x = aa[x].first-aa[x+1].first;
    if(y+1<m) dif_y = bb[y].first-bb[y+1].first;
    if(dif_x>dif_y) y++;
    else x++;
  }
  
}