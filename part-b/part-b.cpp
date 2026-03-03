#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

/*******************************************************************************
 * Time Complexity:
 * Tower of Hanoi makes (2^n - 1) moves => O(2^n) time
 * Recursion depth: O(n)
*******************************************************************************/

/*******************************************************************************
 * Function prototype
*******************************************************************************/
void towerHanoi(int, string, string, string, int&);

/*******************************************************************************
 * Function definition
*******************************************************************************/
void towerHanoi(int numDisks, string source, string buffer, string target, int& numMoves) {
    if (numDisks == 0) return;

    towerHanoi(numDisks - 1, source, target, buffer, numMoves);

    cout << "Moving disc " << numDisks
         << " from " << source
         << " to " << target << endl;
    numMoves++;

    towerHanoi(numDisks - 1, buffer, source, target, numMoves);
}

/*******************************************************************************
 * Description:
 * Starting point of the program. Calls a function to recursively determine
 * solutions for the first 5 instances of the Tower of Hanoi problem.
*******************************************************************************/
int main() {
    // solve the first 5 cases of the Tower of Hanoi problem
    for (int i = 1, numMoves = 0; i <= 5; i++, numMoves = 0) {
        cout << setfill('-') << setw(40) << "" << endl;
        cout << "Trying n = " << i << endl << endl;
        towerHanoi(i, "Rod #1", "Rod #2", "Rod #3", numMoves);
        cout << endl << "Number of Moves = " << numMoves << endl;
    }

    // terminate
    return 0;
}