// LCA - Euler Path
/* latex
\begin{tabular}{l|l}
  \hline
  $\bigO(n\log n)$ time &
  $\bigO(n)$ space \\
  \hline
\end{tabular}
*/
vi idx(n);
int tk = 1;

void dfs(int v, int d) { // call with dfs(root, 0);
	for (auto u : adj[v]) {
		st.update(tk, {d, v});
		tk++;
		dfs(u, d+1);
	}
	idx[v] = tk;
	st.update(tk, {d, v});
	tk++;
}

int lca(int v, int u) {
	int l = idx[v], r = idx[u];
	return st.minquery(l, r).second; // .first is depth
}
