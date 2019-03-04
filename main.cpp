#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <sstream>
using namespace std;

class profile
{
    string name;
    int nomatric;
    string gender;
    string address;
    string email;
    string nophone;
    public:
    profile()
    {
        name="null";
        nomatric=0;
        gender="null";
        address="null";
        email="null";
        nophone="null";
    }

    profile(string Name, int Nomatric, string Gender, string Address, string Email, string NoPhone)
    {
     name=Name;
     nomatric=Nomatric;
     gender=Gender;
     address=Address;
     email=Email;
     nophone=NoPhone;
    }
    void change(string Name, int Nomatric, string Gender, string Address, string Email, string NoPhone)
    {
     name=Name;
     nomatric=Nomatric;
     gender=Gender;
     address=Address;
     email=Email;
     nophone=NoPhone;
    }
    string getname()
       {
           return name;
       }
    int getmatric()
    {
        return nomatric;
    }

    string getgender()
    {
        return gender;
    }

    string getaddress()
    {
        return address;
    }
    string getemail()
    {
        return email;
    }
     string getnophone()
     {
         return nophone;
     }
};

bool checkfordigit(const string X);
bool emailcheck(const string X);
void readline(string line,profile student[],int i);
int main()
{
    ifstream readf("file1.txt");
    if (!readf)
        cout<<"Fail to read file";
    else
        {
                string line;
                int i=0;
                profile student[100];
                while(!readf.eof())
                {
                getline(readf,line);
                readline(line,student,i);
                i++;
            }
                cout<<" sucess..."<<endl;
                system("cls");
                cout<<"Filter \n";
                cout<<"1. Gender \n2. Display All \n3. Name\n4. \n";
                int j;
                cin>>j;
                if(j==1)
                {
                    cout<< "1. Filter as Male \n"<<"2. Filter as Female \n";
                    cin>>j;
                    if(j==1)
                        for(int k=0;k<i;k++)
                            if(student[k].getgender()=="male")
                                cout<<student[k].getname()<<" "<<student[k].getmatric()<<" "<<student[k].getgender()<<" "<<student[k].getaddress()<<" "<<student[k].getemail()<<" "<<student[k].getnophone()<<endl;
                        else if(j==2)
                            for(int k=0;k<i;k++)
                                if(student[k].getgender()=="female")
                                    cout<<student[k].getname()<<" "<<student[k].getmatric()<<" "<<student[k].getgender()<<" "<<student[k].getaddress()<<" "<<student[k].getemail()<<" "<<student[k].getnophone()<<endl;
                }
                if(j==2)
                    for(int k=0;k<i;k++)
                        cout<<student[k].getname()<<" "<<student[k].getmatric()<<" "<<student[k].getgender()<<" "<<student[k].getaddress()<<" "<<student[k].getemail()<<" "<<student[k].getnophone()<<endl;
                if(j==3)
                {
                    char str;
                    char a;
                    cout<<"First Alphabet : \n";
                    cin>>str;
                    for(int k=0;k<i;k++)
                    {
                        a=student[k].getname()[0];
                        if(a==str)
                            cout<<student[k].getname()<<" "<<student[k].getmatric()<<" "<<student[k].getgender()<<" "<<student[k].getaddress()<<" "<<student[k].getemail()<<" "<<student[k].getnophone()<<endl;
                    }
                }
        }
}

void readline(string line,profile student[],int i)
{
    stringstream readl;
    readl.str(line);
    string Name,a,gender,address,email,nophone;
    int nomatric;
    readl>>Name>>a;
    while(!checkfordigit(a))    //read text until numbers.
    {
        Name.insert(Name.length()," "+a);
        readl>>a;
    }
    nomatric=stoi(a);
    readl>>gender>>address>>email;
    while(!emailcheck(email))
    {
        address.insert(address.length()," "+email);
        readl>>email;
    }
        readl>>nophone;
        cout<<Name<<" " <<nomatric<<" " <<gender<<" "<<address<<" "<<email<< " "<<nophone<<endl;
        student[i].change(Name,nomatric,gender,address, email,nophone);
        cout<<student[i].getname()<<" "<<student[i].getmatric()<<" "<<student[i].getgender()<<" "<<student[i].getaddress()<<" "<<student[i].getemail()<<" "<<student[i].getnophone();
}


bool checkfordigit(const string X)
{
    char str[X.length()];
    for (unsigned int j =0;j<X.length();j++)    //change the string into array of char because isdigit accept char.
        str[j]=X[j];
    for (unsigned int i =0;i<X.length();i++)   //check one by one.
    {
        if (!isdigit(str[i]))   //check for digit
            return false;
    }
    return true;
}

bool emailcheck(const string X)
{
    for (unsigned int i =0;i<X.length();i++)   //check one by one.
    {
        if (X[i]=='@')   //check for digit
            return true;
    }
    return false;
}
