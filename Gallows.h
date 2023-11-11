//
// Created by user on 11.11.2023.
//
#include "includes.h"
#ifndef GIT_STUDY_GALLOWS_H
#define GIT_STUDY_GALLOWS_H


class Gallows {
public:
    std::string EncryptString(const std::string& plainText, int shift) ;
    std::string DecryptString(const std::string& encryptedText, int shift) ;
    std::vector<std::string> readEncryptedWords(const std::string& filename) ;
   void start();
};


#endif //GIT_STUDY_GALLOWS_H
