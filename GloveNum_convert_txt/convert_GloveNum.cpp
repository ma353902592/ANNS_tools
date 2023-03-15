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

    // 创建输出文件
    ofstream outfile("newfile.txt");
    if (!outfile)
    {
        cout << "无法创建新文件" << endl;
        return 1;
    }

    // 指定要删除的特殊字符
    //string specialChars = "@#$%";

    // 逐行读取文件，删除特殊字符，并写入新文件
    string line;
    while (getline(infile, line))
    {
        int i=0;
        for (; i < line.length(); i++)
        {
            if(line[i]==' '){
                break;
            }
        }
        i++;
        for(;i<line.length();i++){
            outfile << line[i];
        }       
        outfile << endl;
    }

    // 关闭文件
    infile.close();
    outfile.close();

    return 0;
}