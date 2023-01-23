#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int n;
  cin >> n;

  vector<bool> a(n+1,true);  // a[i]==true -> i is prime
  a[0]=false; a[1]=false;
  for(int i=2; i<=n; i++) {  // i*i<=Nとしてよかった
    if(a[i]==false) continue;
    for(int j=i+i; j<=n; j+=i) {
      a[j]=false;
    }
  }
  rep(i,n+1) if(a[i]) cout << i << endl;

}