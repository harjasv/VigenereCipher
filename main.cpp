//
//  main.cpp
//  VigenereCipher
//
//  Created by Harjas Virk on 2019-06-26.
//  Student Number: 3373921
//  Copyright © 2019 Harjas Virk. All rights reserved.
//  Compiled on Xcode, g++ on a linux environment should work without any problems as well.
//
#include <iostream>
#include <string>

char encryptAid(char k, char p){
    if(k + p - 65 > 90){
        return static_cast<char>(k + p - 65 - 26);
    } else {
        return static_cast<char>(k + p - 65);
    }
}

char decryptAid(char k, char c){
    if(c - k + 65 < 65){
        return static_cast<char>(c - k + 65 + 26);
    } else {
        return static_cast<char>(c - k + 65);
    }
}

std::string encrypt(char const* key, std::string &plaintext){
    int i = 0;
    int j = 0;
    std::string temp;
    std::string newString;
    while(i < plaintext.length()){
        if(j == strlen(key)) j = 0;
        temp = encryptAid(key[j], plaintext[i]);
        newString.append(temp);
        i++;
        j++;
    }
    plaintext = newString;
    return newString;
}

std::string decrypt(char const* key, std::string &plaintext){
    int i = 0;
    int j = 0;
    std::string temp;
    std::string newString;
    while(i < plaintext.length()){
        if(j == strlen(key)) j = 0;
        temp = decryptAid(key[j], plaintext[i]);
        newString.append(temp);
        i++;
        j++;
    }
    plaintext = newString;
    return newString;
}

void cleanUp(std::string &s){
    std::transform(s.begin(), s.end(),s.begin(), ::toupper);
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
}

int main(int argc, const char * argv[]) {
    int selection, i;
    std::string message;
    char const* keys[] = {
        "LEMON",
        "ACE",
        "KEY",
        "CRYPT",
        "OMEGA",
        "ALPHA"
    };
    
    std::cout << "Welcome. Please select a key to use:\n";
    for(i = 0; i < 6; i++){
        std::cout << i+1 << ". " << keys[i] << "\n";
    }
    std::cin >> selection;
    std::cout << "Please type a message you would like to encrypt (only alphabets, no numbers, or special characters):\n";
    std::cin.ignore();
    getline (std::cin, message);
    cleanUp(message);
    std::cout << "Your encrypted message is: " << encrypt(keys[selection - 1], message) << "\n" << "Your decrypted message is: " << decrypt(keys[selection - 1], message) << "\n";
    
    return 0;
}
