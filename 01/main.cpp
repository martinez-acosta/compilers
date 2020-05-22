#include <iostream>
#include <string>
#include "cmdline.h"
#include "nfa.h"
#include "state.h"

int main(int argc, char **argv) {
  gengetopt_args_info args_info;

  if (cmdline_parser(argc, argv, &args_info) != 0) {
    std::cout << "Unable to start cmdline_parser\n";
    exit(1);
  }

  std::string filename(args_info.input_arg);
  std::string input;

  NFA nfa;
  nfa.init(filename);

  std::cout << "Enter the string to be tested:\n";
  std::cin >> input;

  nfa.testString(input);
  return 0;
}
