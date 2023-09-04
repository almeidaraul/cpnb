// Sieve of Eratosthenes
/* latex
\vspace{4pt}
\noindent
\begin{tabular}{ll}
  \hline
  \textbf{Time} & \textbf{Space} \\ \hline
  $\bigO(n\log\log n)$ & $\bigO(n)$ \\
  \hline
\end{tabular}
*/

bitset<11234567> pr;
vector<int> factors(M, 0);
vector<int> primes;

void sieve(int n) {
	pr.set();
	for (int i = 2; i*i <= n; ++i)
		if (pr[i]) { //factors[i] == 0
			primes.push_back(i);
			for (int p = i*i; p <= n; p += i) {
				pr[p] = false;
				factors[p]++;
			}
		}
}

// O(1) for small n, O(sieve_size) else
bool isPrime(int n) {
	int sieve_size = 11234567;
	if (n <= sieve_size) return pr[n];
	for (auto p: primes) // only works if n <= primes.back()^2
		if (!(n%p)) return false;
	return true;
}
