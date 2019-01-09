
#ifndef MANAGE_H
#define MANAGE_H
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
struct node
{
	vector<pair<string, string> >file;
	vector<pair<node*, string> >folder;
	node *dotdot;
};

class manage
{
    public:
        //manage();
        void renameFile(node *root, string oldFileName, string OldFileExtension);
        void renameFolder(node *root, string oldFolderName);
        bool createFile(string fileName, string fileExtension, node *root);
        bool createFolder(string folderName, node *root);

    protected:

    private:
    	

    		
};
bool manage :: createFile(string fileName, string fileExtension, node *root)
{
	root->file.push_back(make_pair(fileName,fileExtension));
	return true;
}
bool manage :: createFolder(string folderName, node *root)
{
	node *temp = new node;
	temp=NULL;
	root->dotdot=root;
	root->folder.push_back(make_pair(temp, folderName));
	return true;
}

void manage :: renameFile(node *root, string oldFileName, string OldFileExtension)
{
	vector<pair<string, string> > :: iterator it;
	int p=0;
	for(it=root->file.begin();it!=root->file.end();++it)
	{
		if(it->first==oldFileName && it->second==OldFileExtension)
		{
			cout<<"Enter new name: ";
			cin>>it->first;
			cout<<endl<<"Enter  new Extension: ";
			cin>>it->second;
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
	for(it=root->folder.begin();it!=root->folder.end();++it)
	{
		if(it->first==oldFolderName)
		{
			cout<<"Enter new name: ";
			cin>>it->second;
			p=1;
			break;
		}
	}
	if(p==0)
		cout<<"folder doesnt exist"<<endl;
}
#endif // MANAGE_H