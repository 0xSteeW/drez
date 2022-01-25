#ifndef BOARD_H
#define BOARD_H

#define FLAG_PIN       0x1 /* block piece when it would discover a check */
#define FLAG_CHECK     0x2 /* block moves when king is in check (additional checking
							  should be done for moves preventing check) */
#define FLAG_FIRSTMOVE 0x4 /* for castles and pawn starts */

#include "piece.h"
#include <stdint.h>
#define SIZE_STD 8

enum FILE_NUMS { a = 0, b = 1, c = 2, d = 3, e = 4, f = 5, g = 6, h = 7 };
typedef enum { BLACK, WHITE, NONE } SIDE;
typedef enum {
  NORMAL,
  SKIP
} MOVE_KIND; /* signals whether a piece (namely the knight) can ignore other
                                            pieces in its path */
typedef struct {
  piece *piece;
  SIDE side;
  uint8_t flags;
} moveable;

typedef struct {
  piece *rook;
  piece *bishop;
  piece *knight;
  piece *queen;
  piece *pawn;
  piece *king;
  int size_x; 
  int size_y; 
  /* TODO: piece location hash table */
  /*            rank      file     */
  moveable game[SIZE_STD][SIZE_STD];
} board;

board *init_board();
void free_board(board *game);
char *key_from_coords(position pos);
int move(position origin, position target, board *game);
#endif