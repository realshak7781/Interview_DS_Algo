#include<bits\stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

     // Create bitsets of size 8
    bitset<8> b1("10101010"); // Initialize with binary string
    bitset<8> b2("11001100"); // Another bitset for operations

    cout << "Initial Bitsets:" << endl;
    cout << "b1: " << b1 << endl;
    cout << "b2: " << b2 << endl;

    // 1. set() - Set bits to 1
    cout << "\n1. Using set():" << endl;
    b1.set(0); // Set the 1st bit (index 0) to 1
    cout << "b1 after b1.set(0): " << b1 << endl;
    b1.set(); // Set all bits to 1
    cout << "b1 after b1.set(): " << b1 << endl;

    // 2. reset() - Reset bits to 0
    cout << "\n2. Using reset():" << endl;
    b1.reset(0); // Reset the 1st bit (index 0) to 0
    cout << "b1 after b1.reset(0): " << b1 << endl;
    b1.reset(); // Reset all bits to 0
    cout << "b1 after b1.reset(): " << b1 << endl;

    // 3. flip() - Toggle bits
    cout << "\n3. Using flip():" << endl;
    b2.flip(1); // Flip the 2nd bit (index 1)
    cout << "b2 after b2.flip(1): " << b2 << endl;
    b2.flip(); // Flip all bits
    cout << "b2 after b2.flip(): " << b2 << endl;

    // 4. count() - Count the number of 1s
    cout << "\n4. Using count():" << endl;
    cout << "Number of 1s in b2: " << b2.count() << endl;

    // 5. size() - Get size of the bitset
    cout << "\n5. Using size():" << endl;
    cout << "Size of b2: " << b2.size() << " bits" << endl;

    // 6. all(), any(), none() - Check bit conditions
    cout << "\n6. Using all(), any(), none():" << endl;
    cout << "b2.all(): " << b2.all() << " (true if all bits are 1)" << endl;
    cout << "b2.any(): " << b2.any() << " (true if at least one bit is 1)" << endl;
    cout << "b2.none(): " << b2.none() << " (true if all bits are 0)" << endl;

    // 7. test() - Check value of a specific bit
    cout << "\n7. Using test():" << endl;
    cout << "b2.test(3): " << b2.test(3) << " (true if bit at index 3 is 1)" << endl;

    // 8. Bitwise operations (&, |, ^)
    cout << "\n8. Using bitwise operators:" << endl;
    cout << "b1: " << b1 << endl;
    cout << "b2: " << b2 << endl;
    cout << "b1 & b2: " << (b1 & b2) << " (AND operation)" << endl;
    cout << "b1 | b2: " << (b1 | b2) << " (OR operation)" << endl;
    cout << "b1 ^ b2: " << (b1 ^ b2) << " (XOR operation)" << endl;

    // 9. Shift operations (<<, >>)
    cout << "\n9. Using shift operators:" << endl;
    cout << "b2 << 2: " << (b2 << 2) << " (Left shift by 2)" << endl;
    cout << "b2 >> 2: " << (b2 >> 2) << " (Right shift by 2)" << endl;

    // 10. Convert to string and unsigned long
    cout << "\n10. Converting to string and unsigned long:" << endl;
    cout << "b2 as string: " << b2.to_string() << endl;
    cout << "b2 as unsigned long: " << b2.to_ulong() << endl;

    // 11. Indexing to access individual bits
    cout << "\n11. Accessing bits using indexing:" << endl;
    cout << "b2[0]: " << b2[0] << " (bit at index 0)" << endl;
    cout << "b2[1]: " << b2[1] << " (bit at index 1)" << endl;


    return 0;
}