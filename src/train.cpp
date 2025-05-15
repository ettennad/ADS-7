// Copyright 2021 NNTU-CS
#include "train.h"
#include <cstdlib>

Train::Train() {
  start = nullptr;
  countOp = 0;
}

Train::~Train() {
  if (!start) return;
  Car* current = start->next;
  while (current != start) {
    Car* tmp = current;
    current = current->next;
    delete tmp;
  }
  delete start;
}

void Train::addCar(bool light) {
  Car* newCar = new Car{light, nullptr, nullptr};
  if (!start) {
    start = newCar;
    start->next = start;
    start->prev = start;
  } else {
    Car* last = start->prev;
    last->next = newCar;
    newCar->prev = last;
    newCar->next = start;
    start->prev = newCar;
  }
}

int Train::getLength() {
  Car* current = start;
  current->light = true;
  int length = 1;
  while (true) {
    countOp++;
    current = current->next;
    length++;
    if (current->light) {
      break;
    } else {
      current->light = true;
    }
  }
  return length;
}
int Train::getOpCount() {
  return countOp;
}
