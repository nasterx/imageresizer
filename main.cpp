#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sys/types.h>
#include <dirent.h>
#include "CImg.h"

std::vector<std::string> *listdir(const char*);

int main(int argc, char* argv[]) {
  if(argc < 2) {
    std::cerr << "Error: no directory." << std::endl;
  }
  std::vector<std::string> *vec;
  vec = listdir(argv[1]);
  std::vector<std::string>::iterator it = vec->begin();
  for(; it != vec->end(); ++it) {
    std::cout << *it << std::endl;
  }
  return 0;
}

std::vector<std::string> *listdir(const char *dirname) {
  DIR *dp;
  dirent *d;
  std::vector<std::string> * vec = new std::vector<std::string>;

  dp = opendir(dirname);
  while((d= readdir(dp)) != NULL) {
    vec->push_back(d->d_name);
  }
  std::sort(vec->begin(), vec->end());
  return vec;
}
