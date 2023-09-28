// cmp
// upper_bound: 1st > x, lower_bound: 1st >= x
// last <= x: up-1, first >= x: lo
priority_queue<int, vector<int>, greater<int>> pq;
struct {
  bool operator()(const int& a, const int& b) const {
    return a < b;
  }
} cmp;
priority_queue<int, vector<int>, cmp> pq2;
sort(all(v), cmp);
