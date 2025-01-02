#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <unordered_map>

int main() {
    std::vector<int> a, b;
    int x, y;

    while (std::cin >> x >> y) {
        a.push_back(x);
        b.push_back(y);
    }

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    int result = 0;
    for (size_t i = 0; i < a.size(); ++i) {
        result += std::abs(a[i] - b[i]);
    }

    std::cout << "Part 1: " << result << std::endl;

    std::unordered_map<int, int> cnt;
    for (int elem : b) {
        ++cnt[elem];
    }

    int result2 = 0;
    for (int elem : a) {
        if (cnt.find(elem) == cnt.end()) continue;
        result2 += elem * cnt[elem];
    }

    std::cout << "Part 2: " << result2 << std::endl;
    return 0;
}