// LCA - Binary lifting
/* latex
\begin{tabular}{l|l}
  \hline
  $\bigO(n\log n)$ time &
  $\bigO(n\log n)$ space \\
  \hline
\end{tabular}
*/
int L = //log2(n)

void dfs(int v, int p) { // uso: dfs(raiz, raiz)
	up[v][0] = p;
	for (int l = 1; l <= L; ++l)
		up[v][l] = up[up[v][l-1]][l-1];
	for (int u : g[v])
    if (u != p) dfs(u, v);
}

int lca(int a, int b) {
  if (dep[b] >= dep[a]) { swap(a, b); }
  int diff = dep[a] - dep[b];
  for (int l = L; l >= 0; l--) if (diff & (1 << l))
    a = up[a][l];
  if (a == b) { return a; }
  for (int l = L; l >= 0; l--) if (up[a][l] != up[b][l])
    a = up[a][l], b = up[b][l];
  return up[a][0];
}
