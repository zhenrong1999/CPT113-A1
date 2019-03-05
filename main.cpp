#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <sstream>
#include <algorithm>
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
        name="empty";
        nomatric=0;
        gender="empty";
        address="empty";
        email="empty";
        nophone="empty";
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
    int j;int i=0;
    profile student[100];
    bool cond=true;
    while(cond)
    {
    system("cls");
    cout<<"Input data by"<<endl<<"1. Key in\n2. Files\n3. Cond."<<endl;
    cin>>j;
    if(j==1) //key in for the student info manually
    {
    string Name,a,gender,address,email,nophone;
    int nomatric;
    system("cls");
    cout<<"Name of the student: "<<endl;
    cin.clear();cin.ignore();
    getline(cin,Name);
    cout<<"No. matric of the student: "<<endl;
    cin>>nomatric;
    cout<<"Gender of the student(male/female): "<<endl;
    cin>>gender;
    cout<<"Address of the student: "<<endl;
    cin.clear();cin.ignore();
    getline(cin,address);
    cout<<"Email of the student: "<<endl;
    cin>>email;
    cout<<"Phone number of the student: "<<endl;
        cin>>nophone;
        cout<<Name<<" " <<nomatric<<" " <<gender<<" "<<address<<" "<<email<< " "<<nophone<<endl;
        student[i].change(Name,nomatric,gender,address, email,nophone);
        cout<<student[i].getname()<<" "<<student[i].getmatric()<<" "<<student[i].getgender()<<" "<<student[i].getaddress()<<" "<<student[i].getemail()<<" "<<student[i].getnophone(); // put into the class as a member

        i++;
    }
    else if(j==2)
{
    ifstream readf("file1.txt"); //read file function
    if (!readf)
        cout<<"Fail to read file";
    else
        {
                string line;

                while(!readf.eof()) //start reading
                {
                getline(readf,line);
                readline(line,student,i);
                i++;
            }
                cout<<" sucess..."<<endl; //read finished
        }
}
    else if(j==3)   // exit the loop for the menu
        cond=false;
}
                system("cls");
                cout<<"Filter \n";      //filter menu
                cout<<"1. Gender \n2. Display All \n3. Name\n4. Sorting\n";

                cin>>j;
                switch (j)
                    {
                case 1:
                    cout<< "1. Filter as Male \n"<<"2. Filter as Female \n";
                    cin>>j;
                    if(j==1)
                        for(int k=0;k<i;k++)
                            if(student[k].getgender()=="male")  //search one by one for male
                                cout<<student[k].getname()<<" "<<student[k].getmatric()<<" "<<student[k].getgender()<<" "<<student[k].getaddress()<<" "<<student[k].getemail()<<" "<<student[k].getnophone()<<endl;
                        else if(j==2)
                            for(int k=0;k<i;k++)
                                if(student[k].getgender()=="female")     //search one by one for female
                                    cout<<student[k].getname()<<" "<<student[k].getmatric()<<" "<<student[k].getgender()<<" "<<student[k].getaddress()<<" "<<student[k].getemail()<<" "<<student[k].getnophone()<<endl;
                    break;
                case 2:
                    for(int k=0;k<i;k++)     //show all
                        cout<<student[k].getname()<<" "<<student[k].getmatric()<<" "<<student[k].getgender()<<" "<<student[k].getaddress()<<" "<<student[k].getemail()<<" "<<student[k].getnophone()<<endl;
                    break;
                case 3:
                    char str;
                    cout<<"First Alphabet : \n";
                    cin>>str;
                    for(int k=0;k<i;k++)
                    {
                        if(student[k].getname().at(0)==str)  //search one by one for the first alphabet
                            cout<<student[k].getname()<<" "<<student[k].getmatric()<<" "<<student[k].getgender()<<" "<<student[k].getaddress()<<" "<<student[k].getemail()<<" "<<student[k].getnophone()<<endl;
                    }
                    break;
                case 4:
                    cout<<"1. By Name\n2.By No. Matric\n";
                    cin>>j;
                    if (j==1)
                    {
                        sort(student, student + i,[](profile  a, profile  b) -> bool{ return a.getname() < b.getname(); } );    //sorting the student according to the name of the student
                        for(int k=0;k<i;k++)
                        cout<<student[k].getname()<<" "<<student[k].getmatric()<<" "<<student[k].getgender()<<" "<<student[k].getaddress()<<" "<<student[k].getemail()<<" "<<student[k].getnophone()<<endl;
                    }
                    else if(j==2)
                    {
                        sort(student, student + i,[](profile  a, profile  b) -> bool{ return a.getmatric() < b.getmatric(); } );    //sorting according to the no. matric
                        for(int k=0;k<i;k++)
                        cout<<student[k].getname()<<" "<<student[k].getmatric()<<" "<<student[k].getgender()<<" "<<student[k].getaddress()<<" "<<student[k].getemail()<<" "<<student[k].getnophone()<<endl;
                    }
                        break;
                }
        }


void readline(string line,profile student[],int i)
{
    stringstream readl; //let the string like cout and cin
    readl.str(line); //set line as the read
    string Name,a,gender,address,email,nophone;
    int nomatric;
    readl>>Name>>a;
    while(!checkfordigit(a))    //read text until numbers.
    {
        Name.insert(Name.length()," "+a); //add the string a after the original string name
        readl>>a;
    }
    nomatric=stoi(a);
    readl>>gender>>address>>email;
    while(!emailcheck(email))
    {
        address.insert(address.length()," "+email);  //add the string email after the original string address
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
