#include<stdio.h>
#define ROW 50
#define COL 50
void print(int arr[][COL], int row);
void takeData(int arr[], int size);
void process(int arr[][COL], int row,const int data[], int size);
int main()
{
	int floor[ROW][COL] = { 0 }, inf[100] = { 0 };
	printf("\t\t\twelcoem to TURTLE GRAPHICS\nintialy you start going to the right and your pen up, here's the commands\n(1). pen up\t(2).  pen down\t(3).  turn right\t(4).  turn left\n(5) to move forward and the next command how many steps\t (6)to print floor\t(9)  end of data\n");
	takeData(inf, 100);
	process(floor, ROW, inf, 100);
	return 0;
}
void print(int arr[][COL],int row)
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			if (arr[i][j] == 1)
				printf("* ");
			else
				printf("  ");
			//printf("%d ", arr[i][j]);
		}
		puts("");
	}

}
void takeData(int arr[], int size)
{
	//take the commands 
	for (int i = 0; (i < size); ++i)
	{
		printf("Enter command (9 to end input): ");
		scanf_s("%d", &arr[i]);
		if (arr[i] == 9 && arr[i - 1] != 5)
			break;
	}
}
void process(int arr[][COL], int row, const int data[], int size)
{
	//dir1 for 3,,,dir2 for 4
	int pen = 1, whereCol = 0, whereRow = 0, dir = 3;
	//to process each order in data array,,and for performance to stop when see 9 and don't complete to zeroes
	for (int i = 0; (i < size) && (data[i] != 9) && (data[i] != 0); ++i)
	{
		switch (data[i])
		{
			//to sign pen data
		case 1:
		case 2:
		{
			pen = data[i];
			break;
		}
			//direction data
		case 3:
		case 4:
		{
			if ((data[i] == 3 && dir == 3)||(data[i] == 3 && dir == 4))
				dir = 7;//down
			else if ( (data[i] == 4 && dir == 3) || (data[i] == 4 && dir == 7) || (data[i] == 4 && dir == 8) )
				dir = 4;//left
			else if ( (data[i] == 3 && dir == 7) || (data[i] == 3 && dir == 8))
				dir = 3;//right
			else if (data[i] == 4 && dir == 4)
				dir = 8;//up
			break;
		}
		case 6:
			print(arr, row);
			break;
		case 5:
		{
			int j;
			for ( j = 0; j < data[i + 1]; ++j)
			{
				if (pen == 2)
				{
					if (dir == 3)
						arr[whereRow][whereCol + j] = 1;
					else if(dir==4)
						arr[whereRow][whereCol - j] = 1;
					else if (dir == 7)
						arr[whereRow+j][whereCol] = 1;
					else if (dir == 8)
						arr[whereRow-j][whereCol] = 1;
				}
			}
			if (dir == 3)
				whereCol += j;
			else if (dir == 4)
				whereCol -= j;
			else if (dir == 7)
				whereRow += j;
			else if (dir == 8)
				whereRow -= j;
			//++ to skip the next number to 5 beacuse its already processed
			++i;
			break;
		}
		}
	}
}
