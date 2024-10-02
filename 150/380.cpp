class RandomizedSet
{
public:
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (indexLookup.count(val))
        {
            return false;
        }
        indexLookup[val] = values.size();
        values.push_back(val);
        return true;
    }

    bool remove(int val)
    {
        if (!indexLookup.count(val))
        {
            return false;
        }
        int index = indexLookup[val];
        indexLookup[values.back()] = index;
        values[index] = values.back();
        values.pop_back();
        indexLookup.erase(val);
        return true;
    }

    int getRandom()
    {
        return values[rand() % values.size()];
    }

private:
    unordered_map<int, int> indexLookup;
    vector<int> values;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */