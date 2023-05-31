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


    // ------------------ tidy -------------------
    MagicalContainer(const MagicalContainer& other) = default;
    MagicalContainer& operator=(const MagicalContainer& other) = default;
    MagicalContainer(MagicalContainer&& other) = default;
    MagicalContainer& operator=(MagicalContainer&& other) = default;

    class AscendingIterator {
    public:
        const MagicalContainer& container;
        std::vector<int>::size_type index;

        AscendingIterator(const MagicalContainer& container): container(container), index(0){
            
        }   
        AscendingIterator(const AscendingIterator& other): container(other.container), index(other.index){}
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


        // ------------------ tidy -------------------

        AscendingIterator& operator=(const AscendingIterator& other) = delete;
        AscendingIterator(AscendingIterator&& other) = default;
        AscendingIterator& operator=(AscendingIterator&& other) = delete;

    };

    class PrimeIterator {
    private:
        const MagicalContainer& container;
        std::vector<int>::size_type index;

    public:
        PrimeIterator(const MagicalContainer& container): container(container), index(0){}
        PrimeIterator(const PrimeIterator& other) : container(other.container), index(other.index){}
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

        // ------------------ tidy -------------------

        PrimeIterator& operator=(const PrimeIterator& other) = delete;
        PrimeIterator(PrimeIterator&& other) = default;
        PrimeIterator& operator=(PrimeIterator&& other) = delete;
    };

    class SideCrossIterator {
    private:
        const MagicalContainer& container;
        std::vector<int>::size_type index;

    public:
        SideCrossIterator(const MagicalContainer& container) : container(container), index(0){}
        SideCrossIterator(const SideCrossIterator& other) : container(other.container), index(other.index){}
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

        // ------------------ tidy -------------------

        SideCrossIterator& operator=(const SideCrossIterator& other) = delete;
        SideCrossIterator(SideCrossIterator&& other) = default;
        SideCrossIterator& operator=(SideCrossIterator&& other) = delete;
    };
};



#endif