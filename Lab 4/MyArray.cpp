/*
 *  File Name: MyArray.cpp
 *  Assignment: ENSF 614 Lab 4 Exercise A
 *  Lab Section: Lab B01
 *  Completed by: Steven Duong (30022492)
 *  Submission Date: Feb 12, 2023
 */

#include "MyArray.h"

MyArray::MyArray() {
    sizeM = 0;
    storageM = new EType[sizeM];
}

MyArray::MyArray(const EType *builtin, int sizeA) {
    if (sizeA <= 0) {
        return;
    }

    sizeM = sizeA;
    storageM = new EType[sizeM];

    for (int i = 0; i < sizeA; i++) {
        storageM[i] = builtin[i];
    }
}

MyArray::MyArray(const MyArray& source) {
    sizeM = source.sizeM;
    storageM = new EType[sizeM];

    for (int i = 0; i < source.sizeM; i++) {
        storageM[i] = source.storageM[i];
    }
}

MyArray &MyArray::operator=(const MyArray &rhs) {
    if (this != &rhs) {
        delete[] storageM;
        sizeM = rhs.size();
        storageM = new EType[sizeM];

        for (int i = 0; i < sizeM; i++) {
            storageM[i] = rhs.storageM[i];
        }
    }

    return *this;
}

MyArray::~MyArray() {
    delete[] storageM;
    storageM = nullptr;
}

int MyArray::size() const {
    return sizeM;
}

EType MyArray::at(int i) const {
    if (i >= 0 && i < sizeM) {
        return storageM[i];
    }
}

void MyArray::set(int i, EType new_value) {
    if (i >= 0 && i < sizeM) {
        storageM[i] = new_value;
    }
}

void MyArray::resize(int new_size) {
    if (new_size < 0) {
        return;
    }

    EType *temp = new EType[new_size];
    int minSize = (new_size < sizeM) ? new_size : sizeM;
    for (int i = 0; i < minSize; ++i) {
        temp[i] = storageM[i];
    }
    delete[] storageM;
    storageM = temp;
    sizeM = new_size;
}