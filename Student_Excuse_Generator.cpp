#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>   // FIX 1: uncommented — needed for rand() and srand()
#include <ctime>     // FIX 1: uncommented — needed for time()

using namespace std;

int main() {
    string studentName;

    cout << "========================================" << endl;
    cout << "     Student Excuse Generator v1.0      " << endl;
    cout << "========================================" << endl;
    cout << "Enter student name: ";
    cin >> studentName;

    vector<string> excuses = {
        "{name} couldn't complete the assignment because the laptop battery died unexpectedly.",
        "{name} tried finishing the homework, but the internet stopped working.",
        "{name} was ready to submit the assignment when the file mysteriously disappeared.",
        "{name} couldn't finish the assignment because the laptop decided to install updates for six hours.",
        "{name} was about to complete the homework when the Wi-Fi mysteriously disappeared.",
        "{name} tried finishing the assignment, but the computer keyboard suddenly stopped cooperating.",
        "{name} had the homework done, but the printer ran out of ink at midnight.",
        "{name} accidentally submitted the wrong file and only noticed after the deadline.",
        "{name}'s little sibling thought the assignment paper was a drawing sheet.",
        "{name} saved the assignment on a USB drive that decided to format itself.",
        "{name} stayed up all night working, but the power went out and erased everything.",
        "{name} finished the homework, but the family dog treated it as a chew toy."
    };

    srand(time(0));  // FIX 1: seeds rand() with current time — different result each run

    int index = rand() % excuses.size();
    string excuse = excuses[index];

    size_t pos = excuse.find("{name}");  // FIX 2: changed "[name]" to "{name}"
    if (pos != string::npos) {
        excuse.replace(pos, 6, studentName);
    }

    cout << "\nYour excuse: " << excuse << endl;
    cout << "\n========================================" << endl;

    return 0;
}
