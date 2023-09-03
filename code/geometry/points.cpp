// Points
using pt = complex<double>;
#define px real()
#define py imag()

double dot(pt a, pt b) { return (conj(a)*b).px; }
double cross(pt a, pt b) { return (conj(a)*b).py; }
pt vec(pt a, pt b) { return b-a; }
int sgn(double v) { return (v > -EPS) - (v < EPS); }
int seg_ornt(pt a, pt b, pt c) {
  return sgn(cross(vec(a, b), vec(a, c)));
}
int ccw(pt a, pt b, pt c, bool col) {
  int o = seg_ornt(a, b, c);
  return (o == 1) || (o == 0 && col);
}
const double PI = acos(-1);
double angle(pt a, pt b, pt c) {
  return abs(remainder(arg(a-b) - arg(c-b), 2.0*PI));
}
