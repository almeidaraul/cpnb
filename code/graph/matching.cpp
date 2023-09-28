// MCBM (Kunh Matching)
/* latex
$\bigO(VE)$ time

Max Cardinality Bipartite Matching

\texttt{g}: arcos do lado esquerdo pro lado direito do grafo
*/
vi mat;
vector<bool> vis;

bool match(int v) {
  if (vis[v]) return false;
  vis[v] = true;
  for (int u: g[v])
    if (mat[u] < 0 || match(mat[u])) {
      mat[u] = v;
      return true;
    }
  return false;
}

mat.assign(n, -1);
int mcbm = 0; // num matched vertices
for (int i = 0; i < n; ++i) {
  vis.assign(n, false);
  mcbm += try_kuhn(i);
}
// match: mat[i] -> i (i é do lado direito)
