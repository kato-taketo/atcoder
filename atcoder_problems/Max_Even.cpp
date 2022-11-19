// AC

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i,N) cin >> A[i];

  sort(A.begin(), A.end());
  vector<int> odd, even;
  rep(i,N) {
    if(A[i]%2==0) even.push_back(A[i]); 
    else odd.push_back(A[i]);
  }
  int e_len=even.size(), o_len=odd.size();
  if(e_len<2 && o_len<2) {
    cout << -1 << endl; return 0;
  } else {
    int res = 0;
    if(e_len>=2) res = max(res, even[e_len-1]+even[e_len-2]);
    if(o_len>=2) res = max(res, odd[o_len-1]+odd[o_len-2]);
    cout << res << endl; return 0;
  }

}