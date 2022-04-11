#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#define MAX 100
using namespace std;
class person
{
public:
	long long int num;
	char name[20];
	char sex[4];
	int age;
};
//Teacher class
class Teacher :virtual public person
{
public:
	char dept[20];
	char special[20];
	char title[20];
	void Input()
	{
		cout << "请输入编号："; cin >> num;
		cout << "请输入姓名:"; cin >> name;
		cout << "请输入性别:"; cin >> sex;
		cout << "请输入年龄:"; cin >> age;
		cout << "请输入所在系:"; cin >> dept;
		cout << "请输入专业:"; cin >> special;
		cout << "请输入职称:"; cin >> title;
	}
	void Output()
	{
		cout << "编号: " << num << "  " << "姓名: " << name << "  " << "性别: " << sex << "  " << "年龄: " << age << "  " << "所在系: " << dept << "  " << "专业: " << special << "  " << "职称: " << title << endl;
			
	}
};
Teacher Tea[MAX];
static int Teatop;

class TeaManager
{
public:
	int Add();
	int Search();
	void Show();
	void Edit();
	int Delete();
	void Save();
	void Read();
};
int TeaManager::Add()
{
	Teacher t;
	int i,p=0;
	long long int nu;
	if (Teatop == MAX)
	{
		cout << "人数已满" << endl;
		getchar();
		return 0;
	}
	else if (Teatop == 0)
	{
		cout << "库里无任何信息" << endl;
		p = 1;
	}
	if (!p)
	{
		cout << "请输入编号（确认是否已经存在该编号）："; cin >> nu;
	}
	for (i = 0; i < Teatop; i++)
	{
		if (nu == Tea[i].num)
		{
			cout << "已有编号，请重新输入" << endl;
			getchar();
			return 0;
		}
		else
		{
			cout << "编号不重复，请继续" << endl;

		}
	}
	t.Input(); Tea[Teatop] = t; Teatop++;
	cout << "添加成功！" << endl;
	getchar();
	return 1;
}
int TeaManager::Search()
{
	int j,i,p,q;
	char chaxun_name[20];
	long long int  n;
	cout << "1.按照编号查询。" << endl;
	cout << "2.按照姓名查询。" << endl;
	cin >> i;
	switch (i)
	   { 
		case 1 :
			cout << "请输入编号："; cin >> n;
			for (j = 0; j < Teatop; j++)
			{
				if (n == Tea[j].num) break;
			}
			if (j == Teatop)
				cout << "没有此人！" << endl;
			else
				Tea[j].Output();
			getchar();
			return 0;

		case 2 :
			q = 0;
			p = 0;
			cout << "请输入姓名："; cin >> chaxun_name;
			for (j = 0; j < Teatop; j++)
			{
				if (strcmp(chaxun_name , Tea[j].name)==0)
				{
					Tea[j].Output();
					cout << endl;
					p = j + 1;
					q++;
				}
			}
			if (q==0)
				cout << "没有此人！" << endl;
			getchar();
			return 0;
		}
	return 1;
	
}
void TeaManager::Show()
{
	int i;
	if (Teatop == 0)
	{
		cout << "记录为空！" << endl;
		getchar();
		return; 
	}
	for (i = 0; i < Teatop; i++)
		Tea[i].Output();
        getchar();
}
void TeaManager::Edit()
{
	Teacher t1;
	int j,i;
	long long int n;
	cout << "请输入要编辑的人的编号："; cin >> n;
	for (j = 0; j < Teatop; j++)
	{
		if (n == Tea[j].num) break;
	}
	if (j == Teatop)
	{
		cout << "没有此人！" << endl;
		getchar();
		return;
	};
	cout << "输入修改后的信息，编号不能改:" << endl;
	t1.Input();
	Tea[j] = t1;
	cout << "编辑成功！" << endl;
	getchar();
}
int TeaManager::Delete()
{
	int j,p;
	long long int n;
	if (Teatop == 0)
	{
		cout << "库里无任何信息" << endl;
		p = 1;
		getchar();
		return 0;
	}
	else
	{
		cout << "请输入要删除的人的编号："; cin >> n;
	}
	for (j = 0; j < Teatop; j++)
	{
		if (n == Tea[j].num) break;
	}
	if (j == Teatop)
	{
		cout << "没有此人！" << endl;
		getchar();
		return 0;
	};
	for (j; j < Teatop; j++)
	{
		Tea[j] = Tea[j + 1];
	}
	Teatop--;
	cout << "删除成功！" << endl;
	getchar();
	return 1;
}
void TeaManager::Save()
{
	int i;
	ofstream outfile, outfile1;
	outfile1.open("Teatop.bat", ios::out);//一共有多少个教师
	outfile1 << Teatop;
	outfile.open("Tea_data.bat", ios::binary);
	if (!outfile)
	{
		cerr << "打开失败!" << endl;
		getchar();
		return;
	}
	for (i = 0; i < Teatop; i++)
		outfile.write((char*)&Tea[i], sizeof(Tea[i]));
	getchar();
	outfile.close();
	outfile1.close();
	cout << "保存成功！" << endl;

}
void TeaManager::Read()
{
	int i;
	ifstream infile, infile1;
	infile1.open("Teatop.bat", ios::in);
	infile1 >> Teatop;
	infile.open("Tea_data.bat", ios::binary);
	if (!infile)
	{
		cerr << "open error!" << endl;
		getchar();
		return;
	}
	for (i = 0; i < Teatop; i++)
		infile.read((char*)&Tea[i], sizeof(Tea[i]));
	getchar();
	infile.close();
	cout << "读取成功！" << endl;
	
}
void Tea_mune(TeaManager TM)
{
	int b;
	char c;
	do {
		cout << "教师管理" << endl;
		cout << "==========================================================================================" << endl;
		cout << "| 1.添加    ";
		cout << "2.查询    ";
		cout << "3.显示    ";
		cout << "4.编辑    ";
		cout << "5.删除    ";
		cout << "6.保存    ";
		cout << "7.读取    ";
		cout << "0.退出 |" << endl;
		cout << "==========================================================================================" << endl;
		cout << "请选择："; cin >> b;
		switch (b)
		{
		case 1:TM.Add(); break;
		case 2:TM.Search(); break;
		case 3:TM.Show(); break;
		case 4:TM.Edit(); break;
		case 5:TM.Delete(); break;
		case 6:TM.Save(); break;
		case 7:TM.Read(); break;
		default:cout << "\n error" << endl; break;
		case 0:break;
		}
		cout << "按回车键继续" << endl;
		c = getchar();
		system("cls");
	} while (b != 0);
}

class Tester :virtual public person
{
public:
	char testroom[10];
	char post[10];
	void Input()
	{
		cout << "请输入编号:"; cin >> num;
		cout << "请输入姓名:"; cin >> name;
		cout << "请输入性别:"; cin >> sex;
		cout << "请输入年龄:"; cin >> age;
		cout << "请输入实验室:"; cin >> testroom;
		cout << "请输入职务:"; cin >> post;
	}
	void Output()
	{
		cout << "编号: " << num << "  " << "姓名: " << name << "  " << "性别: " << sex << "  " << "年龄: " << age <<"  " << "所在实验室: " << testroom << "  " << "职务: " << post << endl;
	}

};
Tester Test[MAX];
static int Testop;
class TestManager
{
public:
	int Add();
	int Search();
	void Show();
	void Edit();
	int Delete();
	void Save();
	void Read();
};
int TestManager::Add()
{
	Tester t;
	int i,p=0;
	long long int nu;
	if (Testop == MAX)
	{
		cout << "人数已满" << endl;
		getchar();
		return 0;
	}
	else if (Testop == 0)
	{
		p = 1;
		cout << "库里无任何信息" << endl;
		getchar();

	}
	if (!p) 
	{
		cout << "请输入编号（确认是否已经存在该编号）：";
		cin >> nu;
	}
	for (i = 0; i < Testop; i++)
	{
		if (nu == Test[i].num)
		{
			cout << "已有编号，请重新输入" << endl;
			getchar();
			return 0;
		}
		else
		{
			cout << "编号不重复，请继续" << endl;
		}
	}
	t.Input();Test[Testop] = t;
	Testop++;
	cout << "添加成功！" << endl;
	getchar();
	return 1;
}
int TestManager::Search()
{
	int j,i,p,q;
	char chaxun_name[20];
	long long int  n;
	cout << "1.按照编号查询。" << endl;
	cout << "2.按照姓名查询。" << endl;
	cin >> i;
	switch (i)
	   { 
		case 1 :
		cout << "请输入编号："; cin >> n;
		for (j = 0; j < Testop; j++)
		{
			if (n == Test[j].num) break;
		}
		if (j == Testop)
			cout << "没有此人！" << endl;
		else
			Test[j].Output();
		getchar();
		return 0;

		case 2 :
		
			q = 0;
			p = 0;
			cout << "请输入姓名："; cin >> chaxun_name;
			for (j = 0; j < Testop; j++)
			{
				if (strcmp(chaxun_name, Test[j].name) == 0)
				{
					Test[j].Output();
					cout << endl;
					p = j + 1;
					q++;
				}
			}
			if (q == 0)
				cout << "没有此人！" << endl;
			getchar();
			return 0;
		}


}
void TestManager::Show()
{
	int i;
	if (Testop == 0)
	{
		cout << "记录为空！" << endl; 
		getchar();
		return;
	}
	for (i = 0; i < Testop; i++)
		Test[i].Output();
	getchar();
}
void TestManager::Edit()
{
	Tester t1;
	int j;
	long long int n;
	cout << "请输入要编辑的人的编号："; cin >> n;
	for (j = 0; j < Testop; j++)
	{
		if (n == Test[j].num) break;
	}
	if (j == Testop)
	{
		cout << "没有此人！" << endl; 
		getchar();
		return;
	};
	cout << "输入修改后的信息，编号不能改:" << endl;
	t1.Input();
	Test[j] = t1;
	cout << "编辑成功！" << endl;
	getchar();
}
int TestManager::Delete()
{
	int j,p;
	long long int n;
	if (Testop == 0)
	{
		p = 1;
		cout << "库里无任何信息" << endl;
		getchar();
		return 0;
	}
	else
	{
		cout << "请输入要删除的人的编号："; cin >> n;
	}
	for (j = 0; j < Testop; j++)
	{
		if (n == Test[j].num) break;
	}
	if (j == Testop)
	{
		cout << "没有此人！" << endl; 
		getchar();
		return 0;
	};
	for (j; j < Testop; j++)
	{
		Test[j] = Test[j + 1];
	}
	Testop--;
	cout << "删除成功！" << endl;
	getchar();
	return 1;
}
void TestManager::Save()
{
	int i;
	ofstream outfile, outfile1;
	outfile1.open("Testop.bat", ios::out);
	outfile1 << Testop;
	outfile.open("Test_data.bat", ios::binary);
	if (!outfile)
	{
		cerr << "open error!" << endl;
		getchar();
		return;
	}
	for (i = 0; i < Testop; i++)
		outfile.write((char*)&Test[i], sizeof(Test[i]));
	outfile.close();
	cout << "保存成功！" << endl;
	getchar();
}
void TestManager::Read()
{
	int i;
	ifstream infile, infile1;
	infile1.open("Testop.bat", ios::in);
	infile1 >> Testop;
	infile.open("Test_data.bat", ios::binary);
	if (!infile)
	{
		cerr << "open error!" << endl;
		getchar();
		return;
	}
	for (i = 0; i < Testop; i++)
		infile.read((char*)&Test[i], sizeof(Test[i]));
	infile.close();
	cout << "读取成功！" << endl;
	getchar();
}
void Test_mune(TestManager TM)
{
	int b;
	char c;
	do {
		cout << "实验人员管理" << endl;
		cout << "==========================================================================================" << endl;
		cout << "| 1.添加    ";
		cout << "2.查询    ";
		cout << "3.显示    ";
		cout << "4.编辑    ";
		cout << "5.删除    ";
		cout << "6.保存    ";
		cout << "7.读取    ";
		cout << "0.退出 |" << endl;
		cout << "==========================================================================================" << endl;
		cout << "请选择："; cin >> b;
		switch (b)
		{
		case 1:TM.Add(); break;
		case 2:TM.Search(); break;
		case 3:TM.Show(); break;
		case 4:TM.Edit(); break;
		case 5:TM.Delete(); break;
		case 6:TM.Save(); break;
		case 7:TM.Read(); break;
		default:cout << "\n error" << endl; break;
		case 0:break;
		}
		cout << "按回车键继续" << endl;
		c = getchar();
		system("cls");
	} while (b != 0);
}

class Policer :virtual public person
{
public:
	char office[10];
	char post1[10];
	void Input()
	{
		cout << "请输入编号:"; cin >> num;
		cout << "请输入姓名:"; cin >> name;
		cout << "请输入性别:"; cin >> sex;
		cout << "请输入年龄:"; cin >> age;
		cout << "请输入所在办公室:"; cin >> office;
		cout << "请输入职称:"; cin >> post1;
	}
	void Output()
	{
		cout << "编号: " << num << "  " << "姓名: " << name << "  " << "性别: " << sex << "  " << "年龄: " << age <<
			"  " << "所在办公室: " << office << "  " << "职称: " << post1 << endl;
	}

};
Policer Policers[MAX];
static int Policersop;
class PolicerManager
{
public:
	int Add();
	int Search();
	void Show();
	void Edit();
	int Delete();
	void Save();
	void Read();
};
int PolicerManager::Add()
{
	
	Policer t;
	int i, p = 0;
	long long int nu;
	if (Policersop == MAX)
	{
		cout << "人数已满" << endl;
		getchar();
		return 0;
	}
	else if (Policersop == 0)
	{
		cout << "库里无任何信息" << endl;
		p = 1;
	}
	if (!p)
	{
		cout << "请输入编号（确认是否已经存在该编号）："; cin >> nu;
	}
	for (i = 0; i < Policersop; i++)
	{
		if (nu == Policers[i].num)
		{
			cout << "已有编号，请重新输入" << endl;
			getchar();
			return 0;
		}
		else
		{
			cout << "编号不重复，请继续" << endl;
		}
	}
	t.Input();
	Policers[Policersop] = t;
	Policersop++;
	cout << "添加成功！" << endl;
	getchar();
	return 1;
}
int PolicerManager::Search()
{
	int j, i,q,p;
	char chaxun_name[20];
	long long int  n;
	cout << "1.按照编号查询。" << endl;
	cout << "2.按照姓名查询。" << endl;
	cin >> i;
	switch (i)
	{
	case 1:
		cout << "请输入编号："; cin >> n;
		for (j = 0; j < Policersop; j++)
		{
			if (n == Policers[j].num) break;
		}
		if (j == Policersop)
			cout << "没有此人！" << endl;
		else
			Policers[j].Output();
		getchar();
		return 1;

	case 2:
		q = 0;
		p = 0;
		cout << "请输入姓名："; cin >> chaxun_name;
		for (j = 0; j < Policersop; j++)
		{
			if (strcmp(chaxun_name, Policers[j].name) == 0)
			{
				Policers[j].Output();
				cout << endl;
				p = j + 1;
				q++;
			}
		}
		if (q == 0)
			cout << "没有此人！" << endl;
		getchar();
		return 1;
	}

}
void PolicerManager::Show()
{
	int i;
	if (Policersop == 0)
	{
		cout << "记录为空！" << endl;
		getchar();
		return;
	}
	for (i = 0; i < Policersop; i++)
		Policers[i].Output();
	getchar();
}
void PolicerManager::Edit()
{
	Policer t1;
	int j;
	long long int n;
	cout << "请输入要编辑的人的编号："; cin >> n;
	for (j = 0; j < Policersop; j++)
	{
		if (n == Policers[j].num) break;
	}
	if (j == Policersop)
	{
		cout << "没有此人！" << endl;
		getchar();
		return;
	};
	cout << "输入修改后的信息，编号不能改:" << endl;
	t1.Input();
	Policers[j] = t1;
	cout << "编辑成功！" << endl;
	getchar();
}
int PolicerManager::Delete()
{
	int j,p;
	long long int n;
	if (Policersop == 0)
	{
		cout << "库里无任何信息" << endl;
		p = 1;
		getchar();
		return 0;
	}
	else
	{
		cout << "请输入要删除的人的编号：";
		cin >> n;
	}
	for (j = 0; j < Policersop; j++)
	{
		if (n == Policers[j].num) break;
	}
	if (j == Policersop)
	{
		cout << "没有此人！" << endl;
		getchar();
		return 0;
	};
	for (j; j < Policersop; j++)
	{
		Policers[j] = Policers[j + 1];
	}
	Policersop--;
	cout << "删除成功！" << endl;
	getchar();
	return 1;
}
void PolicerManager::Save()
{
	int i;
	ofstream outfile, outfile1;
	outfile1.open("Policersop.txt", ios::out);
	outfile1 << Policersop;
	outfile.open("Policers_data.txt", ios::binary);
	if (!outfile)
	{
		cerr << "open error!" << endl;
		getchar();
		return;
	}
	for (i = 0; i < Policersop; i++)
		outfile.write((char*)&Policers[i], sizeof(Policers[i]));
	getchar();
	outfile.close();
	cout << "保存成功！" << endl;
}
void PolicerManager::Read()
{
	int i;
	ifstream infile, infile1;
	infile1.open("Policersop.txt", ios::in);
	infile1 >> Policersop;
	infile.open("Policers_data.txt", ios::binary);
	if (!infile)
	{
		cerr << "open error!" << endl;
		getchar();
		return;
	}
	for (i = 0; i < Policersop; i++)
		infile.read((char*)&Policers[i], sizeof(Policers[i]));
	getchar();
	infile.close();
	cout << "读取成功！" << endl;
}
void Policers_mune(PolicerManager TM)
{
	int b;
	char c;
	do {
		cout << "行政人员管理" << endl;
		cout << "==========================================================================================" << endl;
		cout << "| 1.添加    ";
		cout << "2.查询    ";
		cout << "3.显示    ";
		cout << "4.编辑    ";
		cout << "5.删除    ";
		cout << "6.保存    ";
		cout << "7.读取    ";
		cout << "0.退出 |" << endl;
		cout << "==========================================================================================" << endl;
		cout << "请选择："; cin >> b;
		switch (b)
		{
		case 1:TM.Add(); break;
		case 2:TM.Search(); break;
		case 3:TM.Show(); break;
		case 4:TM.Edit(); break;
		case 5:TM.Delete(); break;
		case 6:TM.Save(); break;
		case 7:TM.Read(); break;
		default:cout << "\n error" << endl; break;
		case 0:break;
		}
		cout << "按回车键继续" << endl;
	
		c = getchar();
		system("cls");
	} while (b != 0);
}



class Policer_Teacher :virtual public Policer, virtual public Teacher
{
public:
	char office[10];
	char post1[10];
	void Input()
	{
		cout << "请输入编号:"; cin >> num;
		cout << "请输入姓名:"; cin >> name;
		cout << "请输入性别:"; cin >> sex;
		cout << "请输入年龄:"; cin >> age;
		cout << "请输入所在系:"; cin >> dept;
		cout << "请输入专业:"; cin >> special;
		cout << "请输入职称:"; cin >> title;
		cout << "请输入所在办公室:"; cin >> office;
		cout << "请输入职务:"; cin >> post1;
	}
	void Output()
	{
		cout << "编号: " << num << "  " << "姓名: " << name << "  " << "性别: " << sex << "  " << "年龄: " << age <<
			"  " << "所在系: " << dept << "  " << "专业: " << special << "  " << "职称: " << title <<  "所在办公室: " << office << "  " << "职务: " << post1 << endl;
	}

};
Policer_Teacher Policer_Teachers[MAX];
static int Policer_Teachersop;
class Policer_TeacherManager
{
public:
	int Add();
	int Search();
	void Show();
	void Edit();
	int Delete();
	void Save();
	void Read();
};
int Policer_TeacherManager::Add()
{

	Policer_Teacher t;
	int i, p = 0;
	long long int nu;
	if (Policer_Teachersop == MAX)
	{
		cout << "人数已满" << endl;
		getchar();
		return 0;
	}
	else if (Policer_Teachersop == 0)
	{
		cout << "库里无任何信息" << endl;
		p = 1;
	}
	if (!p)
	{
		cout << "请输入编号（确认是否已经存在该编号）："; cin >> nu;
	}
	for (i = 0; i < Policer_Teachersop; i++)
	{
		if (nu == Policer_Teachers[i].num)
		{
			cout << "已有编号，请重新输入" << endl;
			getchar();
			return 0;
		}
		else
		{
			cout << "编号不重复，请继续" << endl;
		}
	}
	t.Input();
	Policer_Teachers[Policer_Teachersop] = t;
	Policer_Teachersop++;
	cout << "添加成功！" << endl;
	getchar();
	return 1;
}
int Policer_TeacherManager::Search()
{
	int j, i,p,q;
	char chaxun_name[20];
	long long int  n;
	cout << "1.按照编号查询。" << endl;
	cout << "2.按照姓名查询。" << endl;
	cin >> i;
	switch (i)
	{
	case 1:
		cout << "请输入编号："; cin >> n;
		for (j = 0; j < Policer_Teachersop; j++)
		{
			if (n == Policer_Teachers[j].num) break;
		}
		if (j == Policer_Teachersop)
			cout << "没有此人！" << endl;
		else
			Policer_Teachers[j].Output();
		getchar();
		return 1;

	case 2:
		q = 0;
		p = 0;
		cout << "请输入姓名："; cin >> chaxun_name;
		for (j = 0; j < Policer_Teachersop; j++)
		{
			if (strcmp(chaxun_name, Policer_Teachers[j].name) == 0)
			{
				Policer_Teachers[j].Output();
				cout << endl;
				p = j + 1;
				q++;
			}
		}
		if (q == 0)
			cout << "没有此人！" << endl;
		getchar();
		return 1;
	}

}
void Policer_TeacherManager::Show()
{
	int i;
	if (Policer_Teachersop == 0)
	{
		cout << "记录为空！" << endl;
		getchar();
		return;
	}
	for (i = 0; i < Policer_Teachersop; i++)
		Policer_Teachers[i].Output();
	getchar();
}
void Policer_TeacherManager::Edit()
{
	Policer_Teacher t1;
	int j;
	long long int n;
	cout << "请输入要编辑的人的编号："; cin >> n;
	for (j = 0; j < Policer_Teachersop; j++)
	{
		if (n == Policer_Teachers[j].num) break;
	}
	if (j == Policer_Teachersop)
	{
		cout << "没有此人！" << endl;
		getchar();
		return;
	};
	cout << "输入修改后的信息，编号不能改:" << endl;
	t1.Input();
	Policer_Teachers[j] = t1;
	cout << "编辑成功！" << endl;
	getchar();
}
int Policer_TeacherManager::Delete()
{
	int j;
	long long int n;
	cout << "请输入要删除的人的编号："; cin >> n;
	for (j = 0; j < Policer_Teachersop; j++)
	{
		if (n == Policer_Teachers[j].num) break;
	}
	if (j == Policer_Teachersop)
	{
		cout << "没有此人！" << endl;
		getchar();
		return 0;
	};
	for (j; j < Policer_Teachersop; j++)
	{
		Policer_Teachers[j] = Policer_Teachers[j + 1];
	}
	Policer_Teachersop--;
	cout << "删除成功！" << endl;
	getchar();
	return 1;
}
void Policer_TeacherManager::Save()
{
	int i;
	ofstream outfile, outfile1;
	outfile1.open("Policer_Teachersop.bat", ios::out);
	outfile1 << Policer_Teachersop;
	outfile.open("Policer_Teachers_data.bat", ios::binary);
	if (!outfile)
	{
		cerr << "open error!" << endl; 
		getchar();
		return;
	}
	for (i = 0; i < Policer_Teachersop; i++)
		outfile.write((char*)&Policer_Teachers[i], sizeof(Policer_Teachers[i]));
	getchar();
	outfile.close();
	cout << "保存成功！" << endl;
}
void Policer_TeacherManager::Read()
{
	int i;
	ifstream infile, infile1;
	infile1.open("Policer_Teachersop.bat", ios::in);
	infile1 >> Policer_Teachersop;
	infile.open("Policer_Teachers_data.bat", ios::binary);
	if (!infile)
	{
		cerr << "open error!" << endl;
		getchar();
		return;
	}
	for (i = 0; i < Policer_Teachersop; i++)
		infile.read((char*)&Policer_Teachers[i], sizeof(Policer_Teachers[i]));
	getchar();
	infile.close();
	cout << "读取成功！" << endl;
}
void Policer_Teachers_mune(Policer_TeacherManager TM)
{
	int b;
	char c;
	do {
		cout << "行政人员管理" << endl;
		cout << "==========================================================================================" << endl;
		cout << "| 1.添加    ";
		cout << "2.查询    ";
		cout << "3.显示    ";
		cout << "4.编辑    ";
		cout << "5.删除    ";
		cout << "6.保存    ";
		cout << "7.读取    ";
		cout << "0.退出 |" << endl;
		cout << "==========================================================================================" << endl;
		cout << "请选择："; cin >> b;
		switch (b)
		{
		case 1:TM.Add(); break;
		case 2:TM.Search(); break;
		case 3:TM.Show(); break;
		case 4:TM.Edit(); break;
		case 5:TM.Delete(); break;
		case 6:TM.Save(); break;
		case 7:TM.Read(); break;
		default:cout << "\n error" << endl; break;
		case 0:break;
		}
		cout << "按回车键继续" << endl;
		c = getchar();
		system("cls");
	} while (b != 0);
}


void man_count(TeaManager &Tmer1,TestManager &Tetmer,PolicerManager &Polimer, Policer_TeacherManager &Policer_Teachmer)//统计男
{
	int sum_nan=0;
	int  j;
	char man[4] ="男";

	for (j = 0; j < Teatop; j++)
	{
		if (strcmp(Tea[j].sex,man) == 0)
			sum_nan++;

	}
	for (j = 0; j < Testop; j++)
	{
		if (strcmp(Test[j].sex,man) == 0)
			sum_nan++;

	}
	for (j = 0; j < Policersop; j++)
	{
		if (strcmp(Policers[j].sex,man) == 0)
			sum_nan++;
	}
	for (j = 0; j < Policer_Teachersop; j++)
	{
		if (strcmp(man, Policer_Teachers[j].sex) == 0)
			sum_nan++;

	}
	cout << "男员工有" << sum_nan << "人" << endl;
	getchar();
}
void woman_count(TeaManager Tmer1, TestManager Tetmer, PolicerManager Polimer, Policer_TeacherManager Policer_Teachmer)//统计女
{
	int  sum_nv = 0;
	int  j;
	char woman[] = "女";

	for (j = 0; j < Teatop; j++)
	{

		if (strcmp(woman, Tea[j].sex) == 0)
			sum_nv++;
	}
	for (j = 0; j < Testop; j++)
	{

		if (strcmp(woman, Test[j].sex) == 0)
			sum_nv++;
	}
	for (j = 0; j < Policersop; j++)
	{
		if (strcmp(woman, Policers[j].sex) == 0)
			sum_nv++;
	}
	for (j = 0; j < Policer_Teachersop; j++)
	{
		if (strcmp(woman, Policer_Teachers[j].sex) == 0)
			sum_nv++;
	}
	cout << "女员工有" << sum_nv <<"人" << endl;
	getchar();
}


int main()
{
	TeaManager Tmer1;
	TestManager Tetmer;
	PolicerManager Polimer;
	Policer_TeacherManager Policer_Teachmer;
	int a = 1, m = 0, b = 1;
	char c;
	int q = 1;
	do
	{
		int a = 1, m = 0, b = 1;
		system("cls");
		cout << "    ---------------------------------" << endl;
		cout << "    |       高校人员管理系统        |" << endl;
		cout << "    ---------------------------------" << endl;
		cout << "  ****欢迎使用高校人员信息管理系统****" << endl;
		cout << "    =================================" << endl;
		cout << "    | 1.人员信息管理                |" << endl;
		cout << "    | 2.全校人员信息概况统计        |" << endl;
		cout << "    | 0.退出                        |" << endl;
		cout << "    =================================" << endl;
		cout << "请选择：" << endl;
		cin >> q;
		getchar();
		switch (q)
		{
		case 1:
			while (a)
			{
				system("cls");
				cout << endl;
				cout << "              ****欢迎使用高校人员信息管理系统****" << endl;
				cout << "               =================================" << endl;
				cout << "               | 1.教师管理                    |" << endl;
				cout << "               | 2.实验员管理                  |" << endl;
				cout << "               | 3.行政员管理                  |" << endl;
				cout << "               | 4.教师兼行政人员管理          |" << endl;
				cout << "               | 0.退出                        |" << endl;
				cout << "               =================================" << endl;
				cout << "请选择:"; cin >> a;
				switch (a)
				{
					system("cls");
				case 1:Tea_mune(Tmer1); break;
				case 2:Test_mune(Tetmer); break;
				case 3:Policers_mune(Polimer); break;
				case 4:Policer_Teachers_mune(Policer_Teachmer); break;
				case 0:break;
				default:cout << "\n error" << endl;
					cout << "按回车键继续" << endl;
					c = getchar();
					system("cls");
					break;
				}

			}break;
		case 2:
			while (b)
			{
				system("cls");
				cout << "高校人员信息概况统计" << endl;
				cout << "============================================================================================================" << endl;
				cout << "| 1.高校总人员统计 ";
				cout << "2.教师数量 ";
				cout << "3.实验员数量 ";
				cout << "4.行政人员数量 ";
				cout << "5.教师兼行政人员数量 ";
				cout << "6.男员工数量 ";
				cout << "7.女员工数量 ";
				cout << "0.退出 |" << endl;
				cout << "============================================================================================================" << endl;
				cout << "请选择：";
				cin >> b;
				char c;
				switch (b)
				{
				case 1:cout << "高校总人数为：" << Teatop + Testop + Policersop + Policer_Teachersop << endl; getchar(); break;
				case 2:cout << "教师总人数为：" << Teatop << endl; getchar(); break;
				case 3:cout << "实验员总人数为：" << Testop << endl; getchar(); break;
				case 4:cout << "行政人员总人数为：" << Policersop << endl; getchar(); break;
				case 5:cout << "教师兼行政人员总人数为：" << Policer_Teachersop << endl; getchar(); break;
				case 6:man_count(Tmer1, Tetmer, Polimer, Policer_Teachmer); break;
				case 7:woman_count(Tmer1, Tetmer, Polimer, Policer_Teachmer);  break;
				default:cout << "\n error" << endl; break;
				case 0:break;
				}
				cout << "按回车键继续" << endl;
				c = getchar();
				system("cls");
			}break;
		case 0:break;
		default:cout << "\n error" << endl;
			cout << "按回车键继续" << endl;
			c = getchar();
		}
	
	}
while (q != 0);
	cout << endl << "谢谢使用" << endl;

	c = getchar();
	return 0;
}

