#pragma once
#pragma warning(disable:4244)
#pragma warning(disable:4715)
#pragma warning(disable : 4996) 
#pragma warning (disable :4003)
#pragma warning (disable :4018)
#include <iostream>
#include <string>
#include <string.h>
#include <limits>
#include <cstring>
#include <ctime>
#include <fstream>
#include <time.h>
#include <sstream>
void DisplayCourse();

//void playcustomsound(std::string soundname) {
//	soundname = soundname + ".wav";
//	PlaySound(TEXT(soundname.c_str()), NULL, SND_SYNC);
//}

namespace {
#include "consoleDisplays.h"
}

int countsession();
template <typename T>
std::string NumberToString(T Number);

void rewritecountsession(int readnumber);
void StudentPromotion(void);
using namespace std;
class Date
{
	int day;
	int month;
	int year;
public:
	Date();
	void setday(int day);
	int getday()const;
	void setmonth(int month);
	int getmonth()const;
	void setyear(int year);
	int getyear()const;
	friend ostream& operator << (ostream& o, Date& obj);
	friend istream& operator >> (istream& i, Date &obj);

	////////////////////////


};
class Promotion {
	float mid1_weightage;
	float mid2_weightage;
	float final_weightage;
	float threshold;
public:
	Promotion();
	void SetMid1Weightage(float mid1_weightage);
	void SetMid2Weightage(float mid2_weightage);
	void SetFinalWeightage(float final_weightage);
	float GetMid1Weightage()const;
	float GetMid2Weightage()const;
	float GetFinalWeightage()const;
	void SetThreshold(float threshold);
	float GetThreshold()const;
};
class Student
{
	string first_name;
	string last_name;
	int class_number;
	string roll_number;
	Date date;
	char gender;
	string phone_number;
	string father_name;
	string fathers_profession;
	string parents_contact_number;
	bool fee_submitted;
	string blood_group;
	string address;
public:
	void setfirst_name(string first_name);
	string getfirst_name()const;
	void setlast_name(string last_name);
	string getlast_name()const;
	void setclass_number(int class_number);
	int getclass_number()const;
	void setroll_number(string roll_number);
	string getroll_number()const;
	void setdate(Date date);
	Date getdate()const;
	void setgender(char gender);
	char getgender()const;
	void setphone_number(string phone_number);
	string getphone_number()const;
	void setfather_name(string father_name);
	string getfather_name()const;
	void setfathers_profession(string fathers_profession);
	string getfathers_profession()const;
	void setparent_contact_number(string parent_contact_number);
	string getparent_contact_number()const;
	void setfee_submitted(bool fee_submitted);
	bool getfee_submitted()const;
	void setblood_group(string blood_group);
	string getblood_group()const;
	void setaddress(string address);
	string getaddress()const;
};
class Course {
	//protected:
	string parent_course;
	string course_code;
	string course_name;
	int class_number;
public:
	Course();
	//Setter's Getter's
	void SetParentCourse(string parent_course);
	string GetParentCourse()const;
	void SetCourseCode(string course_code);
	string GetCourseCode()const;
	void SetCourseName(string course_name);
	string GetCourseName()const;
	void SetClassNumber(int class_number);
	int GetClassNumber()const;
	Course* readCourse_forAssigning(Course *ptr,int &Size);
};


template<typename temp>
temp* increase(temp *ptr, int Size) {
	temp *_newptr = new temp[Size + 1];
	for (int i = 0; i < Size; i++) {
		_newptr[i] = ptr[i];
	}
	delete[] ptr;
	return _newptr;
}
class Admin;
template<typename dataType>
void take_input(std::string msg, dataType &input, dataType cond1, dataType cond2);
bool check_cnic(std::string input);
bool check_contactNo(std::string input);
void take_input(std::string msg, std::string &input, std::string custom);



class login // updated 15th june
{
private:
	std::string username;
	std::string password;
public:
	login* loadUsers(login *ptr, int &Size, std::string filename);
	bool Trylogin(std::string user, std::string pass);


	std::string get_username() const {
		return this->username;
	}
	std::string get_password() const {
		return this->password;
	}

	void set_Username(std::string username) {
		this->username = username;
	}
	void set_Password(std::string password) {
		this->password = password;
	}

	void set_username() {
		take_input("Enter the Username: ", this->username, "mix");
	}
	void set_password() {
		take_input("Enter the Password: ", this->password, "password");
	}

}; // class login ends here...


struct teacher_courses {
	std::string parentCourse;
	std::string courseName;
	std::string courseCode;
	int Class;
};

class Teacher {
private:
	std::string firstName; // common
	std::string lastName; // common
	std::string email; //not common
	Date joiningDate; // struct Date consists of day,month,year
	std::string username;
	std::string password;
	std::string confirmPassword;
	std::string cnic;
	std::string gender; // common
	std::string qualification; // not common
	std::string contactNo; // common
	Date dob; // not common
	std::string address; // common
	long int salary; // almost common compare to fee submmited
	teacher_courses *myCourses; int total_myCourses;

public:

	Teacher() { this->total_myCourses = 0; }


	void set_firstName();
	void set_lastName();
	void set_email();
	void set_joiningDate();
	void set_username();
	void set_password();
	void set_confirmPassword();
	void set_cnic();
	void set_gender();
	void set_qualification();
	void set_contactNo();
	void set_dob();
	void set_address();
	void set_salary();


	std::string get_firstName() const;
	std::string get_lastName() const;
	std::string get_email() const;
	std::string get_username() const;
	std::string get_password() const;
	std::string get_confirmPassword() const;
	std::string get_cnic() const;
	std::string get_gender() const;
	std::string get_qualification() const;
	std::string get_contactNo() const;
	Date get_dob() const;
	std::string get_address() const;
	long int get_salary() const;

	///////////////////////////////////////
	void writeTeacher(Teacher *ptr, const int Size); // write data on the file from the pointer
	Teacher* readTeacher(Teacher *ptr, int& Size); // reads data from the file and loads into the pointer
	void input_data(); // takes input from the user
	void update_at(); // updates data at required index...
	void assign_Course(std::string PC, std::string CN, std::string CC,int );
	void viewMyCourses();

	void resetMyCourses() { // added 15th june
		this->total_myCourses = 0;
		myCourses = NULL;
	}
	bool check_if_assigned(std::string checkCourse) { // added 15th june
		bool status = false;
		for (int i = 0; i < this->total_myCourses; i ++ ) {
			if (this->myCourses[i].courseName == checkCourse) {
				status=true;
			}
		}
		return status;
	}


	friend std::ostream &operator<<(std::ostream &out, const Teacher &obj) {
		out << "=----------------------------------------------------------=" << endl;
		out << "Full Name: " << obj.firstName << " " << obj.lastName << "\t";
		out << "Gender:  " << obj.gender << "\n";
		out << "Qualification: " << obj.qualification << "\n" ;
		out << "Contact No.: " << obj.contactNo << "\n";
		out << "Email @ : " << obj.email << "\n";
		out << "Address: " << obj.address << std::endl;
		out << "=----------------------------------------------------------=" << endl;
		out << "\n\n" << std::endl;
		return out;
	}

	// added  14th june 2020 , 1:49 pm
	int get_totalmycourses() const  {
		return this->total_myCourses;
	}
	int get_myCourseClass_at(int index) const {
		return this->myCourses[index].Class;
	}
	teacher_courses Get_courseInfo_at(int index) const {
		return this->myCourses[index];
	}
	std::string get_myCourseName_at(int index) const {
		return this->myCourses[index].courseName;
	}



protected:


}; // class teacher ends


class Admin {
private:
	Teacher *teachers; int total_number_teachers;
	login *adminUsers; int total_adminUsers; // for now implementation of the user and teacher login is going to be same
	login *studentUsers; int total_studentUsers;
	login *teacherUsers; int total_teacherUsers;
	Promotion promote;public:
/////////////////////////////////
	Student *student;
	int student_size;
	Course *course;
	int course_size;
	ifstream fin;
	ofstream fout;

public:
	Admin();
	Admin(const Admin  &obj);
	//Student's Functions
	void AddStudent(Student obj);
	// stop show me the errors just 
	// kam ho gya ha sai show me errors 
	Student getStudent(int ind)const;
	void setstudent_size(int student_size);
	int getstudent_size()const;
	void setStudent(Student obj, int ind);
	void FileRead();
	void WriteFile(ofstream &fout);
	//Course's Functions
	void AddCourse(Course obj);
	Course GetCourse(int ind)const;
	void SetCourseSize(int course_size);
	int GetCourseSize()const;
	void SetCourse(Course obj, int ind);
	void FileReadCourse();
	void WriteFileCourse(ofstream &fout);
	~Admin() {}
	void SetStudentPointer(int ind);

	void add_teacher_viaInput() { // updated 15th june

		teachers = increase(this->teachers, this->total_number_teachers);
		teachers[this->total_number_teachers].input_data();

		std::string username = teachers[this->total_number_teachers].get_firstName();
		std::string password = teachers[this->total_number_teachers].get_password();

		this->teacherUsers = increase(this->teacherUsers,this->total_teacherUsers);
		this->teacherUsers[this->total_teacherUsers].set_Username(username);
		this->teacherUsers[this->total_teacherUsers].set_Password(password);
		++this->total_teacherUsers;
		this->writeTeacherUsers();

		++this->total_number_teachers;
		this->teachers->writeTeacher(this->teachers, this->total_number_teachers);
		this->writeAssginedCourse(this->teachers,this->total_number_teachers);
		
	}

	void add_AdminUser_viaInput() {
		this->adminUsers = increase(this->adminUsers, this->total_adminUsers);
		std::cin.ignore();
		adminUsers[this->total_adminUsers].set_username();
		adminUsers[this->total_adminUsers].set_password();
		++this->total_adminUsers;
		this->writeAdminUsers();
	}
	//////////////////////////////////////////////// lOADING TEACHER,COURSE ////////////////////////////////////////////////////////

	void load_Teacher() { // here size = total numbers of objects exsisting
		teachers = this->teachers->readTeacher(this->teachers, this->total_number_teachers);

		this->Allot_TeacherCoursesFromFile();// added 14th june 2020 6:03 pm 
	}

	void load_Course() {
		this->course = this->course->readCourse_forAssigning(this->course,this->course_size);
	}

	//////////////////////////////////////////////// WRITE USERS ON FILE ////////////////////////////////////////////////////////
	void writeAdminUsers() {
		this->write_respective_File(this->adminUsers, this->total_adminUsers, "adminUsers.txt");
	}
	void writeStudentUsers() {
		this->write_respective_File(this->studentUsers, this->total_studentUsers, "studentUsers.txt");
	}
	void writeTeacherUsers() {
		this->write_respective_File(this->teacherUsers, this->total_teacherUsers, "TeacherUsers.txt");
	}
	//////////////////////////////////////////////// lOAD USERS INTO PROGRAM ////////////////////////////////////////////////////////

	void load_AdminUsers() {
		this->adminUsers = this->adminUsers->loadUsers(this->adminUsers, this->total_adminUsers, "adminUsers.txt");
	}
	void load_studentUsers() {
		this->studentUsers = this->studentUsers->loadUsers(this->studentUsers, this->total_studentUsers, "studentUsers.txt");
	}
	void load_teacherUsers() {
		this->teacherUsers = this->teacherUsers->loadUsers(this->studentUsers, this->total_teacherUsers, "TeacherUsers.txt");
	}
	//////////////////////////////////////////////// -=-=-=-=-=-=-=-=-=-=--= ////////////////////////////////////////////////////////


	bool login_AdminUser() {
		std::string user, password; bool loginStatus = false;
		std::cin.ignore();
		take_input("Enter User Name : ", user, "mix");
		//std::cin.ignore();
		take_input("Enter Password  : ", password, "mix");
		//std::cin.ignore();
		for (int i = 0; i < this->total_adminUsers; i++) {
			loginStatus = this->adminUsers[i].Trylogin(user, password);
			if (loginStatus == true) {
				break;
			}
		}
		return loginStatus;
	}

	bool login_TeacherUser() {
		std::string user, password; bool loginStatus = false;
		std::cin.ignore();
		take_input("Enter User Name : ", user, "mix");
		//std::cin.ignore();
		take_input("Enter Password  : ", password, "mix");
		//std::cin.ignore();
		for (int i = 0; i < this->total_teacherUsers; i++) {
			loginStatus = this->teacherUsers[i].Trylogin(user, password);
			if (loginStatus == true) {
				break;
			}
		}
		return loginStatus;
	}
	
	
	////////////////////////////////////////

	bool login_StudentUser(string &user) {
		std::string password; bool loginStatus = false;
		std::cin.ignore();
		take_input("Enter Your Roll Number : ", user, "mix");
		take_input("Enter Password  : ", password, "mix");

		for (int i = 0; i < this->total_studentUsers; i++) {
			loginStatus = this->studentUsers[i].Trylogin(user, password);
			if (loginStatus == true) {
				break;
			}
		}
		return loginStatus;
	}

	//////////////////////////////////////////
		
	void assignCourse() {

		this->course = this->course->readCourse_forAssigning(this->course,this->course_size);
		DisplayCourse();
		std::string CourseCode;
		std::cin.ignore();
		take_input("Enter the respective Course Code: ", CourseCode, "mix");
		std::string sameCourseCode = CourseCode;
		CourseCode = " " + CourseCode;
		bool assigned = false;
		for (int i = 0; i < this->course_size; i++) {

			if ( CourseCode == this->course[i].GetCourseCode() ) {

				this->view_allTeachers(); int pickTeacher;
				take_input("Enter the respective Number : ", pickTeacher, 0, this->total_number_teachers);
				std::string coursebeingassigned = this->course[i].GetCourseName();

				if (this->teachers[pickTeacher].check_if_assigned(coursebeingassigned)==true ) {
					// checks if course is already assigned....
					notification_console();
					std::cout << "\n\t\tCourse Already Assigned!" << std::endl;
					assigned = false;
					break;
				} else {
					this->teachers[pickTeacher].assign_Course(this->course[i].GetParentCourse(), this->course[i].GetCourseName(), sameCourseCode, this->course[i].GetClassNumber());
					assigned = true;
					break;
				}

			}

		}

		if (assigned == true) {
			notification_console();
			std::cout << "\n\t\tCourse was assigned Successfully!" << std::endl;
			writeAssginedCourse(this->teachers, this->total_number_teachers); // write to the file the changes
		} else {
			notification_console();
			std::cout << "\n\t\tCourse could'nt be assigned!" << std::endl;
		}
		system("pause");
	}

   protected: // added 14th june
    
  void writeAssginedCourse(Teacher const *Entity,int Size,std::string filename="Teacher_courses.txt") {
	  std::fstream file;
	  file.open(filename.c_str(),std::ios::out);
	  if (file.is_open()) {
		 
		  for (int i = 0; i < Size; i++) {
			  file << Entity[i].get_cnic()<<","<<  Entity[i].get_firstName() << "," << Entity[i].get_lastName() << ",";
			  file << Entity[i].get_totalmycourses() << " ";
			  
			  if (Entity[i].get_totalmycourses() == 0) {
				  file << " No Courses Assgined Yet " << std::endl;
			  } else {

				  for (int j = 0; j < Entity[i].get_totalmycourses();j++) {
					  teacher_courses temp = Entity[i].Get_courseInfo_at(j);
					  int local_class = temp.Class;
					  std::string local_courseCode = temp.courseCode;
					  std::string local_parentCourse = temp.parentCourse;
					  std::string local_courseName = temp.courseName;
					  file << local_class << "  " << local_courseCode <<","<< local_parentCourse <<","<<local_courseName << ",";
				  } // for loop ends here..
				  file << std::endl;

			  } // else condition ends here
		  } 
		  file.close();
	  }  else {
		  std::cout << "File Named Teacher_courses.txt  can't be opened" << std::endl;
	  }
	  system("pause");
  }


  void Allot_TeacherCoursesFromFile() {
	  std::fstream file;
	  file.open("Teacher_courses.txt",std::ios::in);
	  std::string local_firstname;
	  std::string local_lastname;
	  std::string local_cnic;
	  int local_size;

	  if (file.is_open()) {

		  while (!file.eof()) {

			  std::getline(file, local_cnic, ',');
			  std::getline(file, local_firstname, ',');
			  std::getline(file, local_lastname, ',');
			  file >> local_size;
			  int index = -1;

			  if (file.eof() == true) {
				  break;
			  }

			  for (int i = 0; i < this->total_number_teachers; i++) {
				  if (local_cnic == this->teachers[i].get_cnic() && local_firstname == this->teachers[i].get_firstName() && local_lastname==this->teachers[i].get_lastName() ){
					  index = i;
				  }
			  }

			  if (local_size != 0 && index>=0 ) {

				  int local_classno;
				  std::string local_coursecode;
				  std::string local_parentcourse;
				  std::string local_coursename;
				  for (int i = 0; i < local_size; i++) {
					  file >> local_classno;
					  std::getline(file,local_coursecode,',');
					  std::getline(file, local_parentcourse, ',');
					  std::getline(file, local_coursename, ',');
					  this->teachers[index].assign_Course(local_parentcourse,local_coursename,local_coursecode,local_classno);
				  }

			  }	 else {
				  std::string trash;
				  std::getline(file,trash);
				  continue;
			  }
		  } // 
		  file.close();
	  } else {
		  std::cout << "File Named Teacher_courses.txt  can't be loaded" << std::endl;
		  system("pause");
	  }

  }

   public: // added 14th june


	void updateTeacher() {
		for (int i = 0; i < total_number_teachers; i++) {
			std::cout << "Press " << i << " to update=-> ";
			std::cout << this->teachers[i].get_firstName() << " " << this->teachers[i].get_lastName() << "\t";
			std::cout << this->teachers[i].get_cnic() << std::endl;
		}
		int index;  take_input("Enter respective number: ", index, 0, this->total_number_teachers - 1);
		this->teachers[index].update_at();
		this->teachers->writeTeacher(this->teachers, this->total_number_teachers);
	}

	void view_allTeachers() {
		for (int i = 0; i < this->total_number_teachers; i++) {
			std::cout << "#" << i << ": " << this->teachers[i].get_firstName() << " " << this->teachers[i].get_lastName();
			std::cout << "\t\t" << this->teachers[i].get_cnic() << std::endl;
		}
	}

	public: // added 15th june 

		void reset_Teachers(std::string passFileName,bool admincontrol=false) {


			std::cout << "\t\tPress 1 to =-> Keep the Assigned Courses to Teachers" << std::endl;
			std::cout << "\t\tPress 2 to =-> Reset All Assigned Courses to Teachers" << std::endl;
			int choice; take_input("\t\tEnter the respective no. : ",choice ,1,2);
			
			if (admincontrol == false) {
				this->writeAssginedCourse(this->teachers, this->total_number_teachers, passFileName); // whereas passFileName = Teacher_coursesSession[some number].txt
			   //this->writeAssginedCourse(this->teachers,this->total_number_teachers); // add 3rd parameter a string like Teacher_coursesSession1.txt
			}

			if (choice == 2) {

				for (int i = 0; i < this->total_number_teachers; i++) {
					this->teachers[i].resetMyCourses();
				}
				this->writeAssginedCourse(this->teachers, this->total_number_teachers);

			} // no need for choice ==1 condition statements

		}

	////////////////////////////////// Teacher Portal SYSTEM GiveAWAY /////////////////////////////////////////////////

	int get_totalTeacherUsers() const {
		return this->total_number_teachers;
	}
	std::string get_Teacher_Username(int index) const {
		return this->teachers[index].get_username();
	}
	std::string get_Teacher_Password(int index) const {
		return this->teachers[index].get_password();
	}

	void viewSpecifiedTeacherCourses(int index) const {
		this->teachers[index].viewMyCourses();
	}

	int get_SpecifiedTeacherCourseCount(int index) const { // added 14th june 
		return this->teachers[index].get_totalmycourses();
	}

	int get_SpecifiedTeacherCourseClass(int index,int course) const {
		return this->teachers[index].get_myCourseClass_at(course);
	}
	std::string get_SpecifiedTeacherCourseName(int index, int courseindex) const {
		return this->teachers[index].get_myCourseName_at(courseindex);
	}


	Student* get_AllStudnets() const {
		return this->student;
	}
	int get_AllStudents_Count() const {
		return this->student_size;
	}

	////////// =-> addition 14th june ends here =-> ..............//


	void change_SpecifiedTeacherPassword(int index) { // added before 14th june // updated 15th june
		std::cin.ignore();
		std::cout << "=------------<< Enter New Password  >>--------------=" << std::endl;
		this->teachers[index].set_password();
		std::cout << "=------------<< Confirm New Password  >>--------------=" << std::endl;
		this->teachers[index].set_confirmPassword();

		this->teachers->writeTeacher(this->teachers,this->total_number_teachers);
		this->teacherUsers[index].set_Password(this->teachers[index].get_password() );

		this->writeTeacherUsers();
	}


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	void view_allTeachers_Details() const {
		if (this->total_number_teachers > 0) {
			for (int i = 0; i < this->total_number_teachers; i++) {
				std::cout << this->teachers[i];
			}
		} else {
			notification_console();
			std::cout << "\n\t\tNo Teacher Record Found" << std::endl;
		}

	}




protected:

	template<typename ptr>
	void write_respective_File(ptr *admin, const int Size, std::string fileName) {
		std::fstream file;
		file.open(fileName.c_str(), std::ios::out);
		if (file.is_open()) {
			for (int i = 0; i < Size; i++) {
				file << admin[i].get_username() << "," << admin[i].get_password() << std::endl;
			}
			file.close();
		}
		else {
			std::cout << "Error-File cant be opened" << std::endl;
		}
	}
};

/////////////////////////////////////////////////////////////////////////////
template<typename dataType>
void take_input(std::string msg, dataType &input, dataType cond1, dataType cond2);
string SpaceControl(string &name);
bool Number(string str);
bool Alphabet(string str);
string ValidNumber(string str);
string ValidAlphabet(string str);
string Input(string str);
template <class T>
T* ResizeInc(T *ptr, int size);
template <class T>
T* ResizeDec(T *ptr, int size);
template <class T>
T *Del(T *ptr, int size, int ind);

Student *Read(ifstream &fin, Student *ptr, int &size, int count);
Course *ReadCourse(ifstream &fin, Course *ptr, int &size, int count);
class CourseMarks {
	int total_marks_mid1;
	int total_marks_mid2;
	int total_marks_final;
	int obtained_marks_mid1;
	int obtained_marks_mid2;
	int obtained_marks_final;
	string course_name;
public:
	CourseMarks();
	void SetCourseName(string course_name);
	string GetCourseName()const;
	void SetTotalMarksMid1(int total_marks);
	int GetTotalMarksMid1()const;
	void SetTotalMarksMid2(int total_marks);
	int GetTotalMarksMid2()const;
	void SetTotalMarksFinal(int total_marks);
	int GetTotalMarksFinal()const;
	void SetObtainedMarksMid1(int obtained_marks);
	int GetObtainedMarksMid1()const;
	void SetObtainedMarksMid2(int obtained_marks);
	int GetObtainedMarksMid2()const;
	void SetObtainedMarksFinal(int obtained_marks);
	int GetObtainedMarksFinal()const;
	//Pass And Fail Method
	bool Status(double threshold, double mid1_weightage, double mid2_weightage, double final_weightage);
};

class StudentModule {
	string roll_number;
	int class_number;;
	CourseMarks *course;
	int course_size;
	////////////////

	bool status;
public:
	void SetStatus(Promotion);
	bool GetStatus()const;



public:
	StudentModule();
	void SetRollNumber(string roll_number);
	string GetRollNumber()const;
	void SetClassNumber(int class_number);
	int GetClassNumber()const;
	//Course's Functions
	void AddCourse(CourseMarks obj);
	CourseMarks GetCourse(int ind)const;
	void SetCourseSize(int course_size);
	int GetCourseSize()const;
	void SetCourse(CourseMarks obj, int ind);
};

void WriteCourseMarks(ofstream &fout, StudentModule *ptr, const int size);
void Write(ofstream &fout, Student *ptr, const int size);
void WriteCourse(ofstream &fout, Course *ptr, const int size);
void Display();
void DisplayCourse();
StudentModule* MarksUpdate(StudentModule *new_data, int &size, string ind,string,string );
void MarksView(StudentModule *new_data, int &size, string ind);
StudentModule *FileReadStudentCourses(StudentModule *file, int &sizefile);
void ListClass(string &ind);
StudentModule* FillingNewData(StudentModule *new_data, Admin &admin, int &size);
StudentModule* FillingPreviousMarks(StudentModule *new_data, StudentModule *file, int &sizefile);
StudentModule *ViewAndUpdateMarks(StudentModule *new_data, int &size, string &ind);
void AddNewStudent(); void AddNewCourse();
void EditStudentDetails(); void ViewStudentMarks();
void UpdateStudentMarks();
void ViewFeeStatus();
void TeacherPortal(Admin &ptr);
/////////////////////////////////////////////////////////////////////////////////////////////

