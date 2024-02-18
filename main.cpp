#include <iostream>
#include <vector>
#include <deque>
#include <fstream>
#include <iterator>

template <typename Iterator>
void print(Iterator begin, Iterator end) {
    while (begin != end) {
        std::cout << *begin++ << " ";
    }
}

int main() {
    // read numbers (task 1)
    std::vector<int> vector;
    int line;
    while (std::cin >> line) {
        vector.push_back(line);
    }

    std::vector<int> newVector(vector);

    // copy all elements except last to the end (task 1) (task 2)
    std::copy(vector.begin(), vector.end() - 1, std::back_inserter(newVector));
    // add "brackets"
    newVector.push_back(66);
    newVector.insert(newVector.begin(), 66);

    // create deque for front insertion (task 2, 4)
    std::deque<int> deque;
    std::copy(vector.begin(), vector.end(), std::front_inserter(deque));

    // create vector for middle insertion
    std::vector<int> middle(newVector);
    std::copy(newVector.begin(), newVector.end(),
              std::inserter(middle, middle.begin() + (middle.size()/2)));

    // print
    print(vector.begin(), vector.end());
    std::cout << std::endl;
    print(newVector.begin(), newVector.end());
    std::cout << std::endl;
    print(middle.begin(), middle.end());
    std::cout << std::endl;
    print(deque.begin(), deque.end());
    std::cout << std::endl;

    // removing all except first and last
    print(vector.begin(), vector.end());
    std::cout << std::endl;
    vector.erase(vector.begin() + 1, vector.end() - 1);
    print(vector.begin(), vector.end());

    // read from file test.txt with default iterator and then write it to same file (task 3)
    std::ifstream file("test.txt");
    std::vector<int> fileVector;
    int fileLine;
    while (file >> fileLine) {
        fileVector.push_back(fileLine);
    }
    file.close();
    std::ofstream fileOut("test.txt", std::ios::app);
    std::copy(fileVector.begin(), fileVector.end(), std::ostream_iterator<int>(fileOut, "\n"));
    // write in reverse order with reverse iterator (task 5)
    std::copy(fileVector.rbegin(), fileVector.rend(), std::ostream_iterator<int>(fileOut, "\n"));
    fileOut.close();
}
