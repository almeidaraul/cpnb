// C++ structs
struct st {
  vector<int> a;
  vector<bool> b = vector<bool>(5); // default value
  int i;
  st(int _i) : a(_i), i(_i) {};
  bool operator< (st& e) const { return i < e.i; }
};

st e = st(3); st f(3);

struct matrix {
  vector<vector<int>> m;
  matrix(int n) m(n, vector<int>(n)) {};
  matrix operator * (const matrix &b) {
    matrix c = matrix();
    for (int i = 0; i < m.size(); ++i)
      for (int j = 0; j < m.size(); ++j)
        for (int k = 0; k < m.size(); ++k)
          c.m[i][j] = c.m[i][j] + 1LL*m[i][k]*b.m[k][j];
    return c;
  }
};.
