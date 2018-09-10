#include <algorithm>
#include <iostream>
#include <iterator>

#include "btree.h"

int main(void) {
  btree<char> b(4);

  b.insert('M');
  b.insert('X');
  b.insert('P');
  b.insert('G');
  b.insert('T');
  b.insert('B');
  b.insert('Z');
  b.insert('N');
  b.insert('R');
  b.insert('S');
  b.insert('W');
  b.insert('Q');
  b.insert('V');

  for(btree<char>::iterator iter = b.begin(); iter != b.end(); ++iter)
    std::cout << *iter << std::endl;

  std::cout << b << "\n";
  return 0;
}
