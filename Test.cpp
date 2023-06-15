#include "doctest.h"
#include <stdexcept>
#include <iostream>
#include "sources/MagicalContainer.hpp"

using namespace std;
using namespace ariel;


// General testing magical container
TEST_CASE("Check MagicalConatiner"){
    MagicalContainer container;

    CHECK(container.size() == 0);

    container.addElement(1);
    CHECK(container.size() == 1);

    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);
    CHECK(container.size() == 5);

    container.addElement(5);
    CHECK(container.size() == 6);
    CHECK_NOTHROW(container.removeElement(4));
    CHECK(container.size() == 5);

    CHECK_THROWS(container.removeElement(4));
    CHECK_NE(container.size(), 4);
    CHECK(container.size() == 5);

    container.removeElement(1);
    CHECK(container.size() == 4);

    container.removeElement(2);
    CHECK_NE(container.size(),4);
}


TEST_CASE("Check the isPrime function"){
    MagicalContainer container;

    int a = 1;
    CHECK(container.isPrime(a) == false);
    CHECK_NE(container.isPrime(2) , false);
    CHECK(container.isPrime(5) == true);
    CHECK(container.isPrime(400) == false);
    CHECK_NE(container.isPrime(20) , true);
}

// Testing the sorting of the ascending iterator
TEST_CASE("Check the ascendingIterator sorting"){
    MagicalContainer container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(1);
    container.addElement(10);
    container.addElement(9);
    
    MagicalContainer ::AscendingIterator ascending(container);
    
    auto current = ascending.begin();
    // checks the operator* overloading
    CHECK(*current == 1);
    // testes the ++ operator
    ++current;
    CHECK(*current == 2);
    ++current;
    CHECK(*current == 5);
    CHECK_NOTHROW(++current);
    CHECK(*current == 9);
    CHECK_NOTHROW(++current);
    CHECK(*current == 10);
    
}

TEST_CASE("Check the rest of the functions in the ascending iterator"){
    MagicalContainer container;
    MagicalContainer ::AscendingIterator ascending(container);
    // This check tests the operator==
    CHECK(ascending.begin() == ascending.end());
    
    container.addElement(1);
    // Tests both != and == operators
    MagicalContainer ::AscendingIterator ascending1(container);
    CHECK_NE(ascending1.begin(), ascending1.end());

}


TEST_CASE("Check the rest of the functions in the ascending iterator"){
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    MagicalContainer ::AscendingIterator ascending(container);
    MagicalContainer ::AscendingIterator ascending1(container);
    CHECK(ascending == ascending1);
    // Test the operator<
    CHECK_FALSE(ascending < ascending1);
    // Test the operator>
    CHECK_FALSE(ascending > ascending1);
    CHECK_FALSE(ascending != ascending1);
        

    MagicalContainer container2;
    container2.addElement(1);
    container2.addElement(2);
    container2.addElement(3);
    container2.addElement(4);
    container2.addElement(5);
    MagicalContainer ::AscendingIterator ascending2(container2);

    CHECK(ascending == ascending2);
    ++ascending2;
    CHECK_FALSE(ascending == ascending2);
    CHECK(ascending < ascending2);
    ++ascending;
    CHECK(ascending == ascending2);

    CHECK(*ascending.end() <  *ascending2.end());
    CHECK_FALSE(*ascending.end() == *ascending2.end());
    CHECK_FALSE(*ascending.end() > *ascending2.end());
    
}



TEST_CASE("Check the PrimeIterator"){
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);
    container.addElement(6);
    container.addElement(7);
    container.addElement(8);

    MagicalContainer ::PrimeIterator prime(container);
    
    auto current = prime.begin();
    CHECK(*current == 2);
    CHECK_NOTHROW(++current);
    CHECK(*current == 3);
    CHECK_NOTHROW(++current);
    CHECK(*current == 5);
    CHECK_NOTHROW(++current);
    CHECK(*current == 7);
    ++current;
    CHECK(current == prime.end());
    // reached the end of container
    CHECK_THROWS(++current);
    
}


TEST_CASE("Check the rest of the functions in the Prime iterator"){
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);
    MagicalContainer ::AscendingIterator prime(container);
    MagicalContainer ::AscendingIterator prime1(container);
    CHECK(prime == prime1);
    // Test the operator<
    CHECK_FALSE(prime < prime1);
    // Test the operator>
    CHECK_FALSE(prime > prime1);
    CHECK_FALSE(prime != prime1);
        

    MagicalContainer container2;
    container2.addElement(1);
    container2.addElement(2);
    container2.addElement(3);
    container2.addElement(4);
    container2.addElement(5);
    container2.addElement(6);
    container2.addElement(7);
    MagicalContainer ::AscendingIterator prime2(container2);


    CHECK(prime == prime2);
    ++prime2;
    CHECK_FALSE(prime == prime2);
    CHECK(prime < prime2);
    ++prime;
    CHECK(prime == prime2);

    
    CHECK(*prime.end() <  *prime2.end());
    CHECK_FALSE(*prime.end() == *prime2.end());
    CHECK_FALSE(*prime.end() > *prime2.end());
    
}




TEST_CASE("Check the SideCrossIterator"){
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);
    container.addElement(6);
    container.addElement(7);
    container.addElement(8);
    
    MagicalContainer ::SideCrossIterator side(container);
    
    auto current = side.begin();
    CHECK(*current == 1);
    ++current;
    CHECK(*current == 8);
    ++current;
    CHECK(*current == 2);
    ++current;
    CHECK(*current == 7);
    ++current;
    CHECK(*current == 3);
    ++current;
    CHECK(*current == 6);
    ++current;
    CHECK(*current == 4);
    ++current;
    CHECK(*current == 5);
    ++current;
    CHECK_THROWS(++current);
    CHECK(current == side.end());
    
}

TEST_CASE("Check the rest of the functions in the Prime iterator"){
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);
    MagicalContainer ::AscendingIterator side(container);
    MagicalContainer ::AscendingIterator side1(container);
    CHECK(side == side1);
    // Test the operator<C
    CHECK_FALSE(side < side1);
    // Test the operator>
    CHECK_FALSE(side > side1);
    CHECK_FALSE(side != side1);

        

    MagicalContainer container2;
    container2.addElement(1);
    container2.addElement(2);
    container2.addElement(3);
    container2.addElement(4);
    container2.addElement(5);
    container2.addElement(6);
    container2.addElement(7);
    MagicalContainer ::AscendingIterator side2(container2);


    CHECK(side == side2);
    ++side2;
    CHECK_FALSE(side == side2);
    CHECK(side < side2);
    ++side;
    CHECK(side == side2);

    
    CHECK(*side.end() <  *side2.end());
    CHECK_FALSE(*side.end() == *side2.end());
    CHECK_FALSE(*side.end() > *side2.end());
    
}

