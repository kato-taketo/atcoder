#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, ret1[1 << 18], ret2[1 << 18];
string S;

int main() {
  cin >> N >> S;

  int streak1 = 1; 
  ret1[0] = 1;
  for (int i = 0; i < N -1; i++) {
    if (S[i] == 'A') streak1 += 1;
    if (S[i] == 'B') streak1 = 1;
    ret1[i + 1] = streak1;
  }
  int streak2 = 1;
  ret2[N-1] = 1;
  for (int i = N - 2; i >= 0; i--) {
    if(S[i] == 'A') streak2 = 1;
    if(S[i] == 'B') streak2 += 1;
    ret2[i] = streak2;
  }

  long long Answer = 0;
  for (int i=0; i<N; i++) Answer += max(ret1[i], ret2[i]);
  cout << Answer << endl;
  return 0;
}