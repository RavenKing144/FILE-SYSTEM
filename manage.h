#ifndef MANAGE_H
#define MANAGE_H
#include<bits/stdc++.h>
#include "file.h"
#include "sql.h"
#include<string.h>
using namespace std;
struct node
{
	vector<pair<string, string> >file;
	vector<pair<node*, string> >folder;
};

class manage
{
    public:
        void renameFile(node *root, string oldFileName, string OldFileExtension);
        void renameFolder(node *root, string oldFolderName);
        void createFile(string fileName, string fileExtension, node *root);
        void createFolder(string folderName, node *root);
        void list(node *root);
        void traverse(node * root);
        void actions();
        bool checkFile(node * root, string name);
        bool checkFolder(node * root, string name);
        void help();
    protected:

    private:
    	file obj;
    	sql obj1;
    	

    		
};
void manage :: createFile(string fileName, string fileExtension, node *root)
{
	root->file.push_back(make_pair(fileName,fileExtension));
	cout<<"Enter file conytent"<<endl;
	string temp=obj.inputFile();
}
void manage :: createFolder(string folderName, node *root)
{
	node *temp = new node;
	temp=NULL;
	root->folder.push_back(make_pair(temp, folderName));
}

void manage :: renameFile(node *root, string oldFileName, string OldFileExtension)
{
	vector<pair<string, string> > :: iterator it;
	int p=0;
	string newName;
	bool a=false;
	cout<<"Enter new name: ";
	cin>>newName;
	while(a==false)
	{
		for(it=root->file.begin();it!=root->file.end();++it)
		{
			if(it->first== newName && it->second==OldFileExtension)
			{
				cout<<"File with that name already exist"<<endl;
				a=true;
				break;
			}
		}
		if(a==true)
		{
			cout<<"Re-enter file name: ";
			cin>>newName;
		}
		else
		{
			a=false;
		}
	}
	for(it=root->file.begin();it!=root->file.end();++it)
	{
		if(it->first==oldFileName && it->second==OldFileExtension)
		{
			it->first=newName;
			p=1;
			break;
		}
	}
	if(p==0)
		cout<<"file doesnt exist"<<endl;
}
void manage :: renameFolder(node *root, string oldFolderName)
{
	vector<pair<node*, string> > :: iterator it;
	int p=0;
	string newName;
	cout<<"Enter new name: ";
	cin>>newName;
	bool a=false;
	while(a==false)
	{
		for(it=root->folder.begin();it!=root->folder.end();++it)
		{
			if(it->second== newName)
			{
				cout<<"Folder with that name already exist"<<endl;
				a=true;
				break;
			}
		}
		if(a==true)
		{
			cout<<"Re-enter folder name: ";
			cin>>newName;
		}
		else
		{
			a=false;
		}
	}
	for(it=root->folder.begin();it!=root->folder.end();++it)
	{
		if(it->second==oldFolderName)
		{
			it->second= newName;
			p=1;
			break;
		}
	}
	if(p==0)
		cout<<"folder doesnt exist"<<endl;
}
void manage :: list(node * root)
{
	vector<pair<string, string> > :: iterator it;
	vector<pair<node*, string> > :: iterator i;
	for(it=root->file.begin(); it!=root->file.end(); ++it)
	{
		cout<<it->first<<"."<<it->second<<endl;
	}
	for(i=root->folder.begin(); i!=root->folder.end(); ++i)
	{
		cout << "\033[1;31m";
		cout<<i->second<<endl;
		cout<<"\033[0m";
	}
}
void manage :: traverse(node *root)
{
	vector<node *>path;
	vector<string>p;
	node * curr = root;
	while(1)
	{
		vector<string> :: iterator a;
		path.push_back(curr);
		cout<<"******************************************************************************************"<<endl;
		for(a=p.begin();a!=p.end();++a)
		{
			cout<<*a<<"->";
		}
		cout<<"******************************************************************************************"<<endl;
		list(curr);
		cout<<endl<<endl<<endl<<endl<<endl<<endl;
			string temp;
			cout<<"Enter file name to open or folder name to enter in it: ";
			cin>>temp;
			vector<pair<string, string> > :: iterator it;
			vector<pair<node*, string> > :: iterator i;
			if(checkFile(curr, temp))
			{
				for(it=curr->file.begin(); it!=curr->file.end(); ++it)
				{
					if(temp==it->first)
					{
						//openFile(it->first, it->second);
					}
				}
			}
			else if(checkFolder(curr,temp))
			{
				for(i=curr->folder.begin(); i!=curr->folder.end(); ++i)
				{
					if(temp==i->second)
						curr=i->first;
					p.push_back(temp);
				}
			}
			else
				cout<<"doesnt exist"<<endl;

	}

}
bool manage :: checkFile(node * root, string name)
{
	vector<pair<string, string> > :: iterator it;
	for(it=root->file.begin();it!=root->file.end();++it)
	{
		if(it->first==name)
		{
			return true;
		}
	}
	return false;
}
bool manage :: checkFolder(node * root, string name)
{
	vector<pair<node*, string> > :: iterator it;
	for(it=root->folder.begin();it!=root->folder.end();++it)
	{
		if(it->second==name)
		{
			return true;
		}
	}
	return false;
}
void manage :: help()
{
	map<string, string>h;
	map<string, string> :: iterator it;
	cout<<"Command and their functionality are as follows: "<<endl;
	for(it=h.begin();it!=h.end();it++)
	{
		cout<<it->first<<" :-> "<<it->second<<endl;
	}
}
void manage :: actions()
{
	cout<<"Create File\tCreate Folder\tRename File\t Rename Folder";    
}
#endif // MANAGE_Hz