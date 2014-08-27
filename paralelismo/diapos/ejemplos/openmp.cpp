#include <iostream>
#include <vector>

int main() {
  int elementos = 1000*1000;
  int suma = 0;
  std::vector<int> a(elementos, 1);
  std::vector<int> b(elementos, 2);
  std::vector<int> resultado(elementos, 0);

#pragma omp parallel for
  for(int i=0; i<elementos; i++) {
    resultado[i] = a[i]+b[i];
  }

#pragma omp parallel for reduce(+:suma)
  for(int i=0; i<elementos; i++) {
    suma += resultado[i];
  }
  std::cout << suma << std::endl;
  return 0;
}
