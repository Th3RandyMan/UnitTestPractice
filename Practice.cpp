#include "Practice.h"
#include <string>

using std::string;

// Receive three integers and rearrange their values so that they are in
// descending order from greatest (first) to least (third)
void Practice::sortDescending(int & first, int & second, int & third)
{
  if( first < second )
  {
    int temp = first;
    first = second;
    second = temp;
  }
  if( first < third )
  {
    int temp = first;
    first = third;
    third = temp;
  }
  if( second < third )
  {
    int temp = second;
    second = third;
    third = temp;
  }
}

// Receive a string and return whether or not it is strictly a palindrome,
// where it is spelled the same backwards and forwards when considering every
// character in the string, but disregarding case ('x' is the same as 'X')
bool Practice::isPalindrome(string input)
{
  for(unsigned int i=0; i < input.size(); i++)
  {
    if( input[i] < 'A' || input[i] > 'Z' )
    {
      //change lower case to upper case
      input[i] = input[i] - ('a' - 'A');
    }
  }
  for(unsigned int i=0; i < input.size()/2; i++)
  {
    if( input[i] != input[input.size()-1-i] )
      return false;
  }
  return true;
}

// This function receives a string and counts how many times the same character
// is repeated at the beginning of the string, before any other characters. The
// function is case sensative so 'Z' is different than 'z'.
int Practice::count_starting_repeats(string word)
{
    int repetition = 1;
    int index = 0;
    
    while( index < word.length()-1 && word[index] == word[index+1] ){
      repetition++;
      index++;
    }

    return repetition;
}


// Receives an array that represents the hours someone sleeps each night of the week
// (as an array of seven integers) and returns a pointer to locate the first instance
// of an "all nighter" in the array (a day with 0 hours sleep) and returns the pointer. 
// However, if there are no such days found, the function should return nullptr.

/* Implementation A
int* Practice::allnighter(int sleep[7]) //we aren't checking for not sleeping...
{
 return nullptr;
}
*/

/* Implementation B
int* Practice::allnighter(int sleep[7])//we aren't checking other nights
{
 return & sleep[0];
}
*/

/* Implementation C
int* Practice::allnighter(int sleep[7]) //redundant condition checking address and not value
{                                         //breaks at i = 7, seg fault
 int i=0;
 int *place = &sleep[i];
 while(place && place != nullptr)
 {
   place = &sleep[++i];
 }
 return place;
}
*/


/* Implementation D 
int* Practice::allnighter(int sleep[7])   //won't segfault, but will always return last element
{
 int i=0;
 int *place = &sleep[i];
 while(place && place != nullptr && i < 7)
 {
   place = &sleep[++i];
 }
 return place;
}
*/

/* Implementation E*/
int* Practice::allnighter(int sleep[7]) //good
{
 int *place = nullptr;
 for(int i=0; i < 7; i++)
 {
    if( sleep[i] == 0 ){
      place = &sleep[i];
      return place;
    }
 }
 return place;
}


/* Implementation F
int* Practice::allnighter(int sleep[7]) //will return last instance instead of first
{
 int *place = nullptr;
 for(int i=0; i < 7; i++)
 {
   if( sleep[i] == 0 )
     place = &sleep[i];
 }
 return place;
}
*/