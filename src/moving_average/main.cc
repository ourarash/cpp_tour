#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

#include "src/lib/utility.h" // Necessary for PrintVector

enum class Signal { NONE = 0, BUY, SELL };

// Calculates Simple Moving Average.
std::vector<float> CalculateSMA(std::vector<float> &input, int period) {
  std::vector<float> sma(input.size());
  int i = 0;
  std::generate(sma.begin(), sma.end(), [&i, &input, period]() {
    if (i < period) {
      i++;
      return 0.0f;
    } else {
      float result =
          std::accumulate(input.begin() + i - period, input.begin() + i, 0.0f) /
          period;
      i++;
      return result;
    }
  });

  return sma;
}

// Calculates moving average corssover signals.
std::vector<Signal> CalculateSignal(const std::vector<float> &short_term_sma,
                                    const std::vector<float> &long_term_sma) {
  std::vector<Signal> signals(short_term_sma.size());

  int i = 0;
  std::generate(signals.begin(), signals.end(),
                [&i, &short_term_sma, &long_term_sma]() {
                  Signal result = Signal::NONE;

                  if (i == 0 || i == short_term_sma.size() - 1) {
                    result = Signal::NONE;

                  }
                  // Cross from below to above
                  else if (short_term_sma[i - 1] < long_term_sma[i - 1] &&
                           short_term_sma[i + 1] >= long_term_sma[i - 1]) {
                    result = Signal::BUY;
                  }
                  // Cross from above to below
                  else if (short_term_sma[i - 1] > long_term_sma[i - 1] &&
                           short_term_sma[i + 1] <= long_term_sma[i - 1]) {
                    result = Signal::SELL;
                  }
                  i++;
                  return result;
                });
  return signals;
}

int main() {
  std::vector<float> input(100);
  srand (123);

  // Generate a sample input.
  std::generate(input.begin(), input.end(), []() { return rand()%100; });

  PrintVector(input);

  // Calculate SMA10, SMA50, and Signals.
  auto sma10 = CalculateSMA(input, 10);
  auto sma50 = CalculateSMA(input, 20);
  auto signals = CalculateSignal(sma10, sma50);

  PrintVector(sma10);
  PrintVector(sma50);

  // Print signals.
  for (auto e : signals) {
    std::cout << static_cast<int>(e)<< ", ";
  }
  std::cout << std::endl;

  return 0;
}