// Merge/Disjoint Union-Find
/* latex
\vspace{4pt}
\noindent
\begin{tabular}{lll}
  \hline
  \textbf{Time} & \textbf{Space} & \textbf{Usage} \\ \hline
  $\bigO(A\times n)$ & $\bigO(n)$ & \texttt{muf(n)} \\
  \hline
\end{tabular}
*/
struct muf {
	int N;
	vi par, rk, count;

	muf(int N) : N(N), par(N), rk(N, 0), count(N, 1) {
    for (int i = 0; i < N; ++i)
      par[i] = i;
	}

	int findSet(int i) {
		return par[i] == i ? i : (par[i] = findSet(par[i]));
	}
	
	int unite(int a, int b) {
		int x = findSet(a), y = findSet(b);
		if (x != y)
			count[x] = count[y] = (count[x]+count[y]);
		if (rk[x] < rk[y])
			par[x] = y;
		else {
			par[y] = x;
			if (rk[x] == rk[y])
				rk[x]++;
		}
		return count[x];
	}

	bool sameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}
};
