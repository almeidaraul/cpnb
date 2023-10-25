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

\texttt{lcm} is the same size as \texttt{primes}
and stores the exponent of each prime in the LCM
of all factorized numbers.

Useful to calculate LCM mod some P. You can also use map
*/

vi primes, lcm;

vector<ii> pf(int n) {
  vector<ii> factors;
  rep(i,0,primes.size()) {
    int p = primes[i];
		if (p*p > n) break;
		int e = 0;
		while (!(n%p)) {
			n /= p;
			e++;
		}
		factors.push_back({p, e});
    lcm[i] = max(lcm[i], e);
	}
	if (n != 1) {
    factors.push_back({n, 1});
    int ix = lower_bound(all(primes), n) - primes.begin();
    lcm[ix] = max(lcm[ix], 1);
  }
  return factors;
}
