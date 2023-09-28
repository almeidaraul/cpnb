// Graph Check
/* latex
\vspace{4pt}
\noindent
\begin{tabular}{ll}
  \hline
  \textbf{Time/Space} & \textbf{Usage} \\ \hline
  $\bigO(V+E)$ & \texttt{graphCheck(firstVertex, -1)} \\
  \hline
\end{tabular}
*/
int UNVISITED = -1, EXPLORED = 0, VISITED = 1;
vector<vi> adj(M);
vi tin;

void graphCheck(int v, int p) { //vertex, parent
	tin[v] = EXPLORED;
	for (auto u: adj[v]) {
		if (tin[u] == UNVISITED) { //tree edge
			graphCheck(u, v);
		} else if (tin[u] == EXPLORED) {
			if (u == p)
				; //two way edge u <-> v
			else
				; //back edge v -> u
		} else if (tin[u] == VISITED) {
			; //forward/cross edge u-v
		}
	}
	tin[v] = VISITED;
}
