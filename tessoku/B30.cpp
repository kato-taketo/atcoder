#include <iostream>
using namespace std;

long long Power(long long a, long long b, long long m) {
  long long p = a, Answer = 1;
  for (int i = 0; i < 30; i++) {
    int wari = (1 << i);
    if (b & (1<<i)) {
      Answer = (Answer * p) % m;
    }
    p = (p * p) % m;
  }
  return Answer;
}
long long Division(long long a, long long b, long long m) {
  return (a * Power(b, m-2, m) % m);
}

long long ncr(int n, int r) {
  const long long M = 1000000007;

  long long a = 1;
  for (int i = 1; i <= n; i++) a = (a * i) % M;

  long long b = 1;
  for (int i= 1; i <= r; i++) b = (b * i) % M;
  for (int i = 1; i <= n-r; i++) b = (b * i) % M;

  return Division(a, b, M);
}
int main() {
  long long H, W;
  cin >> H >> W;

  cout << ncr(H+W-2, W-1) << endl;
  return 0;
}