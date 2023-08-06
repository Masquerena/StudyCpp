#include "MockString.h"

void MockStringTest1()
{
	MockString::string s1("hello");
	cout << s1.c_str() << endl;

	//size()��������
	cout << "size()��������:" << s1.size() << endl;

	//�����[]���غ�������
	cout << "�����[]���غ�������:";
	for (size_t i = 0; i < s1.size(); ++i)
	{
		cout << ++s1[i];
	}
	cout << endl;
}

void MockStringTest2()
{
	MockString::string s1("hello");
	/*iterator����������*/
	MockString::string::iterator it1 = s1.begin();
	while (it1 != s1.end())
	{
		(*it1)--;
		++it1;
	}
	cout << "iterator����������:" << s1.c_str() << endl;

	/*����iterator�������ķ�Χfor����*/
	cout << "����iterator�������ķ�Χfor����:";
	for (auto& ch : s1)
	{
		cout << ++ch;
	}
	cout << endl;

	/*push_back�뵥�ַ����������+=���ز���*/
	MockString::string s2;
	s2.push_back('s');
	s2.push_back('t');
	s2 += 'i';
	s2 += 'n';
	s2 += 'g';
	cout << "push_back�������+=���ز���:" << s2.c_str() << endl;

	s2 += "hello";
	cout << s2.c_str() << endl;
	s2.clear();
	cout << s2.c_str() << endl;
}

void MockStringTest3()//���캯������
{
	MockString::string s1("hello string");
	MockString::string s2(s1);
	MockString::string s3 = "h";
	cout << s2.c_str() << endl;
	cout << s3.c_str() << endl;
}

void MockStringTest4()//resize������������
{
	MockString::string s1;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	cout << s1.empty() << endl;

	s1.resize(5, 'b');
	//cout << s1 << endl;
	cout << s1.c_str() << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

	s1.resize(20, 'a');
	//cout << s1 << endl;
	cout << s1.c_str() << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

}

void MockStringTest5()//��=����������ز���
{
	MockString::string s1;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

	s1 = "hel";
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	//cout << s1 << endl;
	cout << s1.c_str() << endl;

	MockString::string s2("hello");	
	cout << s2 << endl;
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;

	s2 = s1;
	cout << s2 << endl;
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;

}

void MockStringTest6()//�����ж����������
{
	MockString::string s1;
	MockString::string s2;

	cout << (s1 < s2) << endl;
	cout << (s1 <= s2) << endl;
	cout << (s1 > s2) << endl;
	cout << (s1 >= s2) << endl;
	cout << (s1 == s2) << endl;
	cout << (s1 != s2) << endl;
}

void MockStringTest7()
{
	MockString::string s1("hello");
	cout << s1.find('o', 2) << endl;
	cout << s1.find("ll") << endl;
	cout << s1.find("llo") << endl;
	cout << s1.find("h") << endl;
	cout << s1.find("abc") << endl;
	cout << s1.find("") << endl;

	//MockString::string s2;
	//cout << s2.find("hhh") << endl;
	//cout << s2.find("") << endl;
}

void MockStringTest8()//���ַ��������
{
	MockString::string s1("hello");
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

	s1.insert(3, 'c');
	cout << s1.c_str() << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

	MockString::string s2;
	s2.insert(0, 'c');
	cout << s2.c_str() << endl;
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;
}

void MockStringTest9()//�ַ����������
{
	MockString::string s1("hello");
	s1.insert(5, " string");
	cout << s1.c_str() << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

	MockString::string s2;
	s2.insert(0, "hello");
	cout << s2.c_str() << endl;
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;
}

void MockStringTest10()//ɾ���ַ���������
{
	MockString::string s1("hello");
	s1.erase(0, 10);
	cout << s1.c_str() << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
}

void MockStringTest11()//����ȡ�����������
{
	MockString::string s1;

	cin >> s1;
	cout << s1 << endl;
}

void MockStringTest12()
{
	MockString::string s1("he");
	MockString::string s2("hel");
	cout << (s1 < s2) << endl;
}

int main()
{
	/*MockStringTest5();*/
	MockString::string s1 = "1234";
	return 0;
}

