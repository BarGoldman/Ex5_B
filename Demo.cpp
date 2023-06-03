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


    cout <<"_-----------------------bar -------------------" <<endl;
    MagicalContainer container2;
    for (int i = 1; i <= 2; ++i) {
        container2.addElement(i);
    }
    MagicalContainer::AscendingIterator it1(container2);
    MagicalContainer::AscendingIterator it2(container2);

    cout<< "it1: " << (*it1) << "it2: " << (*it2) <<endl;
    cout<< "1: " << (it1 == it2) <<endl;
    cout<< "2: " << (!(it1 != it2)) <<endl;
    cout<< "3: " << !(it1 < it2) <<endl;
    cout<< "4: " << !(it1 > it2) <<endl;

    cout<< "end: " << (*it1.end()) <<endl;
    cout<< "begin: " << (*it1.begin()) <<endl;
    ++it1;
    cout<< "next: " << (*it1) <<endl;
    cout<< "hii " <<endl;
    ++it1;
    cout << "true / false: " << (it1 == it2.end()) <<endl;

    
    cout <<"_-----------------------bar -------------------" <<endl;



    // // Use DescendingIterator to display elements in descending order
    // std::cout << "Elements in cross order:\n";
    // MagicalContainer::SideCrossIterator crossIter(container);
    // for (auto it = crossIter.begin(); it != crossIter.end(); ++it) {
    //     std::cout << *it << ' ';  // 2 25 3 17 9
    // }
    // std::cout << std::endl;

    // // Use PrimeIterator to display prime numbers only
    // std::cout << "Prime numbers:\n";
    // MagicalContainer::PrimeIterator primeIter(container);
    // for (auto it = primeIter.begin(); it != primeIter.end(); ++it) {
    //     std::cout << *it << ' ';  // 2 3 17 
    // }
    // std::cout << std::endl;

    // Remove an element from the container and display the size
    container.removeElement(9);
    std::cout << "Size of container after removing an element: " << container.size() << std::endl;

    return 0;
}

