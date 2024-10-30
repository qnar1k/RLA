#include <iostream>
#include <string>

using namespace std;

string runLengthEncoding(const string& input) {
    string encoded = "";
    int n = input.length();

    for (int i = 0; i < n; i++) {
        int count = 1;
        while (i < n - 1 && input[i] == input[i + 1]) {
            count++;
            i++;
        }
        encoded += input[i];

        // Manually convert count to string and append
        if (count >= 10) {
            // For counts >= 10
            encoded += (count / 10) + '0'; // Tens place
            encoded += (count % 10) + '0'; // Ones place
        }
        else {
            // For counts < 10
            encoded += count + '0';
        }
    }

    return encoded;
}
string runLengthDecoding(const string& encoded) {
    string decoded = "";
    int n = encoded.length();

    for (int i = 0; i < n; i++) {
        char currentChar = encoded[i];
        i++;

        // Get the count directly from encoded string
        int count = 0;
        while (i < n && isdigit(encoded[i])) {
            count = count * 10 + (encoded[i] - '0'); // Build the count number
            i++;
        }
        i--; // Adjust index after the loop

        for (int j = 0; j < count; j++) {
            decoded += currentChar;
        }
    }

    return decoded;
}
int main() {
    string input;
    cout << "Enter: " << endl;
    getline(cin, input);


    string encoded = runLengthEncoding(input);
    cout << "Encoded string: " << encoded << endl; // Expected: a10b11

    string decoded = runLengthDecoding(encoded);
    cout << "Decoded string: " << decoded << endl; // Expected: aaaaaaaaaabbbbbbbbbbb

    return 0;
}
