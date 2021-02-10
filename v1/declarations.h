/* 
Actually don't know if it's wise declare all
"includes" in here but it works... at least for me.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int turn;
int checker[9];
char title[7][39];
const char PLAYER_ONE[9];
const char PLAYER_TWO[9];
char empty_board[25][39];
char session_board[25][39];
char winning_board[25][39];
char player_mark_one[5][7];
char player_mark_two[5][7];
char players_board_one[5][28];
char players_board_two[5][28];
char glory_board_one[7][34];
char glory_board_two[7][34];

int type_num                (void);
int make_int                (char digit);
_Bool is_draw               (int * checker);
_Bool is_winning            (int * checker, int turn);
_Bool is_gaming             (void);
_Bool is_rematch            (char title[][39], char session_board[][39]);

void load_title_board       (char title[][39]);
void load_player_mark       (char player_mark[][7]);
void load_glory_board       (char glory_board[][34]);
void load_empty_board       (char empty_board[][39]);
void load_players_board     (char players_board[][28]);
void load_session_board     (char session_board[][39]);
void load_winning_board     (char winning_board[][39]);
void load_marker_board      (char session_board[][39], char player_mark[][7]);

void square_one             (char session_board[][39], char player_mark[][7]);
void square_two             (char session_board[][39], char player_mark[][7]);
void square_three           (char session_board[][39], char player_mark[][7]);
void square_four            (char session_board[][39], char player_mark[][7]);
void square_five            (char session_board[][39], char player_mark[][7]);
void square_six             (char session_board[][39], char player_mark[][7]);
void square_seven           (char session_board[][39], char player_mark[][7]);
void square_eight           (char session_board[][39], char player_mark[][7]);
void square_nine            (char session_board[][39], char player_mark[][7]);

void mark_square            (int val, char session_board[][39], char player_mark[][7]);
                                                   
void set_mark               (int * checker, int turn, const char * PLAYER, char player_mark[][7], 
                             char session_board[][39], char players_board[][28]);

void clear_table            (char session_board[][39], char empty_board[ ][39], int * checker, int turn);

void declare_draw           (char title[][39], char session_board[][39]);
void celebrate_winner       (char title[][39], char winning_board[][39], char glory_board[][34], const char * LOOSER);
