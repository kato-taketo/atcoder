// 19:21~20:02

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

ll N,M;
vector<pair<ll,ll> > ba;
ll tmp=-1, cnt=0;
int main(void) {
  cin >> N >> M;
  //a.resize(M), b.resize(M);
  ba.resize(M);
  rep(i,M) cin >> ba[i].second >> ba[i].first;

  sort(ba.begin(), ba.end());
  rep(i,M) {
    if(tmp==-1) tmp = ba[i].first-1, cnt++;
    else if(tmp>=ba[i].second) continue;
    else tmp = ba[i].first-1, cnt++;
  }
  cout << cnt << endl;
}