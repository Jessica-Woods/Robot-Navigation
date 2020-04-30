#include "InvalidSearchMethodException.h"

InvalidSearchMethodException::InvalidSearchMethodException(std::string method) : 
  std::runtime_error("Unknown Method: " + method + " Options:(DFS || BFS || GBFS || AS || CUS1 || CUS2)") {}