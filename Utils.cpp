//
// Created by owen on 28/03/2022.
//

#include <sstream>
#include "Utils.h"

string Utils::matrixToStringIntVertex(int **matrix, int size) {
    int sizeStrLength = to_string(size).length();
    stringstream ss;

    ss << endl << "     ";

    stringstream firstLine;
    for (int i = 0; i < size; i++) {
        firstLine << setfill('0') << setw(sizeStrLength) << i << "  ";
    }

    ss << firstLine.str() << std::endl << "  ";

    ss << setfill(' ') << setw(sizeStrLength) << "";
    ss << setfill('-') << setw(firstLine.str().length()) << "";

    ss << endl;

    for (int i = 0; i < size; i++) {
        ss << setfill('0') << setw(sizeStrLength) << i << " |  ";

        for (int j = 0; j < size; ++j) {
            ss << matrix[i][j] << "  ";
            ss << setfill(' ') << setw(sizeStrLength);
        }

        if (i < size - 1) {
            ss << endl;
        }
    }

    return ss.str();
}

string Utils::matrixToStringCharVertex(int **matrix, int size) {
    int sizeStrLength = to_string(size).length();
    stringstream ss;

    ss << endl << "      ";

    stringstream firstLine;
    for (int i = 0; i < size; i++) {
        firstLine << Utils::getLetterFromAlphabetIndex(i) << "   ";
    }

    ss << firstLine.str() << std::endl << "    ";
    ss << setfill('-') << setw(firstLine.str().length()) << "";

    ss << endl << " ";

    for (int i = 0; i < size; i++) {
        ss << Utils::getLetterFromAlphabetIndex(i) << " |  ";

        for (int j = 0; j < size; ++j) {
            ss << matrix[i][j] << "  ";
            ss << setfill(' ') << setw(sizeStrLength);
        }

        if (i < size - 1) {
            ss << endl;
        }
    }

    return ss.str();
}

string Utils::matrixToRawString(int **matrix, int size, string separator) {
    stringstream ss;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; ++j) {
            ss << matrix[i][j];

            if (j < size - 1) {
                ss << separator;
            }
        }

        if (i < size - 1) {
            ss << endl;
        }
    }

    return ss.str();
}

string Utils::getAlphabet(int max) {
    stringstream ss;

    for (int i = 0; i < max; i++) {
        ss << Utils::getLetterFromAlphabetIndex(i);

        if (i < max - 1) {
            ss << endl;
        }
    }

    return ss.str();
}

int Utils::getIndexInAlphabet(char letter) {
    return tolower(letter) - 'a';
}

char Utils::getLetterFromAlphabetIndex(int letterIndex) {
    return toupper((char) (letterIndex + 'a'));
}

string Utils::boolToYesNo(bool value) {
    return value ? "yes" : "no";
}
