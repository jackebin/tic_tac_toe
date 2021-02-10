#include "declarations.h"

// Funcs loading ... "graphics" into the game.

void load_player_mark (char player_mark[][7]) {
  int i, j;
  for(i=0; i<5; i++) {
    for(j=0; j<6; j++)
      printf("%c", player_mark[i][j]);
    printf("\n");
  }
  printf("\n");
}

void load_players_board (char players_board[][28]) {
  int i, j;
  for(i=0; i<5; i++) {
    for(j=0; j<28; j++)
      printf("%c", players_board[i][j]);
    printf("\n");
  }
}

void load_glory_board (char glory_board[][34]) {
  int i, j;
  for(i=0; i<7; i++) {
    for(j=0; j<34; j++)
      printf("%c", glory_board[i][j]);
    printf("\n");
  }
  printf("\n");
}

void load_title_board (char title[][39]) {
  int i, j;
  for(i=0; i<7; i++) {
    for(j=0; j<39; j++)
      printf("%c", title[i][j]);
    printf("\n");
  }
  printf("\t  - an unbelievable boring game\n");
  printf("\t  _____________________________\n");
}

void load_empty_board(char empty_board[][39]) {
  int i, j;
  printf("\n");
  for(i=0; i<25; i++) {
    for(j=0; j<39; j++)
      printf("%c", empty_board[i][j]);
    printf("\n");
  }
  printf("\n____________________________  \n");
}

void load_session_board (char session_board[][39]) {
  int i, j;
  printf("\n");
  for(i=0; i<25; i++) {
    for(j=0; j<39; j++)
      printf("%c", session_board[i][j]);
    printf("\n");
  }
  printf("\n");
}

void load_winning_board (char winning_board[][39]) {
  int i, j;
  printf("\n");
  for(i=0; i<25; i++) {
    for(j=0; j<39; j++)
      printf("%c", winning_board[i][j]);
    printf("\n");
  }
}

void clear_table (

  char session_board[][39], char empty_board[ ][39], 
  int * checker, int turn) {
  
  int i, j;
  
  for(i=0; i<9; i++) {
    checker[i] = -1;
  }
  turn = 0;
  printf("\n");
  for(i=0; i<25; i++) {
    for(j=0; j<39; j++)
      session_board[i][j] = empty_board[i][j];
  }
}

// Funcs altering "graphics" from inputs during runtime. 

void load_marker_board (char session_board[][39], char player_mark[][7]) {
  int i, j, x, y;
  for(i=11, x=0; i<16; i++, x++) {
    for(j=32, y=0; j<38; j++, y++)
      session_board[i][j] = player_mark[x][y];
  }
}

void square_one (char session_board[][39], char player_mark[][7]) {
  int i, j, x, y;
  for(i=2, x=0; i<7; i++, x++) {
    for(j=2, y=0; j<8; j++, y++)
      session_board[i][j] = player_mark[x][y];
  }
}

void square_two (char session_board[][39], char player_mark[][7]) {
  int i, j, x, y;
  for(i=2, x=0; i<7; i++, x++) {
    for(j=11, y=0; j<17; j++, y++)
      session_board[i][j] = player_mark[x][y];
  }
}

void square_three (char session_board[][39], char player_mark[][7]) {
  int i, j, x, y;
  for(i=2, x=0; i<7; i++, x++) {
    for(j=20, y=0; j<26; j++, y++)
      session_board[i][j] = player_mark[x][y];
  }
}

void square_four (char session_board[][39], char player_mark[][7]) {
  int i, j, x, y;
  for(i=10, x=0; i<15; i++, x++) {
    for(j=2, y=0; j<8; j++, y++)
      session_board[i][j] = player_mark[x][y];
  }
}

void square_five (char session_board[][39], char player_mark[][7]) {
  int i, j, x, y;
  for(i=10, x=0; i<15; i++, x++) {
    for(j=11, y=0; j<17; j++, y++)
      session_board[i][j] = player_mark[x][y];
  }
}

void square_six (char session_board[][39], char player_mark[][7]) {
  int i, j, x, y;
  for(i=10, x=0; i<15; i++, x++) {
    for(j=20, y=0; j<26; j++, y++)
      session_board[i][j] = player_mark[x][y];
  }
}

void square_seven (char session_board[][39], char player_mark[][7]) {
  int i, j, x, y;
  for(i=18, x=0; i<23; i++, x++) {
    for(j=2, y=0; j<8; j++, y++)
      session_board[i][j] = player_mark[x][y];
  }
}

void square_eight (char session_board[][39], char player_mark[][7]) {
  int i, j, x, y;
  for(i=18, x=0; i<23; i++, x++) {
    for(j=11, y=0; j<17; j++, y++)
      session_board[i][j] = player_mark[x][y];
  }
}

void square_nine (char session_board[][39], char player_mark[][7]) {
  int i, j, x, y;
  for(i=18, x=0; i<23; i++, x++) {
    for(j=20, y=0; j<26; j++, y++)
      session_board[i][j] = player_mark[x][y];
  }
}

/* 
From here down to the first boolean type funcs it's mostly 
attempts for handling I/O during runtime
without chrashing everything.
*/

void set_mark(

  int * checker, int turn, const char *PLAYER, 
  char player_mark[][7], char session_board[][39],
  char players_board[][28]) {
  system("clear");
  load_marker_board(session_board, player_mark); 
  load_title_board(title);
  load_session_board(session_board);
  load_players_board(players_board);
  
  int val;
  while (1) {
    val = type_num();
    if (checker[val-1] == -1) {
      checker[val-1] = turn;
      mark_square(val, session_board, player_mark);
      break;
    }
    else {
      printf("\nSquare %d already marked.\nPick another one!", val);
    }
  }  
}

void celebrate_winner (

  char title[][39], char winning_board[][39], 
  char glory_board[][34], const char * LOOSER) {
  
  system("clear");
  
  load_title_board(title);
  load_winning_board(winning_board);
  load_glory_board(glory_board);
  
  printf("\t%s was completely\n\t      HUMULIATED\n\n", LOOSER);
  printf("   <Press ENTER when done CELEBRATING>\n");
  printf("                    ");
  
  char val;
  while(1) {
    val=getchar();
    val=fgetc(stdin);

    if(val==0x0A) {
      break;
    }
  }
}

void declare_draw (char title[][39], char session_board[][39]) {
  system("clear");
  load_title_board(title);
  load_session_board(session_board);
  
  printf("\t IT'S A DRAW!\n");
  printf("   <Press ENTER to continue>\n");
  printf("               ");
  
  char val;
  while(1) {
    val=getchar();
    val=fgetc(stdin);

    if(val==0x0A) {
      break;
    }
  }
}

int type_num (void) {
  while (1) {
    char tmp[10];
    char digit;
    int rest;
    scanf("%s", tmp);
    digit = tmp[0];
    rest = make_int(digit);
    if (rest != 0) {
      return rest;
    }
    else if (rest != 1) {
      printf(
      "\nHmm.. something went wrong. Typed a digit \n"
      "and then pressed <ENTER>? Try again!\n");
    }
  }
}

int make_int(char digit) {
  int i;
  char arr[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
  for (i=0; i<9; i++) {
    if (digit == arr[i] && digit != EOF && isdigit(digit))
      return i+1;
  }
  return 0;
}

void mark_square (int val, char session_board[][39], char player_mark[][7]) {

  if (val == 1) 
    square_one   (session_board, player_mark);
  else if (val == 2) 
    square_two   (session_board, player_mark);
  else if (val == 3) 
    square_three (session_board, player_mark);
  else if (val == 4) 
    square_four  (session_board, player_mark);
  else if (val == 5) 
    square_five  (session_board, player_mark);
  else if (val == 6) 
    square_six   (session_board, player_mark);
  else if (val == 7) 
    square_seven (session_board, player_mark);
  else if (val == 8) 
    square_eight (session_board, player_mark);
  else 
    square_nine  (session_board, player_mark);
}

/* 
Bools checking if the game is on, if anyone is winning, 
if it's a draw or even worth playing a second time.
*/ 

_Bool is_gaming(void) {
  char val;
  printf("\n\t     <Press ENTER to play>");
  printf("\n\t               ");
  while(val != 0x0A) {
    if (val = fgetc(stdin) == 0x0A) {
      return 1;
    }
    else {
      return 0;
    }
  }
}

_Bool is_winning(int * checker, int turn) {
  return (turn == checker[0] && turn == checker[4] && turn == checker[8]) || 
         (turn == checker[2] && turn == checker[4] && turn == checker[6]) ||
         
         (turn == checker[0] && turn == checker[1] && turn == checker[2]) ||
         (turn == checker[3] && turn == checker[4] && turn == checker[5]) ||
         (turn == checker[6] && turn == checker[7] && turn == checker[8]) ||
         
         (turn == checker[0] && turn == checker[3] && turn == checker[6]) ||
         (turn == checker[1] && turn == checker[4] && turn == checker[7]) ||
         (turn == checker[2] && turn == checker[5] && turn == checker[8]);
}

_Bool is_draw(int * checker) {
  int marked = 0;
  for (int i=0; i<9; i++) {
    if (checker[i] != -1) {
      marked++;
    }
  }
  if (marked == 9) {
    return 1;
  }
  else {
    return 0;
  }
}

_Bool is_rematch(char title[][39], char session_board[][39]) {
  system("clear");
  load_title_board(title);
  load_session_board(session_board);
  char val;
  printf("\nRematch [Y/N]?");
  scanf("%c", &val);
  if (val == 'y' || val == 'Y') {
    return 1;
  }
  else {
    return 0;
  }
}
