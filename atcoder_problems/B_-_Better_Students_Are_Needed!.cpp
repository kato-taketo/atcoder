#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

using P = pair<int,int>;
// lhs < rhs ならtrue
bool comp(P lhs, P rhs) {
  if(lhs.first != rhs.first) {
    return lhs.first > rhs.first;
  } else {
    return lhs.second < rhs.second;
  }
}
int main(void) {
  int N,X,Y,Z;
  cin >> N >> X >> Y >> Z;
  vector<int> A(N), B(N);
  rep(i,N) cin >> A[i];
  rep(i,N) cin >> B[i];

  vector<P> vec1(N);   // A value and index
  vector<bool> vec(N,false); // pass or not pass
  rep(i,N) vec1[i] = P(A[i],i);
  sort(vec1.begin(), vec1.end(), comp);
  //rep(i,N) printf("vec1[%d] = %d,%d\n", i, vec1[i].first, vec1[i].second);
  int index=0;
  while(X>0) {
    vec[vec1[index].second]=true;
    X--,index++;
  }

  vector<P> vec2(N);  // B and index
  rep(i,N) vec2[i] = P(B[i],i);
  sort(vec2.begin(), vec2.end(), comp);
  index=0;
  while(Y>0) {
    int point=vec2[index].second;
    if(vec[point]) {
      index++; continue;
    }
    else vec[point]=true, index++, Y--;
  }

  vector<P> vec3(N);  // A+B and index
  rep(i,N) vec3[i] = P(A[i]+B[i],i);
  sort(vec3.begin(),vec3.end(), comp);
  index=0;
  while(Z>0) {
    int point=vec3[index].second;
    if(vec[point]) {
      index++; continue;
    } else {
      vec[point] = true;
      index++, Z--;
    }
  }
  
  // output
  rep(i,N) if(vec[i]) cout << i+1 << endl;
}