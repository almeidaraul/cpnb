// Prefix {AND}
/* latex
$\bigO(1)$ bitwise and on array, $\bigO(N\log N)$ build
*/
vector<vector<int>> ps(n, vector<int>(32));
const int L = 32;

void build(vector<int> &v) {
  int n = v.size();
  for (int i = 0; i < n; ++i) // build
    for (int b = 0; b < L; ++b) {
      if (i > 0) ps[i][b] = ps[i-1][b];
      ps[i][b] += v[i] & (1ll << b);
    }
}

int qry(int l, int r) {
  int num = 0;
  for (int b = 0; b < L; ++b)
    // ligado em todos
    if (ps[r][b] - (l ? ps[l-1][b] : 0) == r-l+1)
      num |= (1ll << b);
  return num;
}
