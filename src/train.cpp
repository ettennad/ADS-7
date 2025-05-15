// Copyright 2021 NNTU-CS
#include "train.h"
#include <iostream>

Train::Train() : first(nullptr), countOp(0) {}

Train::~Train() {
  if (!first) return;
  Car* cur = first->next;
  while (cur != first) {
    Car* toDelete = cur;
    cur = cur->next;
    delete toDelete;
  }
  delete first;
}

void Train::addCar(bool light) {
  Car* newCar = new Car(light);
  if (!first) {
    first = newCar;
    first->next = first;
    first->prev = first;
  } else {
    Car* last = first->prev;
    last->next = newCar;
    newCar->prev = last;
    newCar->next = first;
    first->prev = newCar;
  }
}

int Train::getLength() {
  if (!first) return 0;
  countOp = 0;
  bool initialLight = first->light;
  first->light = !initialLight;
  Car* current = first->next;
  countOp++;
  while (current != first) {
    current = current->next;
    countOp++;
  }
  first->light = initialLight;
  return countOp;
}
int Train::getOpCount() const {
  return countOp;
}
