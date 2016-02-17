#include <iostream>
#include<fstream>
#include<sstream>
using namespace std;
class student{
    string name;
    string USN;
    string branch;
    int sem;
public:
     string buffer;
    void read()
    {
                cout <<"enter the USN"<<endl;
                cin >> USN;
                cout <<"enter the name"<<endl;
                cin >> name;
                cout <<"enter branch"<<endl;
                cin >> branch;
                cout <<"enter the sem"<<endl;
                cin >> sem;
    }
    void pack()
    {
        string sem1,temp;
        stringstream out;
        out<<sem;
        sem1=out.str();
        string buffer;

        temp+= USN +'|'+name+'|'+branch+'|'+sem1;
        for(int i=buffer.length();i<100;i++)
            temp+='$';
                    buffer+=temp;
                    cout<<buffer;
                    fstream fp1;
                        fp1.open("data1.txt",ios::out|ios::app);
                            // cout<<"\n frm write:"<<buffer;
                                fp1<<buffer;
                        fp1.close();
    }
    void write()
    {
    cout<<"\n frm write";

    }
    int insert(key)
    {
        f1.open("file.txt",ios::in);
        while(!f1.eof())
        {
            f1.getline(buffer,100);
            pos=file.tellp();
            unpack();
            if(key==USN)
                break; f=1}
        return pos;
    }
    void unpack()
    {
        while!(buffer[i]=='|')
                USN+=buffer[i];
        while!(buffer[i]=='|')
                name+=buffer[i];
        while!(buffer[i]=='|')
                branch+=buffer[i];
    }
};
int main() {
    int choice;
    student s;
    string key,pos;
    cout << "enter ur choice (1.insert 2.search 3.modify 4.delete)"<<endl;
    cin >> choice;
    switch(choice)
    {
    case 1:
            s.read();
            s.pack();
           s.write();
           break;
    case 2:

    }
    //cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
    return 0;
}
