#ifndef NFA_H
#define NFA_H
#include "state.h"
#include <QString>
#include <QStringList>
#include <algorithm>
#include <fstream>
#include <deque>
#include <set>
#include <tuple>
#include <string>
#include <vector>


char epsilon = 'E';
class SetState {
public:
  const char id;
  //const char c;
  void addState(State *s) { states.insert(s); }

  void removeState(State *s) {
    for (auto c : states)
      if (s->id == c->id)
        states.erase(c);
  }
  std::set<State *> getStates() { return states; }
  SetState(std::set<State *> &set, char id) : id(id){
    for (auto s : set)
      states.insert(s);
    //transitions.push_back(std::make_pair(from,character));
  }
  int getSize(){return states.size();}
  std::vector<std::pair<char,char>>transitions;
private:
  std::set<State *> states;

};

class NFA {
public:
  void subSetConstruction();
  void init(std::string &);

private:
  std::vector<State *> states;
  std::set<std::string> alphabet;
  State *initial;
  std::vector<int> final;
  std::vector<SetState> estados;
  std::vector<std::tuple<char,char,char>>transiciones;
  State *getNextState(int);
  bool isFinal(int);
  bool isNewSet(std::set<State *> &);
  bool Final(SetState &);
  bool Initial(SetState &);
  bool exist(int i, std::set<State *> &set) {
    for (auto s : set)
      if (s->id == i)
        return true;
    return false;
  }
  char nth_letter(int n);
  char getDelta(char from, char ch) {
      for(auto set: estados)
          for(auto t: transiciones)
              if( std::get<0>(t) == from && std::get<1>(t) == ch && std::get<2>(t) == set.id)
                  return set.id;

      return '0';
  }
  char getID(std::set<State *> &tmp){
      int counter = 0;
      for (auto set : estados) { // cada SetState solo tiene único conjunto de estados
        counter = 0;
        for (State* s1 : set.getStates()){
          for (State* s : tmp)
            if (s1->id == s->id)
              counter++;
        if (counter == tmp.size() && counter == set.getSize()) // si ya existe el conjunto...
          return set.id;
        }
      }

  }
  void epsilonClosure(std::set<State *> &, State *);
  void closure(std::set<State *> &, State *);
  void mover(std::set<State *> &, std::set<State *> &, char &);
  void irA(std::set<State *> &, SetState &, char &);
  void print(std::vector<SetState>&);
};

inline State *NFA::getNextState(int id) {
  for (auto c : states)
    if (c->id == id)
      return c;
}

inline char NFA::nth_letter(int n) {
  if (n >= 1 && n <= 26)
    return "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[n - 1];
}

inline bool NFA::isFinal(int id) {
  for (auto s : states)
    for (auto i : final)
      if (s->id == i)
        return true;
  return false;
}

inline void NFA::closure(std::set<State *> &next, State *s) {
  for (auto t : s->transitions)
    if (t.first[0] == epsilon) {
      if (isFinal(s->id))
        next.insert(s);
      epsilonClosure(next, getNextState(t.second));
    }

  int i = 0;
  for (auto t : s->transitions)
    if (t.first[0] == epsilon)
      i++;
  if (i)
    return;
  else
    next.insert(s);
}
inline void NFA::epsilonClosure(std::set<State *> &next, State *s) {
  next.insert(s);
  closure(next, s);
}

inline void NFA::mover(std::set<State *> &tmp, std::set<State *> &set,
                       char &c) {
  std::set<State *> tmp2;
  for (auto s : set)
    for (auto t : s->transitions)
      if (t.first[0] == c)
        tmp2.insert(getNextState(t.second));

  // como puede haber estados repetidos, eliminamos los que sobran

  for (auto s : tmp2)
    if (!exist(s->id, tmp)) // si no existe el estado en tmp, lo agregamos
      tmp.insert(s);
}

inline void NFA::irA(std::set<State *> &tmp, SetState &current, char &c) {
  std::set<State *> set = current.getStates();
  std::set<State *> next;

  mover(tmp, set, c);
  for (auto s : tmp) {
    epsilonClosure(next, s);
  }

  tmp.clear();

  for (auto s : next)
    if (!exist(s->id, tmp)) // si no existe el estado en tmp, lo agregamos
      tmp.insert(s);
}

inline bool NFA::Final(SetState &set) {
    for (auto s: set.getStates())
        for (int i : final)
          if (s->id == i)
            return true;
    return false;
}

inline bool NFA::Initial(SetState &set) {
    for (auto  s: set.getStates())
        if (s->id == initial->id)
            return true;
    return false;
}
inline bool NFA::isNewSet(std::set<State *> &tmp) {
  int counter = 0;
  for (auto set : estados) { // cada SetState solo tiene único conjunto de estados
    counter = 0;
    for (State* s1 : set.getStates()){
      for (State* s : tmp)
        if (s1->id == s->id)
          counter++;
    if (counter == tmp.size() && counter == set.getSize()) // si ya existe el conjunto...
      return false;
    }
  }
  return true;
}

inline void NFA::subSetConstruction() {
  char id = 26;
  std::set<State *> tmp;
  std::deque<SetState> norevisados;
  tmp.insert(initial);

  epsilonClosure(tmp, initial);
  estados.push_back(SetState(tmp, nth_letter(id))); // guardamos el nuevo conjunto
  norevisados.push_front(estados.back());
  //id--;
  tmp.clear();
  do {
    for (auto c : alphabet) {
      irA(tmp, norevisados.back(), c[0]);
      if (tmp.size() != 0 && isNewSet(tmp)) {
          id--;
        estados.push_back(SetState(tmp, nth_letter(id))); // guardamos el nuevo conjunto
        estados.at(estados.size()-1).transitions.push_back(std::make_pair(norevisados.back().id, c[0]));
        transiciones.push_back(std::make_tuple(norevisados.back().id,c[0],estados.back().id));


        norevisados.push_front(estados.back()); //lo agregamos al inicio de la pila
      } else {
          transiciones.push_back(std::make_tuple(norevisados.back().id,c[0],getID(tmp)));
      }
      tmp.clear();
    }
    norevisados.pop_back();//eliminamos el conjunto que ya revisamos...
  } while (!norevisados.empty());
  print(estados);
}
inline void NFA::print(std::vector<SetState> &estados) {

    int i = 0;
    for(auto set: estados) {
        std::cout<<set.id<<":{";
        i = 0;
        for (auto s: set.getStates())
            if ( i < set.getSize()-1){
                std::cout<<s->id<<", ";
                i++;
            } else
                std::cout<<s->id<<"}\n";
    }
    std::cout << "   \u03B4     |     ";
    for (auto c: alphabet)
        std::cout<<c<<"     |     ";
    std::cout<<'\n';
    for (int i=0; i<50;i++)
        std::cout<<"-";
    std::cout<<'\n';

    for (auto set: estados) {
        if (Initial(set) && Final(set))
            std::cout<<"->*"<<set.id<<"     |";
        else if (Initial(set))
            std::cout<<"-> "<<set.id<<"     |";
        else if(Final(set))
            std::cout<<"*  "<<set.id<<"     |";
        else
            std::cout<<"   "<<set.id<<"     |";
        for(auto c: alphabet)
            std::cout<<"   "<<getDelta(set.id,c[0])<<"     |";
        std::cout<<'\n';
    }
char a;

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
    case 0: // states
      list = line.split(',');

      for (QString &v : list)
        states.push_back(new State(v.toInt()));
      break;
    case 1: // alphabet
      list = line.split(',');
      for (QString &v : list)
        alphabet.insert(v.toStdString());
      break;
    case 2: // initial state
      j = line.toInt();
      for (State *v : states)
        if (v->id == j) {
          initial = v;
          break;
        }

      break;
    case 3: // set final states
      list = line.split(',');
      for (QString &v : list)
        final.push_back(v.toInt());
      break;
    default: // transitions
      list = line.split(
          ','); // cada lista tiene 3 elementos: estado_A, string, estado_B
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

#endif // CLASSES_H
