#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int solve_sudoku(int sudoku[9][9]);
void print_puzzle(int printable1[3][3], int printable2[3][3], int printable3[3][3], int intial1[3][3], int intial2[3][3], int intial3[3][3]);
void rand_modif(int arr[3][3], int arr1[3][3], int arr2[3][3], int arc1[3][3], int arc2[3][3]);
void step_checker(int arr[3][3], int arr1[3][3], int arr2[3][3], int arc1[3][3], int arc2[3][3], int* check);
void print_puzzle(int printable1[3][3], int printable2[3][3], int printable3[3][3], int intial1[3][3], int intial2[3][3], int intial3[3][3]);

void rand_modif_box(int arr[3][3])
{
	int i, j, k=0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (arr[i][j] > 0)
				k++;
			if (k > 3)
				arr[i][j] = 0;
		}

	}

}

void print_init_puzzle(int printable1[3][3], int printable2[3][3], int printable3[3][3])
{
	int r, c, counter = 0;
	for (r = 0; r < 3; r++)
	{
		
		if (counter == 0)
		{
			printf("\t");
			printf("-------------------------");
			printf("\n");
		}
		printf("       %d: ", r + 1);
		

		for (c = 0; c < 3; c++)
			if (printable1[r][c] > 0)
				printf("%d ", printable1[r][c]);	
			else
				printf(". ");
		printf(": ");

		for (c = 0; c < 3; c++)
			if (printable2[r][c] > 0)
			{
				printf("%d ", printable2[r][c]);
			}
			else
				printf(". ");

		printf(": ");

		for (c = 0; c < 3; c++)
			if (printable3[r][c] > 0)
			{
				printf("%d ", printable3[r][c]);
			}
			else
				printf(". ");

		printf(":");
		printf("\n");
		counter++;
	}

}

void play_input(int puzzle[3][3],int puzzle_i[3][3],int arr1[3][3], int arr2[3][3], int arr3[3][3], int arr4[3][3], int arr5[3][3], int arr6[3][3], int arr7[3][3], int arr8[3][3], int arr9[3][3],
	int arr1_i[3][3], int arr2_i[3][3], int arr3_i[3][3], int arr4_i[3][3], int arr5_i[3][3], int arr6_i[3][3], int arr7_i[3][3], int arr8_i[3][3], int arr9_i[3][3])
{
	int i, r, c, N;

	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		printf("\nEnter the row and column of the element you would like to enter(numbers between 1 and 3):\n");
		scanf("%d%d", &r, &c);
		if (r <= 3 && c <= 3)
		{
			if (puzzle_i[r - 1][c - 1] == 0)
			{
				printf("Enter the element (%d,%d)\n", r, c);
				scanf("%d", &puzzle[r - 1][c - 1]);
				system("cls");

				printf("\nThe puzzle so far... :\n");
				printf("\t  1 2 3   1 2 3   1 2 3\n");
				print_puzzle(arr1, arr2, arr3, arr1_i, arr2_i, arr3_i); print_puzzle(arr4, arr5, arr6, arr4_i, arr5_i, arr6_i); print_puzzle(arr7, arr8, arr9, arr7_i, arr8_i, arr9_i);
				printf("\t-------------------------");
			}
			else
			{
				system("cls");
				printf("This element (%d,%d) is already in the puzzle,try another slot.",r,c);
				printf("\nThe puzzle so far... :\n");
				printf("\t  1 2 3   1 2 3   1 2 3\n");
				print_puzzle(arr1, arr2, arr3, arr1_i, arr2_i, arr3_i); print_puzzle(arr4, arr5, arr6, arr4_i, arr5_i, arr6_i); print_puzzle(arr7, arr8, arr9, arr7_i, arr8_i, arr9_i);
				printf("\t-------------------------");
			}
			
		}
		else
		{
			system("cls");
			printf("\nIncorrect input,please enter numbers between 1 and 3.\n");
			printf("\nThe puzzle so far... :\n");
			printf("\t  1 2 3   1 2 3   1 2 3\n");
			print_puzzle(arr1, arr2, arr3, arr1_i, arr2_i, arr3_i); print_puzzle(arr4, arr5, arr6, arr4_i, arr5_i, arr6_i); print_puzzle(arr7, arr8, arr9, arr7_i, arr8_i, arr9_i);
			printf("\t-------------------------");
		}
	}

}

void equating_zero(int arr[3][3])
{
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			arr[i][j]=0;
}

void sudoku_reverse(int sudoku[9][9],int box1[3][3], int box2[3][3], int box3[3][3], int box4[3][3], int box5[3][3], int box6[3][3], int box7[3][3], int box8[3][3], int box9[3][3])
{
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			box1[i][j] = sudoku[i][j];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			box2[i][j] = sudoku[i][j + 3];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			box3[i][j] = sudoku[i][j + 6];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			box4[i][j] = sudoku[i + 3][j];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			box5[i][j] = sudoku[i + 3][j + 3];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			box6[i][j] = sudoku[i + 3][j + 6];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			box7[i][j] = sudoku[i + 6][j];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			box8[i][j] = sudoku[i + 6][j + 3];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			box9[i][j] = sudoku[i + 6][j + 6];
}

void sudoku_init(int sudoku[9][9], int arr1[3][3], int arr2[3][3], int arr3[3][3], int arr4[3][3], int arr5[3][3], int arr6[3][3], int arr7[3][3], int arr8[3][3], int arr9[3][3])
{
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			sudoku[i][j] = arr1[i][j];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			sudoku[i][j + 3] = arr2[i][j];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			sudoku[i][j + 6] = arr3[i][j];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			sudoku[i + 3][j] = arr4[i][j];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			sudoku[i + 3][j + 3] = arr5[i][j];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			sudoku[i + 3][j + 6] = arr6[i][j];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			sudoku[i + 6][j] = arr7[i][j];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			sudoku[i + 6][j + 3] = arr8[i][j];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			sudoku[i + 6][j + 6] = arr9[i][j];
}

void equating_matricies(int arr_i[3][3], int arr[3][3])
{
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			arr_i[i][j] = arr[i][j];
}

int random(int sudoku[9][9], int arr1[3][3], int arr2[3][3], int arr3[3][3], int arr4[3][3], int arr5[3][3], int arr6[3][3], int arr7[3][3], int arr8[3][3], int arr9[3][3])
{
	int i, j,m,n,sudoku_i[9][9],z=0;
	srand(time(0));
	
	do {
		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
			{
				sudoku[i][j] = (rand() % 9);
			}
		}


		sudoku_reverse(sudoku, arr1, arr2, arr3, arr4, arr5, arr6, arr7, arr8, arr9);


		rand_modif(arr1, arr2, arr3, arr4, arr7); rand_modif(arr2, arr1, arr3, arr5, arr8); rand_modif(arr3, arr1, arr2, arr6, arr9);
		rand_modif(arr4, arr5, arr6, arr1, arr7); rand_modif(arr5, arr4, arr6, arr2, arr8); rand_modif(arr6, arr4, arr5, arr3, arr9);
		rand_modif(arr7, arr1, arr4, arr8, arr9); rand_modif(arr8, arr7, arr9, arr2, arr5); rand_modif(arr9, arr7, arr8, arr3, arr6);
		rand_modif_box(arr1); rand_modif_box(arr2); rand_modif_box(arr3); rand_modif_box(arr4); rand_modif_box(arr5); rand_modif_box(arr6);
		rand_modif_box(arr7); rand_modif_box(arr8); rand_modif_box(arr9);


		sudoku_init(sudoku, arr1, arr2, arr3, arr4, arr5, arr6, arr7, arr8, arr9);

		for (i = 0; i < 9; i++)
			for (j = 0; j < 9; j++)
				sudoku_i[i][j] = sudoku[i][j];


		if (solve_sudoku(sudoku_i))
		{
			z = 1;
		}
	} while (z != 1);





	return 0;
}

void init(int puzzle[3][3], int arr1[3][3], int arr2[3][3], int arr3[3][3], int arr4[3][3], int arr5[3][3], int arr6[3][3], int arr7[3][3], int arr8[3][3], int arr9[3][3])
{
	int i, r, c,N;
	
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		printf("\nEnter the row and column of the element you would like to enter(numbers between 1 and 3):\n");
		scanf("%d%d", &r, &c);
		if (r <= 3 && c < 3)
		{
			printf("Enter the element (%d,%d)\n", r, c);
			scanf("%d", &puzzle[r - 1][c - 1]);
			system("cls");
			printf("\nThe puzzle so far... :\n");
			printf("\t  1 2 3   1 2 3   1 2 3\n");
			print_init_puzzle(arr1, arr2, arr3); print_init_puzzle(arr4, arr5, arr6); print_init_puzzle(arr7, arr8, arr9);
			printf("\t-------------------------");
		}
		else
		{
			system("cls");
			printf("\nIncorrect input,please enter numbers between 1 and 3.\n");
			printf("\nThe puzzle so far... :\n");
			printf("\t  1 2 3   1 2 3   1 2 3\n");
			print_init_puzzle(arr1, arr2, arr3); print_init_puzzle(arr4, arr5, arr6); print_init_puzzle(arr7, arr8, arr9);
			printf("\t-------------------------");
		}
	}
}

void print_puzzle(int printable1[3][3],int printable2[3][3],int printable3[3][3],int intial1[3][3],int intial2[3][3],int intial3[3][3])
{
	int r, c,counter=0;
	for (r = 0; r < 3; r++)
	{
		
		if (counter==0)
		{
			printf("\t");
			printf("-------------------------");
			printf("\n");
		}
		printf("       %d: ", r + 1);
		
		for (c = 0; c < 3; c++)
			if (printable1[r][c] > 0)
			{
				if (printable1[r][c] != intial1[r][c])
				{
					printf("\033[01;33m"); 		
					printf("%d ", printable1[r][c]);
					printf("\033[0m"); 
				}
				else
					printf("%d ", printable1[r][c]);	
			}
			else
				printf(". ");
		printf(": ");
		
		for (c = 0; c < 3; c++)
			if (printable2[r][c] > 0)
			{
				if (printable2[r][c] != intial2[r][c])
				{
					printf("\033[01;33m");
					printf("%d ", printable2[r][c]);
					printf("\033[0m");
				}
				else
					printf("%d ", printable2[r][c]);
			}
			else
				printf(". ");
		
		printf(": ");
		
		for (c = 0; c < 3; c++)
			if (printable3[r][c] > 0)
			{
				if (printable3[r][c] != intial3[r][c])
				{
					printf("\033[01;33m");
					printf("%d ", printable3[r][c]);
					printf("\033[0m");
				}
				else
					printf("%d ", printable3[r][c]);
			}
			else
				printf(". ");
		
		printf(":");
		printf("\n");
		counter++;		
	}

}

void play(int arr1[3][3], int arr2[3][3],int arr3[3][3],int arr4[3][3],int arr5[3][3],int arr6[3][3], int arr7[3][3], int arr8[3][3], int arr9[3][3]
, int arr1_i[3][3], int arr2_i[3][3], int arr3_i[3][3], int arr4_i[3][3], int arr5_i[3][3], int arr6_i[3][3], int arr7_i[3][3], int arr8_i[3][3], int arr9_i[3][3],int *time_check)

{
	int choice,turns=1;
	float time;

	*time_check = 0;
	clock_t start, end;
	start = clock();

	while (turns != 0)
	{


		printf("Please choose which 3x3 box you'd like to enter a number in(1-9):");
		scanf("%d", &choice);
		int check = 0;
		switch (choice)
		{
		case 1:
			printf("\nPlease enter the amount of elements you would like to enter in grid #1:\n");
			play_input(arr1,arr1_i, arr1, arr2, arr3, arr4, arr5, arr6, arr7, arr8, arr9, arr1_i, arr2_i, arr3_i, arr4_i, arr5_i, arr6_i, arr7_i, arr8_i, arr9_i);
			step_checker(arr1, arr2, arr3, arr4, arr7, &check);
			break;
		case 2:
			printf("\nPlease enter the amount of elements you would like to enter in grid #2:\n");
			play_input(arr2,arr2_i, arr1, arr2, arr3, arr4, arr5, arr6, arr7, arr8, arr9, arr1_i, arr2_i, arr3_i, arr4_i, arr5_i, arr6_i, arr7_i, arr8_i, arr9_i);
			step_checker(arr2, arr1, arr3, arr5, arr8, &check);
			break;
		case 3:
			printf("\nPlease enter the amount of elements you would like to enter in grid #3:\n");
			play_input(arr3,arr3_i, arr1, arr2, arr3, arr4, arr5, arr6, arr7, arr8, arr9, arr1_i, arr2_i, arr3_i, arr4_i, arr5_i, arr6_i, arr7_i, arr8_i, arr9_i);
			step_checker(arr3, arr1, arr2, arr6, arr9, &check);
			break;
		case 4:
			printf("\nPlease enter the amount of elements you would like to enter in grid #4:\n");
			play_input(arr4,arr4_i, arr1, arr2, arr3, arr4, arr5, arr6, arr7, arr8, arr9, arr1_i, arr2_i, arr3_i, arr4_i, arr5_i, arr6_i, arr7_i, arr8_i, arr9_i);
			step_checker(arr4, arr5, arr6, arr1, arr7, &check);
			break;
		case 5:
			printf("\nPlease enter the amount of elements you would like to enter in grid #5:\n");
			play_input(arr5,arr5_i, arr1, arr2, arr3, arr4, arr5, arr6, arr7, arr8, arr9, arr1_i, arr2_i, arr3_i, arr4_i, arr5_i, arr6_i, arr7_i, arr8_i, arr9_i);
			step_checker(arr5, arr4, arr6, arr2, arr8, &check);
			break;
		case 6:
			printf("\nPlease enter the amount of elements you would like to enter in grid #6:\n");
			play_input(arr6,arr6_i, arr1, arr2, arr3, arr4, arr5, arr6, arr7, arr8, arr9, arr1_i, arr2_i, arr3_i, arr4_i, arr5_i, arr6_i, arr7_i, arr8_i, arr9_i);
			step_checker(arr6, arr4, arr5, arr3, arr9, &check);
			break;
		case 7:
			printf("\nPlease enter the amount of elements you would like to enter in grid #7:\n");
			play_input(arr7,arr7_i, arr1, arr2, arr3, arr4, arr5, arr6, arr7, arr8, arr9, arr1_i, arr2_i, arr3_i, arr4_i, arr5_i, arr6_i, arr7_i, arr8_i, arr9_i);
			step_checker(arr7, arr8, arr9, arr1, arr4, &check);
			break;
		case 8:
			printf("\nPlease enter the amount of elements you would like to enter in grid #8:\n");
			play_input(arr8,arr8_i, arr1, arr2, arr3, arr4, arr5, arr6, arr7, arr8, arr9, arr1_i, arr2_i, arr3_i, arr4_i, arr5_i, arr6_i, arr7_i, arr8_i, arr9_i);
			step_checker(arr8, arr7, arr9, arr2, arr5, &check);
			break;
		case 9:
			printf("\nPlease enter the amount of elements you would like to enter in grid #9:\n");
			play_input(arr9,arr9_i, arr1, arr2, arr3, arr4, arr5, arr6, arr7, arr8, arr9, arr1_i, arr2_i, arr3_i, arr4_i, arr5_i, arr6_i, arr7_i, arr8_i, arr9_i);
			step_checker(arr9, arr7, arr8, arr3, arr6, &check);
			break;
		default:
			printf("\nIncorrect input,please try again.");
			break;
		}
		end = clock();
		time = float(end - start) / CLOCKS_PER_SEC;
		if (time > 180.0)
		{			
			(*time_check)++;
			break;
		}
		printf("\nDo you want to enter another number? enter 1 to continue or 0 to stop playing.\n");
		scanf("%d", &turns);
	} 
}

void final_checker(int arr[3][3], int arr1[3][3], int arr2[3][3], int arc1[3][3], int arc2[3][3],int *check)
{
	int i, j, k, m;
	*check = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0;j < 3; j++)
		{
			for (k = 0; k < 3; k++)
			{
				for (m = 0; m < 3; m++)
				{
					if (arr[i][j] == arr[k][m])
					{
						if (i != k || j != m)
						{
							(*check)++;
							break;
						}
					}
					if (arr[i][j] == arr1[i][m])
					{
						
						(*check)++;
						break;
					}
					if (arr[i][j] == arr2[i][m])
					{
						
						(*check)++;
						break;
					}
					if (arr[j][i] == arc1[m][i])
					{
						(*check)++;
						break;
					}
					if (arr[j][i] == arc2[m][i])
					{
						
						(*check)++;
						break;
					}
				}
			}
		}
	}
	
}

void rand_modif(int arr[3][3], int arr1[3][3], int arr2[3][3], int arc1[3][3], int arc2[3][3])
{
	int i, j, k, m;
	
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 3; k++)
			{
				for (m = 0; m < 3; m++)
				{
					if (arr[i][j] == arr[k][m])
					{
						if (i != k || j != m)
						{
							arr[k][m] = 0;
							
						}
					}
					if (arr[i][j] == arr1[i][m])
					{

						arr1[i][m] = 0;
					}
					if (arr[i][j] == arr2[i][m])
					{

						arr2[i][m] = 0;
					}
					if (arr[j][i] == arc1[m][i])
					{
						arc1[m][i] = 0;
					}
					if (arr[j][i] == arc2[m][i])
					{

						arc2[m][i] = 0;
					}
				}
			}
		}
	}

}

void step_checker(int arr[3][3], int arr1[3][3], int arr2[3][3], int arc1[3][3], int arc2[3][3], int* check)
{
	int i, j, k, l, m;
	*check = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 3; k++)
			{
				for (m = 0; (m < 3) && (arr[i][j]!=0) ;m++)
				{
					if (i != k || j != m)
					{
						if (arr[i][j]==arr[k][m])
						{
							
							(*check)++;
							printf("\n%d is an invalid input in (%d,%d)\n", arr[k][m], k, m);
							break;
						}
					}
					if (arr[i][j] == arr1[i][m])
					{
						(*check)++;
						printf("\n%d is an invalid input in (%d,%d)\n", arr1[i][m], i, m);
						break;
					}
					if (arr[i][j] == arr2[i][m])
					{
						
						(*check)++;
						printf("\n%d is an invalid input in (%d,%d)\n", arr2[i][m], i, m);
						break;
					}
					if (arr[j][i] == arc1[m][i]&& arr[j][i]!=0)
					{	
						(*check)++;
						printf("\n%d is an invalid input in (%d,%d)\n", arc1[m][i],m,i);
						break;
					}
					if (arr[j][i] == arc2[m][i] && arr[j][i] != 0)
					{
						(*check)++;
						printf("\n%d is an invalid input in (%d,%d)\n", arc2[m][i],m,i);
						break;
					}
				}
				if (*check > 0)
					break;
			}
			if (*check > 0)
				break;
		}
		if (*check > 0)
			break;
	}

}

int number_unassigned(int sudoku[9][9],int* row, int* col)
{
	int num_unassign = 0;
	int i, j;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (sudoku[i][j] == 0)
			{
				*row = i;
				*col = j;
				num_unassign = 1;
				return num_unassign;
			}
		}
	}
	return num_unassign;
}

int is_safe(int sudoku[9][9],int n, int r, int c)
{
	int i, j;
	for (i = 0; i < 9; i++)
	{
		if (sudoku[r][i] == n)
			return 0;
	}
	for (i = 0; i < 9; i++)
	{
		if (sudoku[i][c] == n)
			return 0;
	}
	int row_start = (r / 3) * 3;
	int col_start = (c / 3) * 3;
	for (i = row_start; i < row_start + 3; i++)
	{
		for (j = col_start; j < col_start + 3; j++)
		{
			if (sudoku[i][j] == n)
				return 0;
		}
	}
	return 1;
}

int solve_sudoku(int sudoku[9][9])
{
	int row;
	int col;
	int i;
	
	if (number_unassigned(sudoku,&row, &col) == 0)
		return 1;
	
	for (i = 1; i <= 9; i++)
	{
		if (is_safe(sudoku,i, row, col))
		{
			sudoku[row][col] = i;
			if (solve_sudoku(sudoku))
				return 1;
			sudoku[row][col] = 0;
		}
	}
	return 0;
}




void main()
{
	int choice;
	int box1[3][3] = { 0,0,0,0,0,0,0,0,0 }; int box2[3][3] = { 0,0,0,0,0,0,0,0,0 };
	int box3[3][3] = { 0,0,0,0,0,0,0,0,0 }; int box4[3][3] = { 0,0,0,0,0,0,0,0,0 };
	int box5[3][3] = { 0,0,0,0,0,0,0,0,0 }; int box6[3][3] = { 0,0,0,0,0,0,0,0,0 };
	int box7[3][3] = { 0,0,0,0,0,0,0,0,0 }; int box8[3][3] = { 0,0,0,0,0,0,0,0,0 }; int box9[3][3] = { 0,0,0,0,0,0,0,0,0 };
	int box1_i[3][3], box2_i[3][3], box3_i[3][3], box4_i[3][3], box5_i[3][3], box6_i[3][3], box7_i[3][3], box8_i[3][3], box9_i[3][3];
	equating_matricies(box1_i, box1);  equating_matricies(box2_i, box2); equating_matricies(box3_i, box3);
	equating_matricies(box4_i, box4); equating_matricies(box5_i, box5); equating_matricies(box6_i, box6);
	equating_matricies(box7_i, box7); equating_matricies(box8_i, box8); equating_matricies(box9_i, box9);
	int c1=0, c2=0, c3=0, c4=0, c5=0, c6=0, c7=0, c8=0, c9=0;
	int sudoku[9][9];
	int solve_check=0;
	int turns = 1, choice_init;
	int time_check;
	printf("Welcome to the sudoku puzzle game");
	printf("\nThis program allows you to make a sudoku puzzle AND have someone else solve it!");
	printf("\nIt can also automatically solve your puzzle for you if it gets too hard!");
	do 
	{
		printf("\nPlease choose one of the following options:");
		printf("\n1-I want to make a puzzle manually");
		printf("\n2-Make a puzzle for me");
		printf("\n3-Start playing");
		printf("\n4-Reset the puzzle to its intial state");
		printf("\n5-Solve the puzzle for me");
		printf("\n6-Check my final solution");
		printf("\n7-Reset everything and start a new game");
		printf("\n8-Quit the game\n");
		scanf("%d", &choice);
		switch (choice)
		{
		
		case 1:
		
		{
			printf("\nThis is the intial stage of the puzzle\nEnter a number between 1 and 9 in each box,or zero if you wish to leave it empty.\n");
			printf("Please don't enter the same number twice in the same row,column or box\n");
			
			do {
				printf("\nPlease choose which 3x3 box you'd like to enter a number in(1-9):");
				scanf("%d", &choice_init);
				
				switch (choice_init)
				{
				case 1:
					printf("\nPlease enter the amount of elements you would like to enter in grid #1:\n");
					init(box1, box1, box2, box3, box4, box5, box6, box7, box8, box9);
					break;
				case 2:
					printf("\nPlease enter the amount of elements you would like to enter in grid #2:\n");
					init(box2, box1, box2, box3, box4, box5, box6, box7, box8, box9);
					break;
				case 3:
					printf("\nPlease enter the amount of elements you would like to enter in grid #3:\n");
					init(box3, box1, box2, box3, box4, box5, box6, box7, box8, box9);
					
					
					break;
				case 4:
					printf("\nPlease enter the amount of elements you would like to enter in grid #4:\n");
					init(box4, box1, box2, box3, box4, box5, box6, box7, box8, box9);
					break;
				case 5:
					printf("\nPlease enter the amount of elements you would like to enter in grid #5:\n");
					init(box5, box1, box2, box3, box4, box5, box6, box7, box8, box9);
					break;
				case 6:
					printf("\nPlease enter the amount of elements you would like to enter in grid #6:\n");
					init(box6, box1, box2, box3, box4, box5, box6, box7, box8, box9);
					break;
				case 7:
					printf("\nPlease enter the amount of elements you would like to enter in grid #7:\n");
					init(box7, box1, box2, box3, box4, box5, box6, box7, box8, box9);
					break;
				case 8:
					printf("\nPlease enter the amount of elements you would like to enter in grid #8:\n");
					init(box8, box1, box2, box3, box4, box5, box6, box7, box8, box9);
					break;
				case 9:
					printf("\nPlease enter the amount of elements you would like to enter in grid #9:\n");
					init(box9, box1, box2, box3, box4, box5, box6, box7, box8, box9);
					break;
				default:
					printf("\nIncorrect input,please try again.");
					break;
				}
				printf("\nDo you want to enter another number? enter 1 to continue or 0 to stop making the puzzle\n");
				scanf("%d", &turns);
			} while (turns != 0);
			
			equating_matricies(box1_i, box1);  equating_matricies(box2_i, box2); equating_matricies(box3_i, box3);
			equating_matricies(box4_i, box4); equating_matricies(box5_i, box5); equating_matricies(box6_i, box6);
			equating_matricies(box7_i, box7); equating_matricies(box8_i, box8); equating_matricies(box9_i, box9);
			system("cls");
			printf("\nThe entered puzzle is:\n");
			printf("\t  1 2 3   1 2 3   1 2 3\n");
			print_puzzle(box1, box2, box3, box1_i, box2_i, box3_i); print_puzzle(box4, box5, box6, box4_i, box5_i, box6_i); print_puzzle(box7, box8, box9, box7_i, box8_i, box9_i);
			printf("\t-------------------------");
			break;
		}

		case 2:

		{
		
		random(sudoku,box1,box2,box3,box4,box5,box6,box7,box8,box9);
		equating_matricies(box1_i, box1);  equating_matricies(box2_i, box2); equating_matricies(box3_i, box3);
		equating_matricies(box4_i, box4); equating_matricies(box5_i, box5); equating_matricies(box6_i, box6);
		equating_matricies(box7_i, box7); equating_matricies(box8_i, box8); equating_matricies(box9_i, box9);
		system("cls");
		printf("\nThe random puzzle is... :\n");
		printf("\t  1 2 3   1 2 3   1 2 3\n");
		print_puzzle(box1, box2, box3, box1_i, box2_i, box3_i); print_puzzle(box4, box5, box6, box4_i, box5_i, box6_i); print_puzzle(box7, box8, box9, box7_i, box8_i, box9_i);
		printf("\t-------------------------");
		

		break;
		}

		case 3:
		
		{
		printf("\nYou can now start playing the game,good luck!");
		printf("\nYou have 3 minutes to complete the puzzle\nGood luck!");
		printf("\nPlease keep in mind that this sudoku puzzle is divided into 9 matricies of order 3x3.");
		play(box1, box2, box3, box4, box5, box6, box7, box8, box9,box1_i,box2_i,box3_i,box4_i,box5_i,box6_i,box7_i,box8_i,box9_i,&time_check);
		system("cls");
		if (time_check == 1)
		{
			printf("\nSorry,time is up!\nBetter luck next time!");
			
		}
		printf("\nThe puzzle so far... :\n");
		printf("\t  1 2 3   1 2 3   1 2 3\n");
		print_puzzle(box1, box2, box3, box1_i, box2_i, box3_i); print_puzzle(box4, box5, box6, box4_i, box5_i, box6_i); print_puzzle(box7, box8, box9, box7_i, box8_i, box9_i);
		printf("\t-------------------------");
		break;
		}

		case 4:
		{
		system("cls");
		printf("\nResetting puzzle...");
		printf("\nThe entered puzzle is:\n");
		printf("\t  1 2 3   1 2 3   1 2 3\n");
		print_init_puzzle(box1_i, box2_i, box3_i); print_init_puzzle(box4_i, box5_i, box6_i); print_init_puzzle(box7_i, box8_i, box9_i);
		printf("\t-------------------------");
		break; 
		}

		case 5:
		
		{

			sudoku_init(sudoku, box1_i, box2_i, box3_i, box4_i, box5_i, box6_i, box7_i, box8_i, box9_i);
			solve_sudoku(sudoku);
			if (solve_sudoku(sudoku))
				solve_check = 1;
			if (solve_check == 1)
			{
				sudoku_reverse(sudoku, box1, box2, box3, box4, box5, box6, box7, box8, box9);
				system("cls");
				printf("\nThe final solution is... :\n");
				printf("\t  1 2 3   1 2 3   1 2 3\n");
				print_puzzle(box1, box2, box3, box1_i, box2_i, box3_i); print_puzzle(box4, box5, box6, box4_i, box5_i, box6_i); print_puzzle(box7, box8, box9, box7_i, box8_i, box9_i);
				printf("\t-------------------------");

			}
			else
			{
				sudoku_reverse(sudoku, box1, box2, box3, box4, box5, box6, box7, box8, box9);
				system("cls");
				printf("\nThe entered puzzle doesn't have a solution,change the puzzle and try again.\n");
				printf("\t  1 2 3   1 2 3   1 2 3\n");
				print_puzzle(box1, box2, box3, box1_i, box2_i, box3_i); print_puzzle(box4, box5, box6, box4_i, box5_i, box6_i); print_puzzle(box7, box8, box9, box7_i, box8_i, box9_i);
				printf("\t-------------------------");
				
				
			}
			break;
		}

		case 6:
	
		{	
		
		system("cls");
		printf("\nChecking your final solution...");
		
		final_checker(box1, box2, box3, box4, box7, &c1); final_checker(box2, box1, box3, box5, box8, &c2);
		final_checker(box3, box1, box2, box6, box9, &c3); final_checker(box4, box5, box6, box1, box7, &c4);
		final_checker(box5, box4, box6, box2, box8, &c5); final_checker(box6, box4, box5, box3, box9, &c6);
		final_checker(box7, box8, box9, box1, box4, &c7); final_checker(box8, box7, box9, box2, box5, &c8);
		final_checker(box9, box7, box8, box3, box6, &c9);
		if (c1 != 0 || c2 != 0 || c3 != 0 || c4 != 0 || c5 != 0 || c6 != 0 || c7 != 0 || c8 != 0 || c9 != 0)
			printf("\nThe solution is incorrect,please try again\n");
		if (c1 == 0 && c2 == 0 && c3 == 0 && c4 == 0 && c5 == 0 && c6 == 0 && c7 == 0 && c8 == 0 && c9 == 0)
			printf("\nCongratulations! Your solution is correct!\n");
		
		printf("\t  1 2 3   1 2 3   1 2 3\n");
		print_puzzle(box1, box2, box3, box1_i, box2_i, box3_i); print_puzzle(box4, box5, box6, box4_i, box5_i, box6_i); print_puzzle(box7, box8, box9, box7_i, box8_i, box9_i);
		printf("\t-------------------------");
		break;
		}

		case 7:

		{
			equating_zero(box1); equating_zero(box2); equating_zero(box3);
			equating_zero(box4); equating_zero(box5); equating_zero(box6);
			equating_zero(box7); equating_zero(box8); equating_zero(box9);

			equating_matricies(box1_i, box1);  equating_matricies(box2_i, box2); equating_matricies(box3_i, box3);
			equating_matricies(box4_i, box4); equating_matricies(box5_i, box5); equating_matricies(box6_i, box6);
			equating_matricies(box7_i, box7); equating_matricies(box8_i, box8); equating_matricies(box9_i, box9);
			system("cls");
			break;
		}

		default:

		{	if (choice == 8)
			printf("Thanks for playing!");
		else
		{
			printf("\nIncorrect input,Enter 0 to exit or 1 to rerun the program:\n");
			scanf("%d", &choice);
		}
		break;
		}

		}
	} while (choice>=1 && choice <=7);
}



