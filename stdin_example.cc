#include <iostream>

#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string line;

    std::cout << "Enter multiple lines of input (Ctrl+D to end):" << std::endl;

    // Read input until EOF (Ctrl+D on Linux/Mac, Ctrl+Z on Windows)
    std::vector<std::string> input_list;
    while (std::getline(std::cin, line)) {
        std::cout << "You entered: " << line << std::endl;
        input_list.emplace_back(line);
    }
    
    for (const auto& line : input_list) {
        std::cout << line << std::endl;
    }

    return 0;
}
