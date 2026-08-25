#include <stdio.h>
int verify_horizontal_vertical(int[][9]);
int verify_tre_per_tre(int[][9]);

int main()
{
    int n;
    scanf("%d", &n);
    int sudokus[9][9], certin[n];
    for (int num_sudokus = 0; num_sudokus < n; num_sudokus++)
    {
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                scanf("%d", &sudokus[row][col]);
            }
        }
        certin[num_sudokus] = verify_horizontal_vertical(sudokus) && verify_tre_per_tre(sudokus);
    }
    for (int num_sudokus = 0; num_sudokus < n; num_sudokus++)
    {
        printf("Instancia %d\n", num_sudokus + 1);
        if (certin[num_sudokus] == 1)
        {
            printf("SIM\n");
        }
        else
        {
            printf("NAO\n");
        }
        printf("\n");
    }
}

int verify_horizontal_vertical(int sudokus[][9])
{
    for (int row = 0; row < 9; row++)
    {
        int seen_row[10] = {0};
        int seen_col[10] = {0};
        for (int col = 0; col < 9; col++)
        {
            int value_row = sudokus[row][col];
            int value_col = sudokus[col][row];
            if (seen_row[value_row] == 1)
            {
                return 0;
            }
            if (seen_col[value_col] == 1)
            {
                return 0;
            }
            seen_row[value_row] = 1;
            seen_col[value_col] = 1;
        }
    }
    return 1;
}

int verify_tre_per_tre(int sudokus[][9])
{
    int seen[10] = {0}, value;
    for (int row = 0; row < 9; row += 3)
    {
        for (int col = 0; col < 9; col += 3)
        {
            int seen[10] = {0};
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    value = sudokus[row + i][col + j];
                    if (seen[value] == 1)
                    {
                        return 0;
                    }
                    seen[value] = 1;
                }
            }
        }
    }
    return 1;
}