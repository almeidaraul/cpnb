// Suffix Array
/* latex
\vspace{4pt}
\noindent
\begin{tabular}{ll}
  \hline
  \textbf{Build} & \textbf{Query} \\ \hline
  $\bigO(n\log n)$ & $\bigO(\log n)$ \\
  \hline
\end{tabular}

To find whether $p$ is a substring of $s$ (and where this ocurrence starts), you can build the suffix array $A$ of $s$. Since $A$ is sorted, you can binary search for $p$ as a prefix of all suffixes of $s$. \textbf{Complexity (besides construction):} $\mathcal{O}(\left|p\right|\log(\left|s\right|))$.
*/
// sort p by the values in c (stable) (O(|alphabet| + n))
void count_sort(vi &p, vi &c) {
  int n = p.size();
  int alphabet = 256; // ascii range
  vi cnt(max(alphabet, n));
  for (auto x : c)
    cnt[x]++;

  vi pos(max(alphabet, n));
  pos[0] = 0;
  for (int i = 1; i < max(alphabet, n); ++i)
    pos[i] = pos[i-1] + cnt[i-1];

  vi p_sorted(n);
  for (auto x : p) {
    p_sorted[pos[c[x]]++] = x;
  }

  p = p_sorted;
}

// build suffix array
vi suffix_array(string s) {
  s += "$";
  int n = s.size();
  // at k = 2^0, sort strings of length 1
  vi p(n), c(n); // suffix start position, equivalence class
  for (int i = 0; i < n; ++i) {
    p[i] = i;
    c[i] = s[i];
  }
  // at first c is just a hack to sort p, it's not really equiv. class
  count_sort(p, c);
  // but then it is
  c[p[0]] = 0;
  for (int i = 1; i < n; ++i) {
    c[p[i]] = c[p[i-1]];
    if (s[p[i]] != s[p[i-1]])
      c[p[i]]++;
  }
  int k = 1;
  while (k < n) {
    // transition from k to k+1
    for (int i = 0; i < n; ++i)
      p[i] = (p[i] - k + n) % n;
    count_sort(p, c);
    // recalculate equiv.
    vi c_upd(n);
    c_upd[p[0]] = 0;
    for (int i = 1; i < n; ++i) {
      ii prev = {c[p[i-1]], c[(p[i-1] + k)%n]};
      ii curr = {c[p[i]], c[(p[i] + k)%n]};
      c_upd[p[i]] = c_upd[p[i-1]];
      if (curr != prev)
        c_upd[p[i]]++;
    }
    c = c_upd;
    k <<= 1;
  }
  return p;
}
