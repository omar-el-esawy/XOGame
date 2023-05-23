#include <iostream>

using namespace std;

void draw();

void re(int, char);

bool check(int);

bool winX();

bool winO();


//char c1 = '1';
//char c2 = '2';
//char c3 = '3';
//char c4 = '4';
//char c5 = '5';
//char c6 = '6';
//char c7 = '7';
//char c8 = '8';
//char c9 = '9';
char grid[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
};

void re(int i, char c) {
    i--;
    grid[i / 3][i % 3] = c;
}


void draw() {
    system("CLS");
    cout << endl;
    cout << "\t" << " " << "\t!\t" << " " << "\t!\t" << " " << endl;
    cout << "\t" << grid[0][0] << "\t!\t" << grid[0][1] << "\t!\t" << grid[0][2] << endl;
    cout << "\t" << " " << "\t!\t" << " " << "\t!\t" << " " << endl;
    cout << "   -------------------------------------------" << endl;
    cout << "\t" << " " << "\t!\t" << " " << "\t!\t" << " " << endl;
    cout << "\t" << grid[1][0] << "\t!\t" << grid[1][1] << "\t!\t" << grid[1][2] << endl;
    cout << "\t" << " " << "\t!\t" << " " << "\t!\t" << " " << endl;
    cout << "   -------------------------------------------" << endl;
    cout << "\t" << " " << "\t!\t" << " " << "\t!\t" << " " << endl;
    cout << "\t" << grid[2][0] << "\t!\t" << grid[2][1] << "\t!\t" << grid[2][2] << endl;
    cout << "\t" << " " << "\t!\t" << " " << "\t!\t" << " " << endl;
    cout << endl;
}

bool check(int input) {

    return (input > 1 and input < 9);
}

bool checkOwnership(int input) {
    input--;
    return (grid[input / 3][input % 3] != 'O') and (grid[input / 3][input % 3] != 'X');
}


bool winX() {

    bool r1 = (grid[0][0] == 'X' && grid[0][1] == 'X' && grid[0][2] == 'X');
    bool r2 = (grid[1][0] == 'X' && grid[1][1] == 'X' && grid[1][2] == 'X');
    bool r3 = (grid[2][0] == 'X' && grid[2][1] == 'X' && grid[2][2] == 'X');

    bool r4 = (grid[0][0] == 'X' && grid[1][0] == 'X' && grid[2][0] == 'X');
    bool r5 = (grid[0][1] == 'X' && grid[1][1] == 'X' && grid[2][1] == 'X');
    bool r6 = (grid[0][2] == 'X' && grid[1][2] == 'X' && grid[2][2] == 'X');

    bool r7 = (grid[0][2] == 'X' && grid[1][1] == 'X' && grid[2][0] == 'X');
    bool r8 = (grid[0][0] == 'X' && grid[1][1] == 'X' && grid[2][2] == 'X');


    if (r1 || r2 || r3 || r4 || r5 || r6 || r7 || r8) {
        cout << "X is the winner" << endl;
        return true;
    }

}


bool winO() {

    bool r1 = (grid[0][0] == 'O' && grid[0][1] == 'O' && grid[0][2] == 'O');
    bool r2 = (grid[1][0] == 'O' && grid[1][1] == 'O' && grid[1][2] == 'O');
    bool r3 = (grid[2][0] == 'O' && grid[2][1] == 'O' && grid[2][2] == 'O');

    bool r4 = (grid[0][0] == 'O' && grid[1][0] == 'O' && grid[2][0] == 'O');
    bool r5 = (grid[0][1] == 'O' && grid[1][1] == 'O' && grid[2][1] == 'O');
    bool r6 = (grid[0][2] == 'O' && grid[1][2] == 'O' && grid[2][2] == 'O');

    bool r7 = (grid[0][2] == 'O' && grid[1][1] == 'O' && grid[2][0] == 'O');
    bool r8 = (grid[0][0] == 'O' && grid[1][1] == 'O' && grid[2][2] == 'O');


    if (r1 || r2 || r3 || r4 || r5 || r6 || r7 || r8) {
        cout << "O is the winner" << endl;
        return true;
    }

}


int main() {

    draw();
    int input, counter = 0;
    char player = 'X';
    while (1) {

        cout << "\t" << player << "   It is your turn   " << endl;
        cin >> input;
        while (!check(input)) {
            cout << "the number you have entered is not available or not right " << endl;
            cout << "\t" << player << "   It is your turn   " << endl;
            cin >> input;
        }
        while (!checkOwnership(input)) {
            cin >> input;
            cout << "It owns to " << grid[(input - 1) / 3][(input - 1) % 3] << endl;
        }

        if (counter % 2 == 0) {

            re(input, player);
            counter ^= counter;
            player = 'O';
        } else {

            re(input, player);
            counter ^= counter;
            player = 'X';
        }
        draw();
        if (winX()) {
            cout << "do you want to continue the game" << endl;
            break;
        }
        if (winO()) {
            cout << "do you want to continue the game" << endl;
            break;
        }

    }


    return 0;
}
