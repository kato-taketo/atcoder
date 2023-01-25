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
  vector<int> x(n), y(n);
  rep(i,n) cin >> x[i] >> y[i];

  priority_queue<int> pq;
  vector<bool> used(n,false);
  int cnt=0;
  for(int i=1; i<=d; i++) {
    for(int j=0; j<n; j++) {
      
      if(used[j]==false && x[j]==i) pq.push(y[j]), used[j]=true;
    }
  if(!pq.empty()) {
    int value=pq.top();
    pq.pop();
    cnt += value;
    }
  }

  cout << cnt << endl;
}