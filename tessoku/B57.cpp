#include <iostream>
#include <string>
using namespace std;

int N, K;
int dp[32][3000009];

int main() {
  cin >> N >> K;

  for(int i=1; i<=N; i++) {
    string str = to_string(i);
    dp[0][i] = i;
    for(int j=0; j<str.size(); j++) {
      dp[0][i]-=(int)(str[j]-'0');
    }
  }

  for(int d=1; d<=29; d++) {
    for(int i=1; i<=N; i++) dp[d][i]=dp[d-1][dp[d-1][i]];
  }

  for(int i=1; i<=N; i++) {
    int CurrentNum=i;
    for(int d=29; d>=0; d--) {
      if(K&(1<<d)) CurrentNum=dp[d][CurrentNum];
    }
    cout << CurrentNum << endl;
  }
  return 0;
}