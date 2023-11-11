//
// Created by user on 04.11.2023.
//

#include "FileManeger.h"

void FileManager::showContents() {
    listDirectory(rootPath);
}

bool FileManager::createDirectory(const string &dirName) {
    try {
        fs::create_directory(rootPath + '/' + dirName);
        return true;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
}

bool FileManager::deleteItem(const string &itemName){
    try {
        fs::remove(rootPath + '/' + itemName);
        return true;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
}

bool FileManager::renameItem(const string &oldName, const string &newName)  {
    try {
        fs::rename(rootPath + '/' + oldName, rootPath + '/' + newName);
        return true;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
}

bool FileManager::copyItem(const string &itemName, const string &destination) {
    try {
        fs::copy(rootPath + '/' + itemName, destination + '/' + itemName);
        return true;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
}

std::uintmax_t FileManager::calculateSize(const string &itemName) {
    return fs::file_size(rootPath + '/' + itemName);
}

std::vector<std::string> FileManager::searchByMask(const string &mask) {
    std::vector<std::string> result;
    for (const auto& entry : fs::recursive_directory_iterator(rootPath)) {
        if (fs::is_regular_file(entry.path()) &&
            fs::path(entry.path()).filename().string().find(mask) != std::string::npos) {
            result.push_back(entry.path().string());
        }
    }
    return result;
}

void FileManager::listDirectory(const string &path){
    for (const auto& entry : fs::directory_iterator(path)) {
        std::cout << entry.path().filename() << std::endl;
    }
}
