// Extended Euclid for Linear Diophantines
/* latex
\vspace{4pt}
\noindent
\begin{tabular}{ll}
  \hline
  \textbf{Time} & \textbf{Usage for \texttt{a,b}} \\ \hline
  $\bigO(\log \textrm{min}(a,b))$ & \texttt{int x, y; gcd(a, b, x, y); }\\
  \hline
\end{tabular}
*/
int gcd(int a, int b, int& x, int& y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  int x1, y1;
  int d = gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}
