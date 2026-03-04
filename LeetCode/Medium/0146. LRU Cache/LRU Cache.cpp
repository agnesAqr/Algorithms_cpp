    }
private:
            if (cacheMap.size() == capacity)
        }
        else
        {
            auto target_iter = cacheMap[key];
        }
            {
                int removeKey = cacheList.back().first;
            }
                cacheList.pop_back();
                cacheMap.erase(removeKey);
            cacheMap[key] = cacheList.insert(cacheList.begin(), {key, value});
            target_iter->second = value;
            cacheList.splice(cacheList.begin(), cacheList, target_iter);
    int capacity{};
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap{};
    list<pair<int, int>> cacheList{};
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
