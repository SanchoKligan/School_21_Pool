#include <stdio.h>

void field(int height, int width, int left_rocket, int right_rocket, int ball_x,
           int ball_y);                       // функция отрисовки игрового поля
int rocket_coords(int rocket, _Bool direct);  // функция движения ракеток
void congrats(int point_for_left, int point_for_right);  // функция для вывода текста после завершения игры
int change_xdir(int ball_y, int ball_x, int left_rocket, int right_rocket, int width,
                int change_x);  // функция для смены х-координаты шарика
int change_ydir(int ball_y, int ball_x, int change_y, int height,
                int width);  // функция для смены y-координаты шарика
void bread(int point_for_left, int point_for_right, int height, int width, int left_rocket, int right_rocket,
           int ball_x, int ball_y);  // функция для перерисовки консольного вывода

int main(void) {
    int width = 82, height = 27, point_for_right = 0, point_for_left = 0, change_y = -1, change_x = 1,
        left_rocket = 12, right_rocket = 12, ball_y = 13, ball_x = 41;
    char key = ' ';
    bread(point_for_left, point_for_right, height, width, left_rocket, right_rocket, ball_x, ball_y);
    while (point_for_left < 21 && point_for_right < 21 && key != 'q') {
        key = getchar();
        if (key != '\n') {
            change_y = change_ydir(ball_y, ball_x, change_y, height, width);
            change_x = change_xdir(ball_y, ball_x, left_rocket, right_rocket, width, change_x);
            if (ball_x == 1) {
                point_for_right++;
                ball_y = 13;
                ball_x = 41;
            }
            if (ball_x == width - 2) {
                point_for_left++;
                ball_y = 13;
                ball_x = 41;
            }
        }
        switch (key) {
            case 'a':
                left_rocket = rocket_coords(left_rocket, 1);
                ball_y += change_y;
                ball_x += change_x;
                break;
            case 'z':
                left_rocket = rocket_coords(left_rocket, 0);
                ball_y += change_y;
                ball_x += change_x;
                break;
            case 'k':
                right_rocket = rocket_coords(right_rocket, 1);
                ball_y += change_y;
                ball_x += change_x;
                break;
            case 'm':
                right_rocket = rocket_coords(right_rocket, 0);
                ball_y += change_y;
                ball_x += change_x;
                break;
            case ' ':
                ball_y += change_y;
                ball_x += change_x;
                break;
        }
        bread(point_for_left, point_for_right, height, width, left_rocket, right_rocket, ball_x, ball_y);
    }
    congrats(point_for_left, point_for_right);
    return 0;
}

int rocket_coords(int rocket, _Bool direct) {
    if (direct && rocket != 1) {
        rocket--;
    } else if (!direct && rocket != 23) {
        rocket++;
    }
    return rocket;
}

void field(int height, int width, int left_rocket, int right_rocket, int ball_x, int ball_y) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if ((i == 0 && j == 0) || (i == height - 1 && j == 0)) {
                printf("+");
            } else if ((i == 0 && j == width - 1) || (i == height - 1 && j == width - 1)) {
                printf("+\n");
            } else if ((i == 0 || i == height - 1) && j != 0 && j != width - 1) {
                printf("-");
            } else if (i == ball_y && j == ball_x) {
                printf("o");
            } else if ((j == 0 || j == width - 1 || j == width / 2 ||
                        ((j == 4 && i >= left_rocket && i <= left_rocket + 2) ||
                         (j == width - 5 && i >= right_rocket && i <= right_rocket + 2))) &&
                       (i != 0) && (i != height - 1)) {
                printf("|");
                if (j == width - 1) {
                    printf("\n");
                }
            } else {
                printf(" ");
            }
        }
    }
}

int change_xdir(int ball_y, int ball_x, int left_rocket, int right_rocket, int width, int change_x) {
    if (((ball_y == left_rocket || ball_y == left_rocket + 1 || ball_y == left_rocket + 2 ||
          ball_y == left_rocket + 3 || ball_y == left_rocket - 1) &&
         ball_x == 5) ||
        ((ball_y == right_rocket || ball_y == right_rocket + 1 || ball_y == right_rocket + 2 ||
          ball_y == right_rocket + 3 || ball_y == right_rocket - 1) &&
         ball_x == width - 6)) {
        change_x *= -1;
    }
    if (ball_x == 1) change_x = -1;
    if (ball_x == width - 2) change_x = 1;
    return change_x;
}
int change_ydir(int ball_y, int ball_x, int change_y, int height, int width) {
    if (ball_y == 1 || ball_y == height - 2) {
        change_y *= -1;
    }
    if (ball_x == 1) change_y = 1;
    if (ball_x == width - 2) change_y = -1;
    return change_y;
}

void congrats(int point_for_left, int point_for_right) {
    if (point_for_left == 21) {
        printf("Поздравляем игрока слева!\n");
    } else if (point_for_right == 21) {
        printf("Поздравляем игрока справа!\n");
    } else {
        printf("Игра завершена!\n");
    }
}

void bread(int point_for_left, int point_for_right, int height, int width, int left_rocket, int right_rocket,
           int ball_x, int ball_y) {
    printf("\033[0d\033[2J");
    printf("%22d%41d\n", point_for_left, point_for_right);
    field(height, width, left_rocket, right_rocket, ball_x, ball_y);
}