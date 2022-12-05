#include "automaton.h"

//Dada una cadena, devolver un vector de cadenas con los simbolos de la cadena separados
std::vector<std::string> split(std::string str, char delimiter) {
  std::vector<std::string> internal;
  std::istringstream iss(str); // Turn the string into a stream.
  std::string tok;
  
  while(std::getline(iss, tok, delimiter)) {
    internal.push_back(tok);
  }
  
  return internal;
}

void Automaton::loadAutomaton(std::ifstream &in) {
  //eliminate initial comments
  std::string line;
  do {
    std::getline(in, line);
    line = line.substr(0, line.find('#'));
  } while(line == "");
  
  //read states
  states = split(line, ' ');

  // read alphabet
  std::getline(in, line);
  line = line.substr(0, line.find('#'));
  alphabet = split(line, ' ');

  // read stack alphabet
  std::getline(in, line);
  line = line.substr(0, line.find('#'));
  stackAlphabet = split(line, ' ');

  // read initial state
  std::getline(in, line);
  line = line.substr(0, line.find('#'));
  initialState = line;

  // read initial stack symbol
  std::getline(in, line);
  line = line.substr(0, line.find('#'));
  initialStackSymbol = line;

  while(std::getline(in, line)) {
    line = line.substr(0, line.find('#'));
    if(line == "") continue;
    std::vector<std::string> parts = split(line, ' ');
    std::string state = parts[0];
    std::string symbol = parts[1];
    std::string stackSymbol = parts[2];
    std::string nextState = parts[3];
    std::string stackSymbols = parts[4];

    for(int i = 5; i < parts.size(); i++) {
      stackSymbols += " " + parts[i]; //allow multiple stack values
    }
    
    transitions.push_back(Transition(state, symbol, stackSymbol, nextState, stackSymbols));
  }
}

bool Automaton::checkWord(std::string word) {
  return false;
}

void Automaton::printAutomaton(){

}

void Automaton::setTrace(bool value){
  trace = value;
}