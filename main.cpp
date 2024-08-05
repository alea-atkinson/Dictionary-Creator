#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include "dictionary.h"

void displayMenu() {
    std::cout << "\nDictionary Menu:" << std::endl;
    std::cout << "1. Add Word" << std::endl;
    std::cout << "2. Sort Alphabetically" << std::endl;
    std::cout << "3. Sort by Search Count" << std::endl;
    std::cout << "4. Search Word" << std::endl;
    std::cout << "5. Display All Words" << std::endl;
    std::cout << "6. Load in Existing Dictionary" << std::endl;
    std::cout << "7. Exit" << std::endl;
}

// function to ensure that input is not empty
std::string getNonEmptyInput(const std::string& prompt) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (!input.empty()) {
            break;
        } else {
            std::cout << "Error: Input cannot be empty. Please try again." << std::endl;
        }
    }
    return input;
}

// function to ensure proper menu choice is entered
int getValidChoice() {
    std::string input;
    int choice;

    while (true) {
        std::cout << "Enter your choice: ";
        std::getline(std::cin, input);

        if (input.empty()) {
            std::cout << "Error: Input cannot be empty. Please enter a number between 1 and 6." << std::endl;
            displayMenu();
            continue;
        }

        try {
            choice = std::stoi(input);
        } catch (...) {
            choice = 0; // invalid input
        }

        if (choice < 1 || choice > 7) {
            std::cout << "Invalid choice. Please enter a number between 1 and 6." << std::endl;
            displayMenu();
        } else {
            break;
        }
    }

    return choice;
}

int main() {
    Dictionary dict;
    int choice;
    std::string word, definition, synonym, fileName, numLines;
    std::vector<std::string> synonyms;
    std::cout << "Personal Dictionary Creator";
    std::ifstream file("data");

    // while function for display menu
    while (true) {
        displayMenu();
        choice = getValidChoice();

        switch (choice) {
            // add word function
            case 1:
                word = getNonEmptyInput("Enter word: ");
                definition = getNonEmptyInput("Enter definition: ");
                synonyms.clear();
                while (true) {
                    std::cout << "Enter synonyms (type 'done' to finish): ";
                    synonym = getNonEmptyInput("");
                    if (synonym == "done")
                        break;
                    synonyms.push_back(synonym);
                }
                dict.addWord(word, definition, synonyms);
                break;
            // sort alphabetically
            case 2:
                dict.sortAlphabetically();
                std::cout << "Dictionary sorted alphabetically." << std::endl;
                break;
            // sort by search count
            case 3:
                dict.sortBySearchCount();
                std::cout << "Dictionary sorted by search count." << std::endl;
                break;
            // search funtion
            case 4:
                word = getNonEmptyInput("Enter word to search: ");
                if (dict.searchWord(word, definition, synonyms)) {
                    std::cout << "Definition: " << definition << std::endl;
                    std::cout << "Synonyms: ";
                    for (const auto& syn : synonyms)
                        std::cout << syn << " ";
                    std::cout << std::endl;
                } else {
                    std::cout << "Word not found." << std::endl;
                }
                break;
            // display dictionary
            case 5:
                dict.displayAllWords();
                break;
            case 6:
                if (!file.is_open()) {
                    std::cout << "Invalid dictionary file" << std::endl;
                }
                else{
                    std::getline(file, numLines); // number of lines that follow --> numLines/2 = number of words to add
                    //int newWords = std::stoi(numLines) / 2;
                    for (int i = 0; i < stoi(numLines)/2; i++) {
                        std::getline(file, word);
                        std::getline(file, definition);
                        dict.addWord(word, definition, synonyms);
                    }
                    file.close();
                }
                break;

            // exit menu
            case 7:
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
