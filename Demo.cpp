#include <iostream>
#include "sources/MagicalContainer.hpp"
using namespace ariel;
int main() {
    // Create a MagicalContainer and add some elements
    MagicalContainer container;
    container.addElement(7);
    container.addElement(2);
    container.addElement(25);
    container.addElement(99);
    container.addElement(18);
    container.addElement(11);

    // Print container size
    std::cout << "Size of container: " << container.size() << std::endl;

    // Use AscendingIterator 
    std::cout << "Elements in ascending order:\n";
    MagicalContainer::AscendingIterator ascIter(container);
    for (auto it = ascIter.begin(); it != ascIter.end(); ++it) {
        std::cout << *it << " ";   // 2 7 11 18 25 99
    }
    std::cout << "\n " << std::endl;


    MagicalContainer container2;
    container2.addElement(1);
    container2.addElement(2);
    container2.addElement(3);
    container2.addElement(4);
    container2.addElement(5);
    container2.addElement(6);
    container2.addElement(7);
    container2.addElement(8);


    // Use DescendingIterator to display elements in descending order
    std::cout << "Elements in cross order:\n";
    MagicalContainer::SideCrossIterator crossIter(container2);
    for (auto it = crossIter.begin(); it != crossIter.end(); ++it) {
        std::cout << *it << " ";  // 1 8 2 7 3 6 4 5 
    }
    std::cout << "\n " << std::endl;

    // Use PrimeIterator to display prime numbers only
    std::cout << "Prime numbers:\n";
    MagicalContainer::PrimeIterator primeIter(container2);
    for (auto it = primeIter.begin(); it != primeIter.end(); ++it) {
        std::cout << *it << " ";  // 2 3 5 7 
    }
    std::cout << "\n " << std::endl;

    // Remove an element from the container and display the size
    container.removeElement(2);
    std::cout << "Size of container after removing an element: " << container.size() << std::endl;

    return 0;
}