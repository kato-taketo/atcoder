// 22:33~22:43 14:06~14:34
// なぜok??, gccの環境次第でこれでAC

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int N,Q;
vector<double> X,R,H,V;
vector<int> A,B;
int main(void) {
  cin >> N >> Q;
  X.resize(N), R.resize(N), H.resize(N), V.resize(N);
  A.resize(Q), B.resize(Q);
  rep(i,N) cin >> X[i] >> R[i] >> H[i];
  rep(i,Q) cin >> A[i] >> B[i];

  rep(i,N) V[i] = R[i]*R[i]*H[i];
  rep(i,Q) {
    double tmp=0;
    rep(j,N) {
      if(B[i]<=X[j]||A[i]>=X[j]+H[j]) tmp+=0;
      else if(A[i]<=X[j]&&X[j]+H[j]<=B[i]) tmp+=V[j];
      else if(A[i]<=X[j]&&B[i]>=X[j]&&B[i]<=X[j]+H[j]) {
        double tmp2=X[j]+H[j]-B[i];
        tmp += V[j]*(H[j]*H[j]*H[j]-tmp2*tmp2*tmp2)/(H[j]*H[j]*H[j]);
      } else if(A[i]>=X[j]&&B[i]<=X[j]+H[j]) {
        double tmp2=X[j]+H[j]-A[i],tmp3=X[j]+H[j]-B[i];
        tmp += V[j]*(tmp2*tmp2*tmp2-tmp3*tmp3*tmp3)/(H[j]*H[j]*H[j]);
      } else {
        double tmp2=X[j]+H[j]-A[i];
        tmp += V[j]*(tmp2*tmp2*tmp2)/(H[j]*H[j]*H[j]);
      }
    }
    tmp *= (M_PI / 3.00000);
    printf("%.4lf\n", tmp);
    //cout << tmp << endl;
  }
}