#include "file.h"
#include "string.h"

#include <fstream>

bool util::file::exists(std::string path) {
  std::ifstream infile(path);
  return infile.good();
}

std::vector<std::string> util::file::readLines(std::string path) {
  std::vector<std::string> lines;
  std::ifstream file(path, std::ifstream::in);
  std::string line;
  char c;

  while (file.get(c)) {
    if (c == '\n') {
      lines.push_back(line);
      line = "";
    } else {
      line += c;
    }
  }

  lines.push_back(line);
  file.close();

  return lines;
}

std::vector<std::string> util::file::readCleanLines(std::string path) {
  auto lines = readLines(path);

  for (auto it = lines.begin(); it != lines.end();) {
    if (it->empty() || it->at(0) == '#') {
      it = lines.erase(it);
    } else {
      *it = util::string::trim(*it);
      ++it;
    }
  }

  return lines;
}