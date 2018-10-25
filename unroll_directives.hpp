#ifndef UNROLL_DIRECTIVES_H
#define UNROLL_DIRECTIVES_H

#define __INNER_UNROLL(plane, row, col, i, j) { \
  output -> color[plane][row][col] += (input -> color[plane][row + i - 1][col + j - 1] * filter -> data[i *3 + j]); \
};

#define __UPDATE_COLORS(plane, row, col) { \
  __INNER_UNROLL(plane, row, col, 0, 0); \
  __INNER_UNROLL(plane, row, col, 0, 1); \
  __INNER_UNROLL(plane, row, col, 0, 2); \
  __INNER_UNROLL(plane, row, col, 1, 0); \
  __INNER_UNROLL(plane, row, col, 1, 1); \
  __INNER_UNROLL(plane, row, col, 1, 2); \
  __INNER_UNROLL(plane, row, col, 2, 0); \
  __INNER_UNROLL(plane, row, col, 2, 1); \
  __INNER_UNROLL(plane, row, col, 2, 2); \
};


#define PLANE_LOOP_TEMPLATE(plane) { \
  output -> color[plane][row][col] = 0; \
  __UPDATE_COLORS(plane, row, col); \
  output -> color[plane][row][col] = (int) (output -> color[plane][row][col] * invDivisor); \
  if ( output -> color[plane][row][col]  < 0 ) { \
    output -> color[plane][row][col] = 0; \
  } \
  if ( output -> color[plane][row][col]  > 255 ) { \
    output -> color[plane][row][col] = 255; \
  } \
};

#endif
