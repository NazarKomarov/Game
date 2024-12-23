#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    std::vector<std::vector<char> > WORDS;

    //WORDS.push_back({'C', 'h', 'i', 'n', 'a', 'z', 'e', 's'});
    //WORDS.push_back({'C', 'r', 'i', 'n', 'g', 'e'});
    //WORDS.push_back({'S', 'c', 'u', 'f'});
    //WORDS.push_back({'C', 'h', 'i', 'l'});
    //WORDS.push_back({'R', 'o', 'f', 'l'});
    //WORDS.push_back({'C', 'r', 'a', 's', 'h'});
    //WORDS.push_back({'H', 'y', 'p', 'e'});
    //WORDS.push_back({'T', 'o', 'x', 'i', 'c'});

    WORDS.push_back(std::vector<char>());
    WORDS[0].push_back('c'); WORDS[0].push_back('h'); WORDS[0].push_back('i'); WORDS[0].push_back('n');
    WORDS[0].push_back('a'); WORDS[0].push_back('z'); WORDS[0].push_back('e'); WORDS[0].push_back('s');

    WORDS.push_back(std::vector<char>());
    WORDS[1].push_back('c'); WORDS[1].push_back('r'); WORDS[1].push_back('i'); WORDS[1].push_back('n');
    WORDS[1].push_back('g'); WORDS[1].push_back('e');

    WORDS.push_back(std::vector<char>());
    WORDS[2].push_back('s'); WORDS[2].push_back('c'); WORDS[2].push_back('u'); WORDS[2].push_back('f');

    WORDS.push_back(std::vector<char>());
    WORDS[3].push_back('c'); WORDS[3].push_back('h'); WORDS[3].push_back('i'); WORDS[3].push_back('l');

    WORDS.push_back(std::vector<char>());
    WORDS[4].push_back('r'); WORDS[4].push_back('o'); WORDS[4].push_back('f'); WORDS[4].push_back('l');

    WORDS.push_back(std::vector<char>());
    WORDS[5].push_back('c'); WORDS[5].push_back('r'); WORDS[5].push_back('a'); WORDS[5].push_back('s');
    WORDS[5].push_back('h');

    WORDS.push_back(std::vector<char>());
    WORDS[6].push_back('h'); WORDS[6].push_back('y'); WORDS[6].push_back('p'); WORDS[6].push_back('e');

    WORDS.push_back(std::vector<char>());
    WORDS[7].push_back('t'); WORDS[7].push_back('o'); WORDS[7].push_back('x'); WORDS[7].push_back('i');
    WORDS[7].push_back('c');

    const int MAX_ATTEMPTS = 5;

    std::srand(std::time(0)); // Ініціалізація генератора випадкових чисел
    int randomIndex = std::rand() % WORDS.size(); // Випадковий вибір слова
    std::vector<char> chosenWord = WORDS[randomIndex];
    std::vector<char> hiddenWord(chosenWord.size(), '*'); // Поле зі зірочками

    int attemptsLeft = MAX_ATTEMPTS;
    int correctGuesses = 0;

    std::cout << "Гра \"Вгадай Слово\" почалася!" << std::endl;

    while (attemptsLeft > 0 && correctGuesses < static_cast<int>(chosenWord.size())) {
        std::cout << "\nСлово: ";
        for (size_t i = 0; i < hiddenWord.size(); ++i) {
            std::cout << hiddenWord[i] << ' ';
        }
        std::cout << "\n";

        char letter;
        std::cout << "Введіть літеру: ";
        std::cin >> letter;

        bool found = false;
        for (size_t i = 0; i < chosenWord.size(); ++i) {
            if (chosenWord[i] == letter && hiddenWord[i] == '*') {
                hiddenWord[i] = letter;
                correctGuesses++;
                found = true;
            }
        }

        if (found) {
            std::cout << "Правильно! Літера \"" << letter << "\" є в слові." << std::endl;
        } else {
            attemptsLeft--;
            std::cout << "Неправильно! Залишилося спроб: " << attemptsLeft << std::endl;
        }
    }

    if (correctGuesses == static_cast<int>(chosenWord.size())) {
        std::cout << "\nВи виграли! Слово: ";
        for (size_t i = 0; i < chosenWord.size(); ++i) {
            std::cout << chosenWord[i];
        }
        std::cout << std::endl;
    } else {
        std::cout << "\nВи програли! Слово було: ";
        for (size_t i = 0; i < chosenWord.size(); ++i) {
            std::cout << chosenWord[i];
        }
        std::cout << std::endl;
    }

    return 0;
}
