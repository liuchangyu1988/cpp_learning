#include <iostream>

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

int main() {
	using namespace std;
	std::string line;

	std::cout << "Enter multiple lines of input (Ctrl+D to end):" << std::endl;

	// Read input until EOF (Ctrl+D on Linux/Mac, Ctrl+Z on Windows)
	std::vector<vector<std::string>> input_list;
	while (std::getline(std::cin, line)) {
		std::cout << "You entered: " << line << std::endl;
		stringstream ss(line);
		string word;
		vector<string> word_list;
		while(getline(ss, word, ' ')) {
			cout << "word is " << word << endl;
			word_list.emplace_back(word);
		}
		input_list.emplace_back(word_list);
	}

	for (const auto& line : input_list) {
		for (const auto& word : line) {
			std::cout << word << ";";
		}
		cout << endl;
	}

	return 0;
}
