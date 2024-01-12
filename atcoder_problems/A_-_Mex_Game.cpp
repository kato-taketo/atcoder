#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int N,af,bf;
string S;
vector<bool> used;
priority_queue<int,vector<int>,greater<int> > ap, bp;
int main(void) {
  cin >> N >> S;
  used.resize(N+1,false);
  af=N+1,bf=N+1;
  rep(i,S.length()) {
    if(S[i]=='A') ap.push(i);
    if(S[i]=='B') bp.push(i);
  }
  for(int k=1; k<=N; k++) {
    if(k%2!=0) {
      // Alice turn
      if(bp.size()!=0) bp.pop();
    } else {
      // Bob turn
      if(ap.size()!=0) ap.pop();
    }
    if(ap.size()==0) af=N+1;
    if(bp.size()==0) bf=N+1;
    if(ap.size()!=0) af=ap.top();
    if(bp.size()!=0) bf=bp.top();
    //cout << "ap.size()" << " " << ap.size() << endl;
    //cout << "bp.size()" << " " << bp.size() << endl;
    if(af>bf) cout << "Bob" << endl;
    else cout << "Alice" << endl;
  }
}