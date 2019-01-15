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
        bool conditions(node * root);
        void cutfile(string source, string dest);
        void cutfolder(string source, string dest);
        void copyfile(string source, string dest);
        void copyfolder(string source, string dest);
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
		system("cls");
		manage::actions();
		cout<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<endl<<endl<<endl<<endl<<endl<<endl;
		vector<string> :: iterator a;
		path.push_back(curr);
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
						//sql query
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
		cout<<"******************************************************************************************"<<endl;
		for(a=p.begin();a!=p.end();++a)
		{
			cout<<*a<<"->";
		}
		cout<<"******************************************************************************************"<<endl;

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
void manage :: actions()
{
	cout<<"Create File -> touch\tCreate Folder -> mkdir\tRename File -> rename\t Rename Folder -> frename\tTerminate -> close"<<endl;
	cout<<"Cut File -> mv\tCut Folder -> fmv\t Copy File -> cp\t Copy Folder -> fcp\t Delete File -> rm\t Delete Folder -> frm"<<endl;
	cout<<"list all file and folder -> ls\t"  ; 
}
bool manage :: conditions(node * root)
{
	cout<<"Enter command: ";
	string command;
	cin>>command;
	vector<string>parts;
	int i=0,j=0;
	while(i<sizeof(command))
	{
		string temp;
		if(command[i]!=32)
			temp+=command[i];
		else
		{
			parts.push_back(temp);
			temp="";
			j++;
		}
		i++;
	}
	if(j>3)
	{
		cout<<"invalid command"<<endl;
		return false;
	}
	if(parts[0]=="touch")
	{
		string a;
		cout<<"Enter file name and extension seprated by '.' ";
		cin>>a;
		string c,b;
		size_t found = a.find(".");
		c=a.substr(0,found);
		b=a.substr(found+1,sizeof(a));
		createFile(c,b,root);
	}
	if(parts[0]=="mkdir")
	{
		string a;
		cout<<"Enter folder name ";
		cin>>a;
		createFolder(a,root);
	}
	if(parts[0]=="rename")
	{
		string a;
		cout<<"Enter file name and extension seprated by '.' ";
		cin>>a;
		string c,b;
		size_t found = a.find(".");
		c=a.substr(0,found);
		b=a.substr(found+1,sizeof(a));
		renameFile(root,c,b);

	}
	if(parts[0]=="frename")
	{
		string a;
		cout<<"Enter folder name ";
		cin>>a;
		renameFolder(root,a);
	}
	if(parts[0]=="ls")
	{
		list(root);
	}
	if(parts[0]=="close")
	{
		exit(0);
	}
	if(parts[0]=="mv")
	{
		
	}
	if(parts[0]=="fmv")
	{
		
	}
	if(parts[0]=="cp")
	{
		
	}
	if(parts[0]=="fcp")
	{
		
	}
	if(parts[0]=="rm")
	{
		string a;
		cout<<"Enter file name and extension seprated by '.' ";
		cin>>a;
		string c,b;
		size_t found = a.find(".");
		c=a.substr(0,found);
		b=a.substr(found+1,sizeof(a));
		int i=0;
		vector<pair<string, string> > :: iterator it;
		for(it=root->file.begin();it!=root->file.end();it++)
		{
			if(it->first==c && it->second==b)
			{
				root->file.erase(root->file.begin()+i+1);
				break;
			}
			else
				i++;
		}
	}
	if(parts[0]=="frm")
	{
		string a;
		cout<<"Enter folder name ";
		cin>>a;
		int i=0;
		vector<pair<node *, string> > :: iterator it;
		for(it=root->folder.begin();it!=root->folder.end();it++)
		{
			if(it->second==a)
			{
				root->folder.erase(root->folder.begin()+i+1);
				break;
			}
			else
				i++;
		}
	}
}
#endif // MANAGE_Hz