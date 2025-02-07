/**
 * Unit Tests for Practice class
**/

#include <gtest/gtest.h>
#include "Practice.h"

class PracticeTest : public ::testing::Test
{
	protected:
		PracticeTest(){} //constructor runs before each test
		virtual ~PracticeTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PracticeTest, smoke_test)
{
    ASSERT_TRUE(true);
}

//	Sort Descending Tests
TEST(PracticeTest, sortDesc1)	//Ascending start
{
  Practice testObject;
  int a=1, b=2, c=3;
  testObject.sortDescending(a,b,c);
  ASSERT_EQ(a,3);
  ASSERT_EQ(b,2);
  ASSERT_EQ(c,1);
}
TEST(PracticeTest, sortDesc2)	//Ascending start, secend and third swap
{
  Practice testObject;
  int a=1, b=3, c=2;
  testObject.sortDescending(a,b,c);
  ASSERT_EQ(a,3);
  ASSERT_EQ(b,2);
  ASSERT_EQ(c,1);
}
TEST(PracticeTest, sortDesc3)	//first and second swap
{
  Practice testObject;
  int a=2, b=1, c=3;
  testObject.sortDescending(a,b,c);
  ASSERT_EQ(a,3);
  ASSERT_EQ(b,2);
  ASSERT_EQ(c,1);
}
TEST(PracticeTest, sortDesc4)	//Ascending shift left
{
  Practice testObject;
  int a=2, b=3, c=1;
  testObject.sortDescending(a,b,c);
  ASSERT_EQ(a,3);
  ASSERT_EQ(b,2);
  ASSERT_EQ(c,1);
}
TEST(PracticeTest, sortDesc5)	//Ascending shift right
{
  Practice testObject;
  int a=3, b=1, c=2;
  testObject.sortDescending(a,b,c);
  ASSERT_EQ(a,3);
  ASSERT_EQ(b,2);
  ASSERT_EQ(c,1);
}
TEST(PracticeTest, sortDesc6)	//Already Descending
{
  Practice testObject;
  int a=3, b=2, c=1;
  testObject.sortDescending(a,b,c);
  ASSERT_EQ(a,3);
  ASSERT_EQ(b,2);
  ASSERT_EQ(c,1);
}


// is Palidrome Tests
TEST(PracticeTest, pal1)	//general
{
  Practice testObject;
  ASSERT_EQ(testObject.isPalindrome("abcba"),true);//should be good
}
TEST(PracticeTest, pal2)
{
  Practice testObject;
  ASSERT_EQ(testObject.isPalindrome("racecar"),true);//should be good
}
TEST(PracticeTest, pal3)	// not palindrome
{
  Practice testObject;
  ASSERT_EQ(testObject.isPalindrome("hello"),false);//should be good
}
TEST(PracticeTest, pal4)	//empty string
{
  Practice testObject;
  ASSERT_EQ(testObject.isPalindrome(""),true);//should be good
}
TEST(PracticeTest, pal5)	//try tabes
{
  Practice testObject;
  ASSERT_EQ(testObject.isPalindrome("		"),true);//should be good
}
TEST(PracticeTest, pal6)	//check case sensitivity
{
  Practice testObject;
  ASSERT_EQ(testObject.isPalindrome("RACEcar"),true);//should be good
}
TEST(PracticeTest, pal7)	// try numbers
{
  Practice testObject;
  ASSERT_EQ(testObject.isPalindrome("123456"),false);//should be good
}
TEST(PracticeTest, pal8)	//check ascii
{
  Practice testObject;
  ASSERT_EQ(testObject.isPalindrome("[^|{"),false);//should be good
}
TEST(PracticeTest, pal9)	// try numbers again
{
  Practice testObject;
  ASSERT_EQ(testObject.isPalindrome("1234321"),true);//should be good
}


// Count Starting Repeats Test
TEST(PracticeTest, repeat1)	//general
{
  Practice testObject;
  ASSERT_EQ(testObject.count_starting_repeats("zzz"),3);
}
TEST(PracticeTest, repeat2)	//case sensitivity
{
  Practice testObject;
  ASSERT_EQ(testObject.count_starting_repeats("aaAAaa"),2);
}
TEST(PracticeTest, repeat3)	//test numbers
{
  Practice testObject;
  ASSERT_EQ(testObject.count_starting_repeats("11223344"),2);
}
TEST(PracticeTest, repeat4)	//no size
{
  Practice testObject;
  ASSERT_EQ(testObject.count_starting_repeats(""),0);
}
TEST(PracticeTest, repeat5)	//no repeat
{
  Practice testObject;
  ASSERT_EQ(testObject.count_starting_repeats("abcd"),0);
}
TEST(PracticeTest, repeat6)	//size one string
{
  Practice testObject;
  ASSERT_EQ(testObject.count_starting_repeats("a"),0);	
}


//All nighter function tests
TEST(PracticeTest, allnight1) //awake all week
{
  Practice testObject;
  int sleep[7] = {0,0,0,0,0,0,0};
  ASSERT_EQ(testObject.allnighter(sleep),&sleep[0]);
}

TEST(PracticeTest, allnight2) //sleep everyday
{
  Practice testObject;
  int sleep[7] = {7,2,5,3,4,5,6};
  ASSERT_EQ(testObject.allnighter(sleep),nullptr);
}

TEST(PracticeTest, allnight3) //no sleep day 1
{
  Practice testObject;
  int sleep[7] = {0,1,2,3,4,5,6};
  ASSERT_EQ(testObject.allnighter(sleep),&sleep[0]);
}

TEST(PracticeTest, allnight4) //no sleep day 2
{
  Practice testObject;
  int sleep[7] = {1,0,2,3,4,5,6};
  ASSERT_EQ(testObject.allnighter(sleep),&sleep[1]);
}

TEST(PracticeTest, allnight5) //no sleep day 3
{
  Practice testObject;
  int sleep[7] = {1,2,0,3,4,5,6};
  ASSERT_EQ(testObject.allnighter(sleep),&sleep[2]);
}

TEST(PracticeTest, allnight6) //no sleep day 4
{
  Practice testObject;
  int sleep[7] = {1,2,3,0,4,5,6};
  ASSERT_EQ(testObject.allnighter(sleep),&sleep[3]);
}

TEST(PracticeTest, allnight7) //no sleep day 5
{
  Practice testObject;
  int sleep[7] = {1,2,3,4,0,5,6};
  ASSERT_EQ(testObject.allnighter(sleep),&sleep[4]);
}

TEST(PracticeTest, allnight8) //no sleep day 6
{
  Practice testObject;
  int sleep[7] = {1,2,3,4,5,0,6};
  ASSERT_EQ(testObject.allnighter(sleep),&sleep[5]);
}

TEST(PracticeTest, allnight9) //no sleep day 7
{
  Practice testObject;
  int sleep[7] = {1,2,3,4,5,6,0};
  ASSERT_EQ(testObject.allnighter(sleep),&sleep[6]);
}