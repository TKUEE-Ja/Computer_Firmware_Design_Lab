#define IN "P06IN.txt"
#define OUT "P06OUT.txt"

int main()
{
	freopen(IN, "r", stdin);
	freopen(OUT, "w", stdout);
	clock_t cS = clock();

	int T[100001] = { 0 };
	int x, y;
	for (int i = 1; i < 100000; i++)
	{
		x = i;
		y = i;
		while (x > 0)
		{
			y = y + (x % 10);
			x = x / 10;
		}
		if (y > 100000)
			continue;
		if (T[y] == 0)
			T[y] = i;

	}

	int times, num;
	scanf("%d", &times);
	for (int i = 0;i < times;i++)
	{
		scanf("%d", &num);
		printf("%d\n", T[num]);
	}

	clock_t cE = clock();
	freopen("CON", "r", stdin);
	freopen("CON", "w", stdout);
	double cost = (double)(cE - cS) / (CLK_TCK);
	printf("Cost time: %.2f\n", cost);

	return 0;
}
