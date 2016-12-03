/*
 * File:   Lab10.cpp
 * Author: Chanse and Jonathan
 *  Please see Jonathan's code. This is what we had before thursday's lab and before we made some changes to it, which i did not get transferred to me from the lab computer. Jonathan may have the properly working code in his lab report. 
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <stdio.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <locale>
#include <cctype>

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
    virtual void printInfo();

    string getMsg() {
        return msg;
    }

    void setMsg(string m) {
        msg = m;
    }
};

MSG::MSG() {
    cout << "Enter your message: ";
}

MSG::MSG(string m) {
    msg = m;
}

void MSG::printInfo() {
    cout << msg << endl;
}

class mCMSG : public MSG {
public:
    mCMSG(string m);
    string *tran_msg;
    int index;
    void translate();
    void printInfo();
    void MorseCodeToLights();
};

mCMSG::mCMSG(string m) : MSG(m) {
    tran_msg = new string[m.length()];
    translate();
}

void mCMSG::translate() {
    int i = 0;
    while (i < msg.length()) {
        index = letters.find(tolower(msg[i]));
        if (isalpha(msg[i]))
            tran_msg[i] = morseCode[index];
        else if (isspace(msg[i]))
            tran_msg[i] = ' ';
        i++;
    }
}

void mCMSG::printInfo() {
    int i = 0;
    cout << msg << endl;
    while (i < msg.length()) {
        cout << tran_msg[i] << " ";
        //MorseCodeToLights(tran_msg[i]);
        i++;
    }
    cout << endl;
}

void mCMSG::MorseCodeToLights(string t_msg) {
    int fd, i = 0; // for the file descriptor of the special file we need to open.
    unsigned long *BasePtr; // base pointer, for the beginning of the memory page (mmap)
    unsigned long *PBDR, *PBDDR; // pointers for port B DR/DDR
    fd = open("/dev/mem", O_RDWR | O_SYNC); // open the special file /dem/mem
    if (fd == -1) {
        printf("\n error\n");
        return (-1); // failed open
    }
    // We need to map Address 0x80840000 (beginning of the page)
    BasePtr = (unsigned long*) mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0x80840000);
    if (BasePtr == MAP_FAILED) {
        printf("\n Unable to map memory space \n");
        return (-2);
    } // failed mmap
    // To access other registers in the page, we need to offset the base pointer to reach the
    // corresponding addresses. Those can be found in the board's manual.
    PBDR = BasePtr + 1; // Address of port B DR is 0x80840004
    PBDDR = BasePtr + 5; // Address of port B DDR is 0x80840014
    *PBDDR |= 0xE0; // configures port B7 as output (Green LED)
    *PBDDR &= 0xFFFFFFFE; // configures port B0 as input (first push button). You could use: &= ~0x01
    // The program will turn on the green LED, sleep for a while, then off, sleep, then on again, then off.
    // You could use loops, if you wanted/needed.
    while (i < t_msg.length()) {
        if (t_msg[i] == '.') {
            *PBDR |= 0x20;
            usleep(500000);
            *PBDR &= ~0x20;
            usleep(100000);
        } else if (t_msg[i] == '_') {
            *PBDR |= 0x40;
            usleep(500000);
            *PBDR &= ~0x40;
            usleep(100000);
        }
        if (t_msg[i] == ' ') {
            *PBDR |= 0x90; // ON: write a 1 to port B0. Mask all other bits.
            usleep(600000); // How can you sleep for less than a second?
            *PBDR &= ~0x90; // OFF: write a 0 to port B0. Mask all other bits.
            usleep(100000);
        }
    }
    close(fd); // close the special file
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

MSGSt::MSGSt() {
    st_top_ptr = 0;
    num_obj = 0;
}

MSGSt::~MSGSt() {
    if (!ptrSt) {
        for (int i = st_top_ptr; i >= 0; i--) {
            delete ptrSt[i];
        }
    }
}

void MSGSt::pop() {
    delete ptrSt[st_top_ptr - 1];
}

void MSGSt::push(MSG obj) {
    ptrSt[st_top_ptr] = new MSG(obj);
    st_top_ptr++;
}

void MSGSt::printStack() {
    int i = 0;
    while (i < st_top_ptr) {
        cout << ptrSt[i]->getMsg() << endl;
        i++;
    }
}

int main(int argc, char** argv) {
    string m;
    MSG obj1;
    getline(cin, m, '\n');
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
