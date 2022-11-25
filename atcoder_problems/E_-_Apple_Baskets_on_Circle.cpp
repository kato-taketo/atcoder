// took long time...

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

using P = pair<ll,int>;
int main(void) {
  ll N,K;
  cin >> N >> K;
  vector<ll> A(N);
  rep(i,N) cin >> A[i];

  // 貪欲砲?
  vector<bool> zero(N,false);  // zero[i] := A[i]=0
  int cnt=0;  // cnt := num(zero[i]=true)
  priority_queue<P, vector<P>, greater<P> > que;
  rep(i,N) {
    if(A[i]==0) zero[i]=true, cnt++;
    else que.push(P(A[i],i));
  }
  int index=0;
  while(1) {
    ll value=que.top().first;


  }
}