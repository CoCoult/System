void Output(int n, int m, int w, schnode a[20])                                /*2.总分输出*/
{
	int x = 0;
	for (int i = 0; i < n; i++)  /*显示结果*/
	{
		printf("学校编号:%d   学校名称:%s  学校总分:%d   男子总分:%d  女子总分:%d\n", a[i].SchId, a[i].SchName, a[i].SchScore, a[i].manScore, a[i].womScore);
		for (int j = 0; j < m + w; j++)
		{
			printf("项目编号:%d  所取名次数量:%d\n", a[i].it[j].itnum, a[i].it[j].ittop);
			for (int k = 0; k < 5; k++)
			{
				if (a[i].it[j].itrank[k] != 0)
					printf("名次:%d  分数:%d\n", a[i].it[j].itrank[k], a[i].it[j].itscore[k]);
			}
		}
		printf("\n");
	}
	printf("\n");
	printf("输出完毕!输入1返回菜单");    /*返回菜单*/
	scanf("%d", &x);
	printf("\n");
	if (x != 1)
		printf("输出已经结束!");
	printf("\n");
	Menu(n, m, w, a);
}

