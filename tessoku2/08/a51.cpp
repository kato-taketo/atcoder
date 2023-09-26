// 13:53
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int Q;
vector<int> Query;
vector<string> x;
stack<string> st;
int main(void) {
  cin >> Q;
  Query.resize(Q); x.resize(Q);
  rep(i,Q) {
    cin >> Query[i];
    if(Query[i] == 1) cin >> x[i];
  }
  rep(i,Q) {
    if(Query[i] == 1) st.push(x[i]);
    else if(Query[i] == 2) cout << st.top() << endl;
    else if(Query[i] == 3) st.pop();
  }
}