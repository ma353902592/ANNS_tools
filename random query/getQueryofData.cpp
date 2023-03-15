#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<cstdlib>
#include <ctime>
using namespace std;
int main(int argc,char* argv[]){
    srand(time(nullptr));
    if(argc!=5){
        cout<<"input.txt output.txt datanum querynum";
        return 0;
    }
    int datanum=(int)stof(argv[3]);
    int querynum=(int)stof(argv[4]);
    if(datanum<querynum){
        cout<<"wrong querynum"<<endl;
        return 0;
    }
    ifstream readfile(argv[1]);
     if (!readfile)
    {
        cout << "无法打开文件" << endl;
        return 1;
    }
    ofstream writefile(argv[2]);
    if(!writefile)
    {
        cout<<"无法写入文件"<<endl;
        return 1;
    }
    
    int* flag=new int[datanum]();
    int count=0;
    
    int a;
    while(count<querynum){
        a=rand()%datanum;
        if(flag[a]){continue;}
        flag[a]=1;
        count++;
    }
    a=0;
    count=0;
    string str;
    while(getline(readfile,str)){
        count++;
        if(count>datanum) {cout<<"wrong datanum(less)"<<endl;break;}
        if(flag[a]){
            for(int i=0;i<str.length();i++){
            writefile << str[i];
            }
            writefile<<endl;
        }
        a++;
    }
    if(count<datanum){cout<<"wrong datanum(more)"<<endl;}
    readfile.close();
    writefile.close();
    return 0;
}