## Stress
for (( I=0; I < 5; I++ )); do
  ./gen $I > z.in
  ./brute < z.in > expected.txt
  ./prog < z.in > output.txt
  if diff -u expected.txt output.txt; then : ; else
    echo "--> input (z.in):"; cat z.in
    echo "--> expected output:"; cat expected.txt
    echo "--> received output:"; cat output.txt
    break
  fi
  echo -n .
done
