// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <iostream>
#include <string>

struct SYM {
  char ch;
  int prior;
};

template<typename T, int size>
class TPQueue {
 private:
    int first;
    int last;
    T arr[20];

 public:
  TPQueue() {
    first = 0;
    last = 0;
  }
  void push(T current) {
    if (last - first >= size) throw std::string ("Full");
    for (int i = first; i < last; i++) {
      if (current.prior > arr[i % size].prior) {
        for (int j = last-1; j >= i; j--) {
          arr[(j + 1) % size] = arr[j % size];
        }
        last++;
        arr[i % size] = current;
        return;
      }
    }
    arr[last++ % size] = current;
  }
  T& pop() {
    return arr[(first++) % size];
  }
  void print() {
    for (int i = first; i < last; i++) {
      std::cout << arr[i % size].ch << ' '<< arr[i%size].prior<< std::endl;
    }
  }
};

#endif  // INCLUDE_TPQUEUE_H_
