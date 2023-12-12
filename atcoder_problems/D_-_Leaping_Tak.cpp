#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007
#define mod 998244353
class RangeMax {
  public:
    int size_=1;
    vector<long long> dat;
    void init(int sz) {
      while(size_<=sz) size_*=2;
      dat.resize(size_*2, 0);
    }
    void update(int pos,long long x) {
      pos += size_;
      dat[pos]=x;
      while(pos>=2) {
        pos >>=1;
        dat[pos] = (dat[pos*2]+dat[pos*2+1])%mod;
      }
    }
    long long query_(int l,int r, int a, int b, int u) {
      if(l <= a && b <= r) return dat[u];
      if(r <= a || b <= l) return 0;
      long long v1 = query_(l, r, a, (a+b) >> 1, u*2);
      long long v2 = query_(l, r, (a+b) >> 1, b, u*2+1);
      return (v1+v2)%mod;
    }
    long long query(int l, int r) {
      return query_(l, r, 0, size_, 1);
    }
  };
int N,K;
vector<int> L,R;
vector<ll> dp;
RangeMax rm;
int sum_of(int l, int r) {
  if(l<=0) l=1;
  else if(l>N) return 0;
  if(r>N) r=N+1;
  else if(r<=0) return 0;
  return rm.query(l,r);
}


int main(void) {
  cin >> N >> K;
  L.resize(K);
  R.resize(K);
  rep(i,K) cin >> L[i] >> R[i];

  dp.resize(N+1,0);
  dp[1]=1;
  
  rm.init(N);
  rm.update(1,1);
  for(int i=2; i<=N; i++) {
    rep(j,K) {
      dp[i] += sum_of(i-R[j],i-L[j]+1);
      dp[i] %= mod;
      rm.update(i,dp[i]);
      //cout << "dp[" << i << "] = " << dp[i] << endl;
    }
  }

  cout << dp[N] << endl;
}