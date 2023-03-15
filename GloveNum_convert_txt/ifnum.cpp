#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>

using namespace std;

int main(int argc,char* argv[])
{
    // 打开要操作的txt文件
    ifstream infile(argv[1]);
    if (!infile)
    {
        cout << "无法打开文件" << endl;
        return 1;
    }

    
    string line;
    int flag=0;
    int linenum=0;
    while (getline(infile, line)&&flag==0)
    {
        linenum++;
        int i=0;
        for (; i < line.length(); i++)
        {
            if(isdigit(line[i])){
                break;
            }
            else{
                if(line[i]!='-'){
                    cout<<"no num!";
                    cout<<linenum;
                    flag=1;
                    break;
                }
            }
        }
              
    }

    // 关闭文件
    infile.close();

    return 0;
}