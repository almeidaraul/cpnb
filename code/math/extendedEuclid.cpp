// Extended Euclid for solving Linear Diophantine Equations
// Status: not tested
// Source: cp-algorithms
// O(log min(a, b)) time

int gcd(int a, int b, int& x, int& y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  int x1, y1;
  int d = gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}

int gcd(int a, int b) {
  int x, y;
  return gcd(a, b, x, y);
}
