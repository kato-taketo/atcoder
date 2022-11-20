// AC

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

bool f(char x) {
  if(x == 'T' || x == 'H') return true;
  else return false;
}
int main(void) {
  int N, S;
  cin >> N >> S;
  vector<int> a(N+1),b(N+1);
  rep2(i,1,N+1) cin >> a[i] >> b[i];

  // dp
  // dp[i][j] := iコメまで見た時に総和がjを取るときiコメの値H,T
  vector<vector<char> > dp(N+1, vector<char>(S+1));
  dp[0][0]='H';
  for(int i=1; i<=N; i++) {
    for(int j=0; j<=S; j++) {
      if(j-a[i]>=0 && f(dp[i-1][j-a[i]])) dp[i][j]='H';
      else if(j-b[i]>=0 && f(dp[i-1][j-b[i]])) dp[i][j]='T';
    }
  }

  // output
  if(f(dp[N][S])) {
    cout << "Yes" << endl;
    string str="";
    int i=N, j=S;
    while(i>=1) {
      str = dp[i][j] + str;
      if(dp[i][j]=='T') j-=b[i];
      else if(dp[i][j]=='H') j-= a[i];
      i--;
      
    }
    cout << str << endl;
    return 0;
  }
  cout << "No" << endl;
}