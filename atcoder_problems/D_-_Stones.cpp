

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int N,K;
  cin >> N >> K;
  vector<int> A(K);
  rep(i,K) cin >> A[i];

  //// 貪欲砲?? まさかの貪欲ではない???
  //int t_sum=0, a_sum=0;
  //for(int i=0; N>0 ; i++) {
  //  int index;
  //  index = upper_bound(A.begin(), A.end(), N)-A.begin();
  //  index--;
  //  N -= A[index];
  //  if(i%2==0) t_sum += A[index];
  //  else a_sum += A[index];
  //}
//
  //cout << t_sum << endl;

  // dp で行う -> 高橋君目線になって、青木君の最大化にならない
  // dp[i][j] := i番目の動作後で、残りのNがjとなる
}