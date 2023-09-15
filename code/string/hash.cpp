// Rolling hash (linear)
/* latex
$\bigO(n)$ time

Let $h_{i..j} = \textrm{hash}(s_{i..j})$.

$h_{i..j}\times p^i = h_{0..j} - h_{0..i-1}$. Instead of finding the multiplicative inverse of $p^i$, you can multiply this term by $p^{n-i}$ (so every hash is compared multiplied by $p^n$).
*/
ll hash(string const& s) {
  const int p = 31; // ~alphabet size (31 for lowercase, 53 for uppercase)
  const int M = 1e9 + 9;
  ll h = 0;
  ll p_pow = 1; // precompute for performance
  for (char c : s) {
    h = (h + (c - 'a' + 1)*p_pow) % M;
    p_pow = (p_pow * p) % M;
  }
  return h;
}
