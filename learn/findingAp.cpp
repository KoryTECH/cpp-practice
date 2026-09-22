#include <iostream>
#include <vector>

static long findMissing(std::vector<long> list) {
  if (list.empty()) {
    return 0;
  }

  if (list.size() < 2) {
    return list[0];
  }

  long difference = (list.back() - list.front()) / static_cast<long>(list.size());

  for (std::size_t i = 1; i < list.size(); ++i) {
    if (list[i] - list[i - 1] != difference) {
      return list[i - 1] + difference;
    }
  }

  return list[0];
}

int main() {
    std::vector<long> test = {1, 3, 5, 9, 11};
    std::cout << "Missing value: " << findMissing(test) << '\n';
}
    