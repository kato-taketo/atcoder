#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int n,d;
  cin >> n >> d;
  vector<int> x(n),y(n);
  rep(i,n) cin >> x[i] >> y[i];

  vector<bool> virus(n,false);
  virus[0]=true;
  queue<int> que; // virus index
  que.push(0);
  while(!que.empty()) {
    int v=que.front();
    que.pop();
    for(int i=0; i<n; i++) {
      if(virus[i]) continue;
      if((x[i]-x[v])*(x[i]-x[v])+(y[i]-y[v])*(y[i]-y[v])<=d*d) virus[i]=true, que.push(i);
    }
  }
  int cnt=0;
  rep(i,n) if(virus[i]) cout << "Yes" << endl; else cout << "No" << endl;
}