void Output(int n, int m, int w, schnode a[20])                                /*2.�ܷ����*/
{
	int x = 0;
	for (int i = 0; i < n; i++)  /*��ʾ���*/
	{
		printf("ѧУ���:%d   ѧУ����:%s  ѧУ�ܷ�:%d   �����ܷ�:%d  Ů���ܷ�:%d\n", a[i].SchId, a[i].SchName, a[i].SchScore, a[i].manScore, a[i].womScore);
		for (int j = 0; j < m + w; j++)
		{
			printf("��Ŀ���:%d  ��ȡ��������:%d\n", a[i].it[j].itnum, a[i].it[j].ittop);
			for (int k = 0; k < 5; k++)
			{
				if (a[i].it[j].itrank[k] != 0)
					printf("����:%d  ����:%d\n", a[i].it[j].itrank[k], a[i].it[j].itscore[k]);
			}
		}
		printf("\n");
	}
	printf("\n");
	printf("������!����1���ز˵�");    /*���ز˵�*/
	scanf("%d", &x);
	printf("\n");
	if (x != 1)
		printf("����Ѿ�����!");
	printf("\n");
	Menu(n, m, w, a);
}

