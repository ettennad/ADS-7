// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
  Car* newCar = new Car{light, nullptr, nullptr};

  if (!first) {
    first = newCar;
    first->next = first;
    first->prev = first;
  } else {
    Car* last = first->prev;
    newCar->next = first;
    newCar->prev = last;
    last->next = newCar;
    first->prev = newCar;
  }
}

int Train::getLength() {
  if (!first) return 0;

  Car* current = first;
  current->light = true;

  int steps = 1;

  while (true) {
    countOp++;
    current = current->next;
    steps++;

    if (current->light) {
      break;
    } else {
      current->light = true;
    }
  }

  return steps;
}

int Train::getOpCount() {
  return countOp;
}
