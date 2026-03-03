#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;

/*******************************************************************************
 * Time Complexity (findMaxRecTail):
 * - One recursive call per element, constant work each call.
 * - T(n) = T(n-1) + O(1) => O(n) time.
 * - Recursion depth O(n).
 *
 * Time Complexity (findMaxRecBinarySplit):
 * - Splits into halves and combines with one comparison.
 * - T(n) = 2T(n/2) + O(1) => O(n) time.
 * - Recursion depth O(log n).
*******************************************************************************/

/*******************************************************************************
 * Function prototypes
*******************************************************************************/

template <typename T>
T findMaxRecTail(const T arr[], const int size, int i = 0);

template <typename T>
T findMaxRecBinarySplit(const T arr[], const int left, const int right);

/*******************************************************************************
 * Helper for tail recursion (accumulator style)
*******************************************************************************/
template <typename T>
T findMaxRecTailHelper(const T arr[], const int size, int i, T currentMax) {
    if (i >= size) return currentMax;
    if (arr[i] > currentMax) currentMax = arr[i];
    return findMaxRecTailHelper(arr, size, i + 1, currentMax); // tail call
}

/*******************************************************************************
 * Tail-recursive maximum
*******************************************************************************/
template <typename T>
T findMaxRecTail(const T arr[], const int size, int i) {
    // Assumes size > 0 (true for the provided main/tests)
    if (i <= 0) return findMaxRecTailHelper(arr, size, 0, arr[0]);

    // If someone calls with non-zero i, start from that index
    if (i >= size) return arr[0]; // safety fallback (shouldn't happen in tests)
    return findMaxRecTailHelper(arr, size, i, arr[i]);
}

/*******************************************************************************
 * Binary-split recursive maximum
*******************************************************************************/
template <typename T>
T findMaxRecBinarySplit(const T arr[], const int left, const int right) {
    if (left == right) return arr[left];

    int mid = left + (right - left) / 2;
    T maxL = findMaxRecBinarySplit(arr, left, mid);
    T maxR = findMaxRecBinarySplit(arr, mid + 1, right);
    return (maxL > maxR) ? maxL : maxR;
}

/*******************************************************************************
 * Description:
 * Starting point of the program. Creates two arrays, one fixed and the other
 * random. Determines the maximum value by calling the local function and the
 * standard function.
*******************************************************************************/
int main() {
    // create the array
    const int SIZE = 10;
    int myArray[SIZE] = {
        5, 23, 0, -2, 4,
        9, 11, 21, 130, 6
    };

    // display the maximum
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "Maximum using Recursion: "
         << findMaxRecTail(myArray, SIZE) << endl
         << "From Binary split:"
         << findMaxRecBinarySplit(myArray, 0, SIZE - 1)
         << "Should be 130 for the fixed array\n";
    cout << setfill('-') << setw(40) << "" << endl << endl;

    // create a random array
    const int SIZE_2 = 1000;
    const int MAX_VAL = 10000;
    int randArray[SIZE_2];
    srand(time(0));
    for (int& elem : randArray) {
        elem = rand() % MAX_VAL;
    }

    // find the maximum using C++ standard's algorithm
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "Maximum using Standard Algorithm: "
         << *max_element(randArray, randArray + SIZE_2) << endl;

    // find the maximum using the recursive implementation
    cout << "Maximum using Recursion: "
         << findMaxRecTail(randArray, SIZE_2) << endl;
    cout << setfill('-') << setw(40) << "" << endl;

    // terminate
    return 0;
}