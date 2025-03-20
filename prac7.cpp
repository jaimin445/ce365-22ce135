#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

unordered_map<char, vector<string>> grammar = {
    {'S', {"ABC", "D"}},
    {'A', {"a", "ε"}},
    {'B', {"b", "ε"}},
    {'C', {"(S)", "c"}},
    {'D', {"AC"}}
};


unordered_map<char, unordered_set<char>> computeFirstSets() {
    unordered_map<char, unordered_set<char>> firstSets;
    bool changed = true;

   
    for (auto &rule : grammar) {
        char nonTerminal = rule.first;
        for (auto &production : rule.second) {
            if (production == "ε") {
                firstSets[nonTerminal].insert('ε');
            } else if (!isupper(production[0])) {
                firstSets[nonTerminal].insert(production[0]);
            }
        }
    }

  
    while (changed) {
        changed = false;

        for (auto &rule : grammar) {
            char nonTerminal = rule.first;

            for (auto &production : rule.second) {
                if (production == "ε") continue;

                size_t i = 0;
                bool allCanBeEmpty = true;

                while (i < production.length() && allCanBeEmpty) {
                    char symbol = production[i];

                    if (isupper(symbol)) {
                        
                        for (char first : firstSets[symbol]) {
                            if (first != 'ε' && firstSets[nonTerminal].insert(first).second) {
                                changed = true;
                            }
                        }

               
                        if (firstSets[symbol].find('ε') == firstSets[symbol].end()) {
                            allCanBeEmpty = false;
                        }
                    } else {
                    
                        if (firstSets[nonTerminal].insert(symbol).second) {
                            changed = true;
                        }
                        allCanBeEmpty = false;
                    }
                    i++;
                }

                if (allCanBeEmpty) {
                    if (firstSets[nonTerminal].insert('ε').second) {
                        changed = true;
                    }
                }
            }
        }
    }

    return firstSets;
}

unordered_map<char, unordered_set<char>> computeFollowSets(const unordered_map<char, unordered_set<char>>& firstSets) {
    unordered_map<char, unordered_set<char>> followSets;
    bool changed = true;


    followSets['S'].insert('$');

   
    while (changed) {
        changed = false;

        for (auto &rule : grammar) {
            char nonTerminal = rule.first;

            for (auto &production : rule.second) {
                for (size_t i = 0; i < production.length(); i++) {
                    if (!isupper(production[i])) continue;

                    char currentSymbol = production[i];
                    bool allCanBeEmpty = true;

                    for (size_t j = i + 1; j < production.length() && allCanBeEmpty; j++) {
                        char nextSymbol = production[j];

                        if (isupper(nextSymbol)) {
                            for (char first : firstSets.at(nextSymbol)) {
                                if (first != 'ε' && followSets[currentSymbol].insert(first).second) {
                                    changed = true;
                                }
                            }

                            if (firstSets.at(nextSymbol).find('ε') == firstSets.at(nextSymbol).end()) {
                                allCanBeEmpty = false;
                            }
                        } else {
                            if (followSets[currentSymbol].insert(nextSymbol).second) {
                                changed = true;
                            }
                            allCanBeEmpty = false;
                        }
                    }

                    if (i == production.length() - 1 || allCanBeEmpty) {
                        for (char follow : followSets[nonTerminal]) {
                            if (followSets[currentSymbol].insert(follow).second) {
                                changed = true;
                            }
                        }
                    }
                }
            }
        }
    }

    return followSets;
}

void printSets(const unordered_map<char, unordered_set<char>>& sets, const string& setName) {
    for (const auto& pair : sets) {
        char nonTerminal = pair.first;
        cout << setName << "(" << nonTerminal << ") = {";
        vector<char> sortedSymbols(pair.second.begin(), pair.second.end());
        sort(sortedSymbols.begin(), sortedSymbols.end());

        bool first = true;
        for (char symbol : sortedSymbols) {
            if (!first) cout << ", ";
            cout << symbol;
            first = false;
        }
        cout << "}" << endl;
    }
}

int main() {
    unordered_map<char, unordered_set<char>> firstSets = computeFirstSets();
    unordered_map<char, unordered_set<char>> followSets = computeFollowSets(firstSets);

    printSets(firstSets, "First");
    cout << endl;
    printSets(followSets, "Follow");

    return 0;
}