#include "List.h"

int main() {
  List <int> array;
  array.insertBack(1);
  array.insertBack(2);
  array.insertBack(3);
  array.insertBack(4);
  array.insertBack(5);
  array.insertBack(6);
  array.reverseNth(3);
  array.print(std::cout);
  return 0;
}
