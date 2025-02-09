#include <iostream>
#include <string>

using namespace std;
int myAtoi(string s) {
        bool leadingZeros = true;
        bool leadingSign = false;
        bool leadingWhite = true;
        string tempStr = "";
        for(int i = 0; i<s.size();i++){
            if(s[i]==' ' && leadingWhite){
            }else if((s[i]=='+'|| s[i]== '-') && !(leadingSign)){
                
                if(s[i]=='-'){
                    tempStr = "-";
                }
                leadingSign = true;
            }else if((s[i]=='0' && leadingZeros)){
                    cout << "here" << endl;
            }else if((s[i]>='0' && s[i]<='9')){
                tempStr = tempStr+s[i];
                leadingSign = true;
                leadingZeros = false;
                leadingWhite = false;
            }else{
                break;
            }
        }
        if(tempStr.size()>0){

            return stoi(tempStr);
        }
        return 0;
    }
int main(){
    cout << myAtoi("133703d") << endl;
    double * p = new double;
*p = 35.1;
double * q = p;
cout << *p << " " << *q << endl;
p = new double;
*p = 27.1;
cout << *p << " " << *q << endl;
*q = 12.5;
cout << *p << " " << *q << endl;
delete p;
delete q;
cout << INT_MAX;
}