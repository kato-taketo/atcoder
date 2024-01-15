#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
 int N,res;
 cin >> N;
 vector<int> A(N), L(N), R(N);
 rep(i,N) cin >> A[i];

  rep(i,N) {
    if(i==0) {
      L[i]=1;
    } else {
      if(L[i-1]+1<=A[i]) L[i]=L[i-1]+1;
      else L[i]=A[i];
    }
  }
  for(int i=N-1; i>=0; i--) {
    if(i==N-1) R[i]=1;
    else {
      if(R[i+1]+1<=A[i]) R[i]=R[i+1]+1;
      else R[i]=A[i];
    }
  }
  res=0;
  rep(i,N) {
    res = max(res, min(L[i],R[i]));
  }
  cout << res << endl;
}