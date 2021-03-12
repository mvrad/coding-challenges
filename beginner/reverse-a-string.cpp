/*
 * Reverse a string
 * 
 * Example:
 * Str: Hello
 * revStr: olleH
 */

#include <iostream>

// **-- Solution 1: Using a loop --*

using namespace std;

// int main() {
  
//   string greeting = "Hello";
//   int len = greeting.length();
//   int n = len - 1;
//   for(int i = 0; i < (len / 2); i++){

    // Using temp to store the char value at index i so 
    // you can swap it in later for char value at index n
    // char temp = greeting[i];
    // greeting[i] = greeting[n];
    // greeting[n] = temp;
    // n = n - 1;

    // Using the swap method to switch values at each index
    // swap(greeting[i],greeting[n]);
    // n = n-1;
//   }
//   cout << greeting << endl;
// }

// *-- Solution 2: Using a function --*

using namespace std;

void reverse_String (string& greet, int n, int i)
{
  if(n <= i)
  {
    return;
  }

  swap(greet[i], greet[n]);
  reverse_String(greet, n - 1, i + 1);
}

// int main()
// {  
//   string greeting = "Hello";
//   cout << "String before reversal: " << greeting << endl;
//   reverse_String(greeting, greeting.length() - 1, 0);
//   cout << "String after reversal: " << greeting << endl;
// }

// *-- Solution 3: Creating a new string --*

using namespace std;

int main() {
  
  string greeting = "Hello";

  string new_greeting;

  for(int n = greeting.length() - 1; n >= 0; n--){
    new_greeting.push_back(greeting[n]);
  }
  cout << "Original string: " << greeting << endl;
  cout << "New reversed string: " << new_greeting << endl;
  
}