#include "automaton.h"

//Give a string, return a vector of strings with the symbols of the string separated
std::vector<std::string> vectorSplit(std::string str, char delimiter) {
  std::vector<std::string> internal;
  std::istringstream iss(str); // Turn the string into a stream.
  std::string tok;
  
  while(std::getline(iss, tok, delimiter)) {
    internal.push_back(tok);
  }
  return internal;
}

//Given a string, return an unordered set with the symbols of the string separated
std::unordered_set<std::string> ustSplit(std::string str, char delimiter) {
  std::unordered_set<std::string> internal;
  std::istringstream iss(str); // Turn the string into a stream.
  std::string tok;
  
  while(std::getline(iss, tok, delimiter)) {
    internal.insert(tok);
  }
  return internal;
}

Automaton::Automaton (std::ifstream &file) {
  if(!file.is_open()) {
    std::cerr << "Error opening file " << std::endl;
    exit(1);
  }

  this->loadAutomaton(file);
  file.close();
  this->checkAutomaton();

  this->initialize();
  };

Automaton::Automaton(std::string filename) {
  std::ifstream file(filename, std::ios::in);
  if(!file.is_open()) {
    std::cerr << "Error opening file " << filename << std::endl;
    exit(1);
  }

  this->loadAutomaton(file);
  file.close();
  this->checkAutomaton();
  this->initialize();
};

void Automaton::loadAutomaton(std::ifstream &in) {
  //eliminate initial comments
  std::string line;
  do {
    std::getline(in, line);
    line = line.substr(0, line.find('#'));
  } while(line == "");
  
  //read states
  states = ustSplit(line, ' ');

  // read alphabet
  std::getline(in, line);
  line = line.substr(0, line.find('#'));
  alphabet = ustSplit(line, ' ');

  // read stack alphabet
  std::getline(in, line);
  line = line.substr(0, line.find('#'));
  stackAlphabet = ustSplit(line, ' ');

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
    std::vector<std::string> parts = vectorSplit(line, ' ');
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

void Automaton::checkAutomaton() {
  //check if initial state is in states 
  if(states.find(initialState) == states.end()) {
    std::cerr << "Initial state " << initialState << " is not in states" << std::endl;
    exit(2);
  }

  //check if initial stack symbol is in stack alphabet  
  if(stackAlphabet.find(initialStackSymbol) == stackAlphabet.end()) {
    std::cerr << "Initial stack symbol " << initialStackSymbol << " is not in stack alphabet" << std::endl;
    exit(2);
  }

  //check if all transitions are valid
  for(int i = 0; i < transitions.size(); i++) {
    std::string fromState = transitions[i].fromState;
    std::string toState = transitions[i].toState;
    std::string input = transitions[i].input;
    std::string pop = transitions[i].pop;
    std::string push = transitions[i].push;

    //check if fromState is in states
    if(states.find(fromState) == states.end()) {
      std::cerr << "Transition " << i << " has fromState " << fromState << " which is not in states" << std::endl;
      exit(2);
    }

    //check if toState is in states
    if(states.find(toState) == states.end()) {
      std::cerr << "Transition " << i << " has toState " << toState << " which is not in states" << std::endl;
      exit(2);
    }

    //check if input is in alphabet
    if(alphabet.find(input) == alphabet.end() && input != ".") {
      std::cerr << "Transition " << i << " has input " << input << " which is not in alphabet" << std::endl;
      exit(2);
    }

    //check if pop is in stack alphabet
    if(stackAlphabet.find(pop) == stackAlphabet.end()) {
      std::cerr << "Transition " << i << " has pop " << pop << " which is not in stack alphabet" << std::endl;
      exit(2);
    }

    //check if push is in stack alphabet
    std::vector<std::string> pushSymbols = vectorSplit(push, ' ');
    for(int j = 0; j < pushSymbols.size(); j++) {
      if(stackAlphabet.find(pushSymbols[j]) == stackAlphabet.end() && pushSymbols[j] != ".") {
        std::cerr << "Transition " << i << " has push " << pushSymbols[j] << " which is not in stack alphabet" << std::endl;
        exit(2);
      }
    }
  }
}

void Automaton::initializeStack() {
  stack = new std::stack<std::string>();
  stack->push(initialStackSymbol);
}

bool Automaton::checkWord(std::string word, int wordIndex) {
  
  if(stack->empty()) {
    if(wordIndex == word.length()) {
      return true;
    }
    return false;
  }

  std::string symbol(1, word[wordIndex]);
  std::string currentStackSymbol = stack->top();
  std::vector<Transition> possibleTransitions = getPossibleTransitions(currentState, symbol, currentStackSymbol);

  for(int i = 0; i < possibleTransitions.size(); i++) {
    Transition transition = possibleTransitions[i];
    std::string nextState = transition.toState;
    std::string pushSymbols = transition.push;

    currentState = nextState;
    stack->pop();
    std::vector<std::string> pushSymbolsVector = vectorSplit(pushSymbols, ' ');
    for(int j = pushSymbolsVector.size() - 1; j >= 0; j--) {
      if(pushSymbolsVector[j] != ".") {
        stack->push(pushSymbolsVector[j]);
      }
    }
    
    if(transition.input == ".") {
      if(checkWord(word, wordIndex)) {
        return true;
      }
    } else {
      if(checkWord(word, wordIndex + 1)) {
        return true;
      }
    }

    currentState = transition.fromState;
    for(int j = 0; j < pushSymbolsVector.size(); j++) {
      if(pushSymbolsVector[j] != ".") {
        stack->pop();
      }
    }
    stack->push(transition.pop);
  }
  return false;
}

std::ostream& Automaton::write(std::ostream& os) {
  os << "States: ";
  for(auto state : states) {
    os << state << " ";
  }
  os << std::endl;

  os << "Alphabet: ";
  for(auto symbol : alphabet) {
    os << symbol << " ";
  }
  os << std::endl;

  os<< "Stack Alphabet: ";
  for(auto symbol : stackAlphabet) {
    os << symbol << " ";
  }
  os << std::endl;

  os << "Initial State: " << initialState << std::endl;
  os << "Initial Stack Symbol: " << initialStackSymbol << std::endl;

  os << "Transitions: " << std::endl;
  for(auto transition : transitions) {
    os << transition << std::endl;
  }
  return os;
}

void Automaton::setTrace(bool value){
  trace = value;
}

std::vector<Transition> Automaton::getPossibleTransitions(std::string state, std::string input, std::string stackSymbol) {
  std::vector<Transition> possibleTransitions;
  for(int i = 0; i < transitions.size(); i++) {
    if(transitions[i].fromState == state && transitions[i].pop == stackSymbol && (transitions[i].input == input || transitions[i].input == ".")) {
      possibleTransitions.push_back(transitions[i]);
    }
  }
  return possibleTransitions;
}
