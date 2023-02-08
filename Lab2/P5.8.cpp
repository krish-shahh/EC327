#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

const int LINE_LENGTH = 40;

// Function to add spaces between words to make the line exactly LINE_LENGTH characters long
void addSpaces(std::string& line, int lineLength, int spacesToAdd) {
  int spaceIndex = 0;
  while (spacesToAdd > 0) {
    spaceIndex = line.find(" ", spaceIndex);
    if (spaceIndex == std::string::npos) {
      spaceIndex = 0;
    } else {
      line.insert(spaceIndex, " ");
      spaceIndex += 2;
      spacesToAdd--;
    }
  }
}

int main() {
  std::vector<std::string> words;
  std::string word;
  
  // Read words from the user until they enter "end"
  while (true) {
    std::cin >> word;
    if (word == "end") {
      break;
    }
    words.push_back(word);
  }

  std::string line;
  for (int i = 0; i < words.size(); i++) {
    if (line.length() + words[i].length() <= LINE_LENGTH) {
      line += words[i];
      if (i != words.size() - 1) {
        line += " ";
      } else {
        std::cout << line << std::endl;
      }
    } else {
      int spacesToAdd = LINE_LENGTH - line.length();
      addSpaces(line, LINE_LENGTH, spacesToAdd);
      std::cout << line << std::endl;
      line = words[i];
      if (i != words.size() - 1) {
        line += " ";
      } else {
        std::cout << line << std::endl;
      }
    }
  }

  return 0;
}
