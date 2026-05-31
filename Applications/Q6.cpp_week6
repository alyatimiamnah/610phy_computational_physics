/*Write a C++ program that:
Creates a vector.
Uses push_back() to add:
3, 6, 9, 12, 15
  Removes the value 9.
  Prints the remaining elements.*/


void Q6() {

  std::vector<int> numbers;

  numbers.push_back(3);
  numbers.push_back(6);
  numbers.push_back(9);
  numbers.push_back(12);
  numbers.push_back(15);

  for (int i = 0; i < numbers.size(); i++) {

    if (numbers[i] == 9) {

      numbers.erase(numbers.begin() + i);
    }
  }

  for (int i = 0; i < numbers.size(); i++) {

    std::cout << numbers[i]
              << std::endl;
  }
}
