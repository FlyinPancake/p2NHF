#include "palya.hpp"
#include "allomas.hpp"
#include "vonat.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "gtest_lite.h"
#include "jegy.hpp"

int main(int argc, char const *argv[])
{
    Palya tst = Palya("Teszt", 10, 10);
    tm ind, erk;

    TEST(Allomas, hozzaad)
    {
        tst.AddStation("Elso Allomas");
        std::stringstream ss;
        ss << *tst.GetStation(0);
        EXPECT_STREQ("Allomas: Elso Allomas", ss.str().c_str()) ;
        EXPECT_EQ((size_t)1, tst.Hossz());
    } END

    TEST(Allomas, hossz)
    {
        EXPECT_EQ((size_t)1, tst.Hossz());

        tst.AddStation("Masodik allomas");

        EXPECT_EQ((size_t)2, tst.Hossz());

        tst.AddStation("Harmadik allomas");
        
        EXPECT_EQ((size_t)3, tst.Hossz());
        EXPECT_EQ((size_t)0, tst.Vonatok());
    } END
    
    TEST(Vonat, vonatokSzama) 
    {
        EXPECT_EQ((size_t)0, tst.Vonatok());
        
        time_t now = time(NULL);
        erk = ind = *localtime(&now);
        erk.tm_hour++;
        Vonat von = Vonat(tst.GetStation(0), tst.GetStation(2), ind, erk,(size_t) 3, (size_t) 40);
        tst.AddTrain(von);
        EXPECT_EQ((size_t)1, tst.Vonatok());
    } END

    TEST(Vonat, kiiras)
    {
        std::stringstream ss;
        ss << *tst.GetTrain(0);
        std::stringstream elvart;
        elvart << "Vonat szama: 101\n";
        elvart << "Indulo Allomas: Elso Allomas\n";
        elvart << "Erkezo Allomas: Harmadik allomas\n";
        elvart << "Indul: " << asctime(&ind);
        elvart << "Erkezik: " << asctime(&erk);

        EXPECT_STREQ(elvart.str().c_str(), ss.str().c_str());
    } END
    
    TEST(Jegy, foglal)
    {
        EXPECT_TRUE(tst.GetTrain(0)-> CheckSeat(2,5));
        EXPECT_NO_THROW(Jegy proba1(tst.GetTrain(0),2,5));
        EXPECT_FALSE(tst.GetTrain(0)-> CheckSeat(2,5));
    } END

    TEST(Jegy, exceptionok)
    {
        EXPECT_THROW(Jegy(tst.GetTrain(0), 5, 2), const char *);
        EXPECT_THROW(Jegy(tst.GetTrain(0), 2, 50), const char *);
        EXPECT_THROW(Jegy(tst.GetTrain(0), 2, 5), const char *);
    } ENDM



    // std::cout << *tst.GetTrain(0);


       // tst.ListStations();
    //std::cout << vonToo;
    return 0;
}
