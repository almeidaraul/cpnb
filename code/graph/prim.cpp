// Prim MST
/* latex
\vspace{4pt}
\noindent
\begin{tabular}{ll}
  \hline
  \textbf{Time} & \textbf{Space} \\ \hline
  $\bigO(E\log V)$ & $\bigO(V+E)$ \\
  \hline
\end{tabular}
*/
vi par(N, -1);
vector<ll> d(N, oo);
vector<vector<wv>> mst(N);

ll prim(int s) {
  ll sum = 0;
  priority_queue<wv, vector<wv>, greater<wv>> Q;
  auto add = [&](int v, ll x, int p) {
    if (x < d[v]) {
      Q.emplace(d[v]=x, v);
      par[v] = u;
  }};
  add(s, 0, s);
  while (Q.size()) {
    auto [w, v] = Q.top(); Q.pop();
    if (vis[u]) continue;
    vis[u] = true;
    if (par[u] != -1) {
      int p = par[v]; ll w = d[v];
      mst[v].emplace_back(w, u);
      mst[u].emplace_back(w, v);
    }
    sum += w;
    for (auto [c, u] : g[v])
      if (!vis[u])
        add(u, c, v);
  }
  return sum;
}

