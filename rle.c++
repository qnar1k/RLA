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

        if (count >= 10) {
            encoded += (count / 10) + '0';
            encoded += (count % 10) + '0';
        }
        else {
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
        int count = 0;
        while (i < n && isdigit(encoded[i])) {
            count = count * 10 + (encoded[i] - '0');
            i++;
        }
        i--;
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
    cout << "Encoded string: " << encoded << endl;

    string decoded = runLengthDecoding(encoded);
    cout << "Decoded string: " << decoded << endl;

    return 0;
}
