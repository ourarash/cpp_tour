
unsigned serialFib(unsigned n) {
  if (n < 2) {
    return n;
  } else {
    return serialFib(n - 2) + serialFib(n - 1);
  }
}

int number_of_cores = 10;
int count = 0;
void parallelFib(unsigned n, unsigned& sum) {
  if (n < 2) {
    sum = n;
  } else {
    unsigned x, y;
    tbb::parallel_invoke(
        [&x, &n, &count]() {
          if (count > number_of_cores) {
            serialFib(n - 2);
          } else {
            count++;
            parallelFib(n - 2, x);
            count--;
          }
        },
        [&y, &n]() { parallelFib(n - 1, y); });
    sum = x + y;
  }
}


// // Not ok in STL, but ok in TBB
// In thread 1: v.push_back()

// In thread 2: v.empty()


// This is ok: 
// In thread 1: v[1] = 1
// In thread 2: reading v[2]
