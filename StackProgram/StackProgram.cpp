//This Program is used for of A Stack Implementation  by Entering Values 
#include <iostream>

using namespace std;

int choice, value;
int flag = 0, stack_data[100], n = 10, top = -1;

int main() {
    // Display the menu and get a choice.
    do {
        cout << "---------MENU----------" << endl;
        cout << "1: Create a new stack" << endl;
        cout << "2: Push a value" << endl;
        cout << "3: Pop the value" << endl;
        cout << "4: Display the top value" << endl;
        cout << "5: Purge the stack" << endl;
        cout << "6: Display the whole stack" << endl;
        cout << "0: Exit the program" << endl;

     // Get Selection.
        cout << "----------------------" << endl;
        cout << "" << endl;
        cout << "Enter Selection: ";
        cin >> choice;


        switch (choice) {
            //CASE 1 is to Create a New Stack
        case 1:

            flag = 1;
            cout << "stack is created" << endl;
            break;


            //CASE 2 is to Push Element to Stack
        case 2:

            if (flag == 1) {
                cout << "Enter value between 0-10 to be pushed:" << endl;
                cin >> value;
                if (top >= n - 1)
                    cout << "Stack Overflow" << endl;
                else {
                    top++;
                    stack_data[top] = value;
                }
            }
            else {
                cout << "Stack is not created" << endl;
            }
            break;


            //CASE 3 is to Pop Element on Stack
        case 3:

            if (flag == 1) {
                if (top <= -1)
                    cout << "Stack Underflow" << endl;
                else {
                    cout << "The popped element is " << stack_data[top] << endl;
                    top--;
                }
            }
            else {
                cout << "Stack is not created" << endl;
            }
            break;


            //CASE 4 to Show Top Element on Stack
        case 4:

            if (flag == 1) {
                if (top <= -1)
                    cout << "Stack Underflow" << endl;
                else {
                    cout << "The top element is " << stack_data[top] << endl;
                }
            }
            else {
                cout << "Stack is not created" << endl;
            }
            break;


            //CASE 5 is to Purge the Stack
        case 5:

            while (top > -1) {
                stack_data[top] = 0;
                top--;
            }
            flag = 0;
            cout << "stack is purged" << endl;
            break;


            //CASE 6 is to Display Whole Stack
        case 6:

            if (flag == 1) {
                if (top >= 0) {
                    cout << "Stack elements are:" << endl;

                    for (int i = top; i >= 0; i--) {
                        cout << stack_data[i] << " ";
                    }
                    cout << endl;
                }
                else
                    cout << "Stack is empty" << endl;
            }
            else {
                cout << "stack is not created" << endl;
            }
            break;


            //To Exit from Program
        case 0:

            cout << "exit" << endl;
            break;

        default: {
            cout << "You need to make another choice!" << endl;
        }


        }


    } while (choice != 0);
    return 0;
}
