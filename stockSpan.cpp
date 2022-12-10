//Filename: stockSpanBruteForce.cpp
//Author: Daniel Kruze
//Create Date: 09/23/21
//Compile Date: 09/27/21

#include <cstdlib> // srand, rand
#include <iostream> // cin, cout
#include <vector> // vector, vector operations
#include <stack> // stack, stack operations

using namespace std; // namespace for library functions

int n; // integer n for user input
vector<int> prices; // vector for holding prices
vector<int> span; // vector that represents the span
stack<int> spanStack; // stack that is used for calculating individual spans

/*
* This function populates the vector for prices with n random numbers
* The numbers are seeded by the user input integer, meaning each different n has its own, fixed span of pseudo-random values
*   Expected input: integer n
*   Expected output: vector "prices" of size n, with random values from seed n
*/
void setPrices() {
    int stockPrice; // integer representing a price
    srand((n * 10) % 13); // seed the rng
    for (int i = 0; i < n; i++) { // for n elements
        stockPrice = (rand() % 10) + 1; // the price for a given day is a random number mod 10
        prices.push_back(stockPrice); // push that price into the price vector
    }
}

/*
* This function calculates the span for each price, and places it into the vector for span
* These spans are calculated by iterating through each price, and comparing that price to the top of a stack defined globally
* Every value before the price that is lower than that price is pushed on to the stack, and its index minus the index of the top is recorded as its span
* If the value is larger, then the stack is popped until it's either empty or the top is larger than the value.
*   Should the stack be empty, then the index of the current value is increased by 1 and considered the span of itself. That value is now the top of the stack
* The default span for a value with nothing smaller or equal directly before it is 1
*   Expected input: members of the price vector, one by one
*   Expected output: vector "span" of size n, with elements of value [1, n]
*/
void findSpan() {
    spanStack.push(prices[0]); // initialize the stack with the first value
    span.push_back(1); // push a 1 onto the span for the first day's price--this, by definition, is always the case for day 1
    int tempIndex = 0; // let a temporary integer be 0; this will hold a value for subtraction later
    for (int i = 1; i < n; i++) { // iterate through prices
        int tippyTop = spanStack.top(); // let an integer represent the stack's current top
        if (prices[i] <= tippyTop) { // if the current value is smaller than the preceding value
            spanStack.push(prices[i]); // push this value onto the stack
            span.push_back(i - tempIndex); // this value's span is its index minus the index of subtraction
            tempIndex = i; // the index of subtraction is now the current index
        }
        else { // if the current value is larger than its preceding value
            spanStack.pop(); // pop the top of the stack
            if (spanStack.empty() == 1) { // if the stack is empty
                spanStack.push(prices[i]); // push the current value to the stack
                span.push_back(i + 1); // the span of the current value is its index plus 1
                tempIndex = i; // the index of subtraction is now the current index
                continue; // check the next price
            }
            i--; // after popping the stack, decrease i; this will allow the same value to be checked against a different, older member of the stack
        }
    }

}

void printSpan() {
    cout << "Prices for " << n << " days:" << endl; // label the prices
    for (int i = 0; i < (n - 1); i++) { // this for loop prints out all but the latest of the prices in daily order, delineated by commas
        cout << prices[i] << ", "; // delineator
    }
    cout << prices[n-1] << endl; // print the most recent price
    cout << "Span for " << n << " days:" << endl; // label the span
    for (int i = 0; i < (n - 1); i++) { // this for loop prints out all but the latest of the span values in daily order, delineated by commas
        cout << span[i] << ", "; // delineator
    }
    cout << span[n-1] << endl; // print the span of the most recent price
}

int main() {
    bool sentryMain = true; // sentry for the following while loop
    while (sentryMain) { // sentry = true
        cout << "Please enter an integer value greater than 2:\n>> "; // 2 and below represents trivial cases for this problem
        cin >> n; // int n = user input
        if (cin.fail()){ // if the user enters a non-integer
            cin.clear(); // clear the error flag that cin throws
            cin.ignore(100000, '\n'); // ignore up to 100,000 entered characters (technically, an input of 100,001 characters could break this program)
            cout << "Invalid input!" << endl; // warn the user their input is invalid, let them try again
        }
        else if (!cin.fail()) { // if the user enters an integer
            if (n <= 2) { // if the user enters any integer lower than 3
                cout << "Invalid Input!" << endl; // warn the user their input is invalid, let them try again
            }
            else { // if the user enters a valid integer
                setPrices(); // populate the prices vector with random values
                findSpan(); // calculate span members and populate the span vector with them
                printSpan(); // print out the span members
                sentryMain = false; // end the loop
            }
        }
    }
    return 0;
}