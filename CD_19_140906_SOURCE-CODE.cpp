#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class academicStatus {
	
	private:
		double gpa;
		double cgpa;
		string status;
		int accumulatedCredit;
		int muetBand;
		int matricNumber;
	
	public:
		double getGpa();
		double getCgpa();
		string getStatus();
		int getAccumulatedcredit();
		int getMuetband();
		int getMatricnumber();
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

int academicStatus :: getMatricnumber(){
	
	return matricNumber;
}


academicStatus :: academicStatus(){
	
		gpa=0;
		cgpa=0;
		status="";
		accumulatedCredit=0;
		muetBand=1;
		matricNumber=0;
	
}
void academicStatus :: setData(string studentGpa,string studentCgpa,string studentStatus,string studentAccumulatedcredit,string studentMuetband,string studentMatricnumber){
	
		gpa=stod(studentGpa);
		cgpa=stod(studentCgpa);
		status=studentStatus;
		accumulatedCredit=stoi(studentAccumulatedcredit);
		muetBand=stoi(studentMuetband);
		matricNumber=stoi(studentMatricnumber);
	
		
}

 academicStatus :: ~academicStatus(){
	
		gpa=0;
		cgpa=0;
		status="";
		accumulatedCredit=0;
		muetBand=1;
		matricNumber=0;
}

void academicStatus :: displayData(){

cout<<"Matric number : "<<matricNumber<<endl;	
cout<<"Gpa : "<<gpa<<endl;
cout<<"Cgpa : " <<cgpa<<endl;
cout<<"Status : "<<status<<endl;
cout<<"Accumulated credit : "<<accumulatedCredit<<endl;
cout<<"Muet band : "<<muetBand<<endl;

cout<<endl<<endl;
}




int main(){
	
	string studentGpa;
	string studentCgpa;
	string studentStatus;
	string studentAccumulatedcredit;
	string studentMuetband;
	string studentMatricnumber;
	academicStatus unfilterList[10];
	string choice1;
	void readfile(string&,string&,string&, string&,string&,academicStatus[],string&);
	bool checking=false;
	string choice2;
	void filtering(academicStatus[]);
	void keyIn(string&,string&,string&,string&,string&,academicStatus[],string&);
	
	
	while(true){
	
	cout<<"1. Key in data now."<<endl;
	cout<<"2. Read data from file"<<endl;
	cin>>choice1;
	
	if(choice1=="1"){
		system("cls");
		keyIn(studentGpa,studentCgpa,studentStatus,studentAccumulatedcredit,studentMuetband,unfilterList,studentMatricnumber);
		checking=true;
		break;
		
	}
	
	else if(choice1=="2"){
		system("cls");
		readfile(studentGpa,studentCgpa,studentStatus,studentAccumulatedcredit,studentMuetband,unfilterList,studentMatricnumber);
		checking=true;
		break;
	}
	
	else{
		continue;
	}
}

while(checking==true){
	
	cout<<"1. Do you wan to filter some information?"<<endl;
	cout<<"2. Exit"<<endl;
	cin>>choice2;
	
	if(choice2=="1"){
		
	filtering(unfilterList);
	break;
	}
	
	else if(choice2=="2"){
	break;
	}
	
	else{
			continue;
	}
}

cout<<endl<<"Thank you for using this programme, feel free to use again next time !"<<endl;
system("pause");
}


void readfile(string& studentGpa,string& studentCgpa,string& studentStatus,string& studentAccumulatedcredit,string& studentMuetband,academicStatus unfilterList[],string& studentMatricnumber){

	
	ifstream infile;
	infile.open("academic list.txt");
	
	for(int i=0;i<10;i++){
	
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
		continue;}
	
	
	unfilterList[i].setData(studentGpa,studentCgpa,studentStatus,studentAccumulatedcredit,studentMuetband,studentMatricnumber);
	unfilterList[i].displayData();
	
}
}


void filtering(academicStatus unfilterList[]){
	
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
				
				if(matric == to_string(unfilterList[i].getMatricnumber())){
				unfilterList[i].displayData();
			}
		}
}
}

void keyIn(string& studentGpa,string& studentCgpa,string& studentStatus,string& studentAccumulatedcredit,string& studentMuetband,academicStatus unfilterList[],string& studentMatricnumber){
	
	bool checking=true;
	string choice5;
	int i=0;

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
	
	cout<<"*Maximum 10 students' data only";
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

