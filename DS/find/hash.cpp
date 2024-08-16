#include <iostream>

using namespace std;


template <typename Func, typename... Args>
int timeFunction(int iterations, Func&& func, Args&&... args) {
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < iterations; ++i) {
        std::forward<Func>(func)(std::forward<Args>(args)...);
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Average time taken for " << iterations << " iterations: "
              << duration.count() << " milliseconds" << std::endl;