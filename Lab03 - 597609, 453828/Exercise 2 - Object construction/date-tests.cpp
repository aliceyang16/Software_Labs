#include "date.h"
#include <gtest/gtest.h>

// Exercise 2.1
// Remove this test after inspecting the output.
// Tests which require manual verification should not be lumped
// with tests which are automatically verified!
TEST(Date, hasUninitialisedState) {
	Date today;
	printDate(today);
}

TEST(Date, ifValidDoesNotThrowException) {
	Date heritage_day{24, Month::September, 2000};
	EXPECT_EQ(24, heritage_day.day());
	EXPECT_EQ(Month::September, heritage_day.month());
	EXPECT_EQ(2000, heritage_day.year());
}


// Exercise 2.2
// Supply additional tests for the constructor here, which
// verify that an EXEPTION is thrown when an attempt is made
// to construct an invalid date. Think carefully about which
// invalid dates to test.

TEST(Date, ifInvalidThrowException) {
	
	//Whatever you called throw is second
	EXPECT_THROW({Date my_date(31, Month::February, 2000);}, InvalidDate);
}


// Exercise 2.3
TEST(Date, isEquivalentToAnIdenticalDate) {
    Date date_1(1, Month::January, 2000);
    Date date_2(1, Month::January, 2000);

    EXPECT_TRUE(date_1 == date_2);
}

// Supply at least three additional tests for
// the equality operator here, to ensure that
// it is working correctly.

TEST(Date, DaysNotEqualGiveFalse) {
    Date date_1(1, Month::January, 2000);
    Date date_2(2, Month::January, 2000);

    EXPECT_FALSE(date_1 == date_2);
}

TEST(Date, MonthsNotEqualGiveFalse) {
    Date date_1(1, Month::January, 2000);
    Date date_2(1, Month::February, 2000);

    EXPECT_FALSE(date_1 == date_2);
}

TEST(Date, YearsNotEqualGiveFalse) {
    Date date_1(1, Month::January, 2000);
    Date date_2(1, Month::January, 2001);

    EXPECT_FALSE(date_1 == date_2);
}

// Exercise 2.4
// Provide tests for a new member function of the Date class
// which will increase the date by one day.

TEST(Date, IncrementDay) {
    Date date_1(31, Month::January, 2000);
	
    //memberfunction for incrementing date; New date
	date_1.nextDay();
	
	Date date_2(1, Month::February,2000);

    EXPECT_TRUE(date_1 == date_2);
}

// Exercise 2.5
// Write tests for the new default constructor and the
// setDefaultDate method.
TEST(Date, givesSetDefaultDate) {
	Date whatIsDefault;
	Date whatDefaultShouldBe(1, Month::January, 1900);
	EXPECT_TRUE(whatIsDefault._default == whatDefaultShouldBe);	
}

TEST(Date, userSetDefaultDate) {
	Date userDefault;
	userDefault.setDefaultDate(5, Month::February, 1991);
	Date newDefault;
	Date whatDefaultShouldBe2(5, Month::February, 1991);
	EXPECT_TRUE(newDefault._default == whatDefaultShouldBe2);
	}
	
	
//Further illustrate that Default has been changed to user defined Default from previous test
TEST(Date, newDefaultIs) {
	Date myPrevDefinedDefault;
	Date whatDefaultShouldBe2(5, Month::February, 1991);
	EXPECT_TRUE(myPrevDefinedDefault._default == whatDefaultShouldBe2);
	}
