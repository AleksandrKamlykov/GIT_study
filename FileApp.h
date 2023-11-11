//
// Created by user on 04.11.2023.
//

#ifndef GIT_STUDY_FILEAPP_H
#define GIT_STUDY_FILEAPP_H
#include <iostream>
#include "FileManeger.h"



class FileApp {
private:
    FileManager fileManager;
public:
    FileApp( FileManager fileManager) : fileManager(fileManager) {}
    void start();

};


#endif //GIT_STUDY_FILEAPP_H
