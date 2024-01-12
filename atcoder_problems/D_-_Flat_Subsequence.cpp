// 14:30 ~ 14:53

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

ll N,K,res;
vector<ll> A,dp;
map<ll,ll> mp;

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
        dat[pos] = max(dat[pos*2],dat[pos*2+1]);
      }
    }
    long long query_(int l,int r, int a, int b, int u) {
      if(l <= a && b <= r) return dat[u];
      if(r <= a || b <= l) return -(1LL << 60);
      long long v1 = query_(l, r, a, (a+b) >> 1, u*2);
      long long v2 = query_(l, r, (a+b) >> 1, b, u*2+1);
      return max(v1, v2);
    }
    long long query(int l, int r) {
      return query_(l, r, 0, size_, 1);
    }
  };
int main(void) {
  cin >> N >> K;
  A.resize(N);
  rep(i,N) cin >> A[i];

  RangeMax rm;
  rm.init(300005);

  dp.resize(N,0);
  rep(i,N) {
    int l,r;
    l = max(0LL,A[i]-K);
    r = min(A[i]+K, 300000LL);
    dp[i] = rm.query(l, r+1)+1;
    rm.update(A[i], dp[i]);
  }
  res = 0;
  rep(i,N) res = max(res, dp[i]);
  cout << res << endl;
}