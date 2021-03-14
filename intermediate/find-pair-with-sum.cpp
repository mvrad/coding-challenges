/*
 * Find the pair with a given sum in an array
 * 
 * Given an unsorted integer array, find a pair that equal a given sum in the array.
 * 
 * Example:
 * 
 * Input:
 * arr = [8, 7, 2, 5, 3, 1]
 * sum = 10
 * 
 * Output:
 * Pair found at index 0 and 2 (8 + 2)
 * or Pair found at index 1 and 4 (7 + 3)
 */

// Naive Approach (written in C)

#include <stdio.h>

// Naive method to find a pair in an array with a given sum
void findPair1(int arr[], int n, int sum)
{
  // consider each element except the last
  for (int i = 0; i < n - 1; i++)
  {
    // start from the i'th element until the last element
    for (int j = i + 1; j < n; j++)
    {
      // if the desired sum is found, print it
      if (arr[i] + arr[j] == sum)
      {
        printf("Pair found at index %d and %d", i, j);
        return;
      }
    }
  }

  // we reach here if the pair is not found
  printf("Pair not found");
}

// Better solution: O(n log n) using sorting

#include <iostream>
#include <algorithm>
using namespace std;

// Function to find a pair in an array with a given sum using sorting
void findPair2(int arr[], int n, int sum)
{
  // sort the array in ascending order
  sort(arr, arr + n);

  // maintain two indices pointing to endpoints of the array
  int low = 0;
  int high = n - 1;

  // reduce the search space `arr[low…high]` at each iteration of the loop

  // loop till the search space is exhausted
  while (low < high)
  {
    // sum found
    if (arr[low] + arr[high] == sum)
    {
      cout << "Pair found" << endl;
      return;
    }

    // increment `low` index if the total is less than the desired sum;
    // decrement `high` index if the total is more than the desired sum
    (arr[low] + arr[high] < sum) ? low++: high--;
  }

  // we reach here if the pair is not found
  cout << "Pair not found";
}

// Even better solution: O(n) using hashing

// #include <iostream>
#include <unordered_map>
using namespace std;

// Function to find a pair in an array with a given sum using hashing
void findPair3(int arr[], int n, int sum)
{
  // create an empty map
  unordered_map<int, int> map;

  // do for each element
  for (int i = 0; i < n; i++)
  {
  // check if pair `(arr[i], sum - arr[i])` exists

    // if the difference is seen before, print the pair
    if (map.find(sum - arr[i]) != map.end())
    {
      cout << "Pair found at index " << map[sum - arr[i]] <<
        " and " << i << endl;
      return;
      }

    // store index of the current element in the map
    map[arr[i]] = i;
  }

  // we reach here if the pair is not found
  cout << "Pair not found";
}

// **-- main() --**

// *-- Naive Solution --*

// int main()
// {
//   int arr[] = { 8, 7, 2, 5, 3, 1 };
//   int sum = 10;

//   int n = sizeof(arr)/sizeof(arr[0]);

//   findPair1(arr, n, sum);

//   return 0;
// }

// *-- O(n log n) solution --*

// int main()
// {
//   int arr[] = { 8, 7, 2, 5, 3, 1};
//   int sum = 10;

//   int n = sizeof(arr)/sizeof(arr[0]);

//   findPair2(arr, n, sum);

//   return 0;
// }

// *-- O(n) solution --*

int main()
{
  int arr[] = { 8, 7, 2, 5, 3, 1};
  int sum = 10;

  int n = sizeof(arr)/sizeof(arr[0]);

  findPair3(arr, n, sum);

  return 0;
}