#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

// Function to validate if the input string is accepted by the finite automaton
bool validateString(const unordered_map<int, unordered_map<char, int> >& transitionTable,
                    int initialState, const unordered_set<int>& acceptingStates,
                    const string& inputString) {
    int currentState = initialState; // Start at the initial state

    // Process each symbol in the input string
    for (char symbol : inputString) {
        // Check if there's a valid transition for the current symbol
        if (transitionTable.at(currentState).count(symbol) == 0) {
            return false; // Invalid transition, reject the string
        }
        currentState = transitionTable.at(currentState).at(symbol); // Move to the next state
    }

    // Check if the final state is one of the accepting states
    return acceptingStates.count(currentState) > 0;
}

int main() {
    int noOfStates, initialState, noOfAcceptingStates; // Number of states, initial state, and accepting states
    string inputSymbols, inputString; // Symbols and input string
    unordered_set<int> acceptingStates; // Set of accepting states
    unordered_map<int, unordered_map<char, int> > transitionTable; // Transition table

    // Input symbols
    cout << "Enter input symbols: ";
    cin >> inputSymbols; // Take the allowed input symbols as a string

    // Number of states
    cout << "Enter number of states: ";
    cin >> noOfStates; // Number of states in the finite automaton

    // Initial state
    cout << "Enter initial state: ";
    cin >> initialState; // Specify the initial state

    // Accepting states
    cout << "Enter number of accepting states: ";
    cin >> noOfAcceptingStates; // Number of accepting states
    cout << "Enter accepting states: ";
    for (int i = 0; i < noOfAcceptingStates; ++i) {
        int state;
        cin >> state; // Input each accepting state
        acceptingStates.insert(state); // Add it to the set
    }

    // Transition table
    cout << "Define transitions:\n";
    for (int state = 1; state <= noOfStates; ++state) { // For each state
        for (char symbol : inputSymbols) { // For each input symbol
            cout << "State " << state << " + Symbol '" << symbol << "' -> Next State: ";
            int nextState;
            cin >> nextState; // Input the next state for the given state and symbol
            transitionTable[state][symbol] = nextState; // Add transition to the table
        }
    }

    // Input string
    cout << "Enter input string: ";
    cin >> inputString; // String to be validated

    // Validate the input string
    if (validateString(transitionTable, initialState, acceptingStates, inputString)) {
        cout << "The input string is ACCEPTED." << endl; // Accepted case
    } else {
        cout << "The input string is REJECTED." << endl; // Rejected case
    }

    return 0;
}
