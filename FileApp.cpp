//
// Created by user on 04.11.2023.
//

#include "FileApp.h"
void print(string& str){
    std::cout << str << endl;
}
void FileApp::start() {
    while (true){
        string baseText ="Выберите действие которое хотите совершить и введите вариант на клавиатуре]\n0 - посмотреть список файлов в директории\n1- создать директорию\n2 - удалить\n3 - переименовать\n4- поиск по маске\nx - завершить выполнение приложения";
        print(baseText);
        string action = "";
        cin >> action;

        if(action == "0"){
            fileManager.showContents();
            continue;
        }
        if(action == "1"){
            string faileName = "";
            string text = "Введите название директории";
            print(text);
            cin >> faileName;
            fileManager.createDirectory(faileName);
            continue;
        }
        if(action == "2"){
            string faileName = "";
            string text = "Введите название директории/файла";
            print(text);
            cin >> faileName;
            fileManager.deleteItem(faileName);
            continue;
        }
        if(action == "3"){
            string oldName = "";
            string newName = "";
            string oldtext = "Введите название директории/файла";
            string newtext = "Введите название директории/файла";
            print(oldtext);
            cin >> oldName;
            print(newtext);
            cin >> newName;
            fileManager.renameItem(oldName,newName);
            continue;
        }
        if(action == "4"){
            string mask = "";
            string text = "Введите маску елемента";
            print(text);
            cin >> mask;
            std::vector<std::string> searchResults = fileManager.searchByMask(mask);
            for (const std::string& result : searchResults) {
                std::cout << result << std::endl;
            }
            continue;
        }

        if(action == "x"){
            break;
        }
        else{
            continue;
        }

    }
}
