#include <iostream>
using namespace std;

void myGetString(char str[], int n);
int myStrlen(char str[]);

int main()
{
	char str[128] = "";

	//键盘获取字符串
	myGetString(str, sizeof(str));

	//测量字符串长度
	cout<<"长度："<<myStrlen(str)<<endl;
}

void myGetString(char str[], int n)
{
	cout<<"请输入一个字符串：";
	cin.getline(str, n);
}

int myStrlen(char str[])
{
	int i = 0;
	while (str[i] != '\0') {
		i++;
	}
	return i;
}