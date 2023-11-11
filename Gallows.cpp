//
// Created by user on 11.11.2023.
//

#include "Gallows.h"

void Gallows::start() {


    std::vector<std::string> words = readEncryptedWords("./game.txt");
    if (words.empty()) {
        std::cerr << "Ошибка при чтении слов из файла." << std::endl;
        return ;
    }

    srand(static_cast<unsigned int>(time(0)));
    int randomIndex = rand() % words.size();
    std::string selectedWord = words[randomIndex];

    std::string guessedWord(selectedWord.length(), '_');
    int attempts = 0;
    std::string usedLetters;

    bool gameOver = false;
    while (!gameOver) {
        std::cout << "Угадываемое слово: " << guessedWord << std::endl;
        std::cout << "Использованные буквы: " << usedLetters << std::endl;
        std::cout << "Попыток осталось: " << selectedWord.length() - attempts << std::endl;

        std::cout << "Введите букву: ";
        char guess;
        std::cin >> guess;

        if (usedLetters.find(guess) != std::string::npos) {
            std::cout << "Вы уже вводили эту букву. Попробуйте другую." << std::endl;
            continue;
        }

        usedLetters += guess;

        // Проверка, есть ли введенная буква в загаданном слове
        bool correctGuess = false;
        for (int i = 0; i < selectedWord.length(); ++i) {
            if (selectedWord[i] == guess) {
                guessedWord[i] = guess;
                correctGuess = true;
            }
        }

        if (!correctGuess) {
            attempts++;
        }

        if (guessedWord == selectedWord) {
            std::cout << "Поздравляем! Вы угадали слово: " << selectedWord << std::endl;
            gameOver = true;
        } else if (attempts >= selectedWord.length()) {
            std::cout << "Игра окончена. Вы не угадали слово: " << selectedWord << std::endl;
            gameOver = true;
        }
    }
}

std::vector<std::string> Gallows::readEncryptedWords(const string &filename) {
    ifstream  file(filename);

    vector<string> words;
    if(file.is_open()){
        string w;

        while (file >> w){

            words.push_back(DecryptString(w,3));
        }
    }

    return words;
}

std::string Gallows::DecryptString(const string &encryptedText, int shift) {
    return EncryptString(encryptedText, -shift);
}

std::string Gallows::EncryptString(const string &plainText, int shift){
    std::string encryptedText = plainText;

    for (char& c : encryptedText) {
        if (isalpha(c)) {
            char base = (islower(c)) ? 'a' : 'A';
            c = ((c - base + shift) % 26) + base;

        }
    }

    return encryptedText;
}
