// 14:10 ~
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007
int Q;
vector<int> Query;
vector<int> x;
priority_queue<int , vector<int>, greater<int> > pq;
int main(void) {
  cin >> Q;
  Query.resize(Q); x.resize(Q);
  rep(i,Q) {
    cin >> Query[i];
    if(Query[i] == 1) cin >> x[i];
  }
  rep(i,Q) {
    if(Query[i] == 1) pq.push(x[i]);
    else if(Query[i] == 2) cout << pq.top() << endl;
    else if(Query[i] == 3) pq.pop();
  }
}