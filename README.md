# Text-History-Undo-Redo-Management-System

## Project Title
RETRAC: Text History & Undo/Redo Management System
## Research Problem
In digital text editing, users frequently make mistakes or want to compare previous versions of their work. Without a structured way to track "state," a single mistake could result in permanent data loss. Implementing this requires a way to handle history linearly where the most recent action is always the first one to be reverted.
## Motivation
This project demonstrates the practical application of the Last-In, First-Out (LIFO) principle found in Stacks. By simulating the "Undo" and "Redo" features of professional software like VS Code or Word, it shows how complex historical navigation can be simplified into two stacks, ensuring high speed and low memory overhead for version tracking. [1] 
## Control Flow

   1. Launch: The application opens to a blank "Current Text" state with two empty stacks (Undo and Redo).
   2. Type (Action): The user enters new text. The app pushes the current version to the Undo Stack, clears the Redo Stack, and updates the text.
   3. Undo Selection: If the user triggers "Undo," the current state is pushed to the Redo Stack, and the top of the Undo Stack is popped to become the current text.
   4. Redo Selection: If the user triggers "Redo," the current state is pushed back to the Undo Stack, and the most recently "undone" action is popped from the Redo Stack.
   5. Validation: The system checks if stacks are empty before popping to prevent "Stack Underflow" errors. [2, 3, 4, 5, 6] 

## Implementation Strategy

* Tech Stack: Developed in C++ using the Standard Template Library (STL).
* Data Structures:
* Double Stack Architecture: Uses two std::stack<string> objects to manage the "Past" and "Future" timelines of the text.
* Data Models: Operates primarily on std::string objects, treating each entry or historical state as a unique string snapshot.
* State Management: The main loop acts as the state controller, ensuring that whenever a new action occurs, the "Redo" history is wiped to maintain a consistent linear timeline (standard behavior in professional editors).
* Efficiency: Because stacks only allow access to the top element, operations like Undo and Redo are performed in O(1) time, making the response instantaneous regardless of history size. [7, 8] 

