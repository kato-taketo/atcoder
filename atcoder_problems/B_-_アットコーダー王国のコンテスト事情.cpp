#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int N;
vector<ll> T;
ll res=1,res2=0,pre=0;
map<ll,ll> mp;  // value, number
vector<ll> rui;
int main(void) {
  cin >> N;
  T.resize(N);
  rep(i,N) cin >> T[i];

  // 小さい順に解けば良い, Ti,Tjが同じ値の時には、順不同となる
  // 同じ値が存在するなら、同じ値の数の累積となる
  rui.resize(N+1);  // rui[x] := x!
  rui[0]=1;
  rep2(i,1,N+1) {
    rui[i] = (rui[i-1] * i)%MOD;
  }
  sort(T.begin(),T.end());
  rep(i,N) mp[T[i]]++;
  for(const auto& pair: mp) {
    res *= rui[pair.second];
    res %= MOD;
  }
  rep(i,N) {
    res2 += pre + T[i];
    pre = pre + T[i];
  }
  cout << res2 << endl;
  cout << res << endl;
}