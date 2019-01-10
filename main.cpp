#include<bits/stdc++.h>
#include<string.h>
#include "manage.h"
//#include<SQLAPI.h>
using namespace std;
int main()
{
	node *root=new node;
	node *driveA=new node;
	driveA= NULL;
	root->folder.push_back(make_pair(driveA, "Drive A"));
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
	return 0;
}
