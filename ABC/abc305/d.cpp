#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  ll N;
  cin >> N;
  vector<ll> A(N);
  rep(i,N) cin >> A[i];
  ll Q;
  cin >> Q;
  vector<ll> l(Q),r(Q);
  rep(i,Q) cin >> l[i] >> r[i];
  vector<ll> ress(Q);

  vector<ll> sleep(N,0);
  for(int i=2; i<N; i++) {
    if(i%2==0) sleep[i] = sleep[i-1] + A[i]-A[i-1];
    else sleep[i] = sleep[i-1];
  }
  
  rep(i,Q) {
    int mae,at;
    ll res=0;
    mae = lower_bound(A.begin(),A.end(),l[i])-A.begin();
    at = lower_bound(A.begin(),A.end(),r[i]) - A.begin();
    res = sleep[at]-sleep[mae];
    if(mae%2==0) res += A[mae]-l[i];
    if(at%2==0) res -= A[at]-r[i];
    ress[i]=res;
  }

  rep(i,Q) cout << ress[i] << endl;
}