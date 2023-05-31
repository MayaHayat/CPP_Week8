#ifndef MAGICALCONTAINER_HPP
#define MAGICALCONTAINER_HPP

#include <algorithm>
#include <vector>

using namespace std;
namespace ariel{};

class MagicalContainer {
private:
    std::vector<int> mysticalElements;

public:
    MagicalContainer() = default;
    ~MagicalContainer() = default;

    void addElement(int element);
    void removeElement(int element);

    int size() const;
    std::vector<int> getElements() const;

    class AscendingIterator {
    public:
        const MagicalContainer& container;
        int index;

        AscendingIterator(const MagicalContainer& container): container(container), index(0){
            
        }   
        AscendingIterator(const AscendingIterator& other): container(other.container){}
        ~AscendingIterator() = default;

        AscendingIterator begin() const{
            return AscendingIterator(container);
        }
        AscendingIterator end() const{
            AscendingIterator iterator(container);
            iterator.index = container.mysticalElements.size();
            return iterator;
        }
        AscendingIterator& operator++(){
            index++;
            return *this;
        }

        bool operator==(const AscendingIterator& other) const{
            return this->index == other.index;
        }
        bool operator!=(const AscendingIterator& other) const{
            return this ->index != other.index;
        }
        bool operator>(const AscendingIterator& other) const{
            return this ->index > other.index;
        }
        bool operator<(const AscendingIterator& other) const{
            return this ->index < other.index;
        }

        int operator*() const{ 
            return container.mysticalElements[static_cast<std::vector<int>::size_type>(index)];

        }
    };

    class PrimeIterator {
    private:
        const MagicalContainer& container;
        int index;

    public:
        PrimeIterator(const MagicalContainer& container): container(container), index(0){}
        PrimeIterator(const AscendingIterator& other) : container(other.container){}
        ~PrimeIterator() = default;

        PrimeIterator begin() const{
            return PrimeIterator(container);
        }
        PrimeIterator end() const{
            PrimeIterator iterator(container);
            iterator.index = container.mysticalElements.size();
            return iterator;
        }
        PrimeIterator& operator++(){
            index++;
            return *this;
        }

        bool operator==(const PrimeIterator& other) const{
            return this->index == other.index;
        }
        bool operator!=(const PrimeIterator& other) const{
            return this ->index != other.index;
        }
        bool operator>(const PrimeIterator& other) const{
            return this ->index > other.index;
        }
        bool operator<(const PrimeIterator& other) const{
            return this ->index < other.index;
        }

        int operator*() const{
            return container.mysticalElements[static_cast<std::vector<int>::size_type>(index)];
        }
    };

    class SideCrossIterator {
    private:
        const MagicalContainer& container;
        int index;

    public:
        SideCrossIterator(const MagicalContainer& container) : container(container), index(0){}
        SideCrossIterator(const AscendingIterator& other) : container(other.container){}
        ~SideCrossIterator() = default;

        SideCrossIterator begin() const{
            return SideCrossIterator(container);
        }
        SideCrossIterator end() const{
            SideCrossIterator iterator(container);
            iterator.index = container.mysticalElements.size();
            return iterator;
        }
        SideCrossIterator& operator++(){
            index++;
            return *this;
        }

        bool operator==(const SideCrossIterator& other) const{
            return this->index == other.index;
        }
        bool operator!=(const SideCrossIterator& other) const{
            return this ->index != other.index;
        }
        bool operator>(const SideCrossIterator& other) const{
            return this ->index > other.index;
        }
        bool operator<(const SideCrossIterator& other) const{
            return this ->index < other.index;
        }
        int operator*() const{
            return container.mysticalElements[static_cast<std::vector<int>::size_type>(index)];
        }
    };
};



#endif