#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;


class academicStatus {

	private:
		double gpa;
		double cgpa;
		string status;
		int accumulatedCredit;
		int muetBand;

	public:
		double getGpa();
		double getCgpa();
		string getStatus();
		int getAccumulatedcredit();
		int getMuetband();
		void setData(string,string,string,string,string,string);
		void displayData();
		academicStatus();
		~academicStatus();
};

double academicStatus::getGpa(){
	return gpa;
}

double academicStatus :: getCgpa(){
	return cgpa;
}

string academicStatus :: getStatus(){
	return status;
}

int academicStatus :: getAccumulatedcredit(){
	return accumulatedCredit;
}

int academicStatus :: getMuetband(){
	return muetBand;
}

academicStatus :: academicStatus(){
		gpa=0;
		cgpa=0;
		status="";
		accumulatedCredit=0;
		muetBand=1;

}

void academicStatus :: setData(string studentGpa,string studentCgpa,string studentStatus,string studentAccumulatedcredit,string studentMuetband,string studentMatricnumber){
		gpa=stod(studentGpa);
		cgpa=stod(studentCgpa);
		status=studentStatus;
		accumulatedCredit=stoi(studentAccumulatedcredit);
		muetBand=stoi(studentMuetband);


}

 academicStatus :: ~academicStatus(){
		gpa=0;
		cgpa=0;
		status="";
		accumulatedCredit=0;
		muetBand=1;
}

void academicStatus :: displayData(){
cout<<"Gpa : "<<gpa<<endl;
cout<<"Cgpa : " <<cgpa<<endl;
cout<<"Status : "<<status<<endl;
cout<<"Accumulated credit : "<<accumulatedCredit<<endl;
cout<<"Muet band : "<<muetBand<<endl;
cout<<endl<<endl;
}

class courselist
{
private:
  string *course,*grade,*cu;
public:
  courselist(){}
  courselist(string Coursein[],int CUin[],string Gradein[],int size)
  {
    course = new string [size];
    grade = new string [size];
    cu = new string [size];
    for(int i=0;i<size;i++)
    {
      course[i]=Coursein[i];
      grade[i]=Gradein[i];
      cu[i]=CUin[i];
    }
  }

    void course_set(string Coursein[],string CUin[],string Gradein[],int size)
    {
      course = new string [size];
      grade = new string [size];
      cu = new string [size];
      for(int i=0;i<size;i++)
      {
        course[i]=Coursein[i];
        grade[i]=Gradein[i];
        cu[i]=CUin[i];
      }

  }
};

class profile : public academicStatus
{
    string name;
    string nomatric;
    string gender;
    string address;
    string email;
    string nophone;
    courselist Coursetable;
    public:
    profile()
    {
        name="empty";
        nomatric="0";
        gender="empty";
        address="empty";
        email="empty";
        nophone="empty";
    }

    profile(string Name, string Nomatric, string Gender, string Address, string Email, string NoPhone)
    {
     name=Name;
     nomatric=Nomatric;
     gender=Gender;
     address=Address;
     email=Email;
     nophone=NoPhone;
    }
    void change(string Name, string Nomatric, string Gender, string Address, string Email, string NoPhone)
    {
     name=Name;
     nomatric=Nomatric;
     gender=Gender;
     address=Address;
     email=Email;
     nophone=NoPhone;
    }
    void course_change(string Coursein[],string CUin[],string Gradein[],int size)
    {
       Coursetable.course_set (Coursein, CUin, Gradein,  size);
    }
    string getname()
       {
           return name;
       }
    string getmatric()
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

//user defined function

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

void keyIn_by_SY(profile unfilterList[],int &i){

    string studentGpa;
	string studentCgpa;
	string studentStatus;
	string studentAccumulatedcredit;
	string studentMuetband;
	string studentMatricnumber;
	bool checking=true;
	string choice5;

	do{
	cout<<"Key in student matric number."<<endl;
	cin>>studentMatricnumber;

	if(studentMatricnumber.find_first_not_of("1234567890")!=string::npos || studentMatricnumber.length()!=6){

		cout<<"Please key in only integer and proper data. The student's data is not recorded in here."<<endl<<endl<<endl;
		continue;}

	cout<<"Key in student's gpa."<<endl;
	cin>>studentGpa;
	system("cls");

	if(studentGpa.find_first_not_of("1234567890.")!=string::npos || stod(studentGpa)>4.0){

		cout<<"Please key in only integer and proper data. Key in data again."<<endl<<endl<<endl;
		continue;}

	cout<<"Key in student's cgpa."<<endl;
	cin>>studentCgpa;
	system("cls");

	if(studentCgpa.find_first_not_of("1234567890.")!=string::npos || stod(studentCgpa)>4.0){

		cout<<"Please key in only integer and proper data. Key in data again."<<endl<<endl<<endl;
		continue;}

	cout<<"Key in student's status."<<endl;
	cin>>studentStatus;
	system("cls");

	cout<<"Key in student's accumulated credit."<<endl;
	cin>>studentAccumulatedcredit;
	system("cls");

	if(studentAccumulatedcredit.find_first_not_of("1234567890.")!=string::npos){

		cout<<"Please key in only integer and proper data. Key in data again."<<endl<<endl<<endl;
		continue;}

	cout<<"Key in student's muet band."<<endl;
	cin>>studentMuetband;
	system("cls");

	if(studentMuetband.find_first_not_of("1234567890.")!=string::npos || stoi(studentMuetband)>6){

		cout<<"Please key in only integer and proper data. Key in data again."<<endl<<endl<<endl;
		continue;}

	unfilterList[i].setData(studentGpa,studentCgpa,studentStatus,studentAccumulatedcredit,studentMuetband,studentMatricnumber);

	cout<<"Do you wish to continue key in another student's data?"<<endl<<endl;
	cout<<"1. Yes"<<endl;
	cout<<"2. No"<<endl<<endl<<endl<<endl;

	cout<<"*Maximum 100 students' data only";
	cin>>choice5;
	system("cls");
	i++;

	if(choice5=="2"){

		checking=false;
	}

}while(checking==true && i<10);

	for(int j=0;j<i;j++){

		unfilterList[j].displayData();
	}

	cout<<endl<<"Above is the data you had just key in."<<endl<<endl;

}


void readfile1(profile student[],int &i)
{
        ifstream readf("file1.txt"); //read file function
        stringstream readl; //let the string like cout and cin
    if (!readf)
        cout<<"Fail to read file";
    else
        {
                string line;
                string Name,a,gender,address,email,nophone;
                int nomatric;
                while(!readf.eof()) //start reading
                {
                    getline(readf,line);
                    readl.clear();
                    readl.str(line); //set line as the read
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
                    student[i].change(Name,a,gender,address, email,nophone);
                    cout<<student[i].getname()<<" "<<student[i].getmatric()<<" "<<student[i].getgender()<<" "<<student[i].getaddress()<<" "<<student[i].getemail()<<" "<<student[i].getnophone();
                    i++;
                }
                cout<<" sucess..."<<endl; //read finished
        }
}

void readfile2(profile unfilterList[])
{
    string studentGpa;
	string studentCgpa;
	string studentStatus;
	string studentAccumulatedcredit;
	string studentMuetband;
	string studentMatricnumber;

	ifstream infile;
	infile.open("file2.txt");

	for(int i=0;i<100;i++){

	if(infile.eof()){
		break;
	}

	infile>>studentMatricnumber>>studentGpa>>studentCgpa>>studentStatus>>studentAccumulatedcredit>>studentMuetband;

	if(studentMatricnumber.find_first_not_of("1234567890")!=string::npos || studentMatricnumber.length()!=6){
		cout<<"There is an error in matric number section of any one of the students' profile. The student's data is not recorded in here."<<endl<<endl<<endl;
		continue;}

	if(studentGpa.find_first_not_of("1234567890.")!=string::npos || stod(studentGpa)>4){
		cout<<"There is an error in gpa section of any one of the students' profile. The student's data is not recorded in here."<<endl<<endl<<endl;
		continue;}

	if(studentCgpa.find_first_not_of("1234567890.")!=string::npos || stod(studentCgpa)>4){
		cout<<"There is an error in cgpa section of any one of the students' profile. The student's data is not recorded in here."<<endl<<endl<<endl;
		continue;}

	if(studentAccumulatedcredit.find_first_not_of("1234567890.")!=string::npos ){
		cout<<"There is an error in accumulated credit section of any one of the students' profile. The student's data is not recorded in here."<<endl<<endl<<endl;
		continue;}

	if(studentMuetband.find_first_not_of("1234567890.")!=string::npos || stoi(studentMuetband)<1 || stoi(studentMuetband)>6 ){
		cout<<"There is an error in muet band section of any one of the students' profile. The student's data is not recorded in here."<<endl<<endl<<endl;
		continue;
	}

	unfilterList[i].setData(studentGpa,studentCgpa,studentStatus,studentAccumulatedcredit,studentMuetband,studentMatricnumber);
	unfilterList[i].displayData();

}
}

int readfile3(profile stu[])
{
    ifstream readf("file3.txt"); //read file function
    if (!readf)
        cout<<"Fail to read file";
    else
        {
                string line;
                string course[100],grade[100];
                string nomatric[100],cu[100];
                int i=0;
                int nostu=0;
                string x;
                while(!readf.eof()) //start reading
                {
                    getline(readf,line);
                    stringstream readl; //let the string like cout and cin
                    readl.str(line); //set line as the read
                    readl>>x;
                    if (x!=nomatric[i-1])
                    {
                        stu[nostu].course_change(course,cu,grade,i);
                        nostu++;
                        i=0;
                    }
                    nomatric[i]=x;
                    readl>>course[i]>>cu[i]>>grade[i];
                    cout<<nomatric[i]<<course[i]<<cu[i]<<grade[i]<<endl;
                    i++;
                }
                cout<<" sucess..."<<endl; //read finished
        }
}

void filter_by_zr(int i,profile student[])
{
                cout<<"Filter \n";      //filter menu
                cout<<"1. Gender \n2. Display All \n3. Name\n4. Sorting\n";
                int j;
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


void filtering_by_SY(profile unfilterList[]){

	string choice3;
	string choice4;

	system("cls");

	cout<<"Filter by :"<<endl;
	cout<<"0. Matric number"<<endl;
	cout<<"1. Gpa more than or equal to 2.0"<<endl;
	cout<<"2. Cgpa more than or equal to 2.0 "<<endl;
	cout<<"3. Status "<<endl;
	cout<<"4. Accumulated credit more than or equal to 60 credit hours"<<endl;
	cout<<"5. Muet band 4 or higher"<<endl;
	cin>>choice3;

	if(choice3=="1"){

		system("cls");

		for(int i=0;i<10;i++){

			if(unfilterList[i].getGpa()>=2.0){
				unfilterList[i].displayData();
			}
		}

	}

	else if( choice3=="2"){

		system("cls");

		for(int i=0;i<10;i++){

			if(unfilterList[i].getCgpa() >=2.0){
				unfilterList[i].displayData();
			}
		}

	}

	else if(choice3=="3"){

		system("cls");

		cout<<"1. Active"<<endl;
		cout<<"2. P1"<<endl;
		cout<<"3. P2"<<endl;
		cout<<"4. FO"<<endl;
		cin>>choice4;


		if(choice4=="1"){

		system("cls");

		for(int i=0;i<10;i++){

			if(unfilterList[i].getStatus()=="active"){
				unfilterList[i].displayData();
			}
		}
	}

		else if(choice4=="2"){

			system("cls");

			for(int i=0;i<10;i++){

			if(unfilterList[i].getStatus()=="P1"){
				unfilterList[i].displayData();
			}
		}
		}

		else if(choice4=="3"){

			system("cls");

			for(int i=0;i<10;i++){

			if(unfilterList[i].getStatus()=="P2"){
				unfilterList[i].displayData();
			}
		}
	}

		else if(choice4=="4"){

			system("cls");

			for(int i=0;i<10;i++){

			if(unfilterList[i].getStatus()=="FO"){
				unfilterList[i].displayData();
			}
		}
	}

	else{
		system("cls");

		cout<<"Incorrect input, please try again next time ( key in only 1 / 2 / 3 /4) "<<endl;
	}

}

		else if(choice3=="4"){

			system("cls");

			for(int i=0;i<10;i++){

			if(unfilterList[i].getAccumulatedcredit()>=60){
				unfilterList[i].displayData();
			}
		}
		}

		else if(choice3=="5"){

			system("cls");

			for(int i=0;i<10;i++){

			if(unfilterList[i].getMuetband()>=4){
				unfilterList[i].displayData();
			}
		}
		}

		else if(choice3=="0"){

			system("cls");
			string matric;

			cout<<"Key in the student's matric number."<<endl;
			cin>>matric;

			for(int i=0;i<10;i++){

				if(matric == unfilterList[i].getmatric()){
				unfilterList[i].displayData();
			}
		}
}
}



int main()
{
    int j;int i=0;
    profile student[100];
    bool cond=true;
    while(cond)
    {
    system("cls");
    cout<<"Input data by"<<endl<<"1. Key in\n2. Files\n3. Continue"<<endl;
    cin>>j;
    if(j==1) //key in for the student info manually
    {
    string Name,a,gender,address,email,nophone;
    string nomatric;
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
        readfile(student,i); //size of object class.???
        readfile2(student);
        readfile3(student);
    }
    else if(j==3)   // exit the loop for the menu
        cond=false;
}
        system("cls");
        while(true)
        filter_by_zr(i,student);
}

