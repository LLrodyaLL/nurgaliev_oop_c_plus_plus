#include <iostream>
#include <matrixs/matrixs.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>

TEST_CASE("MatrixS constructors") {
    SUBCASE("Default constructor") {
        MatrixS m;
        CHECK(m.nRows() == 0);
        CHECK(m.nCols() == 0);
    }
    SUBCASE("Constructor with size tuple") {
        MatrixS m(MatrixS::SizeType{2, 3});
//        MatrixS m({2, 3});
        CHECK(m.nRows() == 2);
        CHECK(m.nCols() == 3);
    }
    SUBCASE("Constructor with two size arguments") {
        MatrixS m(2, 3);
        CHECK(m.nRows() == 2);
        CHECK(m.nCols() == 3);
    }
}

TEST_CASE("MatrixS copy constructor and assignment operator") {
    MatrixS m1(2, 3);
    m1.at(0, 0) = 1;
    m1.at(0, 1) = 2;
    m1.at(0, 2) = 3;
    m1.at(1, 0) = 4;
    m1.at(1, 1) = 5;
    m1.at(1, 2) = 6;


    SUBCASE("Copy constructor") {
        MatrixS m2(m1);
        CHECK(m2.nRows() == 2);
        CHECK(m2.nCols() == 3);
        CHECK(m2.at(0, 0) == 1);
        CHECK(m2.at(0, 1) == 2);
        CHECK(m2.at(0, 2) == 3);
        CHECK(m2.at(1, 0) == 4);
        CHECK(m2.at(1, 1) == 5);
        CHECK(m2.at(1, 2) == 6);
    }
    SUBCASE("Assignment operator") {
        MatrixS m2;
        m2 = m1;
        CHECK(m2.nRows() == 2);
        CHECK(m2.nCols() == 3);
        CHECK(m2.at(0, 0) == 1);
        CHECK(m2.at(0, 1) == 2);
        CHECK(m2.at(0, 2) == 3);
        CHECK(m2.at(1, 0) == 4);
        CHECK(m2.at(1, 1) == 5);
        CHECK(m2.at(1, 2) == 6);
    }
}

TEST_CASE("MatrixS at method") {
    MatrixS m(3, 4);

    SUBCASE("Non-const at with tuple argument") {
        m.at({0, 0}) = -5;
        CHECK(m.at({0, 0}) == -5);

        const MatrixS &cm = m;
        CHECK(cm.at({0, 0}) == -5);

    }
    SUBCASE("Non-const at with two arguments") {
        m.at(0, 0) = -5;
        CHECK(m.at(0, 0) == -5);
        const MatrixS &cm = m;
        CHECK(cm.at(0, 0) == -5);

    }
}
//
TEST_CASE("MatrixS resize method") {
    MatrixS m;

    SUBCASE("Resize with tuple argument") {
        m.resize({4, 4});
        CHECK(m.nRows() == 4);
        CHECK(m.nCols() == 4);

    }

    SUBCASE("Resize with two arguments") {
        m.resize(4, 4);
        CHECK(m.nRows() == 4);
        CHECK(m.nCols() == 4);

    }
}


    TEST_CASE("MatrixS initialization and resizing") {
        SUBCASE("Default initialization") {
            MatrixS matrix;
            CHECK(matrix.ssize() == std::make_tuple(0, 0));
        }
