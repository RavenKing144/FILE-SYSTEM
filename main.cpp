#include<bits/stdc++.h>
#include<SQLAPI.h>
using namespace std;
struct node
{
	vector<pair<string, string> >file;
	vector<pair<node*, string> >folder;
};
int main()
{
	node *root=new node;
	node *driveA=new node;
	root->folder.push_back(make_pair(driveA, "Drive A"));
	node *driveB=new node;
	root->folder.push_back(make_pair(driveB, "Drive B"));
	node *driveC=new node;
	root->folder.push_back(make_pair(driveC, "Drive C"));
	node *driveD=new node;
	root->folder.push_back(make_pair(driveD, "Drive D"));
	
	return 0;
}
