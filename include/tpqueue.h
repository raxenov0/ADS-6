// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

struct SYM {
  char ch;
  int prior;
};

template<typename T, int size>
class TPQueue {
  private:
  int size_;
  SYM* arr;
  int first;
  int last;
  void replace() {
    SYM* temp = arr;
    int tempSize = size_;
    size_ = size_ + (size_ * 0.3);
    arr = new SYM[size_];
    for (int i = first; i < last; i++) {
      arr[i % size_] = temp[i % tempSize];
    }
    delete temp;
    }

  public:
  TPQueue() {
    this->size_ = size;
    arr = new SYM[size_];
    first = 0;
    last = 0;
  }
  void push(SYM current) {
    last++;
    if ((first % size_) == (last % size_)) replace();
    for (int i = first; i < last; i++) {
      if (current.prior > arr[i % size].prior) {
        for (int j = last-1; j >= i; j--) {
          arr[(j + 1) % size_] = arr[j % size_];
        }
        arr[i] = current;
        return;
      }
    }
    arr[last] = current;
  }
  SYM& pop() {
    return arr[(first++) % size];
  }
  void print() {
    for (int i = first; i < last; i++) {
      cout << arr[i % size_].ch << ' '<< arr[i%size_].prior<< endl;
    }
  }
  ~TPQueue() {
    delete[] arr;
  }
};

#endif  // INCLUDE_TPQUEUE_H_
