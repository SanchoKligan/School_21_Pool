#include <locale.h>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

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
void init(void);  // функция для инициализации библиотеки ncurses

int main(void) {
    setlocale(LC_ALL, "");
    init();
    int width = 82, height = 27, ball_y = 13, ball_x = 41, left_rocket = 12, right_rocket = 12,
        change_y = rand() % 2 * 2 - 1, change_x = rand() % 2 * 2 - 1, point_for_left = 0, point_for_right = 0;
    char key = ' ';
    bread(point_for_left, point_for_right, height, width, left_rocket, right_rocket, ball_x, ball_y);
    while (point_for_left < 21 && point_for_right < 21 && key != 'q') {
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
        key = getch();
        switch (key) {
            case 'a':
                left_rocket = rocket_coords(left_rocket, 1);
                break;
            case 'z':
                left_rocket = rocket_coords(left_rocket, 0);
                break;
            case 'k':
                right_rocket = rocket_coords(right_rocket, 1);
                break;
            case 'm':
                right_rocket = rocket_coords(right_rocket, 0);
                break;
        }
        ball_x += change_x;
        ball_y += change_y;
        bread(point_for_left, point_for_right, height, width, left_rocket, right_rocket, ball_x, ball_y);
        usleep(50000);
    }
    congrats(point_for_left, point_for_right);
    refresh();
    usleep(1500000);
    endwin();
    return 0;
}

int rocket_coords(int rocket, _Bool direct) {
    if (direct && rocket != 2) {
        rocket--;
    } else if (!direct && rocket != 24) {
        rocket++;
    }
    return rocket;
}

void field(int height, int width, int left_rocket, int right_rocket, int ball_x, int ball_y) {
    for (int i = 1; i <= height; i++) {
        for (int j = 0; j < width; j++) {
            if ((i == 1 && j == 0) || (i == height && j == 0)) {
                mvprintw(i, j, "+");
            } else if ((i == 1 && j == width - 1) || (i == height && j == width - 1)) {
                mvprintw(i, j, "+\n");
            } else if ((i == 1 || i == height) && j != 0 && j != width - 1) {
                mvprintw(i, j, "-");
            } else if (i == ball_y && j == ball_x) {
                mvprintw(i, j, "o");
            } else if ((j == 0 || j == width - 1 || j == width / 2 ||
                        ((j == 4 && i >= left_rocket && i <= left_rocket + 2) ||
                         (j == width - 5 && i >= right_rocket && i <= right_rocket + 2))) &&
                       (i != 1) && (i != height)) {
                mvprintw(i, j, "|");
            } else {
                mvprintw(i, j, " ");
            }
        }
    }
}

void congrats(int point_for_left, int point_for_right) {
    if (point_for_left == 21) {
        mvprintw(0, 30, "Поздравляем игрока слева!");
    } else if (point_for_right == 21) {
        mvprintw(0, 29, "Поздравляем игрока справа!");
    } else {
        mvprintw(0, 35, "Игра завершена!");
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
    if (ball_x == 1 || ball_x == width - 2) change_x = rand() % 2 * 2 - 1;
    return change_x;
}
int change_ydir(int ball_y, int ball_x, int change_y, int height, int width) {
    if (ball_y == 2 || ball_y == height - 1) {
        change_y *= -1;
    }
    if (ball_x == 1 || ball_x == width - 2) change_y = rand() % 2 * 2 - 1;
    return change_y;
}

void bread(int point_for_left, int point_for_right, int height, int width, int left_rocket, int right_rocket,
           int ball_x, int ball_y) {
    mvprintw(0, 0, "%22d%41d", point_for_left, point_for_right);
    field(height, width, left_rocket, right_rocket, ball_x, ball_y);
    refresh();
}

void init(void) {
    srand(time(NULL));
    initscr();
    cbreak();
    noecho();
    curs_set(FALSE);
    timeout(0);
    keypad(stdscr, TRUE);
}