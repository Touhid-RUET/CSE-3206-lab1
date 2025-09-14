#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
int total = 0;
class Member {
    private :
        string mobile,name;
        int pin;
        float balance,amount;
        static int tran_id;
    public :
        Member() {balance = 0, amount = 0;}
        void setmob(string m) {mobile = m;}
        void setnam(string n) {name = n;}
        void setpin(int p) {pin = p;}
        void setbalance(float b) {balance = b;}
        void setamount(float a) {amount = a;}
        string getmob() {return mobile;}
        string getnam() {return name;}
        float getbaln() {return balance;}
        float getamnt() {return amount;}
        int getpin() {return pin;}
};
void login();
void cashin(int);
void cashout(int);
void checkbaln(int);
Member mem[10000];
int Member::tran_id = 101;
int terminal1() {
    int op1;
    system("cls");
    cout << "*** MyCash Login***" << endl;
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "3. Exit" << endl;
    cout << "   Enter Your Option(1-3):" << endl;
    cin >> op1;
    return op1;
}
int terminal2() {
    int opt2;
    system("cls");
    cout << "******** MyCash Menu ********" << endl;
    cout << "1. Update Me" << endl;
    cout << "2. Remove Me" << endl;
    cout << "3. Send Money"<< endl;
    cout << "4. Cash-in" << endl;
    cout << "5. Cash-out" << endl;
    cout << "6. Pay Bill" << endl;
    cout << "7. Check Balance" << endl;
    cout << "8. History"<< endl;
    cout << "9. Logout" << endl;
    cout << "   Enter Your Option (1-9):_" << endl;
    cin >> opt2;
    return opt2;
}
int idsearch(string m) {
    int indx = -1;
    for(int i = 0; i < total; i++) {
        if(mem[i].getmob()==m) {
            indx = i;
            break;
        }
    }
    return indx;
}
int pin() {
	string pin;
	char pass[12];
	int indx = 0;
	while(1) {
		char ch = getch();
		if(ch=='\r') break;
		else if(ch=='\b' and indx > 0) {
		cout << "\b \b";
		indx--;
        }
		else if(ch=='\b' and indx == 0) continue;
		else {
			pass[indx++] = ch;
			cout << "*";
		}
	}
	pass[indx] = '\0';
	for(int i = 0; pass[i] != '\0'; i++) pin.push_back(pass[i]);
    if(pin.size()!=5) {
    cout << "\n";
    cout << "Pin must be 5 Digits" << endl;
    srand(time(0));
    return (1000+rand()%9000);
    }
    else return stoi(pin);
}
void update(int loc) {
    string name; int pnI,pnF,randI,randF;
    cout << "Old Name: " << mem[loc].getnam() << endl;
    while(1) {
        cout << "New Name (enter to ignore): " << endl;
        char ch = getch();
        if(ch=='\r') break;
        else {
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        getline(cin,name);
        mem[loc].setnam(name);
        break;
        }
    }
    cout << "Old pin : " << mem[loc].getpin() << endl;
    while(1) {
        cout << "New pin (enter to ignore): "; cout << "\n";
        char ch = getch();
        if(ch=='\r') break;
        else {
        pnI = pin(); cout << "\n";
        cout << "Confirm New pin: ";
        pnF = pin(); cout << "\n";
        if(pnI==pnF) {
            cout << "myCah OTP: ";
            srand(time(0));
            randI = 1000 + rand() % 9000;
            cout << randI << endl;
            cout << "Enter OTP: ";
            cin >> randF;
            if(randI==randF) {
                mem[loc].setpin(pnI);
                cout << "Update is Successfull" << endl;
                break;
            }
            else {
                cout << "OTP does NOT Matched" << endl;
                break;
            }
        }
        else {
        cout << "Pins must be same" << endl;
        break;}
        }
    }
    cout << "Press any key to continue" << endl;
    getch();
}
void Register() {
    string mobile,name;
    int pinI,pinF,otpI,otpF;
    cout << "Enter Mobile number: " << endl;
    cin >> mobile;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    if(idsearch(mobile)==-1) {
        cout << "Enter name: ";
        getline(cin,name);
        cout << "Enter pin: ";
        pinI = pin(); cout << "\n";
        cout << "Confirm Pin: ";
        pinF = pin(); cout << "\n";
        if(pinI == pinF) {
            cout << "mycash OTP: ";
            srand(time(0));
            otpI = (1000 + rand() % 9000); //! (lb + rand() % (ub - lb + 1))
            cout << otpI << endl;
            cout << "Enter OTP: ";
            cin >> otpF;
            if(otpI == otpF) {
                mem[total].setmob(mobile);
                mem[total].setnam(name);
                mem[total].setpin(pinF);
                total++;
                cout << "Registration is Successfull" << endl;
            }
            else cout << "OTP does NOT matched" << endl;

        }
        else cout << "Pins must be Same" << endl;

    }
    else cout << "Memeber already exists" << endl;
    cout << "Press any key to continue" << endl;
    getch();
}
void remove(int loc) {
    int randI,randF,term;
    cout << "mycash OTP: ";
    srand(time(0));
    randI = (1000+rand()%9000);
    cout << randI << endl;
    cout << "Enter OTP: ";
    cin >> randF;
    if(randI==randF) {
        for(int i = loc; i < total - 1; i++) {
            mem[i].setmob(mem[i+1].getmob());
            mem[i].setnam(mem[i+1].getnam());
            mem[i].setpin(mem[i+1].getpin());
        }
        total--;
        cout << "Remove is Successfull" << endl;
        cout << "Back to mycash login Menu" << endl;
        getch();
        for(;;) {
            term = terminal1();
            if(term == 3) {
                cout << "End of Program" << endl;
                break;
            }
            else if(term == 1) login();
            else if(term ==2) Register();
        }
    }
    getch();

}
void login() {
    string mbile; int p,indx,term;
    bool mob = false, pn = false;
    cout << "Enter Mobile No: ";
    cin >> mbile;
    cout << "Enter Pin: ";
    p = pin();
    cout << "\n";
    for(int i = 0; i < total; i++) {
        if(mem[i].getmob()==mbile) {
            mob = true;
            indx = i;
            break;
        }
    }
    if(mem[indx].getpin()==p and mob == true) {
        pn = true; int term2;
        for(;;){
            term = terminal2();
            if(term == 1) update(indx);
            else if(term ==2) remove(indx);
            else if(term == 4) cashin(indx);
            else if(term == 5) cashout(indx);
            else if(term==7) checkbaln(indx);
            else if(term==9) {
                term2 = terminal1();
                if(term2==3){
                cout << "End of Program" << endl;
                break;}
                else {
                    if(term2==1) {
                    login();
                    break;}
                    else if(term2==2) {
                    Register();
                    break;}
                }
            }
                // case 6:paybill();break;
                // case 8:history();break;
        }

    }
    if(mob==false ) {
        cout << "Destination Mobile no. is invalid" << endl;
        cout << "Invalid login" << endl;
    }
    else if(mob==true and pn == false) {
        cout << "Incorrect Pin" << endl;
        cout << "Invalid login" << endl;
    }
    cout << "Press any key to continue" << endl;
    getch();
}
void sendmoney(int loc) {
    string number; float amount;
    int randI,randF;
    cout << "Enter Destination No.(11-Digits): " << endl;
    getline(cin,number);
    cout << "Enter Amount: ";
    cin >> amount;
    cout << "Sending " << amount << " " << "to" << " " << number << endl;
    cout << "Are you sure(Y/N)?" ;
    char ch = cin.get();
    if(ch=='y' or ch =='Y') {
    cout << "mycash OTP: ";
    srand(time(0));
    randI = (1000+rand()%9000);
    cout << "Enter OTP: ";
    cin >> randF;
        if(randI==randF) {
            if(((mem[loc].getbaln())-amount)<0) cout << "Insufficient Fund" << endl;
            else {
            mem[loc].setamount(amount);
            mem[loc].setbalance(mem[loc].getbaln()-amount);
            }
        }
        else {
            cout << "OTP does NOT macthed" << endl;
        }
    }
    else if(ch=='n' or ch=='N') cout << "Send money is Cancalled" << endl;
    else cout << "Please chose between Y/N" << endl;
    cout << "Press any key to continue" << endl;
    getch();
}
void cashin(int loc) {
    float amount;
    cout << "Enter Amount: ";
    cin >> amount;
    cout << "Cash-in " << amount << endl;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Are you sure(Y/N)? ";
    char ch = cin.get();
    if(ch=='y' or ch=='Y') {
        mem[loc].setbalance(mem[loc].getbaln() + amount);
        mem[loc].setamount(amount);
    }
    else if (ch=='n' or ch=='N') {
        cout << "Cash-in is Cancalled" << endl;
    }
    else cout << "Please choose between (Y/N)" << endl;
    cout << "Press any key to continue" << endl;
    getch();

}
void cashout(int loc) {
    float amount;
    int randI,randF;
    cout << "Enter Amount: ";
    cin >> amount;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Cash-out " << amount << endl;
    cout << "Are you sure(Y/N)? ";
    char ch = cin.get();
    if(ch=='y' or ch=='Y') {
        cout << "myCash OTP: ";
        srand(time(0));
        randI = (1000+rand()%9000);
        cout << randI << endl;
        cout << "Enter OTP: ";
        cin >> randF;
        if(randI==randF) {
            if(((mem[loc].getbaln())-amount)<0) cout << "Insufficient Fund" << endl;
            else {
            mem[loc].setamount(amount);
            mem[loc].setbalance(mem[loc].getbaln()-amount);
            }
        }
        else cout << "OTP does NOT Matched" << endl;

    }
    else if(ch=='n' or ch=='N') cout << "Cash-out is Cancalled" << endl;
    else cout << "Please chose Between Y/N" << endl;
    cout << "Press any key to continue" << endl;
    getch();
}
void checkbaln(int loc) {
    cout << "Balance : " << mem[loc].getbaln() << endl;
    cout << "Press any key to continue" << endl;
    getch();
}
int main() {

    int option;
    for(;;) {
        option = terminal1();
        if(option == 3) {
            cout << "End of Program" << endl;
            break;
            }
        switch(option) {
            case 1: login(); break;
            case 2: Register(); break;
        }
    }

}