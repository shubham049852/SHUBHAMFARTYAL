#include<iostream>
#include<stack>
using namespace std;

bool deliMatch(char* data);

int main()
{
    char dataName[50];

    cout<<"Enter a statement (Ex. a=b[8]+c/(d*(e+f));: ";
    cin>>dataName;
    cout<<endl;

    if(deliMatch(dataName))
    cout<<endl<<"Your statement was constructed successfully."<<endl;
    else
    cout<<endl<<"Your statement is incorrectly constructed."<<endl;
}

bool deliMatch(char* data){
    stack<char> vari;
    int counter = 0;
    char ch, temp, popd;
    do{
        ch = data[counter];
        if(ch == ';')
            break;
        if(ch == '(' || ch == '[' || ch == '{')
            vari.push(ch);
        else if(ch == '/'){
            temp = data[counter+1];
            if(temp == '*')
                vari.push(ch);
            else{
                counter++;
                continue;
            }
        }
        else if(ch == ')' || ch == ']' || ch == '}'){
            popd = vari.top();
            vari.pop();
            if((ch==')' && popd!='(') || (ch==']' && popd!='[') || (ch=='}' && popd!='{'))
                return false;
        }
        else if(ch == '*'){
            temp = data[counter+1];
            popd = vari.top();
            vari.pop();
            if(temp == '/' && popd != '/')
                return false;
            else{
                counter++;
                vari.push(popd);
                continue;
            }
        }
        counter++;
    }while(ch != '\n');
    if(vari.empty())
        return true;
    else return false;
}
