#include <stdio.h>

#define N 15
#define M 13

void make_picture(int picture_data[][M], int n, int m);
void reset_picture(int picture_data[][M], int n, int m);
void print_picture(int picture_data[][M], int n, int m);
void foliage(int picture_data[][M], int tree_foliage[]);
void trunk(int picture_data[][M], int tree_trunk[]);

int main(void) {
   int picture_data[N][M];
   make_picture(picture_data, N, M);
   print_picture(picture_data, N, M);
   return 0;
}

void make_picture(int picture_data[][M], int n, int m)
{
   int frame_w[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
   int frame_h[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
   int tree_trunk[] = { 7, 7, 7, 7 };
   int tree_foliage[] = { 3, 3, 3, 3 };
   int sun_data[6][5] = { { 0, 6, 6, 6, 6 }, 
                          { 0, 0, 6, 6, 6 }, 
                          { 0, 0, 6, 6, 6 },
                          { 0, 6, 0, 0, 6 },
                          { 0, 0, 0, 0, 0 },
                          { 0, 0, 0, 0, 0 } };
   reset_picture(picture_data, n, m);
   int length_frame_w = sizeof(frame_w) / sizeof(frame_w[0]);
   int length_frame_h = sizeof(frame_h) / sizeof(frame_h[0]);
   for (int i = 0; i < length_frame_w; i++)
   {
      picture_data[0][i] = frame_w[i];
      picture_data[7][i] = frame_w[i];
      picture_data[14][i] = frame_w[i];
   }
   for (int i = 0; i < length_frame_h; i++) {
      picture_data[i][0] = frame_h[i];
      picture_data[i][6] = frame_h[i];
      picture_data[i][12] = frame_h[i];
   }
   for (int i = 0; i < 6; i++) {
      for (int j = 0; j < 5; j++) {
         picture_data[i + 1][j + 7] = sun_data[i][j];
      }
   }
   foliage(picture_data, tree_foliage);
   trunk(picture_data, tree_trunk);
}

void reset_picture(int picture_data[][M], int n, int m)
{
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         picture_data[i][j] = 0;
      }  
   }
}

void print_picture(int picture_data[][M], int n, int m) {
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         if (j != m - 1) {
            printf("%d ", picture_data[i][j]);
         } else {
            printf("%d", picture_data[i][j]);
         }
      }
      if (i != n - 1) {
          printf("\n");
      }
   }
}

void foliage(int picture_data[][M], int tree_foliage[]) {
   for (int i = 0; i < 2; i++) {
      picture_data[2][i + 3] = tree_foliage[i];
      picture_data[5][i + 3] = tree_foliage[i];
   }
   for (int i = 0; i < 4; i++) {
      picture_data[3][i + 2] = tree_foliage[i];
      picture_data[4][i + 2] = tree_foliage[i];
   }
}

void trunk(int picture_data[][M], int tree_trunk[]) {
   for (int i = 0; i < 2; i++) {
      picture_data[6][i + 3] = tree_trunk[i];
      picture_data[8][i + 3] = tree_trunk[i];
      picture_data[9][i + 3] = tree_trunk[i];
   }
   for (int i = 0; i < 4; i++) {
      picture_data[10][i + 2] = tree_trunk[i];
   }
}