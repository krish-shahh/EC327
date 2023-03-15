#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " input_file" << endl;
        return 1;
    }

    ifstream input_file(argv[1]);

    if (!input_file) {
        cout << "Unable to open input file: " << argv[1] << endl;
        return 1;
    }

    map<string, int> frequency_table;

    char c;
    char last_c = '\0';
    while (input_file.get(c)) {
        if (isalpha(c)) {
            c = toupper(c);
            if (last_c != '\0') {
                string sequence;
                sequence += last_c;
                sequence += c;
                frequency_table[sequence]++;
            }
            last_c = c;
        } else {
            last_c = '\0';
        }
    }

    cout << "Two-Letter Sequence Frequency Table:" << endl;
    cout << "-----------------------------------" << endl;
    cout << "Sequence\tFrequency" << endl;
    cout << "-----------------------------------" << endl;

    int total_sequences = 0;
    for (auto iter = frequency_table.begin(); iter != frequency_table.end(); iter++) {
        cout << iter->first << "\t" << iter->second << endl;
        total_sequences += iter->second;
    }

    cout << "-----------------------------------" << endl;
    cout << "Total\t" << total_sequences << endl;

    return 0;
}
