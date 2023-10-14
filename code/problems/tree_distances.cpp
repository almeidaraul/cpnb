// Tree Distances I
/* latex
Given a tree of $n$ nodes, determine for each
node its maximum distance to another node
*/
vi d(maxn);

void dfs1(int v, int p=-1) { // d[v] = max dist below
  d[v] = 0;
  for (int u : g[v])
    if (u != p) {
      dfs1(u, v);
      d[v] = max(d[v], 1+d[u]);
    }
}

void add(int &a, int &b, int c) {
  if (c > a)
    tie(a, b) = make_pair(c, a);
  else if (c > b)
    b = c;
}

void dfs2(int v, int a, int p=-1) { // include dist above
  // a,b = max and 2nd max subtrees
  int b = 0;
  for (int u : g[v])
    if (u != p)
      add(a, b, 1+d[u]);
  for (int u : g[v])
    if (u != p) {
      int dist = (1+d[u]) == a ? b : a;
      dfs2(u, dist+1, v);
    }
  d[v] = max(d[v], a);
}

signed main() {
  dfs1(src);
  dfs2(src, 0);
  rep(i,0,n)
    cout << d[i] << '\n';
}
