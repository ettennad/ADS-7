// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train() : countOp(0) {}

void Train::addCar(bool light) {
  cars.push_back(Car{light});
}

int Train::getLength() {
  int n = cars.size();
  if (n == 0) return 0;
  int pos = 0;
  cars[pos].light = true;
  int steps = 1;
  while (true) {
    countOp++;
    pos = (pos + 1) % n;
    steps++;
    if (cars[pos].light) {
      break;
    } else {
      cars[pos].light = true;
    }
  }
  return steps;
}
int Train::getOpCount() {
  return countOp;
}
