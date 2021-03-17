#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

#include "src/lib/utility.h"  // Necessary for PrintVector

enum class Signal { NEUTRAL = 0, BUY, SELL };

std::string Convert(Signal s) {
  switch (s) {
    case Signal::BUY:
      return "B";
      break;

    case Signal::SELL:
      return "S";
      break;
    default:
      return "N";
      break;
  }
}
void PrintSignal(const std::vector<Signal> &input) {
  std::cout << "{ ";
  unsigned int count = 0;
  for (auto n : input) {
    count++;

    std::cout << Convert(n);

    if (count < input.size()) std::cout << ", ";
  }
  std::cout << " }" << std::endl;
}

// Calculates Simple Moving Average.
std::vector<float> CalculateSMA(std::vector<float> &input, int period) {
  std::vector<float> sma(input.size());
  int i = 0;
  std::generate(sma.begin(), sma.end(), [&i, &input, period]() {
    if (i < period - 1) {
      i++;
      return 0.0f;
    } else {
      float result = std::accumulate(input.begin() + i - period + 1,
                                     input.begin() + i + 1, 0.0f) /
                     period;
      i++;
      return result;
    }
  });

  return sma;
}

std::vector<int> CompareWithMovingAverage(const std::vector<float> &prices,
                                          const std::vector<float> &sma) {
  std::vector<int> result(prices.size());
  int i = -1;
  std::generate(result.begin(), result.end(), [&i, &sma, &prices]() {
    i++;

    const float price = prices[i];
    if (price < sma[i]) {
      return -1;
    } else if (price == sma[i]) {
      return 0;
    }

    return 1;
  });

  return result;
}

std::vector<Signal> CalculateSignalBasedOnSmaComparison(
    std::vector<int> &sma_comparison) {
  std::vector<int> differences;

  std::adjacent_difference(sma_comparison.begin(), sma_comparison.end(),
                           std::back_inserter(differences));

  differences[0] = 0;

  std::vector<Signal> result;
  int day = -1;

  std::transform(differences.begin(), differences.end(),
                 std::back_inserter(result),
                 [&day, &sma_comparison](int difference) {
                   day++;
                   if (difference == 0.0) {
                     return Signal::NEUTRAL;
                   } else if (difference < 0.0) {
                     return Signal::SELL;

                   } else if (difference > 0.0) {
                     return Signal::BUY;
                   }
                 });
  return result;
}

std::vector<int> CreateOutput(std::vector<Signal> &input) {
  std::vector<std::pair<int, Signal>> day_signal;

  int day = -1;
  std::transform(input.begin(), input.end(), std::back_inserter(day_signal),
                 [&day](const Signal s) {
                   day++;
                   return std::make_pair(day, s);
                 });

  std::vector<std::pair<int, Signal>> sell_days;

  std::copy_if(
      day_signal.begin(), day_signal.end(), std::back_inserter(sell_days),
      [](const std::pair<int, Signal> &p) { return p.second == Signal::SELL; });

  std::vector<int> result;

  std::transform(sell_days.begin(), sell_days.end(), std::back_inserter(result),
                 [](const std::pair<int, Signal> &p) { return p.first; });
  return result;
}

// Calculates moving average corssover signals.
std::vector<Signal> CalculateSignal(const std::vector<float> &short_term_sma,
                                    const std::vector<float> &long_term_sma) {
  std::vector<Signal> signals(short_term_sma.size());

  int i = 0;
  std::generate(signals.begin(), signals.end(),
                [&i, &short_term_sma, &long_term_sma]() {
                  Signal result = Signal::NEUTRAL;

                  if (i == 0 || i == short_term_sma.size() - 1) {
                    result = Signal::NEUTRAL;

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
  {
    std::vector<int> input = {1, 1, 0, 1, 0, 1, -1, 0, -1, 1};
    Print(input);
    auto signals = CalculateSignalBasedOnSmaComparison(input);
    PrintSignal(signals);
    auto output = CreateOutput(signals);

    Print(output);

    std::cout << "a: " << std::endl;
  }
  {
    std::vector<float> input = {4, 4, 13, 10, 4, 10, 16};
    int period = 3;
    auto sma = CalculateSMA(input, period);

    Print(sma);

    auto markings = CompareWithMovingAverage(input, sma);
    Print(markings);

    auto signals = CalculateSignalBasedOnSmaComparison(markings);
    Print(markings);
    // Print(signals);
  }
  std::vector<float> input(100);
  srand(123);

  // Generate a sample input.
  std::generate(input.begin(), input.end(), []() { return rand() % 100; });

  PrintVector(input);

  // Calculate SMA10, SMA50, and Signals.
  auto sma10 = CalculateSMA(input, 10);
  auto sma50 = CalculateSMA(input, 20);
  auto signals = CalculateSignal(sma10, sma50);

  PrintVector(sma10);
  PrintVector(sma50);

  // Print signals.
  for (auto e : signals) {
    std::cout << static_cast<int>(e) << ", ";
  }
  std::cout << std::endl;

  return 0;
}