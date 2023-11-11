//
// Created by user on 04.11.2023.
//
#include "includes.h"
#ifndef GIT_STUDY_FILEMANEGER_H
#define GIT_STUDY_FILEMANEGER_H




class FileManager {
public:
    FileManager(const std::string& rootPath) : rootPath(rootPath) {}

    // Метод для отображения содержимого диска
    void showContents() ;

    // Метод для создания папок
    bool createDirectory(const std::string& dirName) ;

    // Метод для удаления папок/файлов
    bool deleteItem(const std::string& itemName) ;

    // Метод для переименования папок/файлов
    bool renameItem(const std::string& oldName, const std::string& newName);

    // Метод для копирования папок/файлов
    bool copyItem(const std::string& itemName, const std::string& destination) ;

    // Метод для вычисления размера папки/файла
    std::uintmax_t calculateSize(const std::string& itemName) ;

    // Метод для поиска по маске с поиском по подпапкам
    std::vector<std::string> searchByMask(const std::string& mask);

private:
    std::string rootPath;

    // Вспомогательная функция для вывода содержимого директории
    void listDirectory(const std::string& path) ;
};


#endif //GIT_STUDY_FILEMANEGER_H
