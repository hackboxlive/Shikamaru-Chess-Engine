#include <bits/stdc++.h>
using namespace std;
int main()	{
	//0x101010101010101L, 0x202020202020202L, 0x404040404040404L, 0x808080808080808L,
	//0x1010101010101010L, 0x2020202020202020L, 0x4040404040404040L, 0x8080808080808080L
	string s[] = {"0000","0001","0010","0011","0100","0101","0110","0111","1000"};
	string t="8080808080808080";
	string str="";
	for(int i=0;i<t.length();i++)	{
		str+=s[t[i]-'0'];
	}
	long long v=0;
	for(int i=0;i<str.length();i++)	{
		v*=2;
		v+=(str[i]-'0');
	}
	cout<<v<<endl;
	return 0;
}