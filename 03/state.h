#ifndef STATE_H
#define STATE_H

#include <string>
#include <utility>
#include <vector>

class State {
 public:
  const int id;
  std::vector<std::pair<std::string, int>> transitions;
  std::string path;
  State(int x) : id(x) {}
  State() : id(0) {}
  State(State*p) : id(p->id){
      for(auto s: p->transitions)
          this->transitions.push_back(s);
      path = p->path;
  }
};
#endif  // STATE_H
