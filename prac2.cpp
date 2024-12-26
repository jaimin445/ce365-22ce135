#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    int numInputs, stateCount, startState, numFinalStates;
    
    // Read input symbols
    cout << "Enter the number of input symbols: ";
    cin >> numInputs;
    vector<char> inputSymbols(numInputs);
    cout << "Enter input symbols: ";
    for (int i = 0; i < numInputs; ++i) {
        cin >> inputSymbols[i];
    }

    // Read states and transitions
    cout << "Enter the total number of states: ";
    cin >> stateCount;
    cout << "Enter the starting state: ";
    cin >> startState;
    
    cout << "Enter the number of final states: ";
    cin >> numFinalStates;
    vector<int> finalStates(numFinalStates);
    cout << "Enter final states: ";
    for (int i = 0; i < numFinalStates; ++i) {
        cin >> finalStates[i];
    }

    // Define transition table
    vector<vector<int> > transitionTable(stateCount + 1, vector<int>(numInputs));
    cout << "transition table:\n";
    for (int state = 1; state <= stateCount; ++state) {
        for (int symbolIndex = 0; symbolIndex < numInputs; ++symbolIndex) {
            cout << "State " << state << " with " << inputSymbols[symbolIndex] << " : ";
            cin >> transitionTable[state][symbolIndex];
        }
    }

    // Process the input string
    string inputString;
    cout << "Enter the input string: ";
    cin >> inputString;

    int currentState = startState;
    for (char ch : inputString) {
        auto it = find(inputSymbols.begin(), inputSymbols.end(), ch);
        if (it == inputSymbols.end()) {
            cout << "Invalid input symbol: " << ch << endl;
            return 1;
        }
        int symbolIndex = distance(inputSymbols.begin(), it);
        currentState = transitionTable[currentState][symbolIndex];
    }

    // Check if the final state is accepting
    if (find(finalStates.begin(), finalStates.end(), currentState) != finalStates.end()) {
        cout << "The string is accepted." << endl;
    } else {
        cout << "The string is rejected." << endl;
    }

    return 0;
}
