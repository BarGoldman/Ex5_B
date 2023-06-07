#include <iostream>
#include "sources/MagicalContainer.hpp"

using namespace ariel;
int main() {
    // Create a MagicalContainer and add some elements
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);

    // Print container size
    std::cout << "Size of container: " << container.size() << std::endl;

    // Use AscendingIterator to display elements in ascending order
    std::cout << "Elements in ascending order:\n";
    MagicalContainer::AscendingIterator ascIter(container);
    for (auto it = ascIter.begin(); it != ascIter.end(); ++it) {
        std::cout << *it << ' ';   // 2 3 9 17 25
    }
    std::cout << std::endl;

    // cout << "_-----------------------bar -------------------" << endl;

    // MagicalContainer container2;
    // // container2.addElement(1);
    // // container2.addElement(2);
    // // container2.addElement(4);
    // // container2.addElement(5);
    // // container2.addElement(14);
    // // container2.addElement(30);


    // for (int i = 1; i <= 9; ++i)
    // {

    //     container2.addElement(i);
    // }
    // MagicalContainer::PrimeIterator it(container2);
    // MagicalContainer::PrimeIterator it2(container2);
    // cout << "1: " << *it << endl; // 2
    // ++it;
    // cout << "2: " << *it << endl; // 3
    // ++it;
    // cout << "3: " << *it << endl; // 5
    // ++it;
    // cout << "4: " << *it << endl; //7
    // ++it;
    // // cout << "5: " << *it << endl; // 4
    // // ++it;
    // // cout << "5: " << *it << endl; // 5

    // cout << "bar: " << endl;
    // container2.removeElement(2);

    // cout << "1: " << *it2 << endl; // 3
    // ++it2;
    // cout << "2: " << *it2 << endl; // 5
    // ++it2;
    // cout << "3: " << *it2 << endl; // 7
    // // ++it2;
    // // cout << "4: " << *it2 << endl; //14
    // // ++it2;
    // // cout << "5: " << *it2 << endl; // 5


    // cout << "_-----------------------bar -------------------" << endl;

    // Use DescendingIterator to display elements in descending order
    std::cout << "Elements in cross order:\n";
    MagicalContainer::SideCrossIterator crossIter(container);
    for (auto it = crossIter.begin(); it != crossIter.end(); ++it) {
        std::cout << *it << ' ';  // 2 25 3 17 9
    }
    std::cout << std::endl;

    // Use PrimeIterator to display prime numbers only
    std::cout << "Prime numbers:\n";
    MagicalContainer::PrimeIterator primeIter(container);
    for (auto it = primeIter.begin(); it != primeIter.end(); ++it) {
        std::cout << *it << ' ';  // 2 3 17 
    }
    std::cout << std::endl;

    // Remove an element from the container and display the size
    container.removeElement(9);
    std::cout << "Size of container after removing an element: " << container.size() << std::endl;

    return 0;
}

