#include "palya.hpp"
#include "allomas.hpp"
#include "vonat.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "gtest_lite.h"

int main(int argc, char const *argv[])
{
    Palya tst = Palya("Teszt", 10, 10);

    TEST(Test1, sanity) {
        tst.AddStation("Elso Allomas");
        std::stringstream ss;
        ss << *tst.GetStation(0);
        EXPECT_STREQ("Allomas: Elso Allomas", ss.str().c_str()) ;
        EXPECT_EQ(1, tst.Hossz());

        tst.AddStation("Masodik allomas");
        tst.AddStation("Harmadik allomas");
        
        EXPECT_EQ((size_t) 3, tst.Hossz());
        EXPECT_EQ((size_t) 0, tst.Vonatok());
    } ENDM
    tm ind, erk;
    time_t now = time(NULL);
    ind = *localtime(&now);
    erk = *localtime(&now);
    erk.tm_hour++;
    tst.AddTrain(tst.GetStation(0), tst.GetStation(1), ind, erk,(size_t) 3);

    std::cout << *tst.GetTrain(0);


       // tst.ListStations();
    return 0;
}
