#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include "head.cpp"





void Menu(int n, int m, int w, schnode a[20])/*菜单函数*/
{
	printf("\t\t 欢迎使用\t\t\t\n\n");
	printf("\t*******运动会分数统计系统*******\t\n");
	printf("\t***********1.信息输入***********\n");
	printf("\t***********2.总分输出***********\n");
	printf("\t***********3.排序输出***********\n");
	printf("\t***********4.信息查询***********\n");
	printf("\t***********0.退出系统***********\n");
	printf("\n\n");
	printf("请输入要实现的功能；");
	int x;
	scanf("%d", &x);
	switch (x)
	{
	case 1:
		Input(n, m, w, a); break;
	case 2:
		Output(n, m, w, a); break;
	case 3:
		Sort(n, m, w, a); break;
	case 4:
		Search(n, m, w, a); break;
	case 0:
		printf("谢谢使用，再见！\n");
		break;
	default:
		printf("输入错误，请重试！\n");
		Menu(n, m, w, a);
	}
}


void Input(int n, int m, int w, schnode a[20]) {     /*输入统计函数*/
	for (int i = 0; i < n; i++) {		//初始化
		a[i].manScore = 0;
		a[i].SchScore = 0;
		a[i].womScore = 0;
		for (int j = 0; j < m + w; j++) {
			for (int k = 0; k < 5; k++) {
				a[i].it[j].itscore[k] = { 0 }; 
				a[i].it[j].itrank[k] = { 0 }; //数组初始化
			}
		}
	}
	int x;
	for (int i = 0; i < n; i++) {
		printf("请输入学校编号；");
		scanf("%d", &a[i].SchId);   //输入学校编号
		printf("请输入学校名称；");
		scanf("%s", a[i].SchName, 10);   //输入学校名称
		for (int j = 0; j < m + w; j++) {
			printf("请输入该学校第%d个项目的项目编号；",j + 1);
			scanf("%d", &a[i].it[j].itnum);
			printf("请输入该学校第%d个项目需要取前3还是前5；", j + 1);
			scanf("%d", &a[i].it[j].ittop);    //确定该项目取前几名
			if (a[i].it[j].ittop == 3) {
				printf("请输入该项目获得前三的有几人；");  //前三名
			}
			else if (a[i].it[j].ittop == 5) {
				printf("请输入该项目获得前五的有几人；");  //前五名
			}
			else {
				printf("输入有误，请重新输入；");  //输入错误
				return;
			}

			scanf("%d", &x);   //输入该项目取前几名

			for (int l = 0; l < x; l++) {
				printf("请输入项目名次；");   //该项目取前三名
				if (a[i].it[j].ittop == 3) {
					scanf("%d", &a[i].it[j].itrank[l]);
					switch (a[i].it[j].itrank[l]) {
					case 0: a[i].it[j].itscore[l] = 0; break;  //根据名次确定运动员成绩
					case 1: a[i].it[j].itscore[l] = 5; break;
					case 2: a[i].it[j].itscore[l] = 3; break;
					case 3: a[i].it[j].itscore[l] = 2; break;
					}
				}
				else if (a[i].it[j].ittop == 5) {            //该项目取前五名
					scanf("%d", &a[i].it[j].itrank[l]);
					switch (a[i].it[j].itrank[l]) {
					case 0: a[i].it[j].itscore[l] = 0; break;  //根据名次确定运动员成绩
					case 1: a[i].it[j].itscore[l] = 7; break;
					case 2: a[i].it[j].itscore[l] = 5; break;
					case 3: a[i].it[j].itscore[l] = 3; break;
					case 4: a[i].it[j].itscore[l] = 2; break;
					case 5: a[i].it[j].itscore[l] = 1; break;
					}
				}
			}
			printf("\n");
		}
	}
	//学校项目总分，学校男女团总分统计
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m + w; j++) {
			for (int k = 0; k < 5; k++) {
				a[i].SchScore = a[i].SchScore + a[i].it[j].itscore[k]; //学校项目总分
				if (j < m) {
					a[i].manScore = a[i].manScore + a[i].it[j].itscore[k]; //男团项目总分
				}
			}
		}
		a[i].womScore = a[i].SchScore - a[i].manScore; //女团项目总分
	}
	printf("成绩输入完成\n");
	Menu(n, m, w, a); //退回到菜单
}


void Sort(int n, int m, int w, schnode a[20]) {   /*排序输出功能*/
	printf("\t********************************\n");		//打印功能菜单
	printf("\t********1.按学校编号输出********\n");
	printf("\t********2.按学校总分输出********\n");
	printf("\t********3.按男团总分输出********\n");
	printf("\t********4.按女团总分输出********\n");
	printf("请输入功能编号；");
	int x;
	scanf("%d", &x);	//输入功能编号
	switch (x) {
	case 1:		//按学校编号输出
		for (int i = 0; i < n; i++) {   //冒泡排序
			for (int j = 0; j < n; j++) {
				if (a[i].SchId < a[j].SchId) {
					schnode t;
					t = a[i];
					a[i] = a[j];
					a[j] = t;
				}
			}
		}
		printf("学校编号    学校名称    学校总分    学校男团总分    学校女团总分\n");
		for (int i = 0; i < n; i++) {
			printf("%4d %14s %10d %10d %16d\n", a[i].SchId, a[i].SchName, a[i].SchScore, a[i].manScore, a[i].womScore);
		}
		break;
	case 2:		//按学校总分输出
		schnode * b;
		b = a;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (b[i].SchScore > b[j].SchScore) {
					schnode t;
					t = b[i];
					b[i] = b[j];
					b[j] = t;
				}
			}
		}
		printf("学校编号    学校名称    学校总分    学校男团总分    学校女团总分\n");
		for (int i = 0; i < n; i++) {
			printf("%4d %14s %10d %10d %16d\n", b[i].SchId, b[i].SchName, b[i].SchScore, b[i].manScore, b[i].womScore);
		}
		break;
	case 3:		//按男团总分输出
		schnode * f;
		f = a;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (f[i].manScore > f[j].manScore) {
					schnode t;
					t = f[i];
					f[i] = f[j];
					f[j] = t;
				}
			}
		}
		printf("学校编号    学校名称    学校总分    学校男团总分    学校女团总分\n");
		for (int i = 0; i < n; i++) {
			printf("%4d %14s %10d %10d %16d\n", f[i].SchId, f[i].SchName, f[i].SchScore, f[i].manScore, f[i].womScore);
		}
		break;
	case 4:		//按女团总分输出
		schnode * g;
		g = a;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (g[i].womScore > g[j].womScore) {
					schnode t;
					t = g[i];
					g[i] = g[j];
					g[j] = t;
				}
			}
		}
		printf("学校编号    学校名称    学校总分    学校男团总分    学校女团总分\n");
		for (int i = 0; i < n; i++) {
			printf("%4d %14s %10d %10d %16d\n", g[i].SchId, g[i].SchName, g[i].SchScore, g[i].manScore, g[i].womScore);
		}
		break;
	}
	printf("输出完成！\n");
	printf("按1返回菜单\n");
	int y;
	scanf("%d", &y);
	if (y) {
		Menu(n, m, w, a); //返回菜单
	}
}			//			


void Search(int n, int m, int w, schnode a[20])                  /*查找函数*/
{
	int flag1, flag2, flag3, x, y, z;
	printf("\t************查询系统************\n\n");
	printf("\t********1.按学校编号查询********\n");
	printf("\t********2.按项目编号查询********\n");
	do
	{
		int i, j;
		flag1 = -1; flag2 = -1; flag3 = -1;
		printf("请选择要实现功能的编号；");
		scanf("%d", &y);
		switch (y)
		{
		case 1:
			printf("要查询的学校编号；");       /*查找学校编号下标*/
			scanf("%d", &z);
			for (i = 0; i < n; i++)
			{
				if (a[i].SchId == z)
					flag1 = i;
			}
			if (flag1 == -1)
				printf("错误：这个学校没有参加此次运动会!\n");
			else
			{
				printf("要查询的项目编号:");         /*查找项目编号的下标*/
				scanf("%d", &z);
				for (j = 0; j < m + w; j++)
				{
					if (a[flag1].it[j].itnum == z)
						flag2 = j;
				}
				if (flag2 == -1)
					printf("此次运动会没有这个项目\n");
				else                                       /*显示结果*/
				{
					printf("这个项目取前%d名,该学校的成绩如下:\n", a[flag1].it[flag2].ittop);
					for (i = 0; i < 5; i++)
						if (a[flag1].it[flag2].itrank[i] != 0)
							printf("名次:%d\n", a[flag1].it[flag2].itrank[i]);
				}
			}
			break;
		case 2:
			printf("要查询的项目编号:");     /*查找项目编号下标*/
			scanf("%d", &z);
			for (i = 0; i < n; i++) {
				for (int j = 0; j < m + w; j++) {
					if (a[i].it[j].itnum == z)
						flag3 = j;
					if (flag3 == -1)
						printf("此次运动会没有这个项目\n");
					else                                    /*显示结果*/
					{
						printf("该项目取前 %d名,取得名次的学校\n", a[i].it[flag3].ittop);
						for (i = 0; i < n; i++)
							for (j = 0; j < 5; j++)
								if (a[i].it[flag3].itrank[j] != 0)
									printf("学校编号:%d,名次:%d\n", a[i].SchId, a[i].it[flag3].itrank[j]);
					}
					
				}
			}
			break;
		default:
			printf("输入错误,请重试!\n");
		}
		printf("请选择:1.返回主菜单 0.继续");     /*返回菜单或继续查询*/
		scanf("%d", &x);
		printf("\n");
	} while (x == 0);
	printf("\n");
	if (x != 0)
		Menu(n, m, w, a);
}


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

