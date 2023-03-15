#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<cstdlib>
#include <ctime>
using namespace std;

// struct fvecs{
//     int _dim;
//     float* _vecnum;
// };

// void initfvecs(int dim,fvecs& vec){
//     vec._vecnum=new float[vec._dim];
// }
int main(int argc,char* argv[]){
    srand(time(nullptr));
    if(argc!=4){
        cout<<"input.txt output.txt num";
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
    string str;
    string t;
    vector<string> v;
    float max=0;
    float min=0;
    float vecnum;
    int querynum=(int)stof(argv[3]);
    int dim=0;
    while(getline(readfile,str)){
        istringstream in(str);
        while(getline(in,t,' ')){
            v.push_back(t);
        }
        for(int i=0;i<v.size();i++){
            vecnum=stof(v[i]);
            if(vecnum>max)max=vecnum;
            if(vecnum<min)min=vecnum;
        }
        dim=v.size();
        v.resize(0);
    }
    readfile.close();
    cout<<"max:"<<max<<endl<<"min:"<<min<<endl;
    float a;

    for(int j=0;j<querynum;j++){
        for(int i=0;i<dim-1;i++){
            a=((rand() / double(RAND_MAX))-0.5)*(max-min)+((min+max)/2);
            writefile<<a<<' ';
        }
        a=((rand() / double(RAND_MAX))-0.5)*(max-min)+((min+max)/2);
        writefile<<a<<endl;
    }
    return 0;
}