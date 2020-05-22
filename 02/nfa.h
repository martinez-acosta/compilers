#ifndef NFA_H
#define NFA_H
#include <QString>
#include <QStringList>
#include <algorithm>
#include <fstream>
#include <list>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include "state.h"

char epsilon = 'E';

class NFA {
 public:
  void testString(std::string &);
  void init(std::string &);

 private:
  std::vector<State *> states;
  std::set<std::string> alphabet;
  std::set<State *> endSet;
  State *initial;
  std::vector<int> final;
  State *getNextState(int);
  void epsilonClosure(std::set<State *> &, State *);
  void epsilonClosure2(std::set<State *> &, State *);
};

inline State *NFA::getNextState(int id) {
  for (auto c : states) {
    if (c->id == id) {
      return c;
    }
  }
}

inline void NFA::epsilonClosure(std::set<State *> &next, State *s) {
  State *p;
  for (auto t : s->transitions)
    if (t.first[0] == epsilon) {
      p = new State(getNextState(t.second));
      p->path.append(s->path + "q" + std::to_string(s->id) + "(E)->");
      epsilonClosure(next, p);
    }

  // como ya no hay transiciones epsilon
  for (auto t : s->transitions)
    if (t.first[0] == epsilon) return;
  // s->path.append("q" + std::to_string(s->id) + "(");
  next.insert(s);
}

inline void NFA::epsilonClosure2(std::set<State *> &next, State *s) {
  State *p;
  for (auto t : s->transitions)
    if (t.first[0] == epsilon) {
      p = new State(getNextState(t.second));
      p->path.append(s->path + "q" + std::to_string(s->id) + "(E)->");
      epsilonClosure2(next, p);
    }
  for (auto i : final)
    if (s->id == i) next.insert(s);

  // como ya no hay transiciones epsilon
  for (auto t : s->transitions)
    if (t.first[0] == epsilon) return;
  // s->path.append("q" + std::to_string(s->id) + "(");
  next.insert(s);
}

inline void NFA::init(std::string &filename) {
  std::string str;
  QString line;
  std::ifstream input(filename);

  if (!input.is_open()) {
    std::cout << "Unable to open file " << filename << '\n';
    exit(1);
  }

  QStringList list;
  int i = 0, j;
  while (std::getline(input, str)) {
    line = line.fromStdString(str);
    switch (i) {
      case 0:  // states
        list = line.split(',');

        for (QString &v : list) states.push_back(new State(v.toInt()));
        break;
      case 1:  // alphabet
        list = line.split(',');
        for (QString &v : list) alphabet.insert(v.toStdString());
        break;
      case 2:  // initial state
        j = line.toInt();
        for (State *v : states)
          if (v->id == j) {
            initial = v;
            break;
          }

        break;
      case 3:  // set final states
        list = line.split(',');
        for (QString &v : list) final.push_back(v.toInt());
        break;
      default:  // transitions
        list = line.split(
            ',');  // cada lista tiene 3 elementos: estado_A, string, estado_B
        // buscamos el estado_A y agregamos su transición al estado_B
        for (State *s : states)
          if (s->id == list.at(0).toInt()) {
            s->transitions.push_back(
                std::make_pair(list.at(1).toStdString(), list.at(2).toInt()));
            break;
          }
        break;
    }
    i++;
    list.clear();
  }

  input.close();
}

inline void NFA::testString(std::string &input) {
  std::set<State *> current;
  std::set<State *> next;
  State *p;

  current.insert(new State(initial));
  for (char &c : input) {     // for every char in string
    for (auto s : current) {  // epsilon closure
      s->path.append("q" + std::to_string(s->id) + "(");
      for (auto &t : s->transitions)
        if (t.first[0] == epsilon) {
          p = new State(getNextState(t.second));
          p->path.append(s->path + "E)->");
          epsilonClosure(next, p);
        }
    }

    for (auto s : next) {
      s->path.append("q" + std::to_string(s->id) + "(");
      current.insert(s);
    }
    next.clear();
    for (auto s : current)
      for (auto &t : s->transitions)  // for every transition in state
        if (t.first[0] == c) {        // if there is a valid transition
          p = new State(
              getNextState(t.second));  // get next state and make a copy
          p->path.append(s->path);
          p->path.append(t.first + ")->");  // append the path
          next.insert(p);
        }
    current.clear();
    for (auto s : next) {  // current set = next set
      current.insert(s);
    }
    next.clear();
  }

  //última cerradura epsilon
  for (auto s : current) {  // epsilon closure
    s->path.append("q" + std::to_string(s->id) + "(");
    for (auto &t : s->transitions)
      if (t.first[0] == epsilon) {
        p = new State(getNextState(t.second));
        p->path.append(s->path + "E)->");
        epsilonClosure2(next, p);
      }
  }

  for (auto s : next) {
    // s->path.append("q" + std::to_string(s->id) + "(");
    current.insert(s);
  }
  next.clear();

  // impresion final
  // if there is a valid final state, print

  for (auto s : current)
    for (int f : final)
      if (s->id == f)
        std::cout << s->path << "q" << std::to_string(s->id) << '\n';
}

#endif  // CLASSES_H
