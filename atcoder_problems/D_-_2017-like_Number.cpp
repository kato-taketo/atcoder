#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

vector<bool> prime(100005,true);
vector<int> num_2017(100005,0);
int main(void) {
  int Q;
  cin >> Q;
  vector<int> l(Q),r(Q);
  rep(i,Q) cin >> l[i] >> r[i];

  prime[0]=false;
  prime[1]=false;
  for(int i=2; i<100005; i++) {
    if(!prime[i]) continue;
    for(int j=i*2; j<100005; j+=i) {
      prime[j]=false;
    }
  }
  rep(i,100005) {
    if(i==0) continue;
    else if(i%2==0) num_2017[i]=num_2017[i-1];
    else if(prime[i]&&prime[(i+1)/2]) num_2017[i]=num_2017[i-1]+1;
    else num_2017[i]=num_2017[i-1];
  }
  rep(i,Q) {
    cout << num_2017[r[i]]-num_2017[l[i]-1] << endl;
  }
}