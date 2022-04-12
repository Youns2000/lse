#include <gtest/gtest.h>
#include "gad_tests.hh"

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}