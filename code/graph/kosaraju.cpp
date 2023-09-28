// Kosaraju SCC
/* latex
\vspace{4pt}
\noindent
\begin{tabular}{ll}
  \hline
  \textbf{Time/Space} & \textbf{Usage} \\ \hline
  $\bigO(V+E)$ & \texttt{kosaraju()} \\
  \hline
\end{tabular}

\texttt{rep}: representante do componente de cada vtx

\texttt{scc}: 2a dfs, processa os vtx do componente c
*/
vi S, rep(MAXN);

void dfs(int v) {
  vis[v] = true;
  for (int u: g[v])
    if (!vis[u]) dfs(u);
  S.push_back(v);
}

void scc(int v, int c) {
  vis[v] = true;
  rep[v] = c;
  for (int u: gi[v])
    if (!vis[u]) scc(u, c);
}

void kosaraju() {
  for (int i = 0; i < n; ++i)
    if (!vis[i]) dfs(i);
  vis.assign(n, false);
  reverse(all(S));
  for (int v: order)
    if (!vis[v]) scc(v, v);
}
