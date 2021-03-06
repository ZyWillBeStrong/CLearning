#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5

struct point { int row, col;} stack[512];
int top = 0;

void push(struct point c)
{
    stack[top++] = c;
}

struct point pop(void)
{
    return stack[--top];
}

int is_empty(void)
{
    return top == 0;
}

int maze[MAX_ROW][MAX_COL] = {
    0, 1, 0, 0, 0,
    0, 1, 1, 1, 0,
    0, 0, 0, 0, 0,
    0, 1, 1, 1, 0,
    0, 0, 0, 1, 0
};

void print_maze(void)
{
    int i, j;
    for (i = 0; i < MAX_ROW; i++){
        for (j = 0; j < MAX_COL; j++)
            printf("%d ", maze[i][j]);
        putchar('\n');
    }
    printf("***********\n");
}

struct point predecessor[MAX_ROW][MAX_COL] = {
    {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
    {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
    {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
    {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
    {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
};

int visit(int row, int col, struct point pre)
{
    struct point visit_point = {row, col};
    int flag = 1;
    //maze[row][col] = 2;
    //predecessor[row][col] = pre;
    //push(visit_point);
    print_maze();
    if (visit_point.row == MAX_ROW - 1 && visit_point.col == MAX_COL - 1)
        return 0;
    if (visit_point.col + 1 < MAX_COL && maze[visit_point.row][visit_point.col + 1] == 0 && flag)
        flag = visit(visit_point.row, visit_point.col + 1, visit_point);
    if (visit_point.row + 1 < MAX_ROW && maze[visit_point.row + 1][visit_point.col] == 0 && flag)
        flag = visit(visit_point.row + 1, visit_point.col, visit_point);
    if (visit_point.col - 1 >= 0 && maze[visit_point.row][visit_point.col - 1] == 0 && flag)
        flag = visit(visit_point.row, visit_point.col - 1, visit_point);
    if (visit_point.row - 1 >= 0 && maze[visit_point.row - 1][visit_point.col] == 0 && flag)
        flag = visit(visit_point.row - 1, visit_point.col, visit_point);
}

void print_road(struct point p){
    if (predecessor[p.row][p.col].row != -1)
        print_road(predecessor[p.row][p.col]);
    printf("(%d, %d)\n", p.row, p.col);
}

int main(void)
{
    struct point p = {0, 0}, b = {-1, -1};
    int a;
    maze[p.row][p.col] = 2;

     a = visit(p.row, p.col, b);
    // if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1){
    //     print_road(p);
    // }else
    //     printf("No Path!");
    return 0;
}

// int main(void)
// {
//     struct point p = {0, 0};
//
//     maze[p.row][p.col] = 2;
//     push(p);
//
//     while (!is_empty()){
//         p = pop();
//         if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1)
//             break;
//         if (p.col + 1 < MAX_COL && maze[p.row][p.col + 1] == 0)
//             visit(p.row, p.col + 1, p);
//         if (p.row + 1 < MAX_ROW && maze[p.row + 1][p.col] == 0)
//             visit(p.row + 1, p.col, p);
//         if (p.col - 1 >= 0 && maze[p.row][p.col - 1] == 0)
//             visit(p.row, p.col - 1, p);
//         if (p.row - 1 >= 0 && maze[p.row - 1][p.col] == 0)
//             visit(p.row - 1, p.col, p);
//         print_maze();
//     }
//     if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1){
//         print_road(p);
//     }else
//         printf("No Path!");
//     return 0;
// }
