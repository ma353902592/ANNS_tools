#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

// struct fvecs{
//     int _dim;
//     float* _vecnum;
// };

// void initfvecs(int dim,fvecs& vec){
//     vec._vecnum=new float[vec._dim];
// }
int main(int argc,char* argv[]){
    ifstream readfile(argv[1]);
     if (!readfile)
    {
        cout << "无法打开文件" << endl;
        return 1;
    }
    ofstream writefile(argv[2],ios::binary);
    if (!writefile)
    {
        cout << "无法创建新文件" << endl;
        return 1;
    }
    string str;
    string t;
    vector<string> v;
    int dim=4;
    float vecnum;
    while(getline(readfile,str)){
        istringstream in(str);
        while(getline(in,t,' ')){
            v.push_back(t);
        }
        writefile.write((char*)&dim,sizeof(int));
        for(int i=0;i<v.size();i++){
            vecnum=stof(v[i]);
            writefile.write((char*)&vecnum,sizeof(float));
        }
        v.resize(0);
    }
    readfile.close();
    writefile.close();
    return 0;
}