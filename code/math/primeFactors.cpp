// Prime Factors w/ Optimized Trial Divisions
/* latex
\vspace{4pt}
\noindent
\begin{tabular}{ll}
  \hline
  \textbf{Time} & \textbf{Space} \\ \hline
  $\bigO(\pi(\sqrt{n}))$ & $\bigO(n)$ \\
  \hline
\end{tabular}
*/

vi primes;
vector<ii> factors;

void pf(int n) {
	for (auto p: primes) {
		if (p*p > n) break;
		int i = 0;
		while (!(n%p)) {
			n /= p;
			i++;
		}
		factors.push_back({p, i});
	}
	if (n != 1) factors.push_back({n, 1});
}
