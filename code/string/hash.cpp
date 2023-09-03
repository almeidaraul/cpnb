// Rolling hash (O(N))
// Status: not tested
// Source: CP-Algorithms
// O(N) time

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
