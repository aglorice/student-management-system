#include<stdio.h>
#include<easyx.h>
#include<string.h>
char name_1[20]="";
char nember_1[20]="";
char major_1[20]="";
char math_1[20]="";
char english_1[20]="";
struct Student
{
	char student[20];
	char studentnumber[20];
	char major[20];
	char math[20];
	char english[20];
}stu[100];//学生信息
int STUDENT;//学生总数
char name[20];
char nember[20];
char major[20];
char math[20];
char english[20];//修改信息
void Tab(const char*tex,int l,int z);
IMAGE publicimg(1000, 618);
struct Butto
{
	int x1;
	int y1;
	int x2;
	int y2;
	char butto[20];
	int z = 0;//默认按钮状态
};
void textmiddle(int x, int y, int a, int b, int lotx_1, const char* test, int z);
void Textmiddle(int q, int w, int e, int r, int lotx, const char* text);
void gohome(int q_1, int w_1, int e_1, int r_1, int v);
void windows();
void windows_1();
void Adduserimg();//信息添加窗口
void Lookuser();//信息查看窗口
void Lookupuser();//查找用户信息
void Deleteuser();//删除用户
void Modifyuser();//修改用户信息
void outport();//信息导出
void instudate();//读取文件
void outstudate();//导出数据
void outstudentfile();
void tab_1();
void tab_2();
void tab_11();
void tab_22();
void sum();
void Tab_1(const char* te, int o, int p);
void Tab_1(const char* te, int o, int p)
{
	int i;
	i = o;
	Textmiddle(50, 0, 130, 40, 30, "返回");
	while (i != p)
	{
		setfillcolor(WHITE);
		fillrectangle(150, i, 240, i + 50);
		Textmiddle(150, i, 240, i + 50, 30, "");
		fillrectangle(250, i, 740, i + 50);
		Textmiddle(250, i, 740, i + 50, 30, "看这里");
		fillrectangle(750, i, 850, i + 50);
		Textmiddle(750, i, 850, i + 50, 30, te);
		i += 60;
	}
	i = o;
	while (i != p)
	{
		Textmiddle(150, i, 240, i + 50, 30, "姓名");
		i += 60;
		Textmiddle(150, i, 240, i + 50, 30, "学号");
		i += 60;
		Textmiddle(150, i, 240, i + 50, 30, "专业");
		i += 60;
		Textmiddle(150, i, 240, i + 50, 30, "数学");
		i += 60;
		Textmiddle(150, i, 240, i + 50, 30, "英语");
		i += 60;
	}
}
void tab_1()
{
	STUDENT;
	int page = 1;
	int pagesum;
	char num[20];
	char sumpage[20];
	if (STUDENT % 8 == 0)
	{
		pagesum = STUDENT / 8;
	}
	else
	{
		pagesum = STUDENT / 8 + 1;
	}
	itoa(page, num, 10);
	itoa(pagesum, sumpage, 10);
	Textmiddle(50, 160, 100, 200, 23, "序号");
	Textmiddle(100, 160, 200, 200, 23, "姓名");
	Textmiddle(200, 160, 450, 200, 23, "学号");
	Textmiddle(450, 160, 650, 200, 23, "专业");
	Textmiddle(650, 160, 850, 200, 23, "数学");
	Textmiddle(850, 160, 950, 200, 23, "英语");
	Textmiddle(80, 550, 180, 600, 30, "上一页");
	Textmiddle(820, 550, 920, 600, 30, "下一页");
	Textmiddle(450, 550, 550, 600, 30, "导出");
}
void tab_2()
{
	int pagesum;
	if (STUDENT % 8 == 0)
	{
		pagesum = STUDENT / 8;
	}
	else
	{
		pagesum = STUDENT / 8 + 1;
	}
	int page = 1;
	ExMessage m;		// 定义消息变量
	int z = 0;
	int i, k, temp;
	char num[20];
	char number_1[20];
	for (i = 0, k = 200; i < 8; i++, k += 40)
	{
		itoa(i + 1, num, 10);
		Textmiddle(50, k, 100, k + 40, 23, num);
		Textmiddle(100, k, 200, k + 40, 30, stu[i].student);
		Textmiddle(200, k, 450, k + 40, 30, stu[i].studentnumber);
		Textmiddle(450, k, 650, k + 40, 30, stu[i].major);
		Textmiddle(650, k, 850, k + 40, 30, stu[i].math);
		Textmiddle(850, k, 950, k + 40, 30, stu[i].english);
	}
	temp = i;
	while (z == 0)
	{
		// 获取一条鼠标或按键消息
		m = getmessage(EM_MOUSE | EM_KEY);
		switch (m.message)
		{
		case WM_LBUTTONDOWN:
			if (m.x > 80 && m.y > 550 && m.x < 180 && m.y < 600 && page != 1)//上一页
			{
				page -= 1;
				for (i = temp - 16, k = 200; i < 8 * page; i++, k += 40)
				{
					itoa(i + 1, num, 10);
					Textmiddle(50, k, 100, k + 40, 23, num);
					Textmiddle(100, k, 200, k + 40, 30, stu[i].student);
					Textmiddle(200, k, 450, k + 40, 30, stu[i].studentnumber);
					Textmiddle(450, k, 650, k + 40, 30, stu[i].major);
					Textmiddle(650, k, 850, k + 40, 30, stu[i].math);
					Textmiddle(850, k, 950, k + 40, 30, stu[i].english);
				}
				temp = i;
			}
			if (m.x > 820 && m.y > 550 && m.x < 920 && m.y < 600 && page < pagesum)//下一页
			{
				page += 1;
				for (k = 200, i = temp; i < page * 8; i++, k += 40)
				{
					itoa(i + 1, num, 10);
					Textmiddle(50, k, 100, k + 40, 23, num);
					Textmiddle(50, k, 100, k + 40, 23, num);
					Textmiddle(100, k, 200, k + 40, 30, stu[i].student);
					Textmiddle(200, k, 450, k + 40, 30, stu[i].studentnumber);
					Textmiddle(450, k, 650, k + 40, 30, stu[i].major);
					Textmiddle(650, k, 850, k + 40, 30, stu[i].math);
					Textmiddle(850, k, 950, k + 40, 30, stu[i].english);
				}
				temp = i;
			}
			if (m.x > 50 && m.y > 0 && m.x < 130 && m.y < 40)
			{
				z = 1;
			}
			if (m.x > 450 && m.y > 550 && m.x < 550 && m.y < 600)
			{
				outstudentfile();
				windows();
			}
			break;
		}
	}
}
void tab_11()
{
	STUDENT ;
	int page=1;
	int pagesum;
	char num[20];
	char sumpage[20];
	if (STUDENT % 8== 0)
	{
		pagesum = STUDENT / 8;
	}
	if (STUDENT == 0)
	{
		pagesum = 1;
	}
	else
	{
		pagesum = STUDENT / 8 + 1;
	}
	itoa(page, num, 10);
	itoa(pagesum, sumpage, 10);
	Textmiddle(50, 160, 100, 200, 23, "序号");
	Textmiddle(100, 160, 200, 200, 23, "姓名");
	Textmiddle(200, 160, 450, 200, 23, "学号");
	Textmiddle(450, 160, 650, 200, 23, "专业");
	Textmiddle(650, 160, 850, 200, 23, "数学");
	Textmiddle(850, 160, 950, 200, 23, "英语");
	Textmiddle(80, 550, 180, 600, 30, "上一页");
	Textmiddle(820, 550, 920, 600, 30, "下一页");
	Textmiddle(350, 550, 400, 600, 30, "第");
	Textmiddle(400, 550, 450, 600, 30, num);
	Textmiddle(450, 550, 500, 600, 30, "页");
	Textmiddle(500, 550, 550, 600, 30, "共");
	Textmiddle(550, 550, 600, 600, 30, sumpage);
	Textmiddle(600, 550, 650, 600, 30, "页");
}
void tab_22()
{
	int pagesum;
	if (STUDENT % 8 == 0)
	{
		pagesum = STUDENT / 8;
	}
	else
	{
		pagesum = STUDENT / 8 + 1;
	}
	int page=1;
	ExMessage m;		// 定义消息变量
	int z = 0;
	int i, k,temp;
	char num[20];
	char number_1[20];
	for (i = 0, k = 200; i < 8; i++, k += 40)
	{
		itoa(i + 1, num, 10);
		Textmiddle(50, k, 100, k+40, 23,num);
		Textmiddle(100, k, 200, k + 40, 30, stu[i].student);
		Textmiddle(200, k, 450, k + 40, 30, stu[i].studentnumber);
		Textmiddle(450, k, 650, k + 40, 30, stu[i].major);
		Textmiddle(650, k, 850, k + 40, 30, stu[i].math);
		Textmiddle(850, k, 950, k + 40, 30, stu[i].english);
	}
	temp = i;
	while (z==0)
	{
		// 获取一条鼠标或按键消息
		m = getmessage(EM_MOUSE | EM_KEY);
		switch (m.message)
		{
		case WM_LBUTTONDOWN:
			if (m.x > 80 && m.y > 550 && m.x < 180 && m.y < 600&&page!=1)//上一页
			{
				page -= 1;
				for (i=temp-16,k=200;i<8*page;i++,k+=40)
				{
					itoa(i + 1, num, 10);
					itoa(page, number_1, 10);
					Textmiddle(400, 550, 450, 600, 30,number_1 );
					Textmiddle(50, k, 100, k + 40, 23, num);
					Textmiddle(100, k, 200, k + 40, 30, stu[i].student);
					Textmiddle(200, k, 450, k + 40, 30, stu[i].studentnumber);
					Textmiddle(450, k, 650, k + 40, 30, stu[i].major);
					Textmiddle(650, k, 850, k + 40, 30, stu[i].math);
					Textmiddle(850, k, 950, k + 40, 30, stu[i].english);
				}
				temp = i;
			}
			if (m.x > 820 && m.y > 550 && m.x < 920 && m.y < 600&&page<pagesum)//下一页
			{
				page += 1;
				for (k=200,i=temp;i<page*8;i++,k+=40)
				{
					itoa(i + 1, num, 10);
					itoa(page, number_1, 10);
					Textmiddle(400, 550, 450, 600, 30, number_1);
					Textmiddle(50, k, 100, k + 40, 23, num);
					Textmiddle(50, k, 100, k + 40, 23, num);
					Textmiddle(100, k, 200, k + 40, 30, stu[i].student);
					Textmiddle(200, k, 450, k + 40, 30, stu[i].studentnumber);
					Textmiddle(450, k, 650, k + 40, 30, stu[i].major);
					Textmiddle(650, k, 850, k + 40, 30, stu[i].math);
					Textmiddle(850, k, 950, k + 40, 30, stu[i].english);
				}
				temp = i;
			}
			if (m.x > 50 && m.y > 0 && m.x <130&& m.y <40)
			{
				z = 1;
			}
			break;
		}
	}
}
void sum()
{
	char num[20];
	itoa(STUDENT, num, 10);
	Textmiddle(750,120,850,160,23,"共计");
	Textmiddle(850,120,900,160,23,num);
	Textmiddle(900, 120, 950, 160, 23, "人");
}
void instudate()
{
	FILE* fp;
	int i;
	if ((fp = fopen("C:\\Users\\40120\\Desktop\\tex", "r")) == NULL)
	{
		fprintf(stdout, "Can't open tex\n");
		exit(EXIT_FAILURE);
	}
	fseek(fp, -2L, SEEK_END);
	fscanf(fp, "%d", &STUDENT);
	rewind(fp);
	for (i = 0; i < STUDENT; i++)
	{
		fscanf(fp, "%s %s %s %s %s\n", &stu[i].student, &stu[i].studentnumber, &stu[i].major, &stu[i].math, &stu[i].english);
	}
	fclose(fp);
}
void  outstudate()
{
	FILE* fp;
	int i;
	if ((fp = fopen("C:\\Users\\40120\\Desktop\\tex", "w+")) == NULL)
	{
		fprintf(stdout, "Can't open \"wordy\" file.\n");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < STUDENT; i++)
	{
		fprintf(fp, "%s %s %s %s %s\n", stu[i].student, stu[i].studentnumber, stu[i].major, stu[i].math, stu[i].english);
	}
	fprintf(fp, "%d",STUDENT);
	fclose(fp);
}
void outstudentfile()
{
	FILE* fp;
	int i;
	if ((fp = fopen("C:\\Users\\40120\\Desktop\\学生信息", "w+")) == NULL)
	{
		fprintf(stdout, "Can't open \"wordy\" file.\n");
		exit(EXIT_FAILURE);
	}
	fprintf(fp, " 姓名\t\t专业\t\t\t学号\t\t\t数学\t\t\t计导\n");
	for (i = 0; i <STUDENT; i++)
	{
		fprintf(fp, "%d:", i + 1);
		fprintf(fp, "%-4s%28s\t\t%s\t\t%s\t\t\t%s\n", stu[i].student, stu[i].studentnumber, stu[i].major, stu[i].math, stu[i].english);
	}
	fprintf(fp, "总计人数为：%d", STUDENT);
	fclose(fp);
}
void Tab(const char* tex, int l,int z)
{
	char str[20];
	char num[20];
	int i;
	int b;
	int temp, k = 0;
	i = l;
	Textmiddle(450, 530, 550, 580, 23, "保存");
	while (i!= z)
	{
		setfillcolor(WHITE);
		fillrectangle(150, i, 240, i + 50);
		Textmiddle(150, i, 240, i + 50, 30, "");
		fillrectangle(250, i, 740, i + 50);
		Textmiddle(250, i, 740, i + 50, 30, "看这里");
		fillrectangle(750, i, 850, i + 50);
		Textmiddle(750, i, 850, i + 50, 30, tex);
		i += 60;
	}
	i = l;
	while (i != z)
	{
		Textmiddle(150, i, 240, i + 50, 30, "姓名");
		i += 60;
		Textmiddle(150, i, 240, i + 50, 30, "学号");
		i += 60;
		Textmiddle(150, i, 240, i + 50, 30, "专业");
		i += 60;
		Textmiddle(150, i, 240, i + 50, 30, "数学");
		i += 60;
		Textmiddle(150, i, 240, i + 50, 30, "英语");
		i += 60;
	}
	ExMessage m;		// 定义消息变量
	i = l;
	while (k==0)
	{
		// 获取一条鼠标或按键消息
		m = getmessage(EM_MOUSE | EM_KEY);
		b = STUDENT;
		switch (m.message)
		{
		case WM_LBUTTONDOWN:
			if (m.x > 750 && m.y > i&& m.x < 850 && m.y < i+50)
			{
				InputBox(name_1, 20, "请输入你的名字",0,"NULL");
				Textmiddle(250, i, 740, i+50, 30, name_1);
				i += 60;
				
			}
			if (m.x > 750 && m.y > i && m.x < 850 && m.y < i+50)
			{
				InputBox(nember_1, 20, "请输入你的学号", 0, "NULL");
				Textmiddle(250,i, 740, i+50, 30, nember_1);
				i += 60;

			}
			if (m.x > 750 && m.y > i&& m.x < 850 && m.y < i+50)
			{
				InputBox(major_1, 20, "请输入你的专业", 0, "NULL");
				Textmiddle(250, i, 740, i+50, 30, major_1);
				i += 60;
				
			}
			if (m.x > 750 && m.y > i && m.x < 850 && m.y < i+50)
			{
				InputBox(math_1, 20, "请输入你的数学成绩", 0, "NULL");
				Textmiddle(250, i, 740, i+50, 30, math_1);
				i += 60;
				
			}
			if (m.x > 750 && m.y >i && m.x < 850 && m.y < i+50)
			{
				InputBox(english_1, 20, "请输入你的英语", 0, "NULL");
				Textmiddle(250, i, 740, i+50, 30, english_1);
				i += 60;
				
			}
			if (m.x > 450 && m.y > 530 && m.x < 550 && m.y < 580)
			{
				b= STUDENT;
				strcpy(stu[b].student, name_1);
				strcpy(stu[b].studentnumber, nember_1);
				strcpy(stu[b].major, major_1);
				strcpy(stu[b].math, math_1);
				strcpy(stu[b].english, english_1);
				windows();
				STUDENT += 1;
				itoa(STUDENT, num, 10);
				Textmiddle(850, 120, 900, 160, 23, num);
				k = 1;
			}
			if (m.x > 50 && m.y > 0&& m.x < 130&& m.y < 40)
			{
				goto s;
			}
			break;
		}
	}
s:;
}
void gohome(int q_1, int w_1, int e_1, int r_1, int v)
{
	int k = 0;
	ExMessage m;// 定义消息变量
	while (k == 0)
	{
		// 获取一条鼠标或按键消息
		m = getmessage(EM_MOUSE | EM_KEY);

		switch (m.message)
		{
		case WM_LBUTTONDOWN:
			// 如果点左键的同时按下了 Ctrl 键
			if (m.x > q_1 && m.y > w_1 && m.x < e_1 && m.y < r_1)
			{
				textmiddle(q_1, w_1, e_1, r_1, v, "返回", 1);
				k = 1;
			}
			break;
		}
	}
}
void windows()
{
	HWND hwd = GetHWnd();
	SetWindowText(hwd, "学生管理系统");
	MessageBox(hwd, "成功", "提示", MB_OKCANCEL);
}
void windows_1()
{
	HWND hwd = GetHWnd();
	SetWindowText(hwd, "学生管理系统");
	MessageBox(hwd, "失败", "提示", MB_OKCANCEL);
}
void Textmiddle(int q, int w, int e, int r, int lotx, const char* text)//标题居中,lotx控制字体大小（长度)
{
	int xm, ym;
	setfillcolor(RGB(159, 195, 5));
	fillrectangle(q, w, e, r);
	settextstyle(lotx, 0, "黑体");
	char arr_2[100] = "";
	strcpy(arr_2, text);
	xm = q + (e - q) / 2 - textwidth(arr_2) / 2;
	ym = w + (r - w) / 2 - textheight(arr_2) / 2;
	settextcolor(BLACK);
	outtextxy(xm, ym, arr_2);
}
void textmiddle(int x, int y, int a, int b, int lotx_1, const char* test, int z)//文字居中函数+按钮效果
{
	int xm, ym;
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	if (z == 0)//z判断按钮是否被点击
	{
		setfillcolor(RGB(159, 195, 5));
	}
	else
	{
		setfillcolor(RGB(80, 195, 0));
	}
	fillrectangle(x, y, a, b);
	settextstyle(lotx_1, 0, "楷体");
	char arr_1[20] = "";
	strcpy(arr_1, test);
	xm = x + (a - x) / 2 - textwidth(arr_1) / 2;
	ym = y + (b - y) / 2 - textheight(arr_1) / 2;
	outtextxy(xm, ym, arr_1);
}
void Adduserimg()//学生信息录入
{

	SetWorkingImage(&publicimg);
	setbkcolor(RGB(159, 195, 5));
	cleardevice();
	SetWorkingImage();
	putimage(0, 0, &publicimg);
	Textmiddle(50, 0, 130, 40, 30, "返回");
	Textmiddle(382, 0, 618, 150, 50, "信息录入");
	sum();
	Tab("增添",200,500);
	outstudate();
}
void Lookuser()
{
	SetWorkingImage(&publicimg);
	setbkcolor(RGB(159, 195, 5));
	cleardevice();
	SetWorkingImage();
	putimage(0, 0, &publicimg);
	Textmiddle(50, 0, 130, 40, 30, "返回");
	Textmiddle(382, 0, 618, 150, 50, "信息查看");
	sum();
	tab_11();
	tab_22();
}
void Lookupuser()
{
	int i;
	int k = 0;
	char name[20];
	SetWorkingImage(&publicimg);
	setbkcolor(RGB(159, 195, 5));
	cleardevice();
	SetWorkingImage();
	putimage(0, 0, &publicimg);
	Textmiddle(50, 0, 130, 40, 30, "返回");
	Textmiddle(382, 0, 618, 150, 50, "信息查找");
	sum();
	Textmiddle(400, 170, 600, 210, 30, "按名字查找");
	Tab_1("", 220, 520);
	ExMessage m;
	while (k == 0)
	{
		// 获取一条鼠标或按键消息
		m = getmessage(EM_MOUSE | EM_KEY);
		switch (m.message)
		{
		case WM_LBUTTONDOWN:
			if (m.x > 50 && m.y > 0 && m.x < 130 && m.y < 40)
			{
				k = 1;
				break;
			}
			if (m.x > 400 && m.y > 170 && m.x < 600 && m.y < 210)
			{
				InputBox(name, 20, "请输入你的姓名");
				for (i = 0; i < STUDENT; i++)
				{
					if (strcmp(name,stu[i].student)==0)
					{
						windows();
						Textmiddle(250, 220, 740, 270, 30, stu[i].student);
						Textmiddle(250, 280, 740, 330, 30, stu[i].studentnumber);
						Textmiddle(250, 340, 740, 390, 30, stu[i].major);
						Textmiddle(250, 400, 740, 450, 30, stu[i].math);
						Textmiddle(250, 460, 740, 510, 30, stu[i].english);
					}
					else if (i == STUDENT && (strcmp(name, stu[i].student) != 0))
					{
						windows_1();
					}
				}
			}
			break;
		}
	}
}
void Deleteuser()
{
	int k = 0;
	int i,b;
	char num[20];
	SetWorkingImage(&publicimg);
	setbkcolor(RGB(159, 195, 5));
	cleardevice();
	SetWorkingImage();
	putimage(0, 0, &publicimg);
	Textmiddle(50, 0, 130, 40, 30, "返回");
	Textmiddle(382, 0, 618, 150, 50, "信息删除");
	sum();
	Textmiddle(400, 170, 600, 210, 30, "按名字查找");
	Textmiddle(400,560 , 600, 600, 30, "删除");
	Tab_1("", 220, 520);
	ExMessage m;
	while (k == 0)
	{
		// 获取一条鼠标或按键消息
		m = getmessage(EM_MOUSE | EM_KEY);
		switch (m.message)
		{
		case WM_LBUTTONDOWN:
			if (m.x > 50 && m.y > 0 && m.x < 130 && m.y < 40)
			{
				k = 1;
				break;
			}
			if (m.x > 400 && m.y > 170 && m.x < 600 && m.y < 210)
			{
				InputBox(name, 20, "请输入你的姓名");
				for (i = 0; i < STUDENT; i++)
				{
					if (strcmp(name, stu[i].student) == 0)
					{
						windows();
						Textmiddle(250, 220, 740, 270, 30, stu[i].student);
						Textmiddle(250, 280, 740, 330, 30, stu[i].studentnumber);
						Textmiddle(250, 340, 740, 390, 30, stu[i].major);
						Textmiddle(250, 400, 740, 450, 30, stu[i].math);
						Textmiddle(250, 460, 740, 510, 30, stu[i].english);
						b = i;
					}
					else if (i == STUDENT && (strcmp(name, stu[i].student) != 0))
					{
						windows_1();
					}
				}
			}
			if (m.x > 400 && m.y > 560 && m.x < 600 && m.y < 600)
			{
				while (b <=STUDENT)
				{
					strcpy(stu[b].student, stu[b+ 1].student);
					strcpy(stu[b].studentnumber, stu[b + 1].studentnumber);
					strcpy(stu[b].major, stu[b + 1].major);
					strcpy(stu[b].math, stu[b + 1].math);
					strcpy(stu[b].english, stu[b + 1].english);
					STUDENT -= 1;
					itoa(STUDENT, num, 10);
					Textmiddle(850, 120, 900, 160, 23, num);
				}
				windows();
			}
			break;
		}
	}
}
void outport()
{
	SetWorkingImage(&publicimg);
	setbkcolor(RGB(159, 195, 5));
	cleardevice();
	SetWorkingImage();
	putimage(0, 0, &publicimg);
	Textmiddle(50, 0, 130, 40, 30, "返回");
	Textmiddle(382, 0, 618, 150, 50, "信息导出");
	sum();
	tab_1();
	tab_2();
}
void Modifyuser()
{
	char str[20];
	int k = 0;
	int i,b;
	SetWorkingImage(&publicimg);
	setbkcolor(RGB(159, 195, 5));
	cleardevice();
	SetWorkingImage();
	putimage(0, 0, &publicimg);
	Textmiddle(50, 0, 130, 40, 30, "返回");
	Textmiddle(382, 0, 618, 150, 50, "信息修改");
	Textmiddle(400, 170, 600, 210,30, "按名字查找");
	Tab_1("修改",220, 520);
	Textmiddle(400, 560, 600, 600, 30, "保存");
	ExMessage m;
	while (k == 0)
	{
		// 获取一条鼠标或按键消息
		m = getmessage(EM_MOUSE | EM_KEY);
		switch (m.message)
		{
		case WM_LBUTTONDOWN:
			if (m.x > 50 && m.y > 0 && m.x < 130 && m.y < 40)
			{
				k = 1;
				break;
			}
			if (m.x > 400 && m.y > 170 && m.x < 600 && m.y < 210)
			{
				InputBox(name, 20, "请输入你的姓名");
				for (i = 0; i < STUDENT; i++)
				{
					if (strcmp(name, stu[i].student) == 0)
					{
						Textmiddle(250, 220, 740, 270, 30, stu[i].student);
						Textmiddle(250, 280, 740, 330, 30, stu[i].studentnumber);
						Textmiddle(250, 340, 740, 390, 30, stu[i].major);
						Textmiddle(250, 400, 740, 450, 30, stu[i].math);
						Textmiddle(250, 460, 740, 510, 30, stu[i].english);
						windows();
						b = i;
						break;
					}
				}
			}
			if (m.x > 750 && m.y > 220 && m.x < 850 && m.y < 270)
			{
				InputBox(name, 20, "请输入你的名字", 0, "NULL");
				Textmiddle(250, 220, 740, 270, 30, name);
			}
			if (m.x > 750 && m.y > 280 && m.x < 850 && m.y < 330)
			{
				InputBox(nember, 20, "请输入你的学号", 0, "NULL");
				Textmiddle(250, 280, 740, 330, 30, nember);
			}
			if (m.x > 750 && m.y > 340&& m.x < 850 && m.y <390)
			{
				InputBox(major, 20, "请输入你的专业", 0, "NULL");
				Textmiddle(250, 340, 740, 390, 30, major);
			}
			if (m.x > 750 && m.y > 400 && m.x < 850 && m.y < 450)
			{
				InputBox(math, 20, "请输入你的数学成绩", 0, "NULL");
				Textmiddle(250, 400, 740,450, 30, math);
			}
			if (m.x > 750 && m.y > 460 && m.x < 850 && m.y < 510)
			{
				InputBox(english, 20, "请输入你的英语", 0, "NULL");
				Textmiddle(250, 460, 740, 510, 30, english);
			}
			if (m.x > 400 && m.y > 560 && m.x < 600 && m.y < 600)
			{
				strcpy(stu[b].student, name);
				strcpy(stu[b].studentnumber, nember);
				strcpy(stu[b].major, major);
				strcpy(stu[b].math, math);
				strcpy(stu[b].english, english);
				windows();
			}
			break;
		}
	}
}
int main()
{
	instudate();
    int i;
	struct Butto but[8] = {
		{250, 0, 750, 168, "学生管理系统",0},
		{300,168,700,222,"信息录入",0},
		{300,222,700,276,"信息查看",0},
		{300,276,700,330,"信息查找",0},
		{300,330,700,384,"信息删除",0},
		{300,384,700,442,"信息导出",0},
		{300,442,700,500,"信息修改",0},
		{300,500,700,558,"退出系统",0}
	};
s: initgraph(1000, 618,EW_SHOWCONSOLE);
	setbkcolor(RGB(159, 195, 5));
	cleardevice();
for (i = 0; i < 8; i++)
	{
		textmiddle(but[i].x1, but[i].y1, but[i].x2, but[i].y2, 45, but[i].butto, but[i].z);
	}//显示菜单
	i = 0;
	int n;//判断鼠标的行为
	ExMessage m;
	while (i != 8)
	{
		// 获取一条鼠标或按键消息
		m = getmessage(EM_MOUSE | EM_KEY);
		switch (m.message)
		{
		case WM_LBUTTONDOWN:
			for (i = 1; i < 8; i++)
			{
				if (m.x > but[i].x1 && m.y > but[i].y1 && m.x < but[i].x2 && m.y < but[i].y2 && i == 1)//判断鼠标是否在按钮区域
				{
					n = 1;
					textmiddle(but[i].x1, but[i].y1, but[i].x2, but[i].y2, 45, but[i].butto, n);
					Adduserimg();
					outstudate();//录入完成后导出数据
					goto s;//迫不得已啊
				}
				if (m.x > but[i].x1 && m.y > but[i].y1 && m.x < but[i].x2 && m.y < but[i].y2 && i == 2)//判断鼠标是否在按钮区域
				{
					n = 1;
					textmiddle(but[i].x1, but[i].y1, but[i].x2, but[i].y2, 45, but[i].butto, n);
					Lookuser();
					goto s;//迫不得已啊
				}
				if (m.x > but[i].x1 && m.y > but[i].y1 && m.x < but[i].x2 && m.y < but[i].y2 && i == 3)//判断鼠标是否在按钮区域
				{
					n = 1;
					textmiddle(but[i].x1, but[i].y1, but[i].x2, but[i].y2, 45, but[i].butto, n);
					Lookupuser();
					goto s;//迫不得已啊
				}
				if (m.x > but[i].x1 && m.y > but[i].y1 && m.x < but[i].x2 && m.y < but[i].y2 && i == 4)//判断鼠标是否在按钮区域
				{
					n = 1;
					textmiddle(but[i].x1, but[i].y1, but[i].x2, but[i].y2, 45, but[i].butto, n);
					Deleteuser();
					outstudate();
					goto s;//迫不得已啊
				}
				if (m.x > but[i].x1 && m.y > but[i].y1 && m.x < but[i].x2 && m.y < but[i].y2 && i == 5)//判断鼠标是否在按钮区域
				{
					n = 1;
					textmiddle(but[i].x1, but[i].y1, but[i].x2, but[i].y2, 45, but[i].butto, n);
					 outport();
					goto s;//迫不得已啊
				}
				if (m.x > but[i].x1 && m.y > but[i].y1 && m.x < but[i].x2 && m.y < but[i].y2 && i == 6)//判断鼠标是否在按钮区域
				{
					n = 1;
					textmiddle(but[i].x1, but[i].y1, but[i].x2, but[i].y2, 45, but[i].butto, n);
					Modifyuser();
					outstudate();
					goto s;//迫不得已啊
				}
				if (m.x > but[i].x1 && m.y > but[i].y1 && m.x < but[i].x2 && m.y < but[i].y2 && i == 7)//判断鼠标是否在按钮区域
				{
					n = 1;
					textmiddle(but[i].x1, but[i].y1, but[i].x2, but[i].y2, 45, but[i].butto, n);
				}
			}
			break;
		}
	}
	closegraph();
	return 0;
}