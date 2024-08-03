#include <iostream>

using namespace std;

int main() {
  // Initialize the tapes.
  string tape1 = "1101101";
  string tape2 = "1110011";

  // Initialize the pointers to the current positions on the tapes.
  int p1 = tape1.length() - 1;
  int p2 = tape2.length() - 1;

  // Initialize the carry flag.
  bool carry = false;

  // Initialize the result string.
  string result = "";

  // Loop until the end of both tapes or until there's no carry left.
  while (p1 >= 0 || p2 >= 0 || carry) {
    // Get the current digits from the tapes (or 0 if the end is reached).
    int digit1 = (p1 >= 0) ? (tape1[p1] - '0') : 0;
    int digit2 = (p2 >= 0) ? (tape2[p2] - '0') : 0;

    // Add the current digits and the carry flag.
    int sum = digit1 + digit2 + (carry ? 1 : 0);

    // Calculate the current bit and update the carry flag.
    int bit = sum % 2;
    carry = sum >= 2;

    // Prepend the current bit to the result string.
    result = to_string(bit) + result;

    // Update the current positions on the tapes.
    p1--;
    p2--;
  }

  // Print the result.
  cout << result << endl;

  return 0;
}
