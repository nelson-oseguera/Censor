#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
    // Open input and output files
    ifstream inStream;
    ofstream outStream;
    inStream.open("input.rtf");
    outStream.open("output.txt");

    // Check if file opening failed
    if (inStream.fail() || outStream.fail()) {
        cout << "File opening failed.";
        exit(1);
    }

    string line;

    // Read each line from the input file
    while (getline(inStream, line)) {
        int len = line.length();
        string word = "";

        // Iterate through each character in the line
        for (int i = 0; i < len; i++) {
            // Build the current word character by character
            if ((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z')) {
                word += line[i];
            } else {
                // Check if the current word is three letters long
                if (word.length() == 3) {
                    // Replace the word with "C++" or "c--" based on the case
                    if (isupper(word[0])) {
                        outStream << "C++";
                        cout << "C++";
                    } else {
                        outStream << "c--";
                        cout << "c--";
                    }
                } else {
                    // If the word is not three letters long, output it unchanged
                    outStream << word;
                    cout << word;
                }
                // Output the non-alphabetic character
                outStream << line[i];
                cout << line[i];
                // Reset the word to an empty string
                word = "";
            }
        }
        // Process the last word in the line
        if (word.length() == 3) {
            if (isupper(word[0])) {
                outStream << "C++";
                cout << "C++";
            } else {
                outStream << "c--";
                cout << "c--";
            }
        } else {
            outStream << word;
            cout << word;
        }
        // Output a newline at the end of each line
        outStream << endl;
        cout << endl;
    }
    // Close input and output files
    inStream.close();
    outStream.close();
    return 0;
}
