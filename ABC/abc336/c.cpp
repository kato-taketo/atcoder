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
  N--;
  if(N==0) {
    cout << 0 << endl; return 0;
  }
  vector<int> x;
  while(N>0) {
    x.push_back(N%5);
    N/=5;
  }
  
  for(int i=x.size()-1; i>=0; i--) {
    if(x[i]==0) cout << 0;
    else if(x[i]==1) cout << 2;
    else if(x[i]==2) cout << 4;
    else if(x[i]==3) cout << 6;
    else if(x[i]==4) cout << 8;
  }
  cout << endl;
}