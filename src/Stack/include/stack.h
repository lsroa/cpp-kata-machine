#pragma once
#define CAPACITY 10

#include <stdexcept>

template <typename T>
class Stack {
 public:
  Stack() = default;
  int length;
  int data[CAPACITY];
  T pop();
  T peek() const;
  void push(T data);
};

template <typename T>
T Stack<T>::peek() const {
  return data[length - 1];
}

template <typename T>
void Stack<T>::push(T data) {
  if (length >= CAPACITY) {
    throw std::range_error("full stack");
  }

  this->data[length] = data;
  length++;
}

template <typename T>
T Stack<T>::pop() {
  if (length <= 0) {
    throw std::range_error("empty stack");
  }

  int index = length - 1;
  length--;

  return data[index];
}
