//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	//FILE*p=fopen("a,txt", "w");
//	//
//
//	//close();
//	return 0;
//}
//void snake(int x, int y, int n, int arr[9][9], int count, int min, int max, int n1)
//{
//    for (int j = 0; j < (n1 % 2 == 0 ? (n1 / 2) : (n1 / 2 + 1)); j++)
//    {
//        if (n == 1)
//        {
//            arr[x][y] = count;
//        }
//        else
//        {
//            for (int i = 0; i < n - 1; i++)
//            {
//                if ((y >= min && y <= max) && (arr[x][y] == 0))
//                {
//                    arr[x][y] = count;
//                    count++;
//                    y++;
//                }
//            }
//            for (int i = 0; i < n - 1; i++)
//            {
//                if ((x >= min && x <= max) && (arr[x][y] == 0))
//                {
//                    arr[x][y] = count;
//                    count++;
//                    x++;
//                }
//            }
//            for (int i = 0; i < n - 1; i++)
//            {
//                if ((y >= min && y <= max) && (arr[x][y] == 0))
//                {
//                    arr[x][y] = count;
//                    count++;
//                    y--;
//                }
//            }
//            for (int i = 0; i < n - 1; i++)
//            {
//                if ((x >= min && x <= max) && (arr[x][y] == 0))
//                {
//                    arr[x][y] = count;
//                    count++;
//                    x--;
//                }
//            }
//            x++;
//            y++;
//            n -= 2;
//        }
//    }
//}
//void snake(int arr[n][n], int n)
//{
//	int x = 0;
//	int y = 0;
//	int tem = (n + 1) / 2;
//	int m = n;
//	int count = 1;
//	for (int j = 0; j < tem; j++)
//	{
//		if (n == 1)
//		{
//			arr[x][y] = count;
//		}
//		else
//		{
//			for (int i = 0; i < n - 1; i++)
//			{
//				if ((y >= 0 && y < m) && (arr[x][y] == 0))
//				{
//					arr[x][y] = count;
//					count++;
//					y++;
//				}
//			}
//			for (int i = 0; i < n - 1; i++)
//			{
//				if ((x >= 0 && x < m) && (arr[x][y] == 0))
//				{
//					arr[x][y] = count;
//					count++;
//					x++;
//				}
//			}
//			for (int i = 0; i < n - 1; i++)
//			{
//				if ((y >= 0 && y < m) && (arr[x][y] == 0))
//				{
//					arr[x][y] = count;
//					count++;
//					y--;
//				}
//			}
//			for (int i = 0; i < n - 1; i++)
//			{
//				if ((x >= 0 && x < m) && (arr[x][y] == 0))
//				{
//					arr[x][y] = count;
//					count++;
//					x--;
//				}
//			}
//			x++;
//			y++;
//			n -= 2;
//		}
//	}
//}
//int main()
//{
//	int arr[9][9];
//	memset(arr, 0, sizeof(arr));
//	snake(arr, 9);	
//	for (int i = 0; i < 9; i++)
//	{
//		for (int j = 0; j < 9; j++)
//		{
//			printf("%3d", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//int main(void)
//{
//    while (1)
//    {
//        int n = 0;
//        printf("请输入一个正整数：\n<<<");
//        scanf("%d", &n);
//        int n1 = n;
//        int arr[n][n];
//        int min = 0;
//        int max = n - 1;
//        int x = 0;
//        int y = 0;
//        int count = 1;
//        memset(arr, 0, sizeof(arr));
//        snake(x, y, n, arr, count, min, max, n1);
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                printf("%3d", arr[i][j]);
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}