// Suffix Array
// Status: tested (ITMO course)
// Source: ITMO @ CF Edu, CP-Algorithms
// O(nlogn) construction

// sort p by the values in c (stable) (O(|alphabet| + n))
void count_sort(vector<int> &p, vector<int> &c) {
  int n = p.size();
  int alphabet = 256; // ascii range
  vector<int> cnt(max(alphabet, n));
  for (auto x : c)
    cnt[x]++;

  vector<int> pos(max(alphabet, n));
  pos[0] = 0;
  for (int i = 1; i < max(alphabet, n); ++i)
    pos[i] = pos[i-1] + cnt[i-1];

  vector<int> p_sorted(n);
  for (auto x : p) {
    p_sorted[pos[c[x]]++] = x;
  }

  p = p_sorted;
}

// build suffix array
vector<int> suffix_array(string s) {
  s += "$";
  int n = s.size();
  // at k = 2^0, sort strings of length 1
  vector<int> p(n), c(n); // suffix start position, equivalence class
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
    vector<int> c_upd(n);
    c_upd[p[0]] = 0;
    for (int i = 1; i < n; ++i) {
      pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + k)%n]};
      pair<int, int> curr = {c[p[i]], c[(p[i] + k)%n]};
      c_upd[p[i]] = c_upd[p[i-1]];
      if (curr != prev)
        c_upd[p[i]]++;
    }
    c = c_upd;
    k <<= 1;
  }
  return p;
}
