#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

void view_cache(const map<string, vector<string>> &cache)
{
    for (const auto &i : cache)
    {
        cout << i.first << ": ";
        for (const auto &j : i.second)
            cout << j << "\t";
        cout << "\n";
    }
}

void build_cache(map<string, vector<string>> &cache, vector<string> &strings)
{
    for (size_t i = 0; i < strings.size(); ++i)
    {
        string curr_str = strings[i];
        std::sort(strings[i].begin(), strings[i].end());

        if (!cache.count(strings[i]))
            cache.insert({strings[i], {curr_str}});
        else
            cache[strings[i]].push_back(curr_str);
    }
    strings.resize(0);
}

vector<string> get_grouped_anagrams(const map<string, vector<string>> &cache)
{
    vector<string> result;
    for (const auto &i : cache)
    {
        for (const auto &j : i.second)
            result.push_back(j);
    }
    return result;
}

int main()
{
    map<string, vector<string>> cache;
    vector<string> strings = {"eat", "tea", "tan", "ate", "nat", "bat", "tab"};

    build_cache(cache, strings);

    // view_cache(cache);

    vector<string> groups_anagrams = get_grouped_anagrams(cache);

    for (const auto &i : groups_anagrams)
        cout << i << ":";
    cout << "\n";

    return 0;
}