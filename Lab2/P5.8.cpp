#include <iostream>
#include <vector>
#include <string>
#include <sstream>

const int lineLength = 40;

// Helper function to justify a line of text
std::string justifyLine(std::vector<std::string> &words, int start, int end) {
  std::string line;
  int numWords = end - start + 1;
  int totalLength = 0;
  for (int i = start; i <= end; i++) {
    totalLength += words[i].length();
  }
  int numSpaces = lineLength - totalLength;
  int spacesBetweenWords = (numWords > 1) ? numSpaces / (numWords - 1) : 0;
  int extraSpaces = (numWords > 1) ? numSpaces % (numWords - 1) : 0;
  for (int i = start; i <= end; i++) {
    line += words[i];
    if (i < end) {
      line += std::string(spacesBetweenWords, ' ');
      if (extraSpaces > 0) {
        line += ' ';
        extraSpaces--;
      }
    }
  }
  return line;
}

int main() {
  std::vector<std::string> words;
  std::string word;
  std::string line;
  std::string paragraph;
  std::string input;
  
  std::cout << "Enter a paragraph of words, followed by end-of-file: ";
  while (std::getline(std::cin, input)) {
    std::stringstream ss(input);
    while (ss >> word) {
      words.push_back(word);
    }
  }
  
  int start = 0;
  int end = 0;
  int lineLength = 0;
  while (end < words.size()) {
    lineLength += words[end].length();
    if (lineLength > 40) {
      line = justifyLine(words, start, end - 1);
      paragraph += line + '\n';
      start = end;
      lineLength = words[end].length();
    }
    end++;
  }
  line = justifyLine(words, start, end - 1);
  paragraph += line;
  
  std::cout << paragraph << std::endl;
  
  return 0;
}
