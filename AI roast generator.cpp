#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    string name;

    // Take user input
    cout << "Enter your name: ";
    cin >> name;

    // Improved roast templates
    vector<string> roasts = {
        "{name} writes code so slow that even a loading screen gets impatient.",
        "{name}'s code has more twists than a Bollywood plot.",
        "{name} doesn’t debug code, they just hope the bug gets bored and leaves.",
        "{name}'s logic is like WiFi in a basement — weak and unreliable.",
        "{name} opens the compiler and immediately forgets what they were doing.",
        "{name}'s code works… but nobody, including {name}, knows how.",
        "{name} treats error messages like suggestions.",
        "{name}'s code is proof that Ctrl+C and Ctrl+V are powerful tools.",
        "{name} writes code like it’s a mystery novel — no one knows what’s going on.",
        "{name}'s program runs successfully… after emotional support."
    };

    // Seed random generator (FIXED BUG)
    srand(time(0));

    // Generate random index
    int index = rand() % roasts.size();
    string roast = roasts[index];

    // Replace {name} with actual name (handles multiple occurrences)
    size_t pos = roast.find("{name}");
    while (pos != string::npos) {
        roast.replace(pos, 6, name);
        pos = roast.find("{name}");
    }

    // Output final roast
    cout << roast << endl;

    return 0;
}
