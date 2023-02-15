#include <iostream>

int main() {
  int y = 2;
  int y_post_decrement = y--;
  int y_post_increment = y++;
  int result = ((int)(y_post_decrement > y_post_increment) ? ((4 * 10) + 2) : 0);
  std::cout << result << std::endl;
  return 0;
}
