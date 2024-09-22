#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//function prototypes
void normalUser();
void administrator();
void userAccount();
void adminAccount();
void Register();
int Login (string user, string pass);
//Main-Method
int main()
{
    //variable definition
    int role;
    E:
        cout << "****Welcome to CAR RENTAL SYSTEM****" << endl;
        cout << "1. Normal User Login: " << endl;
        cout << "2. Administrator Login: " << endl;
        cout << "Enter role to proceed: " << endl;
        cin >> role;
    switch(role)
    {
    case 1:
        userAccount();
        break;
    case 2:
        administrator();
        break;
    default:
        cout << "Invalid Choice.Please try again" << endl;
        goto E;
    }
    return 0;

}
string user;
string pass;

int Login (string user, string pass)
{
    ifstream file;
    string username, password;
    int n=0;
    file.open("user.txt");
    if (file.is_open())
    {
        while (!file.eof())
        {
            file >> username >> password;
            n++;
            if (user==username && pass==password)
                return n;
        }
    }
    else
    {
        cout << "file not open" << endl;
    }

}
//normalUser Function
void userAccount()
{
    int loginattempts=0;
    ifstream userfile;
    userfile.open("usersDB.txt");
    string userset, passset;
    if (userfile.is_open()){
	
    
    
            while (Login(user, pass)==0)
            {
                loginattempts++;
                cout << "Username: ";
                cin >> user;
                cout << "Password: ";
                cin >> pass;
                if (Login(user, pass)!=0)
                    cout << "Welcome " << user << "." << endl;
                else if (loginattempts==3)
                {
                    cout << "Maximum  attempts " << endl;
                    break;
                }
                else
                {
                    cout << "Invalid username or password" << endl;
                }
            }
            userfile.close();

	}

}

//Administrator Function
void administrator()
{
    //variables definition
    string adminUsername;
    int adminPassword;
    E:
        cout << "\n----------------------------------------------" << endl;
        cout << "Welcome to Administrator's Portal: " << endl;
        cout << "----------------------------------------------" << endl;
        cout << "Enter Administrator Username: " << endl;
        cin >> adminUsername;
        cout << "Enter Administrator Password: " << endl;
        cin >> adminPassword;

    if(adminUsername == "admin" && adminPassword == 1234)
    {
        cout << "Correct password!.." << endl;
        adminAccount();
    }
    else{
        cout << "Incorrect password!.. TRY AGAIN" << endl;
        goto E;
    }
}

//adminAccount Function
void adminAccount(){
    int option;
    float deposit;
    float amount = 0;

     E:
        cout << "\n-----------------------------------" << endl;
        cout << "****WELCOME TO THE ADMINISTRATOR PAGE****" << endl;
        cout << "-----------------------------------" << endl;
        cout << "1. Register new user" << endl;
        cout << "2. Approve User's car rent request" << endl;
        cout << "3. Update system on returned car." << endl;
        cout << "4. Change password" << endl;
        cout << "\n Enter Option to Proceed: " << endl;
        cin >> option;
    switch(option)
    {
    case 1:
    	
        cout << "\nEnter users deposit ";
        cin >> deposit;
        if(deposit<10500) 
		{
			cout<<"user does not have minimum deposit flat fee"<<endl;
		}
		else{
		
        cout << "Successfully registered:"  << endl;
        cout << endl;
        cout << "------------------------------------------------" << endl;
        cout << endl;
        break;	}

    case 2:
        
        cout << "'n'You have approved this users request to rent  a car" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << endl;
        
    
       
    case 3:
        cout << "\nyou have updated the system on the returned" << endl;
       
        break;
    case 4:
    	Register();
        cout << "\nYou have succesfully changed your password" << endl;
        cout << "------------------------------------------------" << endl;
        cout << endl;
        break;

    default:
        cout << "Invalid option PLEASE TRY AGAIN!.." << endl;
        cout << endl;
        

    }
}

// Administrator register NewUser
void Register()
{
    string user;
    string pass;
    int deposit;
    ifstream file;
    ofstream newuser;
    string username, password, passwordconfirm;
    file.open("users.txt", ios::app);
    newuser.open("users.txt", ios::app);
    bool uservalid=false;
    while (!uservalid)
    {
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;
        cout << "Confirm password: ";
        cin >> passwordconfirm;
        cout << "Deposit Amount: ";
        cin >> deposit;

        int m=0;
        int k=0;
        while (file >> user >> pass >> deposit)
        {
            m++;
            if (username!=user)
                k++;
        }
        if (m==k && password==passwordconfirm)
            uservalid=true;
        else if (m!=k)
            cout << "There is already a user with this username." << endl;
        else
            cout << "The passwords given do not match." << endl;
    }
    newuser << username << " " << password << " " << deposit << endl;
    file.close();
    newuser.close();
}