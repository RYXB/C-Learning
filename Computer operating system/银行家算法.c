
/*
Name: ���м��㷨
Author: Deep Baldha (CandyZack)
Mender: Vistar Terry (��ٹ����)
Time: 2019/10/8 16:43
*/
#include <stdio.h>
int main()
{
	// P1, P2, P3, P4, P5  Ϊ�߳���
	int n, m, i, j, k;
	n = 5; // �߳���Ŀ
	m = 3; // ��Դ��Ŀ

	// MAX ����
	int max[5][3] = { { 5, 5, 9 }, // P1
					  { 5, 3, 6 }, // P2
					  { 4, 0, 11 }, // P3
					  { 4, 2, 5 }, // P4
					  { 4, 2, 4 } }; // P5

	// Allocation ����
	int alloc[5][3] = { { 2, 1, 2 }, // P1
						{ 4, 0, 2 }, // P2
						{ 4, 0, 5 }, // P3
						{ 2, 0, 4 }, // P4
						{ 3, 1, 4 } }; // P5

	// Available ����
	int avail[3] = { 2, 3, 3 };

	int f[n], ans[n], ind = 0;
	for (k = 0; k < n; k++)
	{
		f[k] = 0;
	}
	int need[n][m];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			need[i][j] = max[i][j] - alloc[i][j];
	}
	int y = 0;
	for (k = 0; k < 5; k++)
	{
		for (i = 0; i < n; i++)
		{
			if (f[i] == 0) {

				int flag = 0;
				for (j = 0; j < m; j++)
				{
					if (need[i][j] > avail[j])
					{
						flag = 1;
						break;
					}
				}

				if (flag == 0)
				{
					ans[ind++] = i;
					for (y = 0; y < m; y++)
						avail[y] += alloc[i][y];
					f[i] = 1;
				}
			}
		}
	}

	printf("��ȫ�������£�\n");
	for (i = 0; i < n - 1; i++)
		printf(" P%d ->", ans[i]+1);
	printf(" P%d", ans[n - 1]+1);

	return (0);
}
