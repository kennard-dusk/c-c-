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
		cout << "�������ţ�"; cin >> num;
		cout << "����������:"; cin >> name;
		cout << "�������Ա�:"; cin >> sex;
		cout << "����������:"; cin >> age;
		cout << "����������ϵ:"; cin >> dept;
		cout << "������רҵ:"; cin >> special;
		cout << "������ְ��:"; cin >> title;
	}
	void Output()
	{
		cout << "���: " << num << "  " << "����: " << name << "  " << "�Ա�: " << sex << "  " << "����: " << age << "  " << "����ϵ: " << dept << "  " << "רҵ: " << special << "  " << "ְ��: " << title << endl;
			
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
		cout << "��������" << endl;
		getchar();
		return 0;
	}
	else if (Teatop == 0)
	{
		cout << "�������κ���Ϣ" << endl;
		p = 1;
	}
	if (!p)
	{
		cout << "�������ţ�ȷ���Ƿ��Ѿ����ڸñ�ţ���"; cin >> nu;
	}
	for (i = 0; i < Teatop; i++)
	{
		if (nu == Tea[i].num)
		{
			cout << "���б�ţ�����������" << endl;
			getchar();
			return 0;
		}
		else
		{
			cout << "��Ų��ظ��������" << endl;

		}
	}
	t.Input(); Tea[Teatop] = t; Teatop++;
	cout << "��ӳɹ���" << endl;
	getchar();
	return 1;
}
int TeaManager::Search()
{
	int j,i,p,q;
	char chaxun_name[20];
	long long int  n;
	cout << "1.���ձ�Ų�ѯ��" << endl;
	cout << "2.����������ѯ��" << endl;
	cin >> i;
	switch (i)
	   { 
		case 1 :
			cout << "�������ţ�"; cin >> n;
			for (j = 0; j < Teatop; j++)
			{
				if (n == Tea[j].num) break;
			}
			if (j == Teatop)
				cout << "û�д��ˣ�" << endl;
			else
				Tea[j].Output();
			getchar();
			return 0;

		case 2 :
			q = 0;
			p = 0;
			cout << "������������"; cin >> chaxun_name;
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
				cout << "û�д��ˣ�" << endl;
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
		cout << "��¼Ϊ�գ�" << endl;
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
	cout << "������Ҫ�༭���˵ı�ţ�"; cin >> n;
	for (j = 0; j < Teatop; j++)
	{
		if (n == Tea[j].num) break;
	}
	if (j == Teatop)
	{
		cout << "û�д��ˣ�" << endl;
		getchar();
		return;
	};
	cout << "�����޸ĺ����Ϣ����Ų��ܸ�:" << endl;
	t1.Input();
	Tea[j] = t1;
	cout << "�༭�ɹ���" << endl;
	getchar();
}
int TeaManager::Delete()
{
	int j,p;
	long long int n;
	if (Teatop == 0)
	{
		cout << "�������κ���Ϣ" << endl;
		p = 1;
		getchar();
		return 0;
	}
	else
	{
		cout << "������Ҫɾ�����˵ı�ţ�"; cin >> n;
	}
	for (j = 0; j < Teatop; j++)
	{
		if (n == Tea[j].num) break;
	}
	if (j == Teatop)
	{
		cout << "û�д��ˣ�" << endl;
		getchar();
		return 0;
	};
	for (j; j < Teatop; j++)
	{
		Tea[j] = Tea[j + 1];
	}
	Teatop--;
	cout << "ɾ���ɹ���" << endl;
	getchar();
	return 1;
}
void TeaManager::Save()
{
	int i;
	ofstream outfile, outfile1;
	outfile1.open("Teatop.bat", ios::out);//һ���ж��ٸ���ʦ
	outfile1 << Teatop;
	outfile.open("Tea_data.bat", ios::binary);
	if (!outfile)
	{
		cerr << "��ʧ��!" << endl;
		getchar();
		return;
	}
	for (i = 0; i < Teatop; i++)
		outfile.write((char*)&Tea[i], sizeof(Tea[i]));
	getchar();
	outfile.close();
	outfile1.close();
	cout << "����ɹ���" << endl;

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
	cout << "��ȡ�ɹ���" << endl;
	
}
void Tea_mune(TeaManager TM)
{
	int b;
	char c;
	do {
		cout << "��ʦ����" << endl;
		cout << "==========================================================================================" << endl;
		cout << "| 1.���    ";
		cout << "2.��ѯ    ";
		cout << "3.��ʾ    ";
		cout << "4.�༭    ";
		cout << "5.ɾ��    ";
		cout << "6.����    ";
		cout << "7.��ȡ    ";
		cout << "0.�˳� |" << endl;
		cout << "==========================================================================================" << endl;
		cout << "��ѡ��"; cin >> b;
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
		cout << "���س�������" << endl;
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
		cout << "��������:"; cin >> num;
		cout << "����������:"; cin >> name;
		cout << "�������Ա�:"; cin >> sex;
		cout << "����������:"; cin >> age;
		cout << "������ʵ����:"; cin >> testroom;
		cout << "������ְ��:"; cin >> post;
	}
	void Output()
	{
		cout << "���: " << num << "  " << "����: " << name << "  " << "�Ա�: " << sex << "  " << "����: " << age <<"  " << "����ʵ����: " << testroom << "  " << "ְ��: " << post << endl;
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
		cout << "��������" << endl;
		getchar();
		return 0;
	}
	else if (Testop == 0)
	{
		p = 1;
		cout << "�������κ���Ϣ" << endl;
		getchar();

	}
	if (!p) 
	{
		cout << "�������ţ�ȷ���Ƿ��Ѿ����ڸñ�ţ���";
		cin >> nu;
	}
	for (i = 0; i < Testop; i++)
	{
		if (nu == Test[i].num)
		{
			cout << "���б�ţ�����������" << endl;
			getchar();
			return 0;
		}
		else
		{
			cout << "��Ų��ظ��������" << endl;
		}
	}
	t.Input();Test[Testop] = t;
	Testop++;
	cout << "��ӳɹ���" << endl;
	getchar();
	return 1;
}
int TestManager::Search()
{
	int j,i,p,q;
	char chaxun_name[20];
	long long int  n;
	cout << "1.���ձ�Ų�ѯ��" << endl;
	cout << "2.����������ѯ��" << endl;
	cin >> i;
	switch (i)
	   { 
		case 1 :
		cout << "�������ţ�"; cin >> n;
		for (j = 0; j < Testop; j++)
		{
			if (n == Test[j].num) break;
		}
		if (j == Testop)
			cout << "û�д��ˣ�" << endl;
		else
			Test[j].Output();
		getchar();
		return 0;

		case 2 :
		
			q = 0;
			p = 0;
			cout << "������������"; cin >> chaxun_name;
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
				cout << "û�д��ˣ�" << endl;
			getchar();
			return 0;
		}


}
void TestManager::Show()
{
	int i;
	if (Testop == 0)
	{
		cout << "��¼Ϊ�գ�" << endl; 
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
	cout << "������Ҫ�༭���˵ı�ţ�"; cin >> n;
	for (j = 0; j < Testop; j++)
	{
		if (n == Test[j].num) break;
	}
	if (j == Testop)
	{
		cout << "û�д��ˣ�" << endl; 
		getchar();
		return;
	};
	cout << "�����޸ĺ����Ϣ����Ų��ܸ�:" << endl;
	t1.Input();
	Test[j] = t1;
	cout << "�༭�ɹ���" << endl;
	getchar();
}
int TestManager::Delete()
{
	int j,p;
	long long int n;
	if (Testop == 0)
	{
		p = 1;
		cout << "�������κ���Ϣ" << endl;
		getchar();
		return 0;
	}
	else
	{
		cout << "������Ҫɾ�����˵ı�ţ�"; cin >> n;
	}
	for (j = 0; j < Testop; j++)
	{
		if (n == Test[j].num) break;
	}
	if (j == Testop)
	{
		cout << "û�д��ˣ�" << endl; 
		getchar();
		return 0;
	};
	for (j; j < Testop; j++)
	{
		Test[j] = Test[j + 1];
	}
	Testop--;
	cout << "ɾ���ɹ���" << endl;
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
	cout << "����ɹ���" << endl;
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
	cout << "��ȡ�ɹ���" << endl;
	getchar();
}
void Test_mune(TestManager TM)
{
	int b;
	char c;
	do {
		cout << "ʵ����Ա����" << endl;
		cout << "==========================================================================================" << endl;
		cout << "| 1.���    ";
		cout << "2.��ѯ    ";
		cout << "3.��ʾ    ";
		cout << "4.�༭    ";
		cout << "5.ɾ��    ";
		cout << "6.����    ";
		cout << "7.��ȡ    ";
		cout << "0.�˳� |" << endl;
		cout << "==========================================================================================" << endl;
		cout << "��ѡ��"; cin >> b;
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
		cout << "���س�������" << endl;
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
		cout << "��������:"; cin >> num;
		cout << "����������:"; cin >> name;
		cout << "�������Ա�:"; cin >> sex;
		cout << "����������:"; cin >> age;
		cout << "���������ڰ칫��:"; cin >> office;
		cout << "������ְ��:"; cin >> post1;
	}
	void Output()
	{
		cout << "���: " << num << "  " << "����: " << name << "  " << "�Ա�: " << sex << "  " << "����: " << age <<
			"  " << "���ڰ칫��: " << office << "  " << "ְ��: " << post1 << endl;
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
		cout << "��������" << endl;
		getchar();
		return 0;
	}
	else if (Policersop == 0)
	{
		cout << "�������κ���Ϣ" << endl;
		p = 1;
	}
	if (!p)
	{
		cout << "�������ţ�ȷ���Ƿ��Ѿ����ڸñ�ţ���"; cin >> nu;
	}
	for (i = 0; i < Policersop; i++)
	{
		if (nu == Policers[i].num)
		{
			cout << "���б�ţ�����������" << endl;
			getchar();
			return 0;
		}
		else
		{
			cout << "��Ų��ظ��������" << endl;
		}
	}
	t.Input();
	Policers[Policersop] = t;
	Policersop++;
	cout << "��ӳɹ���" << endl;
	getchar();
	return 1;
}
int PolicerManager::Search()
{
	int j, i,q,p;
	char chaxun_name[20];
	long long int  n;
	cout << "1.���ձ�Ų�ѯ��" << endl;
	cout << "2.����������ѯ��" << endl;
	cin >> i;
	switch (i)
	{
	case 1:
		cout << "�������ţ�"; cin >> n;
		for (j = 0; j < Policersop; j++)
		{
			if (n == Policers[j].num) break;
		}
		if (j == Policersop)
			cout << "û�д��ˣ�" << endl;
		else
			Policers[j].Output();
		getchar();
		return 1;

	case 2:
		q = 0;
		p = 0;
		cout << "������������"; cin >> chaxun_name;
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
			cout << "û�д��ˣ�" << endl;
		getchar();
		return 1;
	}

}
void PolicerManager::Show()
{
	int i;
	if (Policersop == 0)
	{
		cout << "��¼Ϊ�գ�" << endl;
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
	cout << "������Ҫ�༭���˵ı�ţ�"; cin >> n;
	for (j = 0; j < Policersop; j++)
	{
		if (n == Policers[j].num) break;
	}
	if (j == Policersop)
	{
		cout << "û�д��ˣ�" << endl;
		getchar();
		return;
	};
	cout << "�����޸ĺ����Ϣ����Ų��ܸ�:" << endl;
	t1.Input();
	Policers[j] = t1;
	cout << "�༭�ɹ���" << endl;
	getchar();
}
int PolicerManager::Delete()
{
	int j,p;
	long long int n;
	if (Policersop == 0)
	{
		cout << "�������κ���Ϣ" << endl;
		p = 1;
		getchar();
		return 0;
	}
	else
	{
		cout << "������Ҫɾ�����˵ı�ţ�";
		cin >> n;
	}
	for (j = 0; j < Policersop; j++)
	{
		if (n == Policers[j].num) break;
	}
	if (j == Policersop)
	{
		cout << "û�д��ˣ�" << endl;
		getchar();
		return 0;
	};
	for (j; j < Policersop; j++)
	{
		Policers[j] = Policers[j + 1];
	}
	Policersop--;
	cout << "ɾ���ɹ���" << endl;
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
	cout << "����ɹ���" << endl;
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
	cout << "��ȡ�ɹ���" << endl;
}
void Policers_mune(PolicerManager TM)
{
	int b;
	char c;
	do {
		cout << "������Ա����" << endl;
		cout << "==========================================================================================" << endl;
		cout << "| 1.���    ";
		cout << "2.��ѯ    ";
		cout << "3.��ʾ    ";
		cout << "4.�༭    ";
		cout << "5.ɾ��    ";
		cout << "6.����    ";
		cout << "7.��ȡ    ";
		cout << "0.�˳� |" << endl;
		cout << "==========================================================================================" << endl;
		cout << "��ѡ��"; cin >> b;
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
		cout << "���س�������" << endl;
	
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
		cout << "��������:"; cin >> num;
		cout << "����������:"; cin >> name;
		cout << "�������Ա�:"; cin >> sex;
		cout << "����������:"; cin >> age;
		cout << "����������ϵ:"; cin >> dept;
		cout << "������רҵ:"; cin >> special;
		cout << "������ְ��:"; cin >> title;
		cout << "���������ڰ칫��:"; cin >> office;
		cout << "������ְ��:"; cin >> post1;
	}
	void Output()
	{
		cout << "���: " << num << "  " << "����: " << name << "  " << "�Ա�: " << sex << "  " << "����: " << age <<
			"  " << "����ϵ: " << dept << "  " << "רҵ: " << special << "  " << "ְ��: " << title <<  "���ڰ칫��: " << office << "  " << "ְ��: " << post1 << endl;
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
		cout << "��������" << endl;
		getchar();
		return 0;
	}
	else if (Policer_Teachersop == 0)
	{
		cout << "�������κ���Ϣ" << endl;
		p = 1;
	}
	if (!p)
	{
		cout << "�������ţ�ȷ���Ƿ��Ѿ����ڸñ�ţ���"; cin >> nu;
	}
	for (i = 0; i < Policer_Teachersop; i++)
	{
		if (nu == Policer_Teachers[i].num)
		{
			cout << "���б�ţ�����������" << endl;
			getchar();
			return 0;
		}
		else
		{
			cout << "��Ų��ظ��������" << endl;
		}
	}
	t.Input();
	Policer_Teachers[Policer_Teachersop] = t;
	Policer_Teachersop++;
	cout << "��ӳɹ���" << endl;
	getchar();
	return 1;
}
int Policer_TeacherManager::Search()
{
	int j, i,p,q;
	char chaxun_name[20];
	long long int  n;
	cout << "1.���ձ�Ų�ѯ��" << endl;
	cout << "2.����������ѯ��" << endl;
	cin >> i;
	switch (i)
	{
	case 1:
		cout << "�������ţ�"; cin >> n;
		for (j = 0; j < Policer_Teachersop; j++)
		{
			if (n == Policer_Teachers[j].num) break;
		}
		if (j == Policer_Teachersop)
			cout << "û�д��ˣ�" << endl;
		else
			Policer_Teachers[j].Output();
		getchar();
		return 1;

	case 2:
		q = 0;
		p = 0;
		cout << "������������"; cin >> chaxun_name;
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
			cout << "û�д��ˣ�" << endl;
		getchar();
		return 1;
	}

}
void Policer_TeacherManager::Show()
{
	int i;
	if (Policer_Teachersop == 0)
	{
		cout << "��¼Ϊ�գ�" << endl;
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
	cout << "������Ҫ�༭���˵ı�ţ�"; cin >> n;
	for (j = 0; j < Policer_Teachersop; j++)
	{
		if (n == Policer_Teachers[j].num) break;
	}
	if (j == Policer_Teachersop)
	{
		cout << "û�д��ˣ�" << endl;
		getchar();
		return;
	};
	cout << "�����޸ĺ����Ϣ����Ų��ܸ�:" << endl;
	t1.Input();
	Policer_Teachers[j] = t1;
	cout << "�༭�ɹ���" << endl;
	getchar();
}
int Policer_TeacherManager::Delete()
{
	int j;
	long long int n;
	cout << "������Ҫɾ�����˵ı�ţ�"; cin >> n;
	for (j = 0; j < Policer_Teachersop; j++)
	{
		if (n == Policer_Teachers[j].num) break;
	}
	if (j == Policer_Teachersop)
	{
		cout << "û�д��ˣ�" << endl;
		getchar();
		return 0;
	};
	for (j; j < Policer_Teachersop; j++)
	{
		Policer_Teachers[j] = Policer_Teachers[j + 1];
	}
	Policer_Teachersop--;
	cout << "ɾ���ɹ���" << endl;
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
	cout << "����ɹ���" << endl;
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
	cout << "��ȡ�ɹ���" << endl;
}
void Policer_Teachers_mune(Policer_TeacherManager TM)
{
	int b;
	char c;
	do {
		cout << "������Ա����" << endl;
		cout << "==========================================================================================" << endl;
		cout << "| 1.���    ";
		cout << "2.��ѯ    ";
		cout << "3.��ʾ    ";
		cout << "4.�༭    ";
		cout << "5.ɾ��    ";
		cout << "6.����    ";
		cout << "7.��ȡ    ";
		cout << "0.�˳� |" << endl;
		cout << "==========================================================================================" << endl;
		cout << "��ѡ��"; cin >> b;
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
		cout << "���س�������" << endl;
		c = getchar();
		system("cls");
	} while (b != 0);
}


void man_count(TeaManager &Tmer1,TestManager &Tetmer,PolicerManager &Polimer, Policer_TeacherManager &Policer_Teachmer)//ͳ����
{
	int sum_nan=0;
	int  j;
	char man[4] ="��";

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
	cout << "��Ա����" << sum_nan << "��" << endl;
	getchar();
}
void woman_count(TeaManager Tmer1, TestManager Tetmer, PolicerManager Polimer, Policer_TeacherManager Policer_Teachmer)//ͳ��Ů
{
	int  sum_nv = 0;
	int  j;
	char woman[] = "Ů";

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
	cout << "ŮԱ����" << sum_nv <<"��" << endl;
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
		cout << "    |       ��У��Ա����ϵͳ        |" << endl;
		cout << "    ---------------------------------" << endl;
		cout << "  ****��ӭʹ�ø�У��Ա��Ϣ����ϵͳ****" << endl;
		cout << "    =================================" << endl;
		cout << "    | 1.��Ա��Ϣ����                |" << endl;
		cout << "    | 2.ȫУ��Ա��Ϣ�ſ�ͳ��        |" << endl;
		cout << "    | 0.�˳�                        |" << endl;
		cout << "    =================================" << endl;
		cout << "��ѡ��" << endl;
		cin >> q;
		getchar();
		switch (q)
		{
		case 1:
			while (a)
			{
				system("cls");
				cout << endl;
				cout << "              ****��ӭʹ�ø�У��Ա��Ϣ����ϵͳ****" << endl;
				cout << "               =================================" << endl;
				cout << "               | 1.��ʦ����                    |" << endl;
				cout << "               | 2.ʵ��Ա����                  |" << endl;
				cout << "               | 3.����Ա����                  |" << endl;
				cout << "               | 4.��ʦ��������Ա����          |" << endl;
				cout << "               | 0.�˳�                        |" << endl;
				cout << "               =================================" << endl;
				cout << "��ѡ��:"; cin >> a;
				switch (a)
				{
					system("cls");
				case 1:Tea_mune(Tmer1); break;
				case 2:Test_mune(Tetmer); break;
				case 3:Policers_mune(Polimer); break;
				case 4:Policer_Teachers_mune(Policer_Teachmer); break;
				case 0:break;
				default:cout << "\n error" << endl;
					cout << "���س�������" << endl;
					c = getchar();
					system("cls");
					break;
				}

			}break;
		case 2:
			while (b)
			{
				system("cls");
				cout << "��У��Ա��Ϣ�ſ�ͳ��" << endl;
				cout << "============================================================================================================" << endl;
				cout << "| 1.��У����Աͳ�� ";
				cout << "2.��ʦ���� ";
				cout << "3.ʵ��Ա���� ";
				cout << "4.������Ա���� ";
				cout << "5.��ʦ��������Ա���� ";
				cout << "6.��Ա������ ";
				cout << "7.ŮԱ������ ";
				cout << "0.�˳� |" << endl;
				cout << "============================================================================================================" << endl;
				cout << "��ѡ��";
				cin >> b;
				char c;
				switch (b)
				{
				case 1:cout << "��У������Ϊ��" << Teatop + Testop + Policersop + Policer_Teachersop << endl; getchar(); break;
				case 2:cout << "��ʦ������Ϊ��" << Teatop << endl; getchar(); break;
				case 3:cout << "ʵ��Ա������Ϊ��" << Testop << endl; getchar(); break;
				case 4:cout << "������Ա������Ϊ��" << Policersop << endl; getchar(); break;
				case 5:cout << "��ʦ��������Ա������Ϊ��" << Policer_Teachersop << endl; getchar(); break;
				case 6:man_count(Tmer1, Tetmer, Polimer, Policer_Teachmer); break;
				case 7:woman_count(Tmer1, Tetmer, Polimer, Policer_Teachmer);  break;
				default:cout << "\n error" << endl; break;
				case 0:break;
				}
				cout << "���س�������" << endl;
				c = getchar();
				system("cls");
			}break;
		case 0:break;
		default:cout << "\n error" << endl;
			cout << "���س�������" << endl;
			c = getchar();
		}
	
	}
while (q != 0);
	cout << endl << "ллʹ��" << endl;

	c = getchar();
	return 0;
}

