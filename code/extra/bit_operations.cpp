// Bit Operations
// floor(log2(i))
// C++20
int lg2_floor(unsigned long i) {
  return bit_width(i) - 1;
}
// pre C++20
int lg2_floor(unsigned long long i) {
  if (i)
    return __builtin_clzll(1) - __builtin_clzll(i)
  else
    return -1;
}
