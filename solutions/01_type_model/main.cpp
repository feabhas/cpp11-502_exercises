// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include <iostream>

int main()
{
  std::cout << "sizeof(bool):\t" << sizeof(bool) << '\n';
  std::cout << "sizeof(char):\t" << sizeof(char) << '\n';
  std::cout << "sizeof(short):\t" << sizeof(short) << '\n';
  std::cout << "sizeof(int):\t" << sizeof(int) << '\n';
  std::cout << "sizeof(long):\t" << sizeof(long) << '\n';
  std::cout << "sizeof(long long):\t" << sizeof(long long) << '\n';

  std::cout << "sizeof(float):\t" << sizeof(float) << '\n';
  std::cout << "sizeof(double):\t" << sizeof(double) << '\n';
  std::cout << "sizeof(long double):\t" << sizeof(long double) << '\n';

  std::cout << "sizeof(void*):\t" << sizeof(void*) << '\n';

  std::cout << '\n'; // force fflush
}
