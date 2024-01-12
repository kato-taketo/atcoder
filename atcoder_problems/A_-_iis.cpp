#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007
int N;
int main(void) {
  cin >> N;
  for(int i=1; i<=N-2; i++) {
    cout << i << " ";
  }
  cout << N << " " << N-1 << " ";
  if(N%2==0) {
    for(int i=N; i>=2; i-=2) {
      for(int j=(i-1)*2-1; j>0 ;j--) {
        if(j%2==0) cout << i-1 << " ";
        else cout << i << " ";
      }
    }
    cout << endl;
  } else {
    for(int i=N; i>=3; i-=2) {
      for(int j=(i-1)*2-1; j>0; j--) {
        if(j%2==0) cout << i-1 << " ";
        else cout << i << " ";
      }
    }
    cout << endl;
  }
}