#include<stdio.h>
#include<math.h>


//��Ŀ
typedef struct {
	int  itnum; //��Ŀ���
	int  ittop; //ȡ��Ŀǰ����
	int  itrank[5];//��Ŀ����
	int  itscore[5];//��Ŀ�÷�
}itnode;

//ѧУ
typedef struct {
	int  SchId; //ѧУ���
	char  SchName[10]; //ѧУ����
	int  SchScore; //ѧУ�ܷ�
	int  manScore; //ѧУ�����ܷ�
	int  womScore; //ѧУŮ���ܷ�
	itnode  it[40]; //ѧУ��Ŀ
}schnode;


void Input(int n, int m, int w, schnode a[20]);
void Sort(int n, int m, int w, schnode a[20]);
void Search(int n, int m, int w, schnode a[20]);
void Output(int n, int m, int w, schnode a[20]);
void Menu(int n, int m, int w, schnode a[20]);