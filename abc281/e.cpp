#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007
using P = pair<ll,int>;

ll min_func(ll x, ll y) {
  if(x>y) return y;
  else return x;
}
int main(void) {
  ll n,m,k;
  cin >> n >> m >> k;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  vector<ll> res(n-m+1);
  priority_queue<P, vector<P>, greater<P> > que;
  map<ll,int> mp;  // (value,number)
  map<ll,int> addmp;  // (value,number)

  // 初期化
  for(int i=0; i<m; i++) {
    mp[a[i]]++;
  }
  for(auto& [value, number]:mp) {
    que.push(P(value,number));
  }
  for(int i=0; i<=n-m; i++) {
    ll tmp=0,used=0;
    bool key1=false,key2=false;
    vector<P> tmpp;
    while(1) {
      ll value=que.top().first; int num=que.top().second;
      que.pop();
      num += addmp[value]; addmp[value]=0;
      tmp+=value*min_func(num,k-used);
      used+=num;
      if(i!=0) {
        if(value==a[i]) num--, key1=true;
        if(value==a[i+m]) num++, key2=true;
        tmpp.push_back(P(value,num));
      }
      if(used>=k) break;
      printf("value = %lld\n", value);
    }
    for(i=0; i<tmpp.size(); i++) {
      if(tmpp[i].second==0) continue;
      else que.push(tmpp[i]);
    }
    tmpp.erase();
    if(key1==false) addmp[a[i]]--;
    if(key2==false) addmp[a[i+m]]++;
    res[i]=tmp;
  }
  cout << "Yes" << endl;
  rep(i,n-m+1) cout << res[i] << endl;
  return 0;
}