/*
这个例子是用来证明，函数类型也可以作为 unordered_map 的 hash template argument。
顺便复习一下 unordered_map 的构造函数的用法
*/

#include <iostream>
#include <unordered_map>
#include <utility>

// 定义一个 Functor 作为哈希函数
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ (h2 << 1); // 简单的哈希组合
    }
};

std::size_t foo(const std::pair<int, int>& p)  {
        auto h1 = std::hash<int>{}(p.first);
        auto h2 = std::hash<int>{}(p.second);
        return h1 ^ (h2 << 1); // 简单的哈希组合
    }

int main() {
    // 使用 pair_hash 作为哈希函数
    std::unordered_map<std::pair<int, int>, bool, std::size_t  (*) (const std::pair<int, int>& )> myUnorderedMap(10, foo);
    
    std::unordered_map<std::pair<int, int>, bool, pair_hash> myUnorderedMap2;


    // 插入一些值
    myUnorderedMap[std::make_pair(1, 2)] = true;
    myUnorderedMap[std::make_pair(3, 4)] = false;
    myUnorderedMap[std::make_pair(5, 6)] = true;
    
    myUnorderedMap2[std::make_pair(1, 2)] = true;
    myUnorderedMap2[std::make_pair(3, 4)] = false;
    myUnorderedMap2[std::make_pair(5, 6)] = true;

    // 访问并打印值
    for (const auto& entry : myUnorderedMap) {
        std::cout << "(" << entry.first.first << ", " << entry.first.second << ") : " << std::boolalpha << entry.second << std::endl;
    }
    std::cout << std::endl;
    
    for (const auto& entry : myUnorderedMap2) {
        std::cout << "(" << entry.first.first << ", " << entry.first.second << ") : " << std::boolalpha << entry.second << std::endl;
    }

    return 0;
}
