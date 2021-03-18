/*
 * Maximum Sum Subarray Problem (Kadane's Algorithm)
 * 
 * Given an integer array, find a contiguous array within it with the largest sum.
 * 
 * Example:
 * 
 * Input:  {-2, 1, -3, 4, -1, 2, 1, -5, 4}
 * Output: Subarray with the largest sum is {4, -1, 2, 1} with sum 6.
 */

// Linear O(n) Solution Using Kadane's Algorithm

#include <iostream>
#include <climits>

using namespace std;

// Function to find the maximum sum of a contiguous subarray
// in a given integer array (handles negative numbers as well)
void maxSubarray(int arr[], int len)
{
  // Stores the maximum sum subarray found so far
  int bestSum = INT_MIN,
    // Stores the maximum sum of subarray ending at the current position
    currentSum = 0,
    start = 0, s = 0, end = 0;
  // Traverse the given array
  for (int i = 0; i < len; i++)
  {
    // Update the maximum sum of subarray "ending" at index "i"
    currentSum += arr[i];
    // If the best sum is less than the current sum
    if (bestSum < currentSum)
    {
      // Then set the best sum to the current sum
      bestSum = currentSum; start = s; end = i;
    }
    // If current sum is negative
    if (currentSum < 0)
    {
      // Then set current back to 0 and move on to the next item
      currentSum = 0; s = i + 1;
    }
  }
  cout << "Maximum sum subarray is: " << bestSum << endl;
  cout << "Starting index: " << start << " Ending index: " << end << endl;
}

// Driver to test the function

int main()
{
  int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3},
    len = sizeof(arr)/sizeof(arr[0]);
  maxSubarray(arr, len); 
  return 0;
}