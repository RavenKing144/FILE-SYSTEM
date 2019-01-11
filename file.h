#ifndef FILE_H
#define FILE_H
#include<bits/stdc++.h>
#include<string.h>
using namespace std;

class file
{
    public:
        //file();
        string inputFile();
        void openFile(string  temp);
        string append(string temp);
        string edit(string temp);
        string copyPaste(string temp);
        string cutPaste(string temp);
    protected:

    private:
};

string file :: inputFile()
{
	cout<<"enter '|||0' to stop writting";
	string temp,ma;
	cin>>temp;
	while(temp!="|||0")
	{
		ma+=temp;
		ma+="-+=";
		cin>>temp;
	}
	return ma;
}
void file :: openFile(string str)
{
	string c="-+=";
	size_t found = str.find(c); 
	int i=0,j=0;
	while(found != string::npos)
	{
		cout<<str.substr(j,found)<<endl;
		j=found+1;
		i++;
		found=str.find(c,found+i);
	}
} 
string file :: append(string temp)
{
	string abc;
	cout<<"Enter data"<<endl;
	cin>>abc;
	while(abc!="|||0")
	{
		temp+=abc;
		cin>>abc;
	}
	return temp;
}
string file :: edit(string str)
{
	vector<vector<string> >abc;
	vector<string >a;
	string c="-+=";
	size_t found = str.find(c); 
	int i=0,j=0;
	while(found != string::npos)
	{
		string temp=str.substr(j,found);
		size_t f= temp.find(" ");
		int k=0,l=0;
		while(f != string::npos)
		{
			a.push_back(temp.substr(l,f));
			l=f+1;
			k++;
			f=temp.find(" ",f+i);
		}
		abc.push_back(a);
		j=found+1;
		i++;
		found=str.find(c,found+i);
	}
	
	vector<vector<string> > :: iterator it;
	int x=0;
	for(it=abc.begin(); it!=abc.end();it++)
	{
		vector<string> temp= *it;
		vector<string> :: iterator i;
		cout<<x<<"->";
		for(i=temp.begin(); i!=temp.end(); i++)
		{
			cout<<*i<<" ";
		}
		cout<<endl;
		x++;
	}
	x=0;
	cout<<"Enter line number :";
	int y,y1;
	cin>>y;
	vector<string>temp1=abc[y];
	vector<string> :: iterator ia;
	for(ia=temp1.begin(); ia!=temp1.end(); ia++)
		{
			cout<<x<<"->"<<*ia<<endl;
		}
	cout<<"Enter word number to be edited: ";
	cin>>y1;
	cout<<"Enter word again :";
	cin>>abc[y][y1];
	//
	x=0;
	for(it=abc.begin(); it!=abc.end();it++)
	{
		vector<string> temp= *it;
		vector<string> :: iterator i;
		for(i=temp.begin(); i!=temp.end(); i++)
		{
			str+=*i;
			str+=" ";
		}
		str+="-+=";
	}
	return str;
}
#endif // FILE_H
