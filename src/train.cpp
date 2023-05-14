// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train() {
        first = nullptr;
        countOp = 0;
}
void Train::addCage(bool light) {
    Cage* s = nullptr;
    if (first == nullptr) {
        first = new Cage;
        first->next = first, first->prev = first;
        first->light = light;
    } else {
        s = new Cage;
        s->next = first, s->prev = first->prev;
        s->light = light;
        first->prev = s;
        s->prev->next = s;
    }
}
int Train::getLength() {
    Cage* z = first;
    z->light = true;
    int kol = 1;
    while (true) {
        z = z->next;
        if (z->light == false) {
            kol++;
            countOp++;
        } else {
            z->light = false;
            for (int i = kol; i > 0; i--) {
                z = z->prev;
                countOp++;
            }
            countOp++;
            if (z->light == false) {
                return kol;
            } else {
                kol = 1;
            }
        }
    }
}
int Train::getOpCount() {
    return countOp;
}
