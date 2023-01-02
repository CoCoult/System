#include<stdio.h>
#include<math.h>


//项目
typedef struct {
	int  itnum; //项目编号
	int  ittop; //取项目前几名
	int  itrank[5];//项目名次
	int  itscore[5];//项目得分
}itnode;

//学校
typedef struct {
	int  SchId; //学校编号
	char  SchName[10]; //学校名称
	int  SchScore; //学校总分
	int  manScore; //学校男子总分
	int  womScore; //学校女子总分
	itnode  it[40]; //学校项目
}schnode;


void Input(int n, int m, int w, schnode a[20]);
void Sort(int n, int m, int w, schnode a[20]);
void Search(int n, int m, int w, schnode a[20]);
void Output(int n, int m, int w, schnode a[20]);
void Menu(int n, int m, int w, schnode a[20]);