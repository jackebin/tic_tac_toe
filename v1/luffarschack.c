#include "declarations.h"

// A web of amateurish pride doing its magic.

int main() {

  system("clear");
  load_title_board(title);
  
  while (is_gaming()) {
    
    while (!is_winning(checker, turn) || !is_draw(checker)) {
      if (turn == 0) {
        if (is_draw(checker)) {	
          declare_draw(title, session_board);
          break;
        }
        set_mark(
        checker, turn, PLAYER_ONE, 
        player_mark_one, session_board, players_board_one);
        
        if (is_winning(checker, turn)) {
          celebrate_winner(title, winning_board, glory_board_one, PLAYER_TWO);
          break;
        }
      turn = 1;  
      }
      if (turn == 1) {
        if (is_draw(checker)) {
          declare_draw(title, session_board);
          break;
        }
        set_mark(
        checker, turn, PLAYER_TWO, 
        player_mark_two, session_board, players_board_two);
      
        if (is_winning(checker, turn)) { 
          celebrate_winner(title, winning_board, glory_board_two, PLAYER_ONE);
          break;
        }
      turn = 0;
      }
    }
    if (is_rematch(title, session_board)) {
      clear_table(session_board, empty_board, checker, turn);
    }
    else {
      system("clear");
      load_title_board(title);
      break;
    }
  }
  return 0;
}
