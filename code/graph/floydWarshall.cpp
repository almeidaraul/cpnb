// Floyd Warshall APSP
/* latex
\vspace{4pt}
\noindent
\begin{tabular}{lll}
  \hline
  \textbf{Time} & \textbf{Space} & \textbf{Usage} \\ \hline
  $\bigO(V^3 + E)$ & $\bigO(V^2+E)$ & \texttt{FloydWarshall(n, edges)} \\
  \hline
\end{tabular}
*/
vector<vector<int>> w(MAXN, vector<int>(MAXN, oo));
void fw(int n) {
	for (int m = 0; m < n; ++m)
    for (int u = 0; u < n; ++u)
      for (int v = 0; v < n; ++v)
        if (max(w[u][m], w[m][v]) < oo)
          w[u][v] = min(w[u][v], w[u][m]+w[m][v]);
}
