#include <iostream>
using namespace std;

int runs(int nn) {
  while (nn!=1) {
    cout << nn = (nn%2==0?nn>>1:(nn<<1)+nn+1);
  }
}