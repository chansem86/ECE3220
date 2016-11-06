/* 
 * File:   Lab8.cpp
 * Author: Hank
 *
 * Created on November 2, 2016, 2:04 PM
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string letters = "abcdefghijklmnopqrstuvwxyz";
string morseCode[] = {"._", "_...", "_._.", "_..", ".", ".._.", "__.", "....", "..", ".___",
                      "_._", "._..", "__", "_.", "___", ".__.", "__._", "._.", "...", "_",
                      ".._", "..._", ".__", "_.._", "_.__", "__.."};

class MSG {
protected:
    string msg;
public:
    MSG();
    MSG(string m);
    ~MSG();
    virtual void printInfo();
    string getMsg(){
        return msg;
    }
    void setMsg(string m){
        msg = m;
    }
};

MSG::MSG() {
    cout << "Enter your message: ";
}

MSG::MSG(string m) {
    msg = m ;
}

MSG::~MSG() {
    
}

void MSG::printInfo() {
    cout << msg << endl;
}

class mCMSG : public MSG {
public:
    mCMSG(string m);
    ~mCMSG();
    string *tran_msg;
    int index;
    void translate();
    void printInfo();
    
};

mCMSG::mCMSG(string m) : MSG(m) {
    tran_msg = new string[m.length()];
    translate();
}

mCMSG::~mCMSG(){
    
}

void mCMSG::translate() {
    int i = 0;
    while (i < msg.length()) {
        index = letters.find(tolower(msg[i]));
        tran_msg[i] = morseCode[index];
        i++;
    }
}

void mCMSG::printInfo(){
    int i = 0;
    cout << msg << endl;
    while (i <= tran_msg->length()){
        cout << tran_msg[i] << "   ";
        i++;
    }
    cout << endl;
}

class MSGSt {
public:
    MSG *ptrSt[10];
    int st_top_ptr;
    int num_obj;
    MSGSt();
    ~MSGSt();
    void pop();
    void push(MSG obj);
    void printStack();
};

MSGSt::MSGSt(){
    st_top_ptr = 0;
    num_obj = 0;
}

MSGSt::~MSGSt(){
    if (!ptrSt){
        for(int i = st_top_ptr; i >= 0; i--){
            delete ptrSt[i];  
        }
    }
}

void MSGSt::pop() {
    delete ptrSt[st_top_ptr-1];
}

void MSGSt::push(MSG obj) {
    ptrSt[st_top_ptr] = new MSG(obj);
    st_top_ptr++;
}

void MSGSt::printStack() {
    int i = 0;
    while (i < st_top_ptr){
        cout << ptrSt[i]->getMsg() << endl;
        i++;
    }
}

int main(int argc, char** argv) {
    string m;
    MSG obj1;
    cin >> m;
    mCMSG obj2(m);
    MSGSt st;
    obj1.printInfo();
    obj2.printInfo();
    obj1.setMsg(obj2.getMsg());
    st.push(obj1);
    st.printStack();
    st.pop();
    return 0;
}

