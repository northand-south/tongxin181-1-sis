#define _CRT_SECURE_NO_WARNINGS


#include <iostream> 
#include "tchar.h"
#include <string> 
#include "sqlite3.h"  
#pragma comment(lib,"sqlite3.lib")

#include <Windows.h>
#include <iomanip>
using namespace std;


sqlite3* pDB=NULL;
static bool userValidated = false;

char* U2G(const char* utf8);
char* G2U(const char* gb2312);
char sqlArray[50] = { 0 };

//��ѯ  
bool SelectUser1();
//����  
bool AddUser(const string& sNumber, const string& sName,
			 const string& sAge, const string& sSex, 
			 const string& sBirthDate, const string& sHome,
			 const string& sTelephone, const string& sEmail);

//ɾ��
bool DeleteUser(const string& sNumber);

//�޸�
bool ModifyUser(const string& sNumber, const string& sName, 
				const string& sAge, const string& sSex, 
				const string& sBirthDate, const string& sHome,
				const string& sTelephone, const string& sEmail);

//�鿴
bool SelectUser2();
int _tmain(int argc, _TCHAR* argv[])
{ 
	//��·������utf-8����  
	//���·���а������ģ���Ҫ���б���ת��  
	int nRes = sqlite3_open("StudentsInformationSystem.db", &pDB);
	if (nRes != SQLITE_OK)
	{
		cout << "Open database fail: " << sqlite3_errmsg(pDB);
		//goto QUIT;
		sqlite3_close(pDB);
	}
	else
	{
		system("color A");
		cout << "�����ݿ�ɹ���" << endl;
		cout << "**************************C++����sqlite���ݲ���**************************" << endl;
		cout << "1.��ѯ" << endl;
		cout << "2.���" << endl;
		cout << "3.ɾ��" << endl;
		cout << "4.�޸�" << endl;
		cout << "5.�鿴" << endl;
		cout << "0.�˳�" << endl;
		cout << "**************************C++����sqlite���ݲ���**************************" << endl;
		cout << "��ѡ������Ҫ�Ĳ���" << endl;
	}
	int a;
	char number, name;
	char Number[20];
	char Name[20];
	char Age[20];
	char Sex[20];
	char BirthDate[20];
	char Home[20];
	char Telephone[20];
	char Email[20];
	while (true)
	{
		cin >> a;
		switch (a) {
		case 1:
			cout << endl;
			cout << "��ѡ���˲�ѯ" << endl;
			cout << "1.��ѧ�Ų�ѯ" << endl;
			cout << "2.��������ѯ" << endl;
			SelectUser1();
			cout << "**************************�����ѡ�������/�˳�**************************" << endl;
			cout << "1.��ѯ" << endl;
			cout << "2.���" << endl;
			cout << "3.ɾ��" << endl;
			cout << "4.�޸�" << endl;
			cout << "5.�鿴" << endl;
			cout << "0.�˳�" << endl;
			cout << "**************************C++����sqlite���ݲ���**************************" << endl;
			cout << "��ѡ������Ҫ�Ĳ���" << endl;
			
			break;
		case 2:
			cout << endl;
			cout << "��ѡ�������" << endl;
			cout << "*******************��������Ҫ��ӵ���Ϣ�磺xiaoming,18*******************" << endl;

			//cin >> id;
			cout << "Number:" << endl;
			scanf("%s", &Number);
			cout << "Name:" << endl;
			scanf("%s", &Name);
			cout << "Age:" << endl;
			scanf("%s", &Age);
			if (sizeof(Age) > 3)
			{
				cout << "��������䲻�Ϸ�������������:";
				scanf("%s", &Age);
			}
			cout << "Sex:" << endl;
			scanf("%s", &Sex);
			cout << "BirthDate:" << endl;
			scanf("%s", &BirthDate);
			cout << "Home:" << endl;
			scanf("%s", &Home);
			cout << "Telephone:" << endl;
			scanf("%s", &Telephone);
			cout << "Email:" << endl;
			scanf("%s", &Email);
			//cout <<Number  << Name << endl;
			if (AddUser(Number, Name, Age, Sex, BirthDate, Home, Telephone, Email)) {

				cout << "��ӳɹ���" << endl;
				cout << endl;
				cout << "**************************�����ѡ�������/�˳�**************************" << endl;
				cout << "1.��ѯ" << endl;
				cout << "2.���" << endl;
				cout << "3.ɾ��" << endl;
				cout << "4.�޸�" << endl;
				cout << "5.�鿴" << endl;
				cout << "0.�˳�" << endl;
				cout << "**************************C++����sqlite���ݲ���**************************" << endl;
				cout << "��ѡ������Ҫ�Ĳ���" << endl;
			}
			break;
		case 3:
			cout << "��ѡ����ɾ��" << endl;
			cout << endl;
			cout << "********************��������Ҫɾ������Ϣ�磺xiaoming*********************" << endl;
			//ɾ��  
			cout << "Number:" << endl;
			scanf("%s", &Number);
			if (DeleteUser(Number))
			{
				cout << "��Ϣɾ���ɹ���" << endl;
				cout << endl;
				cout << "**************************�����ѡ�������/�˳�**************************" << endl;
				cout << "1.��ѯ" << endl;
				cout << "2.���" << endl;
				cout << "3.ɾ��" << endl;
				cout << "4.�޸�" << endl;
				cout << "5.�鿴" << endl;
				cout << "0.�˳�" << endl;
				cout << "**************************C++����sqlite���ݲ���**************************" << endl;
				cout << "��ѡ������Ҫ�Ĳ���" << endl;
			}

			break;
		case 4:
			cout << "��ѡ�����޸�" << endl;
			cout << endl;
			cout << "*******************��������Ҫ�޸ĵ���Ϣ�磺xiaoming,18*******************" << endl;
			//cin >> id;
			cout << "Number:" << endl;
			scanf("%s", &Number);
			cout << "Name:" << endl;
			scanf("%s", &Name);
			cout << "Age:" << endl;
			scanf("%s", &Age);
			cout << "Sex:" << endl;
			scanf("%s", &Sex);
			cout << "BirthDate:" << endl;
			scanf("%s", &BirthDate);
			cout << "Home:" << endl;
			scanf("%s", &Home);
			cout << "Telephone:" << endl;
			scanf("%s", &Telephone);
			cout << "Email:" << endl;
			scanf("%s", &Email);
			if (ModifyUser(Number, Name, Age, Sex, BirthDate, Home, Telephone, Email))
			{
				cout << "��Ϣ�޸ĳɹ���" << endl;
				cout << endl;
				cout << "**************************�����ѡ�������/�˳�**************************" << endl;
				cout << "1.��ѯ" << endl;
				cout << "2.���" << endl;
				cout << "3.ɾ��" << endl;
				cout << "4.�޸�" << endl;
				cout << "5.�鿴" << endl;
				cout << "0.�˳�" << endl;
				cout << "**************************C++����sqlite���ݲ���**************************" << endl;
				cout << "��ѡ������Ҫ�Ĳ���" << endl;
			}
			break;
		case 5:
			cout << endl;
			cout << "��ѡ���˲鿴" << endl;
			
			SelectUser2();
			cout << "**************************�����ѡ�������/�˳�**************************" << endl;
			cout << "1.��ѯ" << endl;
			cout << "2.���" << endl;
			cout << "3.ɾ��" << endl;
			cout << "4.�޸�" << endl;
			cout << "5.�鿴" << endl;
			cout << "0.�˳�" << endl;
			cout << "**************************C++����sqlite���ݲ���**************************" << endl;
			cout << endl;
			cout << "��ѡ������Ҫ�Ĳ���" << endl;
			break;
		default:
			cout << endl;
			cout << "��ѡ�����˳�" << endl;
			cout << "goodbye" << endl;
			
			exit(0);
		}
	}
	//���� 
	/*if (!SelectUser())
	{

		goto QUIT;
	}*/
QUIT:
	sqlite3_close(pDB);

	return 0;
}
static int UserResult(void* NotUsed, int argc, char** argv, char** azColName)
{
	cout << "----------------------------------------------------------------------\n";
	for (int i = 0; i < argc; i++)
	{
	    cout << right << setw(10) << azColName[i] << " : " <<left << U2G(argv[i] ? argv[i] : "NULL") << "\t" << endl;
	}
	//sqlite3_free_table(azColName);
	cout << endl;
	cout << "----------------------------------------------------------------------\n";
	cout << endl;
	return 0;
}

static int UserValidate(void* NotUsed,int argc ,char** argv,char**azColName)
{
	
	if (strcmp(argv[0] ,"0")==0)
		userValidated = false;
	else if (strcmp(argv[0], "0") >0)
		userValidated = true;
	else
	{
		userValidated = false;
		cout << "δ֪����\n��������˳����򣡣���" << endl;
		system("pause");
		exit(0);
	}
	return 0;
}

bool SelectUser1()
{
	char* cErrMsg;
	int i;
	int res=0;
	cout<< "��ѡ���ѯ��ʽ" << endl;
	cin >> i;
	if (i ==1)
	{ 
		int m;
		cout << endl;
		cout << "�������ѯ��ѧ�� "<< endl;
		cin >> m;
		
		 //res = sqlite3_exec(pDB, "select * from Student where Number= m;", UserResult, 0, &cErrMsg);

		sprintf(sqlArray, "SELECT COUNT(*) FROM Student WHERE Number=%d", m);
		res = sqlite3_exec(pDB, sqlArray, UserValidate, 0, &cErrMsg);
		if (res !=SQLITE_OK)
		{
			cout << "select fail: " << cErrMsg << endl;
			return false;
		}
		if (userValidated == true)
		{
			sprintf(sqlArray, "select * from Student where Number = %d", m);
			res = sqlite3_exec(pDB, sqlArray, UserResult, 0, &cErrMsg);
			if (res != SQLITE_OK)
			{
				cout << "select fail: " << cErrMsg << endl;
				return false;
			}
		}
		else
		{
			cout << "���������ѧ�Ų�����\n" << endl;
			return false;
		}

		
	}
	else if(i==2)
	{
		string n;
		cout << endl;
		cout << "�������ѯ������" <<endl;
		cin >> n;
		
		sprintf(sqlArray, "SELECT COUNT(*) FROM Student WHERE Name='%s'", n.c_str());
		res = sqlite3_exec(pDB, G2U(sqlArray), UserValidate, 0, &cErrMsg);
		if (res != SQLITE_OK)
		{
			cout << "select fail: " << cErrMsg << endl;
			return false;
		}
		if (userValidated == true)
		{
			sprintf(sqlArray, "select * from Student where Name='%s'", n.c_str());
			res = sqlite3_exec(pDB, G2U(sqlArray), UserResult, 0, &cErrMsg);
			if (res != SQLITE_OK)
			{
				cout << "select fail: " << cErrMsg << endl;
				return false;
			}
			cout << endl;
		}
		else
		{
			cout << "�������������������\n" << endl;
			return false;
		}


	}
	else if (i != 1|| i != 2)
	{
		cout<< endl;
		cout << "��Ч��ѯ����ѡ���Ӧ�Ĳ�ѯ��ţ�" << endl;
		cout << endl;
	}

	

	return true;
}

bool SelectUser2()
{
	char* cErrMsg;
	int res;
	res = sqlite3_exec(pDB, "select * from Student order by Number", UserResult, 0, &cErrMsg);

	return true;
}
//�������
bool AddUser(const string & sNumber, const string & sName, const string& sAge, const string& sSex, const string& sBirthDate, const string& sHome, const string& sTelephone, const string& sEmail)
{
	string strSql = "";
	strSql += "insert into Student(Number,Name,Age,Sex,BirthDate,Home,Telephone,Email)";
	strSql += "values(";
	strSql += sNumber;
	strSql += ",'";
	strSql += G2U(sName.c_str());
	strSql += "',";
	strSql += sAge;
	strSql += ",'";
	strSql += G2U(sSex.c_str());
	strSql += "','";
	strSql += G2U(sBirthDate.c_str());
	strSql += "','";
	strSql += G2U(sHome.c_str());
	strSql += "',";
	strSql += sTelephone;
	strSql += ",'";
	strSql += sEmail;
	strSql += "');";

	char* cErrMsg;
	int nRes = sqlite3_exec(pDB, strSql.c_str(), 0, 0, &cErrMsg);
	if (nRes != SQLITE_OK)
	{
		cout << "add Student fail: " << cErrMsg << endl;
		return false;
	}
	else
	{
		cout << "add Student success: " << endl;
	}

	return true;
}

//ɾ������
bool DeleteUser(const string & sNumber)
{
	string strSql = "";
	strSql += "delete from Student where Number='";
	strSql += sNumber;
	strSql += "';";

	char* cErrMsg;
	int nRes = sqlite3_exec(pDB, strSql.c_str(), 0, 0, &cErrMsg);
	if (nRes != SQLITE_OK)
	{
		cout << "delete Student fail: " << cErrMsg << endl;
		return false;
	}
	else
	{
		cout << "delete Student success: " << sNumber.c_str() << endl;
	}

	return true;
}

//�޸�����
bool ModifyUser(const string & sNumber, const string & sName, const string& sAge, const string& sSex, const string& sBirthDate, const string& sHome, const string& sTelephone, const string& sEmail)
{
	string strSql = "";
	strSql += "update Student set Name =";
	strSql += sName;
	strSql += " where Number='";
	strSql += sNumber;
	strSql += " where Age='";
	strSql += sAge;
	strSql += " where Sex='";
	strSql += sSex;
	strSql += " where BirthDate='";
	strSql += sBirthDate;
	strSql += " where Home='";
	strSql += sHome;
	strSql += " where Telephone='";
	strSql += sTelephone;
	strSql += " where Email='";
	strSql += sEmail;
	strSql += "';";

	char* cErrMsg;
	int nRes = sqlite3_exec(pDB, strSql.c_str(), 0, 0, &cErrMsg);
	if (nRes != SQLITE_OK)
	{
		cout << "modify Student fail: " << cErrMsg << endl;
		return false;
	}
	else
	{
		cout << "modify Student success: " << sName.c_str() << "\t" << sName.c_str() << endl;
	}

	return true;
}
//UTF-8��GB2312��ת��
char* U2G(const char* utf8)
{
	int len = MultiByteToWideChar(CP_UTF8, 0, utf8, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len + 1];
	memset(wstr, 0, len + 1);
	MultiByteToWideChar(CP_UTF8, 0, utf8, -1, wstr, len);
	len = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* str = new char[len + 1];
	memset(str, 0, len + 1);
	WideCharToMultiByte(CP_ACP, 0, wstr, -1, str, len, NULL, NULL);
	if (wstr) delete[] wstr;
	return str;
}
//GB2312��UTF-8��ת��
char* G2U(const char* gb2312)
{
	int len = MultiByteToWideChar(CP_ACP, 0, gb2312, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len + 1];
	memset(wstr, 0, len + 1);
	MultiByteToWideChar(CP_ACP, 0, gb2312, -1, wstr, len);
	len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* str = new char[len + 1];
	memset(str, 0, len + 1);
	WideCharToMultiByte(CP_UTF8, 0, wstr, -1, str, len, NULL, NULL);
	if (wstr) delete[] wstr;
	return str;
}