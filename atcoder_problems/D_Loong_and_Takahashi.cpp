#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007
vector<vector<int> > vec;
int N,num;
int main(void) { 
  cin >> N;
  vec.resize(N);
  rep(i,N) vec[i].resize(N);
  vec[N/2][N/2]=-1;
  
  num=1;
    for(int k=0; k<N/2; k++) {
      // right
      for(int i=k,j=k; j<N-k; j++) {
        vec[i][j] = num++;
      }
      // down
      for(int i=k+1,j=N-1-k; i<N-k; i++) {
        vec[i][j] = num++;
      }
      // left
      for(int i=N-1-k,j=N-2-k; j>=k; j--) {
        vec[i][j] = num++;
      }
      // up
      for(int i=N-2-k,j=k; i>=k+1; i--) {
        vec[i][j] = num++;
      }
  }

  rep(i,N) {
    rep(j,N) {
      if(vec[i][j]==-1) cout << "T ";
      else cout << vec[i][j] << " ";
    }
    cout << endl;
  }
}