#include "MagicalContainer.hpp"

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

// Returns the first number in the container
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const {
    //cout << " 1 " << endl;
    return AscendingIterator(container);
}

// Returns the end of the container
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const {
    //cout << " 2 " << endl;
    return AscendingIterator(container, container.mysticalElements.size());
}

// Moves to the next element if not reached the end
MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
    //cout << " 3 " << endl;
    if (index >= container.size()) {
        throw std::runtime_error("Reached end of container.");
    }
    index++;
    return *this;
}

// Assigns the iterator to another iterator
MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other) {
    //cout << " 4 " << endl;
    if (&container != &other.container) {
        throw std::runtime_error("Containers aren't the same");
    }
    if (this != &other) {
        index = other.index;
    }
    return *this;
}

// Returns the value of the element at the current position
int MagicalContainer::AscendingIterator::operator*() const {
    //cout << " 5 " << endl;
    return container.mysticalElements[index];
}

// Compares two iterators
bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
    //cout << " 6 " << endl;
    return index == other.index;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
    //cout << " 7 " << endl;
    return !(*this == other);
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
    //cout << " 8 "   << endl;
    return index > other.index;
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
    //cout << " 9 " << endl;
    return index < other.index;
}