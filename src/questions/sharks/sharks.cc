#include <map>
#include <queue>
#include <tuple>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
using ::testing::Combine;
using ::testing::Values;
using ::testing::ValuesIn;
using namespace std;
template <class T>
void Print2dVector(std::vector<std::vector<T>> input) {
  std::cout << "{ " << std::endl;
  for (int i = 0; i < input.size(); i++) {
    for (int j = 0; j < input[0].size(); j++) {
      std::cout << input[i][j];
      if (j < input[0].size() - 1) std::cout << ", ";
    }
    std::cout << std::endl;
  }
  std::cout << " }" << std::endl;
}
//-----------------------------------------------------------------------------
// Returns start, end, and a modified grid with 0's and 1's.
auto CreateModGrid(vector<vector<char>> input) {
  vector<pair<int, int>> shark_locations;
  pair<int, int> start, end;
  // Store shark's locations.
  for (int i = 0; i < input.size(); i++) {
    for (int j = 0; j < input.size(); j++) {
      switch (input[i][j]) {
        case 's':
          shark_locations.push_back(make_pair(i, j));
          break;

        case 'y':
          start = make_pair(i, j);
          break;

        case 'i':
          end = make_pair(i, j);
          break;
      }
    }
  }

  // Use DFS to find distances.
  vector<vector<int>> distances(
      input.size(), vector<int>(input.size(), 2 * input.size() - 2));
  std::map<std::pair<int, int>, int> marks;
  std::queue<std::pair<int, int>> q;

  // Insert all the sharks in the queue.
  for (auto &shark_location : shark_locations) {
    q.push(std::make_pair(shark_location.first, shark_location.second));
    marks[std::make_pair(shark_location.first, shark_location.second)] = 1;
    distances[shark_location.first][shark_location.second] = 0;
  }

  while (!q.empty()) {
    auto cur = q.front();
    q.pop();

    int cur_i = cur.first;
    int cur_j = cur.second;
    marks[std::make_pair(cur_i, cur_j)] = 1;
    // left
    if (cur_i > 0 && !marks[make_pair(cur_i - 1, cur_j)]) {
      q.push(make_pair(cur_i - 1, cur_j));
      distances[cur_i - 1][cur_j] =
          min(distances[cur_i - 1][cur_j], distances[cur_i][cur_j] + 1);
    }

    // right
    if (cur_i < input.size() - 1 && !marks[make_pair(cur_i + 1, cur_j)]) {
      q.push(make_pair(cur_i + 1, cur_j));
      distances[cur_i + 1][cur_j] =
          min(distances[cur_i + 1][cur_j], distances[cur_i][cur_j] + 1);
    }

    // top
    if (cur_j > 0 && !marks[make_pair(cur_i, cur_j - 1)]) {
      q.push(make_pair(cur_i, cur_j - 1));
      distances[cur_i][cur_j - 1] =
          min(distances[cur_i][cur_j - 1], distances[cur_i][cur_j] + 1);
    }
    // bottom
    if (cur_j < input.size() - 1 && !marks[make_pair(cur_i, cur_j + 1)]) {
      q.push(make_pair(cur_i, cur_j + 1));
      distances[cur_i][cur_j + 1] =
          min(distances[cur_i][cur_j + 1], distances[cur_i][cur_j] + 1);
    }
  }

  return std::make_tuple(distances, start, end);
}

//-----------------------------------------------------------------------------
// Returns start, end, and a modified grid.
// Each grid location is the min to
// all sharks.
auto CreateModGrid(vector<vector<char>> input, int block_value) {
  auto [mod_input, start, end] = CreateModGrid(input);

  for (int i = 0; i < input.size(); i++) {
    for (int j = 0; j < input.size(); j++) {
      mod_input[i][j] = (mod_input[i][j] <= block_value ? 0 : 1);
    }
  }

  return std::make_tuple(mod_input, start, end);
}
//-----------------------------------------------------------------------------
//  Whether a path from start to end only using locations with value greater
//  than or equal to i exists.
bool BFS(const vector<vector<int>> &grid, pair<int, int> start,
         pair<int, int> end, int i) {
  std::map<std::pair<int, int>, int> marks;
  std::queue<std::pair<int, int>> q;

  // The srating point is already blocked.
  if (grid[start.first][start.second] <= i) {
    return false;
  }

  q.push(std::make_pair(start.first, start.second));
  marks[std::make_pair(start.first, start.second)] = 1;

  while (!q.empty()) {
    auto cur = q.front();
    q.pop();

    int cur_i = cur.first;
    int cur_j = cur.second;
    marks[std::make_pair(cur_i, cur_j)] = 1;
    // left
    if (cur_i > 0 && !marks[make_pair(cur_i - 1, cur_j)] &&
        grid[cur_i - 1][cur_j] > i) {
      q.push(make_pair(cur_i - 1, cur_j));
    }

    // right
    if (cur_i < grid.size() - 1 && !marks[make_pair(cur_i + 1, cur_j)] &&
        grid[cur_i + 1][cur_j] > i) {
      q.push(make_pair(cur_i + 1, cur_j));
    }

    // top
    if (cur_j > 0 && !marks[make_pair(cur_i, cur_j - 1)] &&
        grid[cur_i][cur_j - 1] > i) {
      q.push(make_pair(cur_i, cur_j - 1));
    }
    // bottom
    if (cur_j < grid.size() - 1 && !marks[make_pair(cur_i, cur_j + 1)] &&
        grid[cur_i][cur_j + 1] > i) {
      q.push(make_pair(cur_i, cur_j + 1));
    }
  }

  return marks[make_pair(end.first, end.second)];
}
//-----------------------------------------------------------------------------
//  Whether a path from start to end only using locations with value greater
//  than or equal to i exists.
bool BFS(const vector<vector<int>> &grid, pair<int, int> start,
         pair<int, int> end) {
  std::map<std::pair<int, int>, int> marks;
  std::queue<std::pair<int, int>> q;

  // The srating point is already blocked.
  if (grid[start.first][start.second] == 0) {
    return false;
  }
  q.push(std::make_pair(start.first, start.second));
  marks[std::make_pair(start.first, start.second)] = 1;

  while (!q.empty()) {
    auto cur = q.front();
    q.pop();

    int cur_i = cur.first;
    int cur_j = cur.second;
    marks[std::make_pair(cur_i, cur_j)] = 1;
    // left
    if (cur_i > 0 && !marks[make_pair(cur_i - 1, cur_j)] &&
        grid[cur_i - 1][cur_j] != 0) {
      q.push(make_pair(cur_i - 1, cur_j));
    }

    // right
    if (cur_i < grid.size() - 1 && !marks[make_pair(cur_i + 1, cur_j)] &&
        grid[cur_i + 1][cur_j] != 0) {
      q.push(make_pair(cur_i + 1, cur_j));
    }

    // top
    if (cur_j > 0 && !marks[make_pair(cur_i, cur_j - 1)] &&
        grid[cur_i][cur_j - 1] != 0) {
      q.push(make_pair(cur_i, cur_j - 1));
    }
    // bottom
    if (cur_j < grid.size() - 1 && !marks[make_pair(cur_i, cur_j + 1)] &&
        grid[cur_i][cur_j + 1] != 0) {
      q.push(make_pair(cur_i, cur_j + 1));
    }
  }

  return marks[make_pair(end.first, end.second)];
}
//-----------------------------------------------------------------------------
// Assumptions
// Sharks: 's', You: 'y', Island: 'i', Empty: ' '
// The sharks don't move.
// You can only move left, right, up, or down. No diagonal.
// By mod_input, we mean Manhattan mod_input.
// Examples:
// 1. Input: No shark. Output: 2N-2
// 2. Input: Far shark, already on island. Output: 2N-2.
// 3. Input: (Impossible) Sharks around the island. Output: 0.
// Insights:
// 1. It looks like:   0 <= output <= 2N-2
// 2. Brute force can use BFS and try all possible values of the output.
// 3. We can bring CreateModGrid outside of the grid.
int FindMaxOfMinDistanceToSharksLinearSearchImproved(
    const vector<vector<char>> &input) {
  int answer = 0;
  auto [mod_input, start, end] = CreateModGrid(input);
  int N = input.size();

  for (int i = 0; i < 2 * N - 2; i++) {
    if (BFS(mod_input, start, end, i)) {
      answer = max(answer, i + 1);
    }
  }
  return answer;
}
//-----------------------------------------------------------------------------
int FindMaxOfMinDistanceToSharksLinearSearch(
    const vector<vector<char>> &input) {
  int answer = 0;

  int N = input.size();
  for (int i = 0; i < 2 * N - 2; i++) {
    auto [mod_input, start, end] = CreateModGrid(input, i);

    if (BFS(mod_input, start, end)) {
      answer = max(answer, i + 1);
    }
  }
  return answer;
}
//-----------------------------------------------------------------------------
int FindMaxOfMinDistanceToSharksBinarySearch(
    const vector<vector<char>> &input) {
  auto [mod_input, start, end] = CreateModGrid(input);

  int l = 0;
  int r = 2 * input.size() - 2;
  int mid = 0, output = 0;

  while (r >= l) {
    mid = (r + l) / 2;
    // std::cout << "l: " << l << ", r: " << r << ", mid: " << mid << std::endl;
    if (BFS(mod_input, start, end, mid)) {
      output = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return output;
}

//-----------------------------------------------------------------------------

TEST(CreateModGrid, SimpleTest1) {
  std::vector<std::vector<char>> input = {//
                                          {' ', ' ', 'i'},
                                          {' ', ' ', ' '},
                                          {' ', 'y', ' '}};

  std::vector<std::vector<int>> expected_grid = {//
                                                 {4, 4, 4},
                                                 {4, 4, 4},
                                                 {4, 4, 4}};
  auto [mod_grid, start, end] = CreateModGrid(input);
  EXPECT_EQ(mod_grid, expected_grid);
  EXPECT_EQ(start, make_pair(2, 1));
  EXPECT_EQ(end, make_pair(0, 2));
}

TEST(CreateModGrid, SimpleTest2) {
  std::vector<std::vector<char>> input = {//
                                          {' ', ' ', 'i'},
                                          {' ', ' ', 's'},
                                          {'s', 'y', ' '}};

  std::vector<std::vector<int>> expected_grid = {//
                                                 {2, 2, 1},
                                                 {1, 1, 0},
                                                 {0, 1, 1}};
  auto [mod_grid, start, end] = CreateModGrid(input);
  EXPECT_EQ(mod_grid, expected_grid);
  EXPECT_EQ(start, make_pair(2, 1));
  EXPECT_EQ(end, make_pair(0, 2));
}

TEST(CreateModGrid, SimpleTest3) {
  std::vector<std::vector<char>> input = {//
                                          {'s', ' ', ' ', ' ', 'i'},
                                          {' ', ' ', ' ', ' ', ' '},
                                          {' ', ' ', ' ', ' ', ' '},
                                          {' ', ' ', ' ', 's', ' '},
                                          {'y', ' ', ' ', ' ', ' '}};

  std::vector<std::vector<int>> expected_grid = {//
                                                 {0, 1, 2, 3, 4},
                                                 {1, 2, 3, 2, 3},
                                                 {2, 3, 2, 1, 2},
                                                 {3, 2, 1, 0, 1},
                                                 {4, 3, 2, 1, 2}};
  auto [mod_grid, start, end] = CreateModGrid(input);
  EXPECT_EQ(mod_grid, expected_grid);
  EXPECT_EQ(start, make_pair(4, 0));
  EXPECT_EQ(end, make_pair(0, 4));
}

//-----------------------------------------------------------------------------
// A pair whose first member is the input of the test function and its second is
// the expected output of the function.
using InputOutputType = std::pair<std::vector<std::vector<char>>, int>;

std::map<std::string, InputOutputType> input_map = {
    {"Empty", InputOutputType{{}, 0}},
    {"SizeTwo",
     InputOutputType({{//
                       {' ', 'i'},
                       {'y', ' '}},
                      2})},
    {"SizeThree_noShark",
     InputOutputType({{//
                       {' ', ' ', 'i'},
                       {' ', ' ', ' '},
                       {' ', 'y', ' '}},
                      4})},
    {"SizeThree_twoSharks",
     InputOutputType({{//
                       {' ', ' ', 'i'},
                       {' ', ' ', 's'},
                       {'s', 'y', ' '}},
                      1})},
    {"SizeThree_twoSharks_0",
     InputOutputType({{//
                       {' ', 's', 'i'},
                       {' ', ' ', 's'},
                       {'y', ' ', ' '}},
                      0})},
    {"SizeThree_twoSharks_0_2",
     InputOutputType({{//
                       {' ', ' ', 'i'},
                       {' ', 's', 's'},
                       {'s', 'y', ' '}},
                      0})},
    {"SizeThree_oneShark",
     InputOutputType({{//
                       {' ', ' ', 'i'},
                       {' ', ' ', 'y'},
                       {'s', ' ', ' '}},
                      3})},
    {"SizeThree_oneShark_2",
     InputOutputType({{//
                       {' ', 's', 'i'},
                       {' ', ' ', 'y'},
                       {' ', ' ', ' '}},
                      1})},
    {"SizeFour_oneShark",
     InputOutputType({{//
                       {'s', ' ', ' ', 'i'},
                       {' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' '},
                       {' ', 'y', ' ', ' '}},
                      3})},
    {"SizeFour_noShark",
     InputOutputType({{//
                       {' ', ' ', ' ', 'i'},
                       {' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' '},
                       {' ', 'y', ' ', ' '}},
                      6})},
    {"SizeFour_OneShark_2",
     InputOutputType({{//
                       {' ', ' ', ' ', 'i'},
                       {' ', ' ', ' ', 'y'},
                       {' ', ' ', ' ', ' '},
                       {'s', ' ', ' ', ' '}},
                      5})}

};

std::map<std::string, std::function<int(std::vector<std::vector<char>> &)>>
    function_map = {
        //
        {"FindMaxOfMinDistanceToSharksLinearSearch",
         FindMaxOfMinDistanceToSharksLinearSearch},
        {"FindMaxOfMinDistanceToSharksLinearSearchImproved",
         FindMaxOfMinDistanceToSharksLinearSearchImproved},
        // {"FindMaxOfMinDistanceToSharksBinarySearch",
        //  FindMaxOfMinDistanceToSharksBinarySearch}
        //
};
//-----------------------------------------------------------------------------
class FindMaxOfMinDistanceToSharksTest
    : public testing::TestWithParam<std::tuple<
          std::pair<const std::string,
                    std::function<int(std::vector<std::vector<char>> &)>>,
          std::pair<const std::string, InputOutputType>>> {};

INSTANTIATE_TEST_SUITE_P(
    FindMaxOfMinDistanceToSharks, FindMaxOfMinDistanceToSharksTest,
    Combine(ValuesIn(function_map), ValuesIn(input_map)),
    [](const testing::TestParamInfo<FindMaxOfMinDistanceToSharksTest::ParamType>
           &info) {
      return std::get<0>(info.param).first + "_" +
             std::get<1>(info.param).first;
    });

TEST_P(FindMaxOfMinDistanceToSharksTest, WorksForVariousInputs) {
  auto p = GetParam();

  auto function_under_test = std::get<0>(p).second;
  auto in = std::get<1>(p).second.first;

  auto actual = function_under_test(in);
  auto expected = std::get<1>(p).second.second;

  EXPECT_EQ(expected, actual);
}
