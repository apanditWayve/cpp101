#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "CLI/CLI11.hpp"

// These are all the words you can accept as "valid" when you press enter
std::vector<std::string> get_valid_wordle_words() {
    std::ifstream f("03_organise/homework/data/valid-wordle-words.txt");
    std::vector<std::string> words;
    std::string line;

    while (std::getline(f, line)) {
        words.push_back(line);
    }

    return words;
}

int main(int argc, char* argv[]) {
    CLI::App app{"Wordle"};
    app.set_help_all_flag("--help-all", "Expand all help");
    app.add_flag("--answer", answer,
                 "Add this flag in if you want the reverse order");
    CLI11_PARSE(app, argc, argv);

    std::vector<std::string> valid_words = get_valid_wordle_words();

    for (size_t i = 0; i < valid_words.size(); i++) {
        std::cout << valid_words[i] << std::endl;
    }
    return 0;
}
