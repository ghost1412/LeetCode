class MyHashMap {
public:
    /** Initialize your data structure here. */
    vector<int> map;
    MyHashMap() {
        map.resize(10, -1);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        if(key>=map.size()){
             map.resize(map.size()+key+1,-1);
        }
        map[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        if(key<map.size()){
            return map[key];
        }
        return -1; 
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        if(key<map.size()){
            map[key]=-1;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
