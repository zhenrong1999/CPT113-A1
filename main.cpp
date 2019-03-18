#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <sstream>
#include <algorithm>
#include <limits>
#include <iomanip>
#include <cmath>

using namespace std;

class academicStatus
//class that store GPA,CGPA,Status,Accumulated credit and MUET band. Have change function which change all variable(GPA,CGPA,Status,Accumulated credit and MUET band) at once.
{
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
void academics_set(string,string,string,string,string);
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
	//constructor function
	gpa=0;
	cgpa=0;
	status="";
	accumulatedCredit=0;
	muetBand=1;

}

void academicStatus :: academics_set(string studentGpa,string studentCgpa,string studentStatus,string studentAccumulatedcredit,string studentMuetband){
	//change all variable(GPA,CGPA,Status,Accumulated credit and MUET band) at once.
	gpa=stod(studentGpa);
	cgpa=stod(studentCgpa);
	status=studentStatus;
	accumulatedCredit=stoi(studentAccumulatedcredit);
	muetBand=stoi(studentMuetband);


}

academicStatus :: ~academicStatus(){
	//destructor function
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
//class that store list of course,grade and course unit.Consist of change function which change all varible(course,grade and course unit) at once
{
private:
string *course,*grade,*cu;//cu is course unit.
int size_of_list=0;
public:									//function AGtoG(change name), function calculate GPA.
courselist(){
}
courselist(string Coursein[],int CUin[],string Gradein[],int size)
{
	course = new string [size];
	grade = new string [size];
	cu = new string [size];
	size_of_list=size;
	for(int i=0; i<size; i++)
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
	size_of_list=size;
	for(int i=0; i<size; i++)
	{
		course[i]=Coursein[i];
		grade[i]=Gradein[i];
		cu[i]=CUin[i];
	}

}

int getsizeoflist()
{
	return size_of_list;
}

string getcourse(int index_number)
{
	return course[index_number];
}

string getgrade(int index_number)
{
	return grade[index_number];
}

string getcourseunit(int index_number)
{
	return cu[index_number];
}

};

class profile : public academicStatus
{ //class that contain all student data(name,no.matric,gender,address,email and no. phone) and function that change the variable of all variable.
//class is derived from class academicStatus.
//class that composite with class Coursetable.
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
void change(string Name, string Nomatric, string Gender, string Address, string Email, string NoPhone) //function is used to add name,no. matric, gender, address, email and no. phone during data input via keyboard or files.
{
	name=Name;
	nomatric=Nomatric;
	gender=Gender;
	address=Address;
	email=Email;
	nophone=NoPhone;
}
void course_change(string Coursein[],string CUin[],string Gradein[],int size) //function that access to the function course_set in class courselist.
{
	Coursetable.course_set (Coursein, CUin, Gradein,  size);//function used to add in course, course unit and grade.
}

void changeNomatric(string Nomatric) //function that change only no. matric
{
	nomatric=Nomatric;
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

int getsizeoflist()
{
	return Coursetable.getsizeoflist();
}

string getcourse(int index_number)
{
	return Coursetable.getcourse(index_number);
}

string getgrade(int index_number)
{
	return Coursetable.getgrade(index_number);
}

string getcourseunit(int index_number)
{
	return Coursetable.getcourseunit(index_number);
}

};

//template class
template <class type>
int binarysearch(int begin,int end, type arr[],type search) //binary search is a search method used to search an object from an arry and give the index_number number of the object in the arry.
{
	int half;
	bool finding=false;
	do
	{
		//cout<<begin<<" "<<end<<endl;
		half=floor((end-begin)/2)+begin;
		if(arr[half]==search)
		{
			finding=true;
			return half;
		}
		else if(search>arr[half])
		{
			begin=++half+begin;
		}
		else if(search<arr[half])
		{
			end=end-half-1;
		}

		if(begin>=end)
		{
			finding=true;
		}
	} while(!finding);
	return -1;
}

//user defined function

bool checkfordigit(const string X)
{
	char str[X.length()];
	for (unsigned int j =0; j<X.length(); j++) //change the string into array of char because isdigit accept char.
		str[j]=X[j];
	for (unsigned int i =0; i<X.length(); i++) //check one by one.
	{
		if (!isdigit(str[i])) //check for digit
			return false;
	}
	return true;
}

bool emailcheck(const string X)
{
	for (unsigned int i =0; i<X.length(); i++) //check one by one.
	{
		if (X[i]=='@') //check for digit
			return true;
	}
	return false;
}

float AGtoG(string AG)//convert Alphabet to numeric //copy to courselist
{
	if (AG=="A")
		return 4.00;
	else if(AG=="A-")
		return 3.67;
	else if (AG=="B+")
		return 3.33;
	else if (AG=="B")
		return 3.00;
	else if(AG=="B-")
		return 2.67;
	else if(AG=="C+")
		return 2.33;
	else if(AG=="C")
		return 2.00;
	else if (AG=="C-")
		return 1.67;
	else if(AG=="D+")
		return 1.33;
	else if (AG=="D")
		return 1.00;
	else if (AG=="D-")
		return 0.67;
	else if(AG=="F")
		return 0.00;
	else
		return -1;
}

void get_array_of_no_matric(string arr[],int studentCount,profile student[])
{
	sort(student, student + studentCount,[](profile a, profile b) -> bool {
		return a.getmatric() < b.getmatric();
	} );
	for(int i=0; i<studentCount; i++)
		arr[i]=student[i].getmatric();
}

void get_array_of_name(string arr[],int studentCount,profile student[])
{
	sort(student, student + studentCount,[](profile a, profile b) -> bool {
		return a.getname() < b.getname();
	} );
	for(int i=0; i<studentCount; i++)
		arr[i]=student[i].getname();
}

void display_student_data(profile student[],int i)
{
	cout<<left<<setw(3)<<"1. "<<setw(20)<<"Name: "<<student[i].getname()<<endl;
	cout<<left<<setw(3)<<"2. "<<setw(20)<<"No. matric: "<<student[i].getmatric()<<endl;
	cout<<left<<setw(3)<<"3. "<<setw(20)<<"Gender: "<<student[i].getgender()<<endl;
	cout<<left<<setw(3)<<"4. "<<setw(20)<<"Address: "<<student[i].getaddress()<<endl;
	cout<<left<<setw(3)<<"5. "<<setw(20)<<"Email: "<<student[i].getemail()<<endl;
	cout<<left<<setw(3)<<"6. "<<setw(20)<<"No. phone: "<<student[i].getnophone()<<endl;
	cout<<left<<setw(3)<<"7. "<<setw(20)<<"GPA: "<<student[i].getGpa()<<endl;
	cout<<left<<setw(3)<<"8. "<<setw(20)<<"CGPA: "<<student[i].getCgpa()<<endl;
	cout<<left<<setw(3)<<"9. "<<setw(20)<<"Status: "<<student[i].getStatus()<<endl;
	cout<<left<<setw(3)<<"10. "<<setw(20)<<"Accumulated Credit: "<<student[i].getAccumulatedcredit()<<endl;
	cout<<left<<setw(3)<<"11. "<<setw(20)<<"Muet band: "<<student[i].getMuetband()<<endl;
	cout<<left<<setw(3)<<"12. "<<"Course list"<<endl;
	cout<<internal<<"|"<<setw(6)<<"No."<<"|"<<setw(7)<<"Course"<<"|"<<setw(12)<<"Course Unit"<<"|"<<setw(6)<<"Grade"<<"|"<<endl;
	for(int j=0; j<student[i].getsizeoflist(); j++)
	{
		cout<<internal<<"|"<<setw(6)<<j+1<<". "<<"|"<<setw(7)<<student[i].getcourse(j)<<"|"<<setw(12)<<student[i].getcourseunit(j)<<"|"<<setw(6)<<student[i].getgrade(j)<<"|"<<endl;
	}
}

void keyIn_by_SY(int &studentCount,profile student[])
{
	string studentGpa;
	string studentCgpa;
	string studentStatus;
	string studentAccumulatedcredit;
	string studentMuetband;
	char choice;
	string Name,gender,address,email,nophone;
	string nomatric;
	bool checking=false;
	int no_of_course;
	//loop for the key in data of the student
	do {
		cout<<"Name of the student: "<<endl; //tell user to type in the name of the student
		cin.clear(); cin.ignore();
		getline(cin,Name); //get the name for the student
		cout<<"No. matric of the student: "<<endl; //tell user to type in the no. matric of the student
		cin>>nomatric;  //get the no. matric for the student
		//verify the no. matric key in is verified to the format of it which is six integer
		if(nomatric.find_first_not_of("1234567890")!=string::npos || nomatric.length()!=6) {

			cout<<"Please key in only integer and proper data. The student's data is not recorded in here."<<endl<<endl<<endl;//display error message to the user to key in only integer
			continue;
		}

		cout<<"Gender of the student(male/female): "<<endl;
		cin>>gender;

		if(gender!="male" && gender != "female") {

			cout<<"Please key in only male or female. The student's data is not recorded in here."<<endl<<endl<<endl;
			continue;
		}

		cout<<"Address of the student: "<<endl;
		cin.clear(); cin.ignore();
		getline(cin,address);

		cout<<"Email of the student: "<<endl;
		cin>>email;

		if(emailcheck(email)==false) {

			cout<<"Please key in only peoper data. The student's data is not recorded in here."<<endl<<endl<<endl;
			continue;
		}

		cout<<"Phone number of the student: "<<endl;
		cin>>nophone;

		if(checkfordigit(nophone)==false) {

			cout<<"Please key in only peoper data. The student's data is not recorded in here."<<endl<<endl<<endl;
			continue;
		}

		student[studentCount].change(Name,nomatric,gender,address, email,nophone);
		system("cls");
		cout<<"Key in student's gpa."<<endl;
		cin>>studentGpa;


		if(studentGpa.find_first_not_of("1234567890.")!=string::npos || stod(studentGpa)>4.0) {

			cout<<"Please key in only integer and proper data. Key in data again."<<endl<<endl<<endl;
			continue;
		}

		cout<<"Key in student's cgpa."<<endl;
		cin>>studentCgpa;


		if(studentCgpa.find_first_not_of("1234567890.")!=string::npos || stod(studentCgpa)>4.0) {

			cout<<"Please key in only integer and proper data. Key in data again."<<endl<<endl<<endl;
			continue;
		}

		cout<<"Key in student's status."<<endl;
		cout<<"1. Active"<<endl;
		cout<<"2. P1"<<endl;
		cout<<"3. P2"<<endl;
		cout<<"4. FO"<<endl;
		cin>>choice;
		switch (choice)
		{
		case '1':      studentStatus="Active"; break;
		case '2':      studentStatus="P1";     break;
		case '3':      studentStatus="P2";     break;
		case '4':      studentStatus="FO";     break;
		default:
			cout<<"Please key in only integer and proper data. Key in data again."<<endl<<endl<<endl;
			cin.clear(); cin.ignore( numeric_limits<int>::max(),'\n'); //discard all the input from cin.
			continue;
		}


		cout<<"Key in student's accumulated credit."<<endl;
		cin>>studentAccumulatedcredit;


		if(studentAccumulatedcredit.find_first_not_of("1234567890.")!=string::npos) {

			cout<<"Please key in only integer and proper data. Key in data again."<<endl<<endl<<endl;
			continue;
		}

		cout<<"Key in student's muet band."<<endl;
		cin>>studentMuetband;


		if(studentMuetband.find_first_not_of("1234567890")!=string::npos || stoi(studentMuetband)>6) {

			cout<<"Please key in only integer and proper data. Key in data again."<<endl<<endl<<endl;
			continue;
		}

		student[studentCount].academics_set(studentGpa,studentCgpa,studentStatus,studentAccumulatedcredit,studentMuetband);
		system("cls");

		cout<<"Key in the number of course. (default: 7)"<<endl;
		do
		{
			try
			{
				cin>>no_of_course;
			}
			catch(...)
			{
				cout<<"Your can't an alphabet."<<endl;
			}
			if(no_of_course<0)
			{
				cout<<"You can't input number less than or equal to 0"<<endl;
			}
		} while(no_of_course<0);
		string *course= new string[no_of_course];
		string *cu= new string[no_of_course];
		string *grade= new string[no_of_course];
		int input;
		for(int i=0; i<no_of_course; i++)
		{
			cout<<i+1<<". Course Code: ";
			cin>>course[i];
			while(course[i].length()!=6)
			{
				cout<<"Please try again.\n";
				cout<<i+1<<". Course Code: ";
				cin>>course[i];
			}
			cout<<i+1<<". Course Unit: ";
			cin>>input;
			while(!(input>0))
			{
				cout<<"Please try again with positive integer.\n";
				cout<<i+1<<". Course Unit: ";
				cin.clear(); cin.ignore();
				cin>>input;
			}
			cu[i]=to_string(input);
			cout<<i+1<<". Grade: ";
			cin>>grade[i];
			while(AGtoG(grade[i])==-1)
			{
				cout<<"Please try again with valid grade.\n";
				cout<<i+1<<". Grade: ";
				cin>>grade[i];
			}
		}
		student[studentCount].course_change(course,cu,grade,no_of_course);
		cout<<"Do you wish to continue key in another student's data?"<<endl<<endl; //ask the user to key in new student profile or no
		cout<<"1. Yes"<<endl;
		cout<<"2. No"<<endl<<endl<<endl<<endl;

		cout<<"*Maximum 100 students' data only"<<endl;
		cin>>choice;

		if(choice=='1') {
			checking=true;
		}

		else  {
			cin.clear(); cin.ignore(numeric_limits<int>::max(),'\n'); //discard all the cin input.
		}
		studentCount++;
	} while(checking==true && studentCount<100);

	for(int j=0; j<studentCount; j++)
		display_student_data(student,j);

	cout<<endl<<"Above is the data you had just key in."<<endl<<endl;
	system("pause");
}

void update_data(const int studentCount,profile student[])
{
	string studentGpa;
	string studentCgpa;
	string studentStatus;
	string studentAccumulatedcredit;
	string studentMuetband;
	char choice;
	string Name,gender,address,email,nophone;
	string nomatric;
	string nomatricarry[studentCount];
	int index_number;
	cout<<"Update Menu"<<endl;
	do
	{
		cout<<"Key in the no. matric of the student (-1 to return)"<<endl;
		cin>>nomatric;
		if(nomatric=="-1")
		{return;}
		if(nomatric.find_first_of("1234567890")!=string::npos && nomatric.length()==6)
		{
			get_array_of_no_matric(nomatricarry,studentCount,student);
			index_number=binarysearch(0,studentCount,nomatricarry,nomatric);
			if(index_number==-1)
			{
				cout<<"Student not found in the database."<<endl;
			}
			else
			{
				cout<<"Student Found"<<endl;
				break;
			}
		}
		else
		{
			cout<<"Please try again"<<endl;
		}
	} while(true);
	//loop for the update the data of the student
	int no_menu;
	bool updating=true;
do{
	system("pause");
	system("cls");
	display_student_data(student,index_number);
	cout<<endl;
	cout<<"To change the student data key in the number in front of each line. For updating courses, please key in 12."<<endl;
	cout<<"Attention! Number matric of student cannot be changed."<<endl;
	cin>>no_menu;

 	switch(no_menu)
	{
		case -1:
		updating=false;
		break;
		case 1:
		cout<<"Name of the student: "<<endl; //tell user to type in the name of the student
		cin.clear(); cin.ignore();
		getline(cin,Name); //get the name for the student
		if(nomatric.find_first_not_of("1234567890")!=string::npos || nomatric.length()!=6) {

			cout<<"Please key in only integer and proper data. The student's data is not recorded in here."<<endl<<endl<<endl;//display error message to the user to key in only integer
			continue;
		}
		student[index_number].change(Name,student[index_number].getmatric(),student[index_number].getgender(),student[index_number].getaddress(), student[index_number].getemail(),student[index_number].getnophone());
		break;

		case 3:
		cout<<"Gender of the student(male/female): "<<endl;
		cin>>gender;

		if(gender!="male" && gender != "female") {

			cout<<"Please key in only male or female. The student's data is not recorded in here."<<endl<<endl<<endl;
			continue;
		}
		student[index_number].change(student[index_number].getname(),student[index_number].getmatric(),gender,student[index_number].getaddress(), student[index_number].getemail(),student[index_number].getnophone());
		break;

		case 4:
		cout<<"Address of the student: "<<endl;
		cin.clear(); cin.ignore();
		getline(cin,address);
		student[index_number].change(student[index_number].getname(),student[index_number].getmatric(),student[index_number].getgender(),address, student[index_number].getemail(),student[index_number].getnophone());
		break;

		case 5:
		cout<<"Email of the student: "<<endl;
		cin>>email;

		if(emailcheck(email)==false) {

			cout<<"Please key in only peoper data. The student's data is not recorded in here."<<endl<<endl<<endl;
			continue;
		}
		student[index_number].change(student[index_number].getname(),student[index_number].getmatric(),student[index_number].getgender(),student[index_number].getaddress(),email ,student[index_number].getnophone());
		break;

		case 6:
		cout<<"Phone number of the student: "<<endl;
		cin>>nophone;

		if(checkfordigit(nophone)==false) {

			cout<<"Please key in only peoper data. The student's data is not recorded in here."<<endl<<endl<<endl;
			continue;
		}
		student[index_number].change(student[index_number].getname(),student[index_number].getmatric(),student[index_number].getgender(),student[index_number].getaddress(), student[index_number].getemail(),nophone);

		break;

case 7:
		cout<<"Key in student's gpa."<<endl;
		cin>>studentGpa;


		if(studentGpa.find_first_not_of("1234567890.")!=string::npos || stod(studentGpa)>4.0) {

			cout<<"Please key in only integer and proper data. Key in data again."<<endl<<endl<<endl;
			continue;
		}
		student[index_number].academics_set(studentGpa,to_string(student[index_number].getCgpa()),student[index_number].getStatus(),to_string(student[index_number].getAccumulatedcredit()),to_string(student[index_number].getMuetband()));

break;

case 8:
		cout<<"Key in student's cgpa."<<endl;
		cin>>studentCgpa;


		if(studentCgpa.find_first_not_of("1234567890.")!=string::npos || stod(studentCgpa)>4.0) {

			cout<<"Please key in only integer and proper data. Key in data again."<<endl<<endl<<endl;
			continue;
		}
		student[index_number].academics_set(to_string(student[index_number].getGpa()),studentCgpa,student[index_number].getStatus(),to_string(student[index_number].getAccumulatedcredit()),to_string(student[index_number].getMuetband()));

break;

case 9:
		cout<<"Key in student's status."<<endl;
		cout<<"1. Active"<<endl;
		cout<<"2. P1"<<endl;
		cout<<"3. P2"<<endl;
		cout<<"4. FO"<<endl;
		cin>>choice;
		switch (choice)
		{
		case '1':      studentStatus="Active"; break;
		case '2':      studentStatus="P1";     break;
		case '3':      studentStatus="P2";     break;
		case '4':      studentStatus="FO";     break;
		default:
			cout<<"Please key in only integer and proper data. Key in data again."<<endl<<endl<<endl;
			cin.clear(); cin.ignore( numeric_limits<int>::max(),'\n'); //discard all the input from cin.
			continue;
		}
		student[index_number].academics_set(to_string(student[index_number].getGpa()),to_string(student[index_number].getCgpa()),studentStatus,to_string(student[index_number].getAccumulatedcredit()),to_string(student[index_number].getMuetband()));

break;

case 10:
		cout<<"Key in student's accumulated credit."<<endl;
		cin>>studentAccumulatedcredit;


		if(studentAccumulatedcredit.find_first_not_of("1234567890.")!=string::npos) {

			cout<<"Please key in only integer and proper data. Key in data again."<<endl<<endl<<endl;
			continue;
		}
		student[index_number].academics_set(to_string(student[index_number].getGpa()),to_string(student[index_number].getCgpa()),student[index_number].getStatus(),studentAccumulatedcredit,to_string(student[index_number].getMuetband()));

break;

case 11:
		cout<<"Key in student's muet band."<<endl;
		cin>>studentMuetband;


		if(studentMuetband.find_first_not_of("1234567890")!=string::npos || stoi(studentMuetband)>6) {

			cout<<"Please key in only integer and proper data. Key in data again."<<endl<<endl<<endl;
			continue;
		}
		student[index_number].academics_set(to_string(student[index_number].getGpa()),to_string(student[index_number].getCgpa()),student[index_number].getStatus(),to_string(student[index_number].getAccumulatedcredit()),studentMuetband);
break;

case 12:
		int no_of_course=student[index_number].getsizeoflist();
		string *course= new string[no_of_course];
		string *cu= new string[no_of_course];
		string *grade= new string[no_of_course];
		do
		{
		system("cls");
		cout<<left<<setw(3)<<"1. "<<setw(20)<<"Name: "<<student[index_number].getname()<<endl;
		cout<<left<<setw(3)<<"2. "<<setw(20)<<"No. matric: "<<student[index_number].getmatric()<<endl;
		cout<<left<<setw(3)<<"12. "<<"Course list"<<endl;
		cout<<internal<<"|"<<setw(4)<<"No."<<"|"<<setw(7)<<"Course"<<"|"<<setw(12)<<"Course Unit"<<"|"<<setw(6)<<"Grade"<<"|"<<endl;
		for(int j=0; j<student[index_number].getsizeoflist(); j++)
		{
			cout<<internal<<"|"<<setw(4)<<j+1<<". "<<"|"<<setw(7)<<student[index_number].getcourse(j)<<"|"<<setw(12)<<student[index_number].getcourseunit(j)<<"|"<<setw(6)<<student[index_number].getgrade(j)<<"|"<<endl;
			course[j]=student[index_number].getcourse(j);
			cu[j]=student[index_number].getcourseunit(j);
			grade[j]=student[index_number].getgrade(j);
		}

		cout<<"Key in the number in front of the course to be changed. (to exit key in -1)"<<endl;
		cin>>no_menu;
		do
		{
			try
			{
				cin>>no_menu;
			}
			catch(...)
			{
				cout<<"Your can't an alphabet."<<endl;
			}
			if(no_menu<0)
			{
				cout<<"You can't input number less than or equal to 0"<<endl;
			}
		} while(no_menu<0);

		int input;
		if (no_menu==-1)
		 break;
		int i=no_menu-1;
			cout<<i+1<<". Course Code: ";
			cin>>course[i];
			while(course[i].length()!=6)
			{
				cout<<"Please try again.\n";
				cout<<i+1<<". Course Code: ";
				cin>>course[i];
			}
			cout<<i+1<<". Course Unit: ";
			cin>>input;
			while(!(input>0))
			{
				cout<<"Please try again with positive integer.\n";
				cout<<i+1<<". Course Unit: ";
				cin.clear(); cin.ignore();
				cin>>input;
			}
			cu[i]=input;
			cout<<i+1<<". Grade: ";
			cin>>grade[i];
			while(AGtoG(grade[i])==-1)
			{
				cout<<"Please try again with valid grade.\n";
				cout<<i+1<<". Grade: ";
				cin>>grade[i];
			}

	}while(true);
	student[index_number].course_change(course,cu,grade,no_of_course);
}


}while(updating);

	system("cls");
		display_student_data(student,index_number);

	cout<<endl<<"Above is the data you had just key in."<<endl<<endl;
	system("pause");
}


void readfile1(profile student[],int &studentCount,const int max_student)
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
			if(studentCount<=max_student)
			{
				getline(readf,line);
				readl.clear(); //clear the contain in the read1 stringstream
				readl.str(line); //set line as the string read by read1
				readl>>Name>>a;
				while(!checkfordigit(a)) //read text until numbers.
				{
					Name.insert(Name.length()," "+a); //add the string a after the original string name
					readl>>a;
				}
				nomatric=stoi(a);
				readl>>gender>>address>>email;
				while(!emailcheck(email))
				{
					address.insert(address.length()," "+email); //add the string email after the original string address
					readl>>email;
				}
				readl>>nophone;
				cout<<Name<<" " <<nomatric<<" " <<gender<<" "<<address<<" "<<email<< " "<<nophone<<endl;
				student[studentCount].change(Name,a,gender,address, email,nophone);
				cout<<student[studentCount].getname()<<" "<<student[studentCount].getmatric()<<" "<<student[studentCount].getgender()<<" "<<student[studentCount].getaddress()<<" "<<student[studentCount].getemail()<<" "<<student[studentCount].getnophone()<<endl;
				studentCount++;
			}
			else
			{
				cout<<"Acheive max number of student.Please change the max number of student to higher value"<<endl;
				cout<<"Below are the student not key in into the database."<<endl;
				getline(readf,line);
				while(!readf.eof())
				{
					cout<<line<<endl;
				}
				break;
			}
		}
		cout<<"file 1 is loaded..."<<endl; //read finished
		system("pause");
	}
}

void readfile2(profile student[],int &studentCount,const int max_student)
{
	string studentGpa;
	string studentCgpa;
	string studentStatus;
	string studentAccumulatedcredit;
	string studentMuetband;
	string studentMatricnumber;
	string line;
	int i=0;
	ifstream infile;
	infile.open("file2.txt");
	stringstream read2;     //let the string like cout and cin

	while(!infile.eof()) {
		read2.clear();  //clear the contain in the read1 stringstream
		getline(infile,line);
		read2.str(line); //set line as the string read by read1
		read2>>studentMatricnumber>>studentGpa>>studentCgpa>>studentStatus>>studentAccumulatedcredit>>studentMuetband;

		if(studentMatricnumber.find_first_not_of("1234567890")!=string::npos || studentMatricnumber.length()!=6) {
			cout<<"There is an error in matric number section of any one of the students' profile. The student's data is not recorded in here."<<endl<<endl<<endl;
			continue;
		}

		if(studentGpa.find_first_not_of("1234567890.")!=string::npos || stod(studentGpa)>4) {
			cout<<"There is an error in gpa section of any one of the students' profile. The student's data is not recorded in here."<<endl<<endl<<endl;
			continue;
		}


		if(studentCgpa.find_first_not_of("1234567890.")!=string::npos || stod(studentCgpa)>4) {
			cout<<"There is an error in cgpa section of any one of the students' profile. The student's data is not recorded in here."<<endl<<endl<<endl;
			continue;
		}

		if(studentAccumulatedcredit.find_first_not_of("1234567890.")!=string::npos ) {
			cout<<"There is an error in accumulated credit section of any one of the students' profile. The student's data is not recorded in here."<<endl<<endl<<endl;
			continue;
		}

		if(studentMuetband.find_first_not_of("1234567890.")!=string::npos || stoi(studentMuetband)<1 || stoi(studentMuetband)>6 ) {
			cout<<"There is an error in muet band section of any one of the students' profile. The student's data is not recorded in here."<<endl<<endl<<endl;
			continue;
		}

		if(studentMatricnumber==student[i].getmatric())
		{
			cout<<student[i].getmatric()<<" ";
			student[i].academics_set(studentGpa,studentCgpa,studentStatus,studentAccumulatedcredit,studentMuetband);
			student[i].displayData();
		}

		else
		{
			cout<<"Dislocation occur at "<<studentMatricnumber<<endl;
			int j=i+1;
			bool success = false;
			for(int k=0; k<studentCount; k++)
			{
				if(studentMatricnumber==student[j].getmatric())
				{
					student[j].academics_set(studentGpa,studentCgpa,studentStatus,studentAccumulatedcredit,studentMuetband);
					student[j].displayData();
					success=true;
					break;
				}
				j++;
				if(j>=studentCount)
				{j=0;}
			}
			if(success==false)
			{
				cout<<"student Not Found in the database.Adding new one."<<endl;
				cout<<"No matric of new student is "<<studentMatricnumber;
				student[studentCount].changeNomatric(studentMatricnumber);
				student[studentCount++].academics_set(studentGpa,studentCgpa,studentStatus,studentAccumulatedcredit,studentMuetband);
				student[studentCount-1].displayData();
			}
		}
		i++;
	}
	cout<<"File 2 is loaded..."<<endl;
	system("pause");
}

void readfile3(profile student[],int &studentCount,const int max_student)
{
	ifstream readf("file3.txt"); //read file function
	if (!readf)
		cout<<"Fail to read file";
	else
	{
		string line;
		string course[100],grade[100];
		string nomatric[100],cu[100];
		int size=0;
		int nostudent=0;
		string x;
		stringstream readl; //let the string like cout and cin
		bool success=false;
		while(!(readf.eof()&&success)) //start reading
		{
			success = false;
			getline(readf,line);
			readl.clear();
			readl.str(line); //set line as the read
			readl>>x;
			if(x==nomatric[size-1]||size==0)
			{
				nomatric[size]=x;
				readl>>course[size]>>cu[size]>>grade[size];
				cout<<nomatric[size]<<course[size]<<cu[size]<<grade[size]<<endl;
				size++;
			}
			if ((x!=nomatric[size-1]&&size>0)||readf.eof())
			{
				if(nomatric[size-1]==student[nostudent].getmatric())
				{
					student[nostudent].course_change(course,cu,grade,size);
					nostudent++;
					size=0;
				}
				else
				{
					cout<<"Dislocation occur at "<<nomatric[size-1]<<endl;
					int j=nostudent+1;

					for(int k=0; k<studentCount; k++)
					{
						if(nomatric[size-1]==student[j].getmatric())
						{
							cout<<"student Found in the database.Adding course."<<endl;
							student[j].course_change(course,cu,grade,size);
							size=0;
							success=true;
							break;
						}
						j++;
						if(j>=studentCount)
						{j=0;}
					}
					if(success==false)
					{
						cout<<"student Not Found in the database.Adding new one."<<endl;
						cout<<"No matric of new student is "<<nomatric[size-1];
						student[studentCount].changeNomatric(nomatric[size-1]);
						student[studentCount++].course_change(course,cu,grade,size);
						size=0;
						success=true;
					}
				}
				if(!readf.eof())
				{
					nomatric[size]=x;
					readl>>course[size]>>cu[size]>>grade[size];
					cout<<nomatric[size]<<course[size]<<cu[size]<<grade[size]<<endl;
					size++;
				}
			}
		}

		cout<<" File 3 is loaded..."<<endl; //read finished
		system("pause");
	}
}

void filtering_by_SY(profile student[],int studentCount){

	string choice3;
	string choice4;

	system("cls");

	cout<<"Filter by :"<<endl;
	cout<<"1. Gpa more than or equal to 2.0"<<endl;
	cout<<"2. Cgpa more than or equal to 2.0 "<<endl;
	cout<<"3. Status "<<endl;
	cout<<"4. Accumulated credit more than or equal to 60 credit hours"<<endl;
	cout<<"5. Muet band 4 or higher"<<endl;
	cin>>choice3;

	if(choice3=="1") {

		system("cls");

		for(int i=0; i<studentCount; i++) {

			if(student[i].getGpa()>=2.0) {
				student[i].displayData();
			}
		}

	}

	else if( choice3=="2") {

		system("cls");

		for(int i=0; i<studentCount; i++) {

			if(student[i].getCgpa() >=2.0) {
				student[i].displayData();
			}
		}

	}

	else if(choice3=="3") {

		system("cls");

		cout<<"1. Active"<<endl;
		cout<<"2. P1"<<endl;
		cout<<"3. P2"<<endl;
		cout<<"4. FO"<<endl;
		cin>>choice4;


		if(choice4=="1") {

			system("cls");

			for(int i=0; i<studentCount; i++) {

				if(student[i].getStatus()=="active") {
					student[i].displayData();
				}
			}
		}

		else if(choice4=="2") {

			system("cls");

			for(int i=0; i<studentCount; i++) {

				if(student[i].getStatus()=="P1") {
					student[i].displayData();
				}
			}
		}

		else if(choice4=="3") {

			system("cls");

			for(int i=0; i<studentCount; i++) {

				if(student[i].getStatus()=="P2") {
					student[i].displayData();
				}
			}
		}

		else if(choice4=="4") {

			system("cls");

			for(int i=0; i<studentCount; i++) {

				if(student[i].getStatus()=="FO") {
					student[i].displayData();
				}
			}
		}

		else{
			system("cls");

			cout<<"Incorrect input, please try again next time ( key in only 1 / 2 / 3 /4) "<<endl;
		}

	}

	else if(choice3=="4") {

		system("cls");

		for(int i=0; i<studentCount; i++) {

			if(student[i].getAccumulatedcredit()>=60) {
				student[i].displayData();
			}
		}
	}

	else if(choice3=="5") {

		system("cls");

		for(int i=0; i<studentCount; i++) {

			if(student[i].getMuetband()>=4) {
				student[i].displayData();
			}
		}
	}
}

void filter_by_zr(int studentCount,profile student[])
{
	cout<<"Filter Menu\n";              //filter menu
	cout<<"1. Display All\n2.Search by matric no.\n3.Name for first alphabet  \n4.Gender \n5. Sorting\n6. Filter GPA,CGPA,Status,Accumulated credit and MUET\n";
	int j; string nomatric;
	cin>>j;
	switch (j)
	{
	case 1:
		for(int k=0; k<studentCount; k++)       //show all
		{display_student_data(student,k);
		 cout<<"----------------------------------------------------------------------------------------------"<<endl;}
		break;

	case 2:
		cout<<"Key in the student's matric number."<<endl;
		cin>>nomatric;

		for(int k=0; k<studentCount; k++) {
			if(nomatric == student[k].getmatric())
			{
				display_student_data(student,k);
				break;
			}
			if(k==studentCount-1)
			{
				cout<<"Student not in database."<<endl;
				break;
			}
		}

		break;

	case 3:
		char str;
		cout<<"First Alphabet : \n";
		cin>>str;
		for(int k=0; k<studentCount; k++)
		{
			if(student[k].getname().at(0)==str)  //search one by one for the first alphabet
			{display_student_data(student,k);
			 cout<<"----------------------------------------------------------------------------------------------"<<endl;}
		}
		break;

	case 4:
		cout<< "1. Filter as Male \n"<<"2. Filter as Female \n";
		cin>>j;
		if (j==1)
		{
			for(int k=0; k<studentCount; k++)
				if(student[k].getgender()=="male")         //search one by one for male
				{display_student_data(student,k);
				 cout<<"----------------------------------------------------------------------------------------------"<<endl;}
		}
		else if(j==2)
			for(int k=0; k<studentCount; k++)
				if(student[k].getgender()=="female")             //search one by one for female
				{display_student_data(student,k);
				 cout<<"----------------------------------------------------------------------------------------------"<<endl;}
		break;

	case 5:
		cout<<"1. By Name\n2.By No. Matric\n";
		cin>>j;
		if (j==1)
		{
			sort(student, student + studentCount,[](profile a, profile b) -> bool {
				return a.getname() < b.getname();
			} );                                                                                                        //sorting the student according to the name of the student in ascending order
			for(int k=0; k<studentCount; k++)
			{display_student_data(student,k);
			 cout<<"----------------------------------------------------------------------------------------------"<<endl;}
		}
		else if(j==2)
		{
			sort(student, student + studentCount,[](profile a, profile b) -> bool {
				return a.getmatric() < b.getmatric();
			} );                                                                                                                //sorting according to the no. matric in ascending order
			for(int k=0; k<studentCount; k++)
			{display_student_data(student,k);
			 cout<<"----------------------------------------------------------------------------------------------"<<endl;}
		}
		break;
	case 6:
		filtering_by_SY(student,studentCount);
		break;
		case 7:
		generate_report(student,studentCount);
		break;
	}
	system("pause");
}



int main()
{
	system("color 02");
	int j;
	int studentCount=0; //Keep track of the total number of student read.
	int max_student=100;    //The maximum number of student can be read.
	profile *pointer; //dynamic array of object of profile
	pointer=new profile [max_student];
	while(true)
	{
		system("cls");
		cout<<"Input data by"<<endl<<"1. Key in\n2. Files\n3. Continue\n4. Change maximum number to be processed (Current:)"<<max_student<<endl;
		cout<<"5. Update data\n"<<"6. Exit"<<endl;
		cin>>j;
		if(j==1) //key in for the student info manually
		{
			if(studentCount<max_student)
				keyIn_by_SY(studentCount,pointer);
			else
			{
				cout<<"The database is full!!"<<endl;
				system("pause");
			}
		}
		//  cout<<student[i].getname()<<" "<<student[i].getmatric()<<" "<<student[i].getgender()<<" "<<student[i].getaddress()<<" "<<student[i].getemail()<<" "<<student[i].getnophone(); // put into the class as a member

		else if(j==2)
		{
			readfile1(pointer,studentCount,max_student);
			readfile2(pointer,studentCount,max_student);
			readfile3(pointer,studentCount,max_student);
			system("cls");
			for(int i=0; i<studentCount; i++)
			{
				display_student_data(pointer,i);
				cout<<"----------------------------------------------------------------------------------------------"<<endl;
			}
			system("pause");
		}
		else if(j==3)  {// exit the loop for the menu
			system("cls");
			filter_by_zr(studentCount,pointer);
		}
		else if(j==4)
		{
			cout<<"Enter the maximum student you want (Default:100)"<<endl;
			cin>>j;
			if(studentCount==0)
			{
				max_student=j;
				delete []pointer; pointer= new profile[max_student];
			}
			if(studentCount>0)
			{
				profile *temperary;
				temperary =new profile[max_student];
				for(int i=0; i<studentCount; i++)
				{
					temperary[i]=pointer[i];
				}
				max_student=j;
				delete []pointer; pointer= new profile[max_student];
				for(int i=0; i<studentCount; i++)
				{
					pointer[i]=temperary[i];
				}
				delete []temperary;
			}


		}
		else if(j==5)
			update_data(studentCount,pointer);
		else if(j==6)
			return 0;
		else
		{
			continue;
		}
	}
}
