typedef struct
{
	int *first, *second;
	int firstLen, secondLen;
} ptrPair;

ptrPair divide(int *a, int n)
{
	ptrPair new;
	int i = getPartitionIndex(a, n);
	new.first = &a[0];
	new.second = &a[i] + 1;
	new.firstLen = i + 1;
	new.secondLen = n - i - 1;
	return new;
}

int getPartitionIndex(int *a, int n)
{
	int x = a[0];
	int i = -1;
	int j = n;
	while (1)
	{
		do
		{
			j = j - 1;
		} while (j >= 0 && a[j] > x);
		do
		{
			i = i + 1;
		} while (i < n && a[i] < x);
		if (i >= j)
			return j;
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
}

void conquer(int *a, int n)
{
	if (n > 1)
	{
		ptrPair new = divide(a, n);
		conquer(new.first, new.firstLen);
		conquer(new.second, new.secondLen);
	}
}

void quickSort(int *a, int n)
{
	conquer(a, n);
}

int isSorted(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] > a[i + 1])
			return 0;
	}
	return 1;
}
