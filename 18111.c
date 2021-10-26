#include <stdio.h>
#include <stdlib.h>

int complete_map(int N, int M, int B, int **map, int target)
{
	int time;
    int sum;

    sum = 0;
    time = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
        {
			sum += map[i][j] - target;
            if (map[i][j] - target < 0)
                time += target - map[i][j];
            else
                time += (map[i][j] - target) * 2;
        }
	}
    if (B + sum >= 0)
	    return (time);
    else
        return (-1);
}

int	main(void)
{
	int N;
	int M;
	int B;
	int **map;
	int time;
	int temp;
	int min;
	int max;
	int target;

	min = 2147483647;
	max = 0;
	scanf("%d %d %d", &N, &M, &B);
	map = malloc(sizeof(int *) * N);
	for (int i = 0; i < N; i++)
	{
		map[i] = malloc(sizeof(int) * M);
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] < min)
				min = map[i][j];
			if (map[i][j] > max)
				max = map[i][j];
		}
	}
	time = 2147483647;
	target = min;
	for (int i = min; i <= max; i++)
	{
		temp = complete_map(N, M, B, map, i);
		if (temp != -1 && temp < time)
		{
			target = i;
			time = temp;
		}
		else if (temp != -1 && temp == time)
		{
			if (i > target)
				target = i;
		}
	}
	for (int k = 0; k < N; k++)
		free(map[k]);
	free(map);
	printf("%d %d\n", time, target);
}