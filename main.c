#include <stdio.h>

#define ROWS 20
#define COLS 40

char canvas[ROWS][COLS];

void initializeCanvas(void)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            canvas[i][j] = '_';
        }
    }
}

void displayCanvas(void)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%c ", canvas[i][j]);
        }
        printf("\n");
    }
}

void drawRectangle(int row, int col, int height, int width)
{
    int endRow = row + height;
    int endCol = col + width;

    if (row < 0) row = 0;
    if (col < 0) col = 0;
    if (endRow > ROWS) endRow = ROWS;
    if (endCol > COLS) endCol = COLS;

    for (int i = row; i < endRow; i++)
    {
        for (int j = col; j < endCol; j++)
        {
            canvas[i][j] = '*';
        }
    }
}

int main(void)
{
    int row, col, height, width;

    initializeCanvas();

    printf("Enter starting row: ");
    scanf("%d", &row);

    printf("Enter starting column: ");
    scanf("%d", &col);

    printf("Enter height of rectangle: ");
    scanf("%d", &height);

    printf("Enter width of rectangle: ");
    scanf("%d", &width);

    drawRectangle(row, col, height, width);

    printf("\nCanvas after drawing rectangle:\n\n");
    displayCanvas();

    return 0;
}