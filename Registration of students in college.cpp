/*---------------Name: Mohamed Sherif Mohamed Mohamed <--> Section: 9---------------*/
#include <iostream>
#include <string>
using namespace std;

int mainchoice;
int main()
{
    do {
        intro();
        switch (mainchoice) {
        case 0:
            break;
        case 1:
            if (x == 100) {
                cout << "Error! You exceeded the maximum number of students." << endl;
            }
            else {
                add();
                x++;
            }
            break;
        case 2:
            if (x == 0) {
                cout << "You hadn't add any student to edit." << endl;
            }
            else {
                edit();
            }
            break;
        case 3:
            if (x == 0) {
                cout << "You hadn't add any student." << endl;
            }
            else {
                summary();
            }
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (mainchoice != 0);
    return 0;
}
