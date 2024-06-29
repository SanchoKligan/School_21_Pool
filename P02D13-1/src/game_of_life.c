#include <locale.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 82
#define HEIGHT 27

void init_field(char array[HEIGHT][WIDTH]);  // инициализация начального поля
int alive_count(char array[HEIGHT][WIDTH]);  // подсчёт количества живых клеток
int game_mode(char key, _Bool *flag, int time);  // изменение скорости игры
void next_gen(char today[HEIGHT][WIDTH], char tomorrow[HEIGHT][WIDTH]);  // расчёт следующего поколения
int neighbours_count(char array[HEIGHT][WIDTH], int a, int b);  // подсчёт количества соседей
void get_frames(char array[HEIGHT][WIDTH]);                     // отрисовка рамок
void draw_field(char array[HEIGHT][WIDTH]);                     // отрисовка поля
void init_ncurses();  // инициализация библиотеки ncurses
void change_gen(char today[HEIGHT][WIDTH], char tomorrow[HEIGHT][WIDTH]);  // смена поколения
void clear_array(char today[HEIGHT][WIDTH]);                               // очистка массива
void read_terminal(char array[HEIGHT][WIDTH]);  // чтение данных из терминала
void read_file(char array[HEIGHT][WIDTH]);      // чтение данных из файла
void cursor_move(char curs, char array[HEIGHT][WIDTH], int *x, int *y);  // перемещение курсора

int main(void) {
    setlocale(LC_ALL, "");
    char today[HEIGHT][WIDTH], tomorrow[HEIGHT][WIDTH];
    int time = 900;
    _Bool flag = 0;
    init_ncurses();
    clear_array(tomorrow);
    init_field(today);
    while (flag != 1) {
        usleep(time * 100);
        char key = getch();
        if (alive_count(today) == 0) {
            flag = 1;
        }
        time = game_mode(key, &flag, time);
        next_gen(today, tomorrow);
    }
    endwin();
    return 0;
}

void init_field(char array[HEIGHT][WIDTH]) {
    clear_array(array);
    if (!isatty(fileno(stdin))) {
        curs_set(false);
        read_file(array);
    } else {
        read_terminal(array);
    }
}

int alive_count(char array[HEIGHT][WIDTH]) {
    int count = 0;
    for (int i = 1; i < HEIGHT - 1; i++) {
        for (int j = 1; j < WIDTH - 1; j++) {
            if (array[i][j] == 'o') {
                count++;
            }
        }
    }
    return count;
}

int game_mode(char key, _Bool *flag, int time) {
    switch (key) {
        case '1':
            time = 900;
            break;
        case '2':
            time = 700;
            break;
        case '3':
            time = 500;
            break;
        case '4':
            time = 300;
            break;
        case '5':
            time = 100;
            break;
        case 'q':
            *flag = 1;
            break;
    }
    return time;
}

void next_gen(char today[HEIGHT][WIDTH], char tomorrow[HEIGHT][WIDTH]) {
    for (int i = 1; i < HEIGHT - 1; i++) {
        for (int j = 1; j < WIDTH - 1; j++) {
            int temp = neighbours_count(today, i, j);
            if (today[i][j] == ' ' &&
                temp == 493) {  // три живых соседа (3 o (код 111) и 5 пробелов (код 32))
                tomorrow[i][j] = 'o';
            }
            if (today[i][j] == 'o' && (temp == 493 || temp == 414)) {  // два или три живых соседа
                tomorrow[i][j] = 'o';
            }
            if (today[i][j] == 'o' &&
                (temp > 493 || temp < 414)) {  // меньше двух или больше трёх живых соседей
                tomorrow[i][j] = ' ';
            }
        }
    }
    get_frames(tomorrow);
    draw_field(tomorrow);
    change_gen(today, tomorrow);
    clear_array(tomorrow);
}

int neighbours_count(char array[HEIGHT][WIDTH], int a, int b) {
    int neighbours = 0;
    int a_ = a - 1, b_ = b - 1, a1 = a + 1, b1 = b + 1;
    if (a_ < 1) {
        a_ = HEIGHT - 2;
    }
    if (b_ < 1) {
        b_ = WIDTH - 2;
    }
    if (a1 > HEIGHT - 2) {
        a1 = 1;
    }
    if (b1 > WIDTH - 2) {
        b1 = 1;
    }
    neighbours += (int)array[a_][b_] + (int)array[a_][b] + (int)array[a_][b1] + (int)array[a][b1] +
                  (int)array[a1][b1] + (int)array[a1][b] + (int)array[a1][b_] + (int)array[a][b_];
    return neighbours;
}

void init_ncurses() {
    initscr();
    cbreak();
    noecho();
    curs_set(true);
    timeout(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
}

void get_frames(char array[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if ((i == 0 && j == 0) || (i == HEIGHT - 1 && j == 0) || (i == 0 && j == WIDTH - 1) ||
                (i == HEIGHT - 1 && j == WIDTH - 1)) {
                array[i][j] = '+';
            } else if ((i == 0 || i == HEIGHT - 1) && j != 0 && j != WIDTH - 1) {
                array[i][j] = '-';
            } else if ((j == 0 || j == WIDTH - 1) && (i != 0) && (i != HEIGHT - 1)) {
                array[i][j] = '|';
            }
        }
    }
}

void draw_field(char array[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            mvprintw(i, j, "%c", array[i][j]);
        }
    }
    refresh();
}

void change_gen(char today[HEIGHT][WIDTH], char tomorrow[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            today[i][j] = tomorrow[i][j];
        }
    }
}

void clear_array(char array[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            array[i][j] = ' ';
        }
    }
}

void read_file(char array[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            scanf("%c", &array[i][j]);
            if (j == WIDTH - 1) {
                getchar();
            }
        }
    }
    if (freopen("/dev/tty", "r", stdin) == NULL) {
        exit(1);
    }
    get_frames(array);
    draw_field(array);
}

void read_terminal(char array[HEIGHT][WIDTH]) {
    get_frames(array);
    draw_field(array);
    char curs = ' ';
    int x = 1, y = 1;
    move(y, x);
    while (curs != 'c') {
        curs = getch();
        cursor_move(curs, array, &x, &y);
    }
}

void cursor_move(char curs, char array[HEIGHT][WIDTH], int *x, int *y) {
    switch (curs) {
        case 'c':
            curs_set(false);
            break;
        case 'd':
            if (*x != 80) {
                move(*y, *x + 1);
                (*x)++;
            }
            break;
        case 's':
            if (*y != 25) {
                move(*y + 1, *x);
                (*y)++;
            }
            break;
        case 'w':
            if (*y != 1) {
                move(*y - 1, *x);
                (*y)--;
            }
            break;
        case 'a':
            if (*x != 1) {
                move(*y, *x - 1);
                (*x)--;
            }
            break;
        case ' ':
            if (array[*y][*x] == ' ') {
                array[*y][*x] = 'o';
            } else if (array[*y][*x] == 'o') {
                array[*y][*x] = ' ';
            }
            draw_field(array);
            move(*y, *x);
            break;
        case 'q':
            exit(0);
            break;
    }
}