#include <iostream>
#include <stack>
#include <string>

using namespace std;

void displayState(const string& text) {
    cout << "\n--- Current Text: \"" << text << "\" ---" << endl;
    cout << "Options: [1] Type [2] Undo [3] Redo [4] Exit" << endl;
    cout << "Selection: ";
}

int main() {
    string currentText = "";
    stack<string> undoStack;
    stack<string> redoStack;
    int choice;

    while (true) {
        displayState(currentText);
        cin >> choice;

        if (choice == 1) {
            string input;
            cout << "Enter text to add: ";
            cin.ignore();
            getline(cin, input);

            undoStack.push(currentText);

            while(!redoStack.empty()) redoStack.pop();

            currentText += (currentText.empty() ? "" : " ") + input;

        } else if (choice == 2) {
            if (!undoStack.empty()) {
                redoStack.push(currentText);
                currentText = undoStack.top();
                undoStack.pop();
                cout << ">> Action Undone." << endl;
            } else {
                cout << ">> Nothing to undo!" << endl;
            }

        } else if (choice == 3) {
            if (!redoStack.empty()) {
                undoStack.push(currentText);
                currentText = redoStack.top();
                redoStack.pop();
                cout << ">> Action Redone." << endl;
            } else {
                cout << ">> Nothing to redo!" << endl;
            }

        } else if (choice == 4) {
            break;
        } else {
            cout << ">> Invalid choice." << endl;
        }
    }
    return 0;
}
