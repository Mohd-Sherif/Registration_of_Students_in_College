/*---------------Name: Mohamed Sherif Mohamed Mohamed <--> Section: 9---------------*/
#include <iostream>
#include <string>
using namespace std;

struct college {
    int id,money;
    string name,subject[3];
};

void intro();
void add();
void submit(int subjectchoice, int studentindex, int subjectorder);
void edit();
void summary();

int mainchoice;
college* student = new college[100];
static int x = 0;
bool flag = false;

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

void intro() {
    cout << "             Registration of students in college             " << endl;
    cout << "      1. Add student." << endl;
    cout << "      2. Edit student." << endl;
    cout << "      3. Show all students in system." << endl;
    cout << "      0. Quit." << endl;
    cout << "      Please choose one from above choices: ";
    cin >> mainchoice;
}

void add() {
    int subjectchoice,firstchoice,secondchoice;
    cout << "             Add a new student.             " << endl;
    do {
        flag = false;
        cout << "Please enter id for a new student: ";
        cin >> student[x].id;
        for (int i = 0; i < x; i++) {
            if (student[x].id == student[i].id) {
                cout << "Error! There is a student with this id." << endl;
                flag = true;
                break;
            }
        }
    } while (flag == true);
    cout << "Please Enter student's first name: ";
    cin >> student[x].name;
    do {
        flag = false;
        cout << "Please Enter the available money: ";
        cin >> student[x].money;
        if (student[x].money < 2000) {
            cout << "Error! The available money is less than the total fees of subjects." << endl;
            flag = true;
        }
    } while (flag == true);
    cout << "The available subjects:\n" << endl;
    cout << "1) Programming languages.\tFee 1000" << endl;
    cout << "2) Technical writing.    \tFee 400" << endl;
    cout << "3) Software Engineering. \tFee 1000" << endl;
    cout << "4) Database.             \tFee 600" << endl;
    do {
        flag = false;
        cout << "Please choose first subject number to enroll in: ";
        cin >> subjectchoice;
        firstchoice = subjectchoice;
        submit(subjectchoice, x, 0);
    } while (flag == true);
    do {
        flag = false;
        cout << "Please choose second subject number to enroll in: ";
        cin >> subjectchoice;
        if (subjectchoice == firstchoice) {
            cout << "Error! You chose this subject before." << endl;
            flag=true;
        }
        else {
            secondchoice = subjectchoice;
            submit(subjectchoice, x, 1);
            if (student[x].money < 400) {
                cout << "Error! The rest money is less than the total fees of the rest subjects." << endl;
                flag = true;
                if (subjectchoice == 1 || subjectchoice == 3) {
                    student[x].money += 1000;
                }
                else if (subjectchoice == 2) {
                    student[x].money += 400;
                }
                else if (subjectchoice == 4) {
                    student[x].money += 600;
                }
            }
        }
    } while (flag == true);
    do {
        flag = false;
        cout << "Please choose third subject number to enroll in: ";
        cin >> subjectchoice;
        if (subjectchoice == firstchoice || subjectchoice == secondchoice) {
            cout << "Error! You chose this subject before." << endl;
            flag = true;
        }
        else {
            if (subjectchoice == 1 || subjectchoice == 3) {
                if (student[x].money < 1000) {
                    cout << "Error! The rest money is less than the total fees of this subject." << endl;
                    flag = true;
                }
                else {
                    submit(subjectchoice, x, 2);
                }
            }
            else if (subjectchoice == 2) {
                if (student[x].money < 400) {
                    cout << "Error! The rest money is less than the total fees of this subject." << endl;
                    flag = true;
                }
                else {
                    submit(subjectchoice, x, 2);
                }
            }
            else if (subjectchoice == 4) {
                if (student[x].money < 600) {
                    cout << "Error! The rest money is less than the total fees of this subject." << endl;
                    flag = true;
                }
                else {
                    submit(subjectchoice, x, 2);
                }
            }
            else {
                cout << "Invalid choice. Please try again." << endl;
                flag = true;
            }
        }
    } while (flag == true);
}

void submit(int subjectchoice,int studentindex,int subjectorder) {
    switch (subjectchoice) {
    case 1:
        student[studentindex].money -= 1000;
        student[studentindex].subject[subjectorder] = "Programming languages";
        break;
    case 2:
        student[studentindex].money -= 400;
        student[studentindex].subject[subjectorder] = "Technical writing";
        break;
    case 3:
        student[studentindex].money -= 1000;
        student[studentindex].subject[subjectorder] = "Software Engineering";
        break;
    case 4:
        student[studentindex].money -= 600;
        student[studentindex].subject[subjectorder] = "Database";
        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
        flag = true;
    }
}

void edit() {
    int subjectchoice, firstchoice, secondchoice, edit;
    char editchoice;
    cout << "             Edit a student.             " << endl;
    do {
        flag = false;
        cout << "Please enter id for a student to edit: ";
        cin >> edit;
        for (int i = 0; i < x; i++) {
            if (student[i].id == edit) {
                edit = i;
                flag = false;
                break;
            }
            flag = true;
        }
        if (flag == true) {
            cout << "Error! There isn't a student with this id." << endl;
        }
    } while (flag == true);
    cout << "Please Enter your student new name: ";
    cin >> student[edit].name;
    do {
        flag = false;
        cout << "Please Enter your student new available money: ";
        cin >> student[edit].money;
        if (student[edit].money < 2000) {
            cout << "Error! The available money is less than the total fees of subjects." << endl;
            flag = true;
        }
    } while (flag == true);
    cout << "The chosen subjects are: ";
    for (int i = 0; i < 2; i++) {
        cout << student[edit].subject[i] << ", ";
    }
    cout << student[edit].subject[2] << "." << endl;
    do {
        flag = false;
        cout << "Do you want to edit them Y/N: ";
        cin >> editchoice;
        switch (editchoice) {
        case 'Y':
            cout << "The available subjects:\n" << endl;
            cout << "1) Programming languages.\tFee 1000" << endl;
            cout << "2) Technical writing.    \tFee 400" << endl;
            cout << "3) Software Engineering. \tFee 1000" << endl;
            cout << "4) Database.             \tFee 600" << endl;
            do {
                flag = false;
                cout << "Please choose first subject number to enroll in: ";
                cin >> subjectchoice;
                firstchoice = subjectchoice;
                submit(subjectchoice, edit, 0);
                if (student[edit].money < 1000) {
                    cout << "Error! The rest money is less than the total fees of the rest subjects." << endl;
                    flag = true;
                    if (subjectchoice == 1 || subjectchoice == 3) {
                        student[edit].money += 1000;
                    }
                    else if (subjectchoice == 2) {
                        student[edit].money += 400;
                    }
                    else if (subjectchoice == 4) {
                        student[edit].money += 600;
                    }
                }
            } while (flag == true);
            do {
                flag = false;
                cout << "Please choose second subject number to enroll in: ";
                cin >> subjectchoice;
                if (subjectchoice == firstchoice) {
                    cout << "Error! You chose this subject before." << endl;
                    flag = true;
                }
                else {
                    secondchoice = subjectchoice;
                    submit(subjectchoice, edit, 1);
                    if (student[edit].money < 400) {
                        cout << "Error! The rest money is less than the total fees of the rest subjects." << endl;
                        flag = true;
                        if (subjectchoice == 1 || subjectchoice == 3) {
                            student[edit].money += 1000;
                        }
                        else if (subjectchoice == 2) {
                            student[edit].money += 400;
                        }
                        else if (subjectchoice == 4) {
                            student[edit].money += 600;
                        }
                    }
                }
            } while (flag == true);
            do {
                flag = false;
                cout << "Please choose third subject number to enroll in: ";
                cin >> subjectchoice;
                if (subjectchoice == firstchoice || subjectchoice == secondchoice) {
                    cout << "Error! You chose this subject before." << endl;
                    flag = true;
                }
                else {
                    if (subjectchoice == 1 || subjectchoice == 3) {
                        if (student[edit].money < 1000) {
                            cout << "Error! The rest money is less than the total fees of this subject." << endl;
                            flag = true;
                        }
                        else {
                            submit(subjectchoice, edit, 2);
                        }
                    }
                    else if (subjectchoice == 2) {
                        if (student[edit].money < 400) {
                            cout << "Error! The rest money is less than the total fees of this subject." << endl;
                            flag = true;
                        }
                        else {
                            submit(subjectchoice, edit, 2);
                        }
                    }
                    else if (subjectchoice == 4) {
                        if (student[edit].money < 600) {
                            cout << "Error! The rest money is less than the total fees of this subject." << endl;
                            flag = true;
                        }
                        else {
                            submit(subjectchoice, edit, 2);
                        }
                    }
                    else {
                        cout << "Invalid choice. Please try again." << endl;
                        flag = true;
                    }
                }
            } while (flag == true);
            break;
        case 'N':
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            flag = true;
        }
    } while (flag == true);
}

void summary() {
    cout << "             Students registered in application.             " << endl;
    cout << "Summary of students registered in system:\n" << endl;
    for (int i = 0; i < x; i++) {
        cout << student[i].id << ") Name is " << student[i].name << " and subjects enrolled in are (";
        for (int j = 0; j < 2; j++) {
            cout << student[i].subject[j] << ", ";
        }
        cout << student[i].subject[2] << ")." << endl;
    }
}
