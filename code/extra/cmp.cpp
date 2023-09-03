// cmp
priority_queue<int, vector<int>, greater<int>> pq;
struct {
  bool operator()(const int& a, const int& b) const {
    return a < b;
  }
} cmp;
priority_queue<int, vector<int>, cmp> pq2;
sort(v.begin(), v.end(), cmp);
