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

void maxSubarray(int arr[], int len)
{
  int bestSum = INT_MIN, currentSum = 0, 
    start = 0, s = 0, end = 0;
  for (int i = 0; i < len; i++)
  {
    currentSum += arr[i];
    if (bestSum < currentSum)
    {
      bestSum = currentSum; start = s; end = i;
    }
    if (currentSum < 0)
    {
      currentSum = 0; s = i + 1;
    }
  }
  cout << "Maximum sum subarray is: " << bestSum << endl;
  cout << "Starting index: " << start << " Ending index: " << end << endl;
}

int main()
{
  int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3},
    len = sizeof(arr)/sizeof(arr[0]);

  maxSubarray(arr, len); 
  return 0;
}