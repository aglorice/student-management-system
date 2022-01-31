#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define USERNAME 100
#define STUDENT_NUMBER 100
#define MAJOR 100
#define MATH 100
#define INTRODUCTION_TO_COMPUTER 100
char Username[USERNAME][20] = {};
char major[MAJOR][20] = {};
long long int student[STUDENT_NUMBER] = {};
int math[MATH] = {};
int introduction[INTRODUCTION_TO_COMPUTER] = {};
int num;
void menu();//系统界面
void lookuser(int num);//查看用户
void exportuser(int c);//导出用户
void adduser(int temp);//学生信息的而增添
void deleteuser(int b);//删除用户
void modifyuser(int c);//修改用户信息
void lookupuser(int a);//查找用户信息
int inexport();//导入信息
void studentdate();
void menu()
{
	printf("-------------------学生管理系统------------------\n");
	printf("                1.学生信息的增添。\n");
	printf("                2.学生信息的导入。\n");
	printf("                3.学生信息的查看。\n");
	printf("                4.学生信息的删除。\n");
	printf("                5.学生信息的修改。\n");
	printf("                6.学生信息的查找。\n");
	printf("                7.退出程序请按'q'。\n");
	printf("-------------------------------------------------\n");
}
void studentdate()
{
	FILE* fp;
	int i;
	if ((fp = fopen("C:\\Users\\40120\\source\\repos\\学生管理系统\\学生管理系统\\文本.txt", "r")) == NULL)
	{
		fprintf(stdout, "Can't open \"wordy\" file.\n");
		exit(EXIT_FAILURE);
	}
	fseek(fp, -1L, SEEK_END);
	fscanf(fp, "%d", &num);
	rewind(fp);
	for(i=0;i<num;i++)
	{
		fscanf(fp, "%s %s %lld %d %d", &Username[i], &major[i], &student[i], &math[i], &introduction[i]);
		if (student[i] == num)
		{
			break;
		}
	}
	num = i;
	fclose(fp);
}
int inexport()
{
	FILE* fp;
	int i;
	if ((fp = fopen("C:\\Users\\40120\\source\\repos\\学生管理系统\\学生管理系统\\文本.txt", "w+")) == NULL)
	{
		fprintf(stdout, "Can't open \"wordy\" file.\n");
		exit(EXIT_FAILURE);
	}
	for(i=0;i<num;i++)
	{
		fprintf(fp, "%s %s %lld %d %d \n", Username[i], major[i], student[i], math[i], introduction[i]);
	}
	fprintf(fp, "%d", num);
	fclose(fp);
}
void lookuser( int num)
{
	int a_username, b_major,d_math,e_introduction;
	long long int  c_studentnumber;
	printf(" 姓名\t\t\t专业\t\t\t学号\t\t\t数学\t\t\t计导\n");
	for (a_username = 0, b_major = 0, c_studentnumber = 0, d_math=0, e_introduction=0; a_username < num; a_username++, b_major++, c_studentnumber++, d_math++,e_introduction++)
	{
		printf("%d:", a_username+1);
		printf("%-4s%28s\t\t%lld\t\t%d\t\t\t%d\n", Username[a_username], major[b_major], student[c_studentnumber], math[d_math], introduction[e_introduction]);
	}
	printf("学生人数总计为:%d个\n", num);
}
void exportuser(int c)
{
	FILE* fp;
	int i;
	if ((fp = fopen("C:\\Users\\40120\\Desktop\\学生信息", "w+")) == NULL)
	{
		fprintf(stdout, "Can't open \"wordy\" file.\n");
		exit(EXIT_FAILURE);
	}
	fprintf(fp, " 姓名\t\t专业\t\t\t学号\t\t\t数学\t\t\t计导\n");
	for(i = 0; i < num; i++)
	{
		fprintf(fp,"%d:", i + 1);
		fprintf(fp,"%-4s%28s\t\t%lld\t\t%d\t\t\t%d\n", Username[i], major[i], student[i], math[i], introduction[i]);
	}
	fprintf(fp, "总计人数为：%d", c);
	fclose(fp);
}
void adduser(int temp)
{
	int ch=1;
	printf("请输入你要录入学生的信息：\n");
	while(ch)
	{
		printf("%d.", temp+1);
		printf("请输入你学生的姓名：\n");
		scanf("%s", &Username[temp]);
		printf("请输入你的专业：\n");
		scanf("%s", &major[temp]);
		printf("请输入你的学号：\n");
		scanf("%lld", &student[temp]);
		printf("请输入你的数学成绩：\n");
		scanf("%d", &math[temp]);
		printf("请输入你的计算机导论成绩：\n");
		scanf("%d", &introduction[temp]);
		temp += 1;
		printf("按0号结束录入（其余数字则继续录入）:\n");
		if (scanf("%d", &ch) == 0)
		{
			break;
		}
	}
	printf("录入成功！！！\n");
	num = temp;
}
void deleteuser(int b)
{
	
	long long int studentnumber;
	int i;
	printf("请输入你想删除的学生的学号:");
	scanf("%lld", &studentnumber);
	for (i = 0; i <b; i++)
	{
		if (student[i] == studentnumber)
		{
			break;
		}
	}
	while (i <=num)
	{
		strcpy(Username[i], Username[i + 1]);
		strcpy(major[i], major[i + 1]);
		student[i] = student[i + 1];
		math[i] = math[i + 1];
		introduction[i] = introduction[i + 1];
		i += 1;
	}
	num = b - 1;
	printf("删除成功！！！\n");
	exportuser(num);
}
void modifyuser(int c)
{
	long long int studentnumber;
	int i, a, k;
	k = 0;
	printf("请输入你要修改人的学号：");
	scanf("%lld", &studentnumber);
	for (i = 0; i < c; i++)
	{
		if (student[i] == studentnumber)
		{
			printf(" 姓名\t\t\t专业\t\t\t学号\t\t\t数学\t\t\t计导\n");
			printf("%d:", i + 1);
			printf("%s%30s\t\t%lld\t\t%d\t\t\t%d\n", Username[i], major[i], student[i], math[i], introduction[i]);
			k = 1;
		}
	}
	if (k != 1)
	{
		printf("系统中没有该学号！！！\n");
	}
	printf("-------------------------------------\n");
	printf("               1.数学\n");
	printf("               2.计导\n");
	printf("             3.以上全部\n");
	printf("-------------------------------------\n");
	printf("请选择你要修改的选项：\n");
	scanf("%d", &a);
	switch (a)
	{
	case 1:
		printf("请输入你修改后的数学成绩：\n");
		scanf("%d", &math[i]);
		break;
		
	case 2:
		printf("请输入你修改后的计算机导论成绩：\n");
		scanf("%d", &introduction[i]);
		break;
	case 3:
		printf("请输入你修改后的数学成绩和计算机导论成绩：\n");
		scanf("%d %d", &math[i],&introduction[i]);
		break;
	default:
		break;
	}
	printf("修改成功！！！\n");
	
}
void lookupuser(int a)
{
	long long int studentnumber;
	int i,k;
	k = 0;
	printf("请输入你要查找人的学号：");
	scanf("%lld", &studentnumber);
	for (i = 0; i < a; i++)
	{
		if (student[i] == studentnumber)
		{
			printf("查询成功！！！\n");
			printf(" 姓名\t\t\t专业\t\t\t学号\t\t\t数学\t\t\t计导\n");
			printf("%d:", i + 1);
			printf("%s%30s\t\t%lld\t\t%d\t\t\t%d\n", Username[i], major[i], student[i], math[i], introduction[i]);
			k = 1;
		}
	}
	if (k != 1)
	{
		printf("系统中没有该学号！！！\n");
	}
	
}
int main()
{
	int number;
	num = 0;
	menu();
	studentdate();
	printf("请选择一个\n");
	while (scanf("%d", &number))
	{
		switch (number)
		{
		case 1:
			printf("---------------------信息增添--------------------\n");
			adduser(num);//学生信息的而增添
			menu();
			printf("请选择一个\n");
			break;
		case 2:
			printf("---------------------信息导入--------------------\n");
		    inexport();//导入信息
			printf("信息导入成功! ! ! \n");
			menu();
			printf("请选择一个\n");
			break;
		case 3:
			printf("---------------------查看信息--------------------\n");
			lookuser(num);//导入用户
			menu();
			printf("请选择一个\n");
			break;
		case 4:
			printf("---------------------信息删除--------------------\n");
			deleteuser(num);//删除用户
			menu();
			printf("请选择一个\n");
			break;
		case 5:
			printf("---------------------信息修改--------------------\n");
			modifyuser(num);//修改用户信息
			menu();
			printf("请选择一个\n");
			break;
		case 6:
			printf("---------------------信息查找--------------------\n");
			lookupuser(num);//查找用户信息
			menu();
			printf("请选择一个\n");
		case 7:
			break;
		}
	} 
	exportuser(num);
	inexport();
	return 0;
}