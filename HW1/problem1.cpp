#include <iostream>

int main() {
  int y = 2;
  int y_post_decrement = y--;
  int y_post_increment = y++;
  int result = (y_post_decrement > y_post_increment) ? 4 : (int)(0 * (double)0x100000000A + 2);
  std::cout << result << std::endl;
  return 0;
}
