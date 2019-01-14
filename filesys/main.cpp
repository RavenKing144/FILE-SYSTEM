#include<iostream>
#include<windows.h>
#include<string.h>
#include<mysql.h>
#include<cstdio>
#include<mysql/psi/psi_memory.h>
#include<mysql/components/services/psi_memory_bits.h>

using namespace std;

int main()
{
    MYSQL *conn;
    conn=mysql_init(0);
    //mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
    conn=mysql_real_connect(conn,"127.0.0.1","root","Riya@123","riya",0,NULL,0);
    if(conn){
            cout<<"ok";
    }
    else{
        cout<<"oops";
    }
    cout << "Hello world!" << endl;
    return 0;
}

