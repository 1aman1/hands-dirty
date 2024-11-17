// This problem was asked by Google.

// You are given a set of synonyms, such as (big, large) and (eat, consume). Using this set, determine if two sentences with the same number of words are equivalent.

// For example, the following two sentences are equivalent:

// "He wants to eat food."
// "He wants to consume food."
// Note that the synonyms (a, b) and (a, c) do not necessarily imply (b, c): consider the case of (coach, bus) and (coach, teacher).


#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

class DSU {
public:
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {
            parent[rootX] = rootY;
        }
    }

private:
    vector<int> parent;
};

bool areSentencesEquivalent(const vector<string>& sentence1, const vector<string>& sentence2, 
                            unordered_map<string, int>& wordIndex, DSU& dsu) {
    if (sentence1.size() != sentence2.size()) return false;

    for (size_t i = 0; i < sentence1.size(); ++i) {
        int index1 = wordIndex[sentence1[i]];
        int index2 = wordIndex[sentence2[i]];
        if (dsu.find(index1) != dsu.find(index2)) {
            return false;
        }
    }

    return true;
}

int main() {
    vector<pair<string, string>> synonyms = {{"big", "large"}, {"eat", "consume"}};
    vector<string> sentence1 = {"He", "wants", "to", "eat", "food"};
    vector<string> sentence2 = {"He", "wants", "to", "consume", "food"};

    unordered_set<string> uniqueWords;
    for (const auto& pair : synonyms) {
        uniqueWords.insert(pair.first);
        uniqueWords.insert(pair.second);
    }
    for (const string& word : sentence1) {
        uniqueWords.insert(word);
    }
    for (const string& word : sentence2) {
        uniqueWords.insert(word);
    }

    unordered_map<string, int> wordIndex;
    int index = 0;
    for (const string& word : uniqueWords) {
        wordIndex[word] = index++;
    }

    DSU dsu(uniqueWords.size());

    for (const auto& pair : synonyms) {
        int index1 = wordIndex[pair.first];
        int index2 = wordIndex[pair.second];
        dsu.unionSets(index1, index2);
    }

    if (areSentencesEquivalent(sentence1, sentence2, wordIndex, dsu)) {
        cout << "The sentences are equivalent." << endl;
    } else {
        cout << "The sentences are not equivalent." << endl;
    }

    return 0;
}
