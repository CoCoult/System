#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include "head.cpp"





void Menu(int n, int m, int w, schnode a[20])/*�˵�����*/
{
	printf("\t\t ��ӭʹ��\t\t\t\n\n");
	printf("\t*******�˶������ͳ��ϵͳ*******\t\n");
	printf("\t***********1.��Ϣ����***********\n");
	printf("\t***********2.�ܷ����***********\n");
	printf("\t***********3.�������***********\n");
	printf("\t***********4.��Ϣ��ѯ***********\n");
	printf("\t***********0.�˳�ϵͳ***********\n");
	printf("\n\n");
	printf("������Ҫʵ�ֵĹ��ܣ�");
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
		printf("ллʹ�ã��ټ���\n");
		break;
	default:
		printf("������������ԣ�\n");
		Menu(n, m, w, a);
	}
}


void Input(int n, int m, int w, schnode a[20]) {     /*����ͳ�ƺ���*/
	for (int i = 0; i < n; i++) {		//��ʼ��
		a[i].manScore = 0;
		a[i].SchScore = 0;
		a[i].womScore = 0;
		for (int j = 0; j < m + w; j++) {
			for (int k = 0; k < 5; k++) {
				a[i].it[j].itscore[k] = { 0 }; 
				a[i].it[j].itrank[k] = { 0 }; //�����ʼ��
			}
		}
	}
	int x;
	for (int i = 0; i < n; i++) {
		printf("������ѧУ��ţ�");
		scanf("%d", &a[i].SchId);   //����ѧУ���
		printf("������ѧУ���ƣ�");
		scanf("%s", a[i].SchName, 10);   //����ѧУ����
		for (int j = 0; j < m + w; j++) {
			printf("�������ѧУ��%d����Ŀ����Ŀ��ţ�",j + 1);
			scanf("%d", &a[i].it[j].itnum);
			printf("�������ѧУ��%d����Ŀ��Ҫȡǰ3����ǰ5��", j + 1);
			scanf("%d", &a[i].it[j].ittop);    //ȷ������Ŀȡǰ����
			if (a[i].it[j].ittop == 3) {
				printf("���������Ŀ���ǰ�����м��ˣ�");  //ǰ����
			}
			else if (a[i].it[j].ittop == 5) {
				printf("���������Ŀ���ǰ����м��ˣ�");  //ǰ����
			}
			else {
				printf("�����������������룻");  //�������
				return;
			}

			scanf("%d", &x);   //�������Ŀȡǰ����

			for (int l = 0; l < x; l++) {
				printf("��������Ŀ���Σ�");   //����Ŀȡǰ����
				if (a[i].it[j].ittop == 3) {
					scanf("%d", &a[i].it[j].itrank[l]);
					switch (a[i].it[j].itrank[l]) {
					case 0: a[i].it[j].itscore[l] = 0; break;  //��������ȷ���˶�Ա�ɼ�
					case 1: a[i].it[j].itscore[l] = 5; break;
					case 2: a[i].it[j].itscore[l] = 3; break;
					case 3: a[i].it[j].itscore[l] = 2; break;
					}
				}
				else if (a[i].it[j].ittop == 5) {            //����Ŀȡǰ����
					scanf("%d", &a[i].it[j].itrank[l]);
					switch (a[i].it[j].itrank[l]) {
					case 0: a[i].it[j].itscore[l] = 0; break;  //��������ȷ���˶�Ա�ɼ�
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
	//ѧУ��Ŀ�ܷ֣�ѧУ��Ů���ܷ�ͳ��
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m + w; j++) {
			for (int k = 0; k < 5; k++) {
				a[i].SchScore = a[i].SchScore + a[i].it[j].itscore[k]; //ѧУ��Ŀ�ܷ�
				if (j < m) {
					a[i].manScore = a[i].manScore + a[i].it[j].itscore[k]; //������Ŀ�ܷ�
				}
			}
		}
		a[i].womScore = a[i].SchScore - a[i].manScore; //Ů����Ŀ�ܷ�
	}
	printf("�ɼ��������\n");
	Menu(n, m, w, a); //�˻ص��˵�
}


void Sort(int n, int m, int w, schnode a[20]) {   /*�����������*/
	printf("\t********************************\n");		//��ӡ���ܲ˵�
	printf("\t********1.��ѧУ������********\n");
	printf("\t********2.��ѧУ�ܷ����********\n");
	printf("\t********3.�������ܷ����********\n");
	printf("\t********4.��Ů���ܷ����********\n");
	printf("�����빦�ܱ�ţ�");
	int x;
	scanf("%d", &x);	//���빦�ܱ��
	switch (x) {
	case 1:		//��ѧУ������
		for (int i = 0; i < n; i++) {   //ð������
			for (int j = 0; j < n; j++) {
				if (a[i].SchId < a[j].SchId) {
					schnode t;
					t = a[i];
					a[i] = a[j];
					a[j] = t;
				}
			}
		}
		printf("ѧУ���    ѧУ����    ѧУ�ܷ�    ѧУ�����ܷ�    ѧУŮ���ܷ�\n");
		for (int i = 0; i < n; i++) {
			printf("%4d %14s %10d %10d %16d\n", a[i].SchId, a[i].SchName, a[i].SchScore, a[i].manScore, a[i].womScore);
		}
		break;
	case 2:		//��ѧУ�ܷ����
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
		printf("ѧУ���    ѧУ����    ѧУ�ܷ�    ѧУ�����ܷ�    ѧУŮ���ܷ�\n");
		for (int i = 0; i < n; i++) {
			printf("%4d %14s %10d %10d %16d\n", b[i].SchId, b[i].SchName, b[i].SchScore, b[i].manScore, b[i].womScore);
		}
		break;
	case 3:		//�������ܷ����
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
		printf("ѧУ���    ѧУ����    ѧУ�ܷ�    ѧУ�����ܷ�    ѧУŮ���ܷ�\n");
		for (int i = 0; i < n; i++) {
			printf("%4d %14s %10d %10d %16d\n", f[i].SchId, f[i].SchName, f[i].SchScore, f[i].manScore, f[i].womScore);
		}
		break;
	case 4:		//��Ů���ܷ����
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
		printf("ѧУ���    ѧУ����    ѧУ�ܷ�    ѧУ�����ܷ�    ѧУŮ���ܷ�\n");
		for (int i = 0; i < n; i++) {
			printf("%4d %14s %10d %10d %16d\n", g[i].SchId, g[i].SchName, g[i].SchScore, g[i].manScore, g[i].womScore);
		}
		break;
	}
	printf("�����ɣ�\n");
	printf("��1���ز˵�\n");
	int y;
	scanf("%d", &y);
	if (y) {
		Menu(n, m, w, a); //���ز˵�
	}
}			//			


void Search(int n, int m, int w, schnode a[20])                  /*���Һ���*/
{
	int flag1, flag2, flag3, x, y, z;
	printf("\t************��ѯϵͳ************\n\n");
	printf("\t********1.��ѧУ��Ų�ѯ********\n");
	printf("\t********2.����Ŀ��Ų�ѯ********\n");
	do
	{
		int i, j;
		flag1 = -1; flag2 = -1; flag3 = -1;
		printf("��ѡ��Ҫʵ�ֹ��ܵı�ţ�");
		scanf("%d", &y);
		switch (y)
		{
		case 1:
			printf("Ҫ��ѯ��ѧУ��ţ�");       /*����ѧУ����±�*/
			scanf("%d", &z);
			for (i = 0; i < n; i++)
			{
				if (a[i].SchId == z)
					flag1 = i;
			}
			if (flag1 == -1)
				printf("�������ѧУû�вμӴ˴��˶���!\n");
			else
			{
				printf("Ҫ��ѯ����Ŀ���:");         /*������Ŀ��ŵ��±�*/
				scanf("%d", &z);
				for (j = 0; j < m + w; j++)
				{
					if (a[flag1].it[j].itnum == z)
						flag2 = j;
				}
				if (flag2 == -1)
					printf("�˴��˶���û�������Ŀ\n");
				else                                       /*��ʾ���*/
				{
					printf("�����Ŀȡǰ%d��,��ѧУ�ĳɼ�����:\n", a[flag1].it[flag2].ittop);
					for (i = 0; i < 5; i++)
						if (a[flag1].it[flag2].itrank[i] != 0)
							printf("����:%d\n", a[flag1].it[flag2].itrank[i]);
				}
			}
			break;
		case 2:
			printf("Ҫ��ѯ����Ŀ���:");     /*������Ŀ����±�*/
			scanf("%d", &z);
			for (i = 0; i < n; i++) {
				for (int j = 0; j < m + w; j++) {
					if (a[i].it[j].itnum == z)
						flag3 = j;
					if (flag3 == -1)
						printf("�˴��˶���û�������Ŀ\n");
					else                                    /*��ʾ���*/
					{
						printf("����Ŀȡǰ %d��,ȡ�����ε�ѧУ\n", a[i].it[flag3].ittop);
						for (i = 0; i < n; i++)
							for (j = 0; j < 5; j++)
								if (a[i].it[flag3].itrank[j] != 0)
									printf("ѧУ���:%d,����:%d\n", a[i].SchId, a[i].it[flag3].itrank[j]);
					}
					
				}
			}
			break;
		default:
			printf("�������,������!\n");
		}
		printf("��ѡ��:1.�������˵� 0.����");     /*���ز˵��������ѯ*/
		scanf("%d", &x);
		printf("\n");
	} while (x == 0);
	printf("\n");
	if (x != 0)
		Menu(n, m, w, a);
}


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

