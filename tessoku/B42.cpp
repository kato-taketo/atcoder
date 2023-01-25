#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int n;
  cin >> n;
  vector<pair<ll,ll> > ab(n);
  rep(i,n) cin >> ab[i].first >> ab[i].second;

  ll res1=0,res2=0,res3=0,res4=0;
  
  rep(i,n) {
    ll tmp=ab[i].first+ab[i].second;
    // sei sei
    if(tmp>0) res1+=tmp;
    // hu hu
    else if(tmp<0) res2-=tmp;
    // sei hu
    ll tmp2=ab[i].first-ab[i].second;
    if(tmp2>0) res3+=tmp2;
    // hu sei
    else if(tmp2<0) res4-=tmp2;
  }
  cout << max(res1,(max(res2,max(res3,res4)))) << endl;
}