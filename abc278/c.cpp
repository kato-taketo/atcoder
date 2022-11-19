#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int N,Q;
  cin >> N >> Q;
  map<int,map<int,int> > mp;
  rep(i,Q) {
    int T, A, B;
    cin >> T >> A >> B;
    if(T==1) mp[A][B]=1;
    else if(T==2) mp[A][B]=0;
    else if(T==3) {
      if(mp[A][B]==1&&mp[B][A]==1) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
  }
}