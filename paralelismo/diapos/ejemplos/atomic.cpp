#include <thread>
#include <iostream>
#include <vector>
#include <atomic>


void sumar(const std::vector<int>& s1,
            const std::vector<int>& s2, int L, int R, std::atomic<int>& res) {
   for(int i=L; i<R; i++) {
      res += s1[i] * s2[i];
   }
}

 int main() {
   std::atomic<int> sumita(0);
   int elems = 1000000;
   int number_threads = 2;
   std::vector<int> q(elems,1);
   std::vector<int> w(elems,1);
   std::vector<std::thread> threads;
   for(int i = 0; i< number_threads; i++) {
     threads.push_back(
       std::thread(sumar, q, w,
                   i*(elems/number_threads),
                   (i+1)*(elems/number_threads), std::ref(sumita)));
   }
   for(auto &v : threads) v.join();
    std::cout << "La suma dio " << sumita << std::endl;
return 0;
}
