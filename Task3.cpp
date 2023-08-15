#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
using namespace std;

int player_1_scores, player_2_scores, turn;
int flags_of_player1[9], flags_of_player2[9], taken[9];
string plyr1, plyr2;
char p1, p2, p3, p4, p5, p6, p7, p8, p9;
int position;


void initialize_game() {
    int i;

    p1 = '1';
    p2 = '2';
    p3 = '3';
    p4 = '4';
    p5 = '5';
    p6 = '6';
    p7 = '7';
    p8 = '8';
    p9 = '9';

    turn = 1;

    player_1_scores = 0;
    player_2_scores = 0;

    for (i = 0; i <= 8; i++) {
        flags_of_player1[i] = 0;
        flags_of_player2[i] = 0;
        taken[i] = 0;
    }

    cout << "\n\npress any key to continue";
    cin.ignore();
    system("cls");
    cin.clear();

    cout << "enter name of player 1: ";
    getline(cin, plyr1);
    cout << "enter name of player 2: ";
    getline(cin, plyr2);

    system("cls");
}

void reset_flags_and_counters() {
    int i;

    for (i = 0; i <= 8; i++) {
        flags_of_player1[i] = 0;
        flags_of_player2[i] = 0;
        taken[i] = 0;
    }

    p1 = '1';
    p2 = '2';
    p3 = '3';
    p4 = '4';
    p5 = '5';
    p6 = '6';
    p7 = '7';
    p8 = '8';
    p9 = '9';

    turn = 1;
}

int check_position(int *ptr, int pos) {
    ptr = ptr + (pos - 1);

    if (*ptr == 1) {
        cout << "\nthis position is already taken by choose a different position: ";
        return 1;
    }

    return 0;
}

void update_flag(int *ptr, int pos) {
    ptr = ptr + (pos - 1);
    *ptr = 1;
}

void print_grid(int GameNum) {
    system("cls");

    cout << "game no: " << GameNum << "\n\n";
    cout << "    |    |    \n";
    cout << " " << p1 << "  | " << p2 << "  | " << p3 << " \n";
    cout << "----|----|----\n";
    cout << "    |    |    \n";
    cout << " " << p4 << "  | " << p5 << "  | " << p6 << " \n";
    cout << "----|----|----\n";
    cout << "    |    |    \n";
    cout << " " << p7 << "  | " << p8 << "  | " << p9 << " \n";
    cout << "    |    |    \n";
}

void check_leaderboard() {
    system("cls");
    cout << "### Welcome to the Leaderboards ###\n\n";
    cout << "------------------------------------------\n";
    cout << " ____________________________________\n";
    cout << "| Players:                  | Score: |\n";
    cout << "|___________________________|________|\n";
    cout << "|                           |        |\n";
    cout << "| Player1:                  |    " << player_1_scores << "   |\n";
    cout << "|                           |        |\n";
    cout << "|---------------------------|--------|\n";
    cout << "|                           |        |\n";
    cout << "| Player2:                  |    " << player_2_scores << "   |\n";
    cout << "|                           |        |\n";
    cout << "|___________________________|________|\n";
    cout << "\n\npress any key to continue";

    cin.ignore();
    getch();
}

void input() {
    char mark;

    if ((turn % 2) == 1) {
        //player 1 turn
        cout << plyr1 << " enter the postion you want to place the mark at:  ";

        do {
            cin >> position;

            while ((position < 1) || (position > 9)) {
                cout << "\ninvalid position enter again: ";
                cin >> position;
            }

        } while (check_position(taken, position) != 0);

        mark = 'X';

        switch (position) {
            case 1: p1 = mark; break;
            case 2: p2 = mark; break;
            case 3: p3 = mark; break;
            case 4: p4 = mark; break;
            case 5: p5 = mark; break;
            case 6: p6 = mark; break;
            case 7: p7 = mark; break;
            case 8: p8 = mark; break;
            case 9: p9 = mark; break;
        }
    } else if ((turn % 2) == 0) {
        //player 2 turn
        cout << plyr2 << " enter the postion you want to place the mark at:  ";

        do {
            cin >> position;

            while ((position < 1) || (position > 9)) {
                cout << "\ninvalid position enter again: ";
                cin >> position;
            }

        } while (check_position(taken, position) != 0);

        mark = 'O';

        switch (position) {
            case 1: p1 = mark; break;
            case 2: p2 = mark; break;
            case 3: p3 = mark; break;
            case 4: p4 = mark; break;
            case 5: p5 = mark; break;
            case 6: p6 = mark; break;
            case 7: p7 = mark; break;
            case 8: p8 = mark; break;
            case 9: p9 = mark; break;
        }
    }
}

int check_win(int *ptr) {
    if ((ptr[0] == 1) && (ptr[1] == 1) && (ptr[2] == 1)) {
        return 1;
    } else if ((ptr[3] == 1) && (ptr[4] == 1) && (ptr[5] == 1)) {
        return 1;
    } else if ((ptr[6] == 1) && (ptr[7] == 1) && (ptr[8] == 1)) {
        return 1;
    } else if ((ptr[0] == 1) && (ptr[3] == 1) && (ptr[6] == 1)) {
        return 1;
    } else if ((ptr[1] == 1) && (ptr[4] == 1) && (ptr[7] == 1)) {
        return 1;
    } else if ((ptr[2] == 1) && (ptr[5] == 1) && (ptr[8] == 1)) {
        return 1;
    } else if ((ptr[0] == 1) && (ptr[4] == 1) && (ptr[8] == 1)) {
        return 1;
    } else if ((ptr[2] == 1) && (ptr[4] == 1) && (ptr[6] == 1)) {
        return 1;
    } else {
        return 0;
    }
}

void tic_tac_toe() {
    cout << "###-----welcome to our game----###\n";
    cout << "xxx--------TIC TAC TOE---------xxx\n";
    cout << " project by: 22k-4308, 22k-4248\n";
    cout << "\n\npress any key to continue";

    cin.ignore();
    getch();
    system("cls");
}

int main() {
    int i, j, games;
    string info = "";
    int win;
    int game_no;

    game_no = 1;

    tic_tac_toe();

    initialize_game();

    do {
        system("cls");
        cout << "do you want to play\nbest of 1\nbest of 3\nbest of 5? \n";
        cin >> games;

        if ((games != 1) && (games != 3) && (games != 5)) {
            cout << "invalid number of games, kindly enter again\n";
            cout << "\n\npress any key to enter again";

            cin.ignore();
            getch();
        }

    } while ((games != 1) && (games != 3) && (games != 5));

    switch (games) {
        case 1:
            print_grid(game_no);

            for (j = 1; j <= 9; j++) {
                input();

                if ((turn % 2) == 1) {
                    update_flag(taken, position);
                    update_flag(flags_of_player1, position);
                    win = check_win(flags_of_player1);
                } else if ((turn % 2) == 0) {
                    update_flag(taken, position);
                    update_flag(flags_of_player2, position);
                    win = check_win(flags_of_player2);
                }

                print_grid(game_no);

                if (((turn % 2) == 1) && (win == 1)) {
                    cout << "\n\nCongratulations " << plyr1 << " is the winner";
                    break;
                }

                if (((turn % 2) == 0) && (win == 1)) {
                    cout << "\n\nCongratulations " << plyr2 << " is the winner";
                    break;
                }

                turn = turn + 1;
            }

            if (win == 0) {
                cout << "\n\ngame has been drawn\n\n";
            }
            break;

        case 3:
            while (game_no < 4) {
                print_grid(game_no);

                for (j = 1; j <= 9; j++) {
                    input();

                    if ((turn % 2) == 1) {
                        update_flag(taken, position);
                        update_flag(flags_of_player1, position);
                        win = check_win(flags_of_player1);
                    } else if ((turn % 2) == 0) {
                        update_flag(taken, position);
                        update_flag(flags_of_player2, position);
                        win = check_win(flags_of_player2);
                    }

                    print_grid(game_no);

                    if (((turn % 2) == 1) && (win == 1)) {
                        cout << "\n\n" << plyr1 << " has won this game\n\n";
                        player_1_scores = player_1_scores + 1;
                        cout << "\n\npress any key to continue";

                        cin.ignore();
                        getch();
                        check_leaderboard();
                        break;
                    }

                    if (((turn % 2) == 0) && (win == 1)) {
                        cout << "\n\n" << plyr2 << " has won this game\n\n";
                        player_2_scores = player_2_scores + 1;
                        cout << "\n\npress any key to continue";

                        cin.ignore();
                        getch();
                        check_leaderboard();
                        break;
                    }

                    turn = turn + 1;
                }

                if (win == 0) {
                    cout << "\n\ngame has been drawn.";
                    cout << "\n\npress any key to continue";

                    cin.ignore();
                    getch();
                    check_leaderboard();
                }

                if (player_1_scores == 2) {
                    break;
                }

                if (player_2_scores == 2) {
                    break;
                }

                reset_flags_and_counters();
                game_no = game_no + 1;
            }

            if (player_1_scores == 2) {
                cout << "\n\nCongratulations " << plyr1 << " is the overall winner";
            } else if (player_2_scores == 2) {
                cout << "\n\nCongratulations " << plyr2 << " is the overall winner";
            }

            if ((game_no == 4) && (player_1_scores == player_2_scores)) {
                cout << "\n\nno overall winner";
            } else if ((game_no == 4) && (player_1_scores > player_2_scores)) {
                cout << "\n\nCongratulations " << plyr1 << " is the overall winner";
            } else if ((game_no == 4) && (player_2_scores > player_1_scores)) {
                cout << "\n\nCongratulations " << plyr2 << " is the overall winner";
            }

            
            break;

        case 5:
            while (game_no < 6) {
                print_grid(game_no);

                for (j = 1; j <= 9; j++) {
                    input();

                    if ((turn % 2) == 1) {
                        update_flag(taken, position);
                        update_flag(flags_of_player1, position);
                        win = check_win(flags_of_player1);
                    } else if ((turn % 2) == 0) {
                        update_flag(taken, position);
                        update_flag(flags_of_player2, position);
                        win = check_win(flags_of_player2);
                    }

                    print_grid(game_no);

                    if (((turn % 2) == 1) && (win == 1)) {
                        cout << "\n\n" << plyr1 << " has won this game\n\n";
                        player_1_scores = player_1_scores + 1;
                        cout << "\n\npress any key to continue";

                        cin.ignore();
                        getch();
                        check_leaderboard();
                        break;
                    }

                    if (((turn % 2) == 0) && (win == 1)) {
                        cout << "\n\n" << plyr2 << " has won this game\n\n";
                        player_2_scores = player_2_scores + 1;
                        cout << "\n\npress any key to continue";

                        cin.ignore();
                        getch();
                        check_leaderboard();
                        break;
                    }

                    turn = turn + 1;
                }

                if (win == 0) {
                    cout << "\n\ngame has been drawn.";
                    cout << "\n\npress any key to continue";

                    cin.ignore();
                    getch();
                    check_leaderboard();
                }

                if (player_1_scores == 3) {
                    break;
                }

                if (player_2_scores == 3) {
                    break;
                }

                reset_flags_and_counters();
                game_no = game_no + 1;
            }

            if (player_1_scores == 3) {
                cout << "\n\nCongratulations " << plyr1 << " is the overall winner";
            } else if (player_2_scores == 3) {
                cout << "\n\nCongratulations " << plyr2 << " is the overall winner";
            }

            if ((game_no == 6) && (player_1_scores == player_2_scores)) {
                cout << "\n\nno overall winner";
            } else if ((game_no == 6) && (player_1_scores > player_2_scores)) {
                cout << "\n\nCongratulations " << plyr1 << " is the overall winner";
            } else if ((game_no == 6) && (player_2_scores > player_1_scores)) {
                cout << "\n\nCongratulations " << plyr2 << " is the overall winner";
            }

            break;
    }

    return 0;
}
