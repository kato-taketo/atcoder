#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int w,h;
  cin >> w >> h;
  int n;
  cin >> n;
  vector<int> p(n),q(n);
  rep(i,n) cin >> p[i] >> q[i];
  ll A;
  cin >> A;
  vector<int> a(A+1);
  a[A]=w;
  rep(i,A) cin >> a[i];
  ll B;
  cin >> B;
  vector<int> b(B+1);
  b[B]=h;
  rep(i,B) cin >> b[i];

  map<pair<int,int>,int> mp;  //map[piece]=cnt数
  ll pieces=0;
  rep(i,n) {
    int x,y;
    x = lower_bound(a.begin(),a.end(),p[i]) - a.begin();
    y = lower_bound(b.begin(),b.end(),q[i]) - b.begin();
    pair<int,int> p=make_pair(x,y);
    if(mp[p]>0) mp[p]++;
    else pieces++, mp[p]=1;
  }
  int min_v=n,max_v=0;
  if(pieces!=(A+1)*(B+1)) min_v=0;
  for(auto iter=mp.begin(); iter != mp.end(); iter++) {
    if(min_v>iter->second) min_v=iter->second;
    if(max_v<iter->second) max_v=iter->second;
  }
  cout << min_v << " " << max_v << endl;
}