#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int n,k,q;
  cin >> n >> k >> q;

  vector<bool> used(n,false);  // b1,b2,...,bkで用いられる
  ll used_min=0;
  ll res=0;
  priority_queue< ll, std::vector<ll>, std::greater<ll> > use_pq;
  priority_queue<ll> nuse_pq;
  map<int,int> use;  // use[index] = 0 or 1
  rep(i,k) use_pq.push(0);
  rep(i,n-k) nuse_pq.push(0);
  rep(i,k) use[i]=1;
  rep(i,q) {
    ll x,y;
    cin >> x >> y;
    x--;
    if(used[x]==false) {
      if(used_min<y){
        res = res + y -used_min, used[x]=true;
        if(k!-0) k--; 
        if(k==0) used_min = min(used_min, )
      } 
    }
  }
}