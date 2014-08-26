#include <thread>
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int elems = 100;
  int computation = 0;
  std::vector<int> q(elems, 1);
  std::vector<std::thread> threads;

  std::thread t1([&]() { for (auto & e : q) std::cout << e; } );
  std::thread t2([&](int& res) { for (auto &e : q) res += e; }, std::ref(computation));
  threads.push_back(std::move(t1));
  threads.push_back(std::move(t2));

  std::for_each(threads.begin(), threads.end(), [](std::thread &t){ t.join(); });

  std::cout << std::endl << computation << std::endl;
  return 0;
}
