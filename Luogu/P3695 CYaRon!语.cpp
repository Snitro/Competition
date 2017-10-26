//  60分 



#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<map>
#include<sstream>
#include<stack>
using namespace std;
//保存int变量 
map <string,int> intVar;
int Array[60][1005],Arraylen;
//保存数组变量 
map <string,int> ArrayVar;
//数据转换 
template<class TA,class TB>
TB change(TA a){
    TB b;
    stringstream st;
    st << a;
    st >> b;
    return b;
}
//比较n字符串是否是以m字符串开头 
bool startWith(string n,string m){
    if(n.size() < m.size())
        return false;
    else{
        for(int i = 0;i < m.size();i++)
            if(n[i] != m[i])
                return false;
        return true;
    }
}
//将n从m处分开   分别复制给a，b 
void StringCut(string n,string m,string &a,string &b){
    int q = n.find(m);
    a = n.substr(0,q);
    b = n.erase(0,q + m.size());
}
//清除空格 
string trim(string s)
{
    int index = 0;
    if(!s.empty()){
        while( (index = s.find(' ',index)) != string::npos){
            s.erase(index,1);
        }
    }
    return s;
}
//设置变量  
void setVars(){
    string s;
    while(getline(cin,s)){
        if(s == "}"){
            return;
        }else{
            string name,type;
            StringCut(s,":",name,type);
            name = trim(name);
            type = trim(type);
            if(type == "int"){
                intVar.insert(make_pair(name,0));
            }else if(startWith(type,"array[")){
                string a,b,c;
                type.erase(0,6);
                StringCut(type,",",type,a);
                StringCut(a,"..",a,b);
                b.erase(b.size()-1,1);
                Array[Arraylen][0] = change<string,int>(a) - 1;
                ArrayVar.insert(make_pair(name,Arraylen++));
            }
        }
    }
}
//获得name对应的int值 
int getIntValue(string value){
    if(intVar.count(value))
        return intVar[value];
    if((value[value.size() - 1] == ']' )){
        string name,wei,pq;
        StringCut(value,"[",name,wei);
        StringCut(wei,"]",wei,pq);
        if(ArrayVar.count(name)){
            return Array[ArrayVar[name]][getIntValue(wei) - Array[ArrayVar[name]][0]];
        }
    }
    return change<string,int>(value);
}
//布尔值判断 
bool judge(string bl,string a,string b){
    if(bl == "lt")
        return getIntValue(a) < getIntValue(b);
    else if(bl == "gt")
        return getIntValue(a) > getIntValue(b);
    else if(bl == "le")
        return getIntValue(a) <= getIntValue(b);
    else if(bl == "ge")
        return getIntValue(a) >= getIntValue(b);
    else if(bl == "eq")
        return getIntValue(a) == getIntValue(b);
    else if(bl == "neq")
        return getIntValue(a) != getIntValue(b);
}
//表达式计算 
int count(string s){
    map <string,int> priority;
    priority.insert(make_pair("(",0));
    priority.insert(make_pair("<",1));
    priority.insert(make_pair(">",1));
    priority.insert(make_pair("<=",1));
    priority.insert(make_pair(">=",1));
    priority.insert(make_pair("==",1));
    priority.insert(make_pair("+",2));
    priority.insert(make_pair("-",2));
    priority.insert(make_pair("*",3));
    priority.insert(make_pair("/",3));
    stack<int> opd;//操作数栈 
    stack<string> opt;//运算符栈 
    opt.push("(");
    s.insert(s.size(),")");
    int i = 0;
    while(i < s.size()){
        while(s[i] == '('){
            opt.push("(");
            i++;
        }
        string var = "";
        for(int q = i;q < s.size();q++){
            string a = s;
            a = a.substr(q,1);
            if(a != "<" && a != ">" && a != "<=" && a != ">="
                && a != "=" && a != "!" && a != "+" && a != "-" && a != "*" 
                && a !="/" && a !=")" && a !="("){ 
                var.insert(var.size(),a);
            }else{
                break;
            }
        }
        i += var.size();
        opd.push(getIntValue(var));
        do{
            string op = "";
            string a = s;
            a = a.substr(i,2);
            if(a == "<=" || a == ">="
                || a == "==" || a == "!="){
                op = a;
            }
            a = a.substr(0,1);
            if(a == "<" || a == ">" || a == "+" || a == "-"
                || a == "*" || a =="/" || a ==")" || a =="("){
                op = a;
            }
            i += op.size() - 1;
            if(op == ")"){
                while(opt.top() != "("){
                    string gett = opt.top();
                    int get2 = opd.top();
                    opd.pop();
                    int get1 = opd.top();
                    opt.pop();
                    opd.pop();
                    if(gett == "+"){
                        opd.push(get1 + get2);
                    }else if(gett == "-"){
                        opd.push(get1 - get2);
                    }else if(gett == "*"){
                        opd.push(get1 * get2);
                    }else if(gett == "/"){
                        opd.push(get1 / get2);
                    }else if(gett == "=="){
                        opd.push(get1 == get2);
                    }else if(gett == "!="){
                        opd.push(get1 != get2);
                    }else if(gett == "<"){
                        opd.push(get1 < get2);
                    }else if(gett == ">"){
                        opd.push(get1 > get2);
                    }else if(gett == "<="){
                        opd.push(get1 <= get2);
                    }else if(gett == ">="){
                        opd.push(get1 >= get2);
                    }
                }
                opt.pop();
            }else{
                while(opt.size() > 0 && priority[op] <= priority[opt.top()]
                    && opt.top() != "("){
                    string gett = opt.top();
                    int get2 = opd.top();
                    opd.pop();
                    int get1 = opd.top();
                    opt.pop();
                    opd.pop();
                    if(gett == "+"){
                        opd.push(get1 + get2);
                    }else if(gett == "-"){
                        opd.push(get1 - get2);
                    }else if(gett == "*"){
                        opd.push(get1 * get2);
                    }else if(gett == "/"){
                        opd.push(get1 / get2);
                    }else if(gett == "=="){
                        opd.push(get1 == get2);
                    }else if(gett == "!="){
                        opd.push(get1 != get2);
                    }else if(gett == "<"){
                        opd.push(get1 < get2);
                    }else if(gett == ">"){
                        opd.push(get1 > get2);
                    }else if(gett == "<="){
                        opd.push(get1 <= get2);
                    }else if(gett == ">="){
                        opd.push(get1 >= get2);
                    }
                }
                opt.push(op);
            }
            i++;
        }while(i < s.size() && s[i - 1] == ')');
    }
    return opd.top();
}
//编译s语句 
void Compile(string s){
    if(startWith(s,"{ vars")){
        setVars();
    }else if(startWith(trim(s),":set")){
        s = trim(s);
        s.erase(0,4);
        string name,value;
        StringCut(s,",",name,value);
        if(intVar.count(name)){
            intVar[name] = count(value);
        }
        string wei,pq;
        StringCut(name,"[",name,wei);
        StringCut(wei,"]",wei,pq);
        if(ArrayVar.count(name)){
            Array[ArrayVar[name]][getIntValue(wei) - Array[ArrayVar[name]][0]] = count(value);
        }
    }else if(startWith(trim(s),":yosoro")){
        s = trim(s);
        s.erase(0,7);
        cout << count(s) << " ";
    }else if(startWith(s,"{ ihu")){
        s = trim(s);
        s.erase(0,4);
        string a,b,c;
        StringCut(s,",",a,b);
        StringCut(b,",",b,c);
        if(judge(a,b,c)){
            string z;
            while(getline(cin,z)){
                if(z == "}")
                    break;
                Compile(z);
            }
        }else{
            string z;
            while(getline(cin,z)){
                if(z == "}")
                    break;
            }
        }
    }else if(startWith(s,"{ hor")){
        string in[100],z;
        int inlen = 0;
        while(getline(cin,z)){
            if(z == "}")
                break;
            in[inlen++] = z;
        }
        s = trim(s);
        s.erase(0,4);
        string a,b,c;
        StringCut(s,",",a,b);
        StringCut(b,",",b,c);
        intVar[a] = getIntValue(b);
        for(int q = intVar[a];q <= getIntValue(c);q++){
            intVar[a] = q;
            for(int p = 0;p < inlen;p++)
                Compile(in[p]);
        }
    }
    else if(startWith(s,"{ while")){
        string in[100],z;
        int inlen = 0;
        while(getline(cin,z)){
            if(z == "}")
                break;
            in[inlen++] = z;
        }
        s = trim(s);
        s.erase(0,6);
        string a,b,c;
        StringCut(s,",",a,b);
        StringCut(b,",",b,c);
        while(judge(a,b,c)){
            for(int p = 0;p < inlen;p++)
                Compile(in[p]);
        }
    }
}
int main(){
    //freopen("in.txt","r",stdin);
    string s;
    while(getline(cin,s)){
        Compile(s);
    }
}
