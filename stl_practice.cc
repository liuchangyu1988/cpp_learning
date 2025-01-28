#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <algorithm>

class MyClass {
private:
    int val_;
public:
    MyClass(int val):val_(val){}
    int getVal() const {
        return val_;
    }
};

bool operator < (const MyClass& a, const MyClass& b) {
    return a.getVal() < b.getVal();
}

bool operator == (const MyClass& a, const MyClass& b) {
    return a.getVal() == b.getVal();
}

struct MyHash {
    int operator()  (const MyClass& a) const {
        return a.getVal();
    }
};

int main()
{
    using namespace std;
    std::cout<<"Hello World" << endl;
    
    vector<string> str_vec(10, "aa");
    str_vec.emplace_back("bb");
    sort(str_vec.begin(), str_vec.end());
    for (const auto& str : str_vec) {
        cout << str << ",";
    }
    cout << endl;
    
    stack<string> str_stack;
    str_stack.push("cc");
    str_stack.push("dd");
    while(!str_stack.empty()) {
        cout << str_stack.top() << ":";
        str_stack.pop();
    }
    cout << endl;
    
    queue<string> str_q;
    str_q.push("ee");
    str_q.push("ff");
    while (!str_q.empty()) {
        cout << str_q.front() << "|";
        str_q.pop();
    }
    cout << endl;
    
    unordered_map<string, string> str_map;
    str_map.emplace("key1", "val1");
    auto iter = str_map.find("key1");
    if (str_map.end() != iter) {
        cout << "found key1" << endl;
    }
    str_map.erase("key1");
    auto iter2 = str_map.find("key1");
    if (str_map.end() == iter2) {
        cout << "did not find key1" << endl;
    }
    str_map.emplace("key1", "val1");
    str_map.emplace("key2", "val2");
    str_map.emplace("key3", "val3");
    for (const auto& kv : str_map) {
        cout << "key=" << kv.first << ", val=" << kv.second << endl;
    }
    
    unordered_set<string> str_set;
    str_set.emplace("set_val1");
    str_set.emplace("set_val2");
    str_set.emplace("set_val3");
    for (const auto& val : str_set) {
        cout << val << ";";
    }
    cout << endl;
    
    deque<string> str_dq;
    str_dq.push_front("gg");
    str_dq.push_back("hh");
    cout << "front is " << str_dq.front() << endl;
    cout << "back is " << str_dq.back() << endl;
    
    map<MyClass, string> my_map;
    my_map.emplace(2, "jj");
    my_map.emplace(1, "kk");
    for (const auto& kv : my_map) {
        cout << "key=" << kv.first.getVal() << ", val=" << kv.second << endl;
    }
    
    unordered_map<MyClass, string, MyHash> my_hashmap;
    my_hashmap.emplace(2, "ll");
    my_hashmap.emplace(1, "mm");
    for (const auto& kv : my_hashmap) {
        cout << "key=" << kv.first.getVal() << ", val=" << kv.second << endl;
    }

    return 0;
}
