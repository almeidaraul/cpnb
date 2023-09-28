// Euler Tour
/* latex
\vspace{4pt}
\noindent
\begin{tabular}{ll}
  \hline
  \textbf{Time} & \textbf{Usage} \\ \hline
  $\bigO(E^2)$ & \texttt{tour(cyc.begin(), start\_vertex)}\\
  \hline
\end{tabular}
*/
list<int> cyc;
vector<vi> adj(M);
vector<vector<bool>> traversed(M, vector<bool>(M, false));

//euler tour (list for fast insertion)
void tour(list<int>::iterator i, int v) {
	for (auto u: adj[v]) {
		if (!traversed[v][u]) {
			traversed[v][u] = true;
			for (auto t: adj[u])
				if (t == v && !traversed[u][t]) {
					traversed[u][t] = true;
					break;
				}
			tour(cyc.insert(i, v), u);
		}
	}
}
