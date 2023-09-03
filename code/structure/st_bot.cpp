// Bottom-Up Segment Tree
// Usage: stree(N);
// Source: CP Handbook
// Status: not tested
// Complexity:
//  build: O(n)
//  query: O(log n)
//  modify: O(log n)
//  + uses less space than top-down 4n segtree (2n here)

struct stree {
  unsigned int n;
  vector<int> tree;

  stree(vector<int> v) : n(v.size()), tree(2*n) {
    for (int i = 0; i < n; ++i)
      modify(i, v[i]);
  }

  int query(int a, int b) {
    a += n, b += n;
    int ans = 0;
    while (a <= b) {
      if (a%2 == 1) ans += tree[a++];
      if (b%2 == 0) ans += tree[b--];
      a >>= 1; b >>= 1;
    }
    return ans;
  }

  void modify(int k, int x) {
    k += n;
    tree[k] += x;
    for (k /= 2; k >= 1; k /= 2)
      tree[k] = tree[k<<1] + tree[(k<<1) + 1];
  }
};
