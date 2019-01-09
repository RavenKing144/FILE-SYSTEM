#include<bits/stdc++.h>
<<<<<<< HEAD
#include<string.h>
#include "manage.h"
//#include<SQLAPI.h>
using namespace std;

=======
#include<SQLAPI.h>
using namespace std;
struct node
{
	vector<pair<string, string> >file;
	vector<pair<node*, string> >folder;
};
>>>>>>> 7ef95f07a5e28dadb3be1a789a07d92ba4fd18a0
int main()
{
	node *root=new node;
	node *driveA=new node;
	driveA= NULL;
	root->folder.push_back(make_pair(driveA, "Drive A"));
	root->dotdot=root;
	node *driveB=new node;
	driveB=NULL;
	root->folder.push_back(make_pair(driveB, "Drive B"));
	node *driveC=new node;
	driveC=NULL;
	root->folder.push_back(make_pair(driveC, "Drive C"));
	node *driveD=new node;
	driveD=NULL;
	root->folder.push_back(make_pair(driveD, "Drive D"));
    vector<pair<node*, string> > :: iterator it;
    for(it=root->folder.begin();it!=root->folder.end();++it)
        cout<<it->second<<endl;
    manage obj;
    cout<<obj.createFile("abc","abc",root)<<endl;
    cout<<obj.createFolder("bcd",root);

	return 0;
}
