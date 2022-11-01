#include "Header.h"

char convert_tolower(char in) {
	if (in <= 'Z' && in >= 'A')
		return in - ('Z' - 'z');
	return in;
}


template<typename dataType>
void take_input(std::string msg, dataType &input, dataType cond1, dataType cond2) {
	while (1) {
		while (std::cout << msg && !(std::cin >> input)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Wrong Data Entered :: TRY AGAIN " << std::endl;
		} // while 1 ends here....
		if (input >= cond1 && input <= cond2) {
			break; // required input entered so break
		}
		else {
			std::cout << "Out of Range Data Entered :: TRY AGAIN " << std::endl;
		}
	} // while ends here...
} // take_input ends here.....

bool check_cnic(std::string input) {

	int length_input = input.length(); // stores the length of the string
	if (length_input == 15) { // checks for the length ==15 or not

		if (input[0] == '3' && input[1] == '3' && input[5] == '-' && input[13] == '-') { // cnic format

			for (int i = 0; i < length_input; i++) {
				if (i == 0 || i == 1 || i == 5 || i == 13) { // skipping
					continue;
				}
				else { // checking if other entries they are numbers or not
					if (!((int)input[i] >= 48) && !((int)input[i] <= 57)) {
						std::cout << "Wrong CNIC Format::Expected Numbers::Try Again " << std::endl;
						return false;
					}

				}

			} // for loop ends here...

			return true; // if all condtions were satisfied

		}
		else { // if format 33***-*******-* was wrong...
			std::cout << "Wrong CNIC Format::Expected Numbers::Try Again " << std::endl;
			return false;
		}


	}
	else { // else condition if length !=15
		std::cout << "Invalid CNIC:: Invalid Length" << std::endl;
		return false;
	}



} // check_cnic ends here....

bool check_contactNo(std::string input) {

	int input_length = input.length();
	if (input_length == 12) {

		if (input[0] == '0' && input[1] == '3' && input[4] == '-') {

			for (int i = 0; i < input_length; i++) {

				if (i == 0 || i == 1 || i == 3) {
					continue; // format things so better not check them again
				}
				else {
					if (!((int)input[i] >= 48) && !((int)input[i] <= 57)) { //checking others are numbers too
						std::cout << "Expected Numbers::Try Again " << std::endl;
						return false;
					}
				}
			} // for loop ends here...
			return true; // if all conditions are good to go
		}
		else { // if format is wrong
			std::cout << "Wrong Format :: Try Again (03**-*******) " << std::endl;
			return false;
		}

	}
	else { // if length was small enough
		std::cout << "Invalid Length::Phone Number" << std::endl;
		return false;
	}


} // check phonenumber ends here...

bool check_name(std::string input) {

	bool status = true;
	int length_input = input.length(); // stores the length of the string
	for (int i = 0; i < length_input; i++) {
		if ( ( (int)input[i] >= 65 && (int)input[i] <= 90 ) || ( (int)input[i]>=97 && (int)input[i] <= 122) || (int)input[i]==32 ) {
			status = true;
		} else {
			status = false;
			break;
		}
	}

	if (status == false) {
		std::cout << "Wrong NameType::Try Again " << std::endl;
	}
	return status;
}

bool check_email(std::string &input) {

	bool status1 = false; bool status2 = false;
	int length_input = input.length(); // stores the length of the string
	int atratecount = 0;
	for (int i = 0; i < length_input; i++ ) {
		input[i] = convert_tolower(input[i]);

		//if(  (input[i]>='a' && input[i] >= 'z') || input[i]  )

		if ((int)input[i] == 64 ) {
			++atratecount;
		} 
		if (atratecount > 1) {
			break;
		}



	}
	if (atratecount == 1) {
		if (input[length_input - 4] == '.' &&  input[length_input - 3] == 'c' && input[length_input - 2] == 'o' && input[length_input - 1] == 'm') {
			return true;
		} else {
			return false;
		}

	
	}
	else {
		return false;
	}

}

void take_input(std::string msg, std::string &input, std::string custom = "mix") {

	while (1) {

		while (std::cout << msg && !(std::getline(std::cin, input))) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Wrong Data Entered :: TRY AGAIN " << std::endl;
		} // while 1 ends here....

		if (custom == "name") {
			bool status = check_name(input);
			if (status == true) { break; } // break if input was correct name
			
		}
		else if (custom == "cnic") {
			bool status = check_cnic(input);
			if (status == true) { break; } // break if input was correct cnic
		}
		else if (custom == "email") {
			bool status = check_email(input);
			if (status == true) { break; } // break if input was correct cnic
		}
		else if (custom == "password") {
			break;
		}
		else if (custom == "mix") {
			break;
		}
		else if (custom == "phone") {
			bool status = check_contactNo(input);
			if (status == true) { break; } // break if input was correct phone number
		}
		else if (custom == "address") {
			if (input.length() >= 5) {
				break;
			}
			else {
				std::cout << "Too short address" << std::endl;
			}

		}

	} // while (1) ends here...

} // take_input ends here.....



  // { class Teacher Functions defined below } //


Date::Date() {
	day = 1;
	month = 1;
	year = 2000;
}
void Date::setday(int day) {
	this->day = day;
}
int Date::getday()const {
	return day;
}
void Date::setmonth(int month) {
	this->month = month;
}
int Date::getmonth()const {
	return month;
}
void Date::setyear(int year) {
	this->year = year;
}
int Date::getyear()const {
	return year;
}
ostream& operator << (ostream& o, Date& obj) {
	o << obj.day << " ";
	o << obj.month << " ";
	o << obj.year;
	return o;
}
istream& operator >> (istream& i, Date &obj) {
	i >> obj.day;
	i >> obj.month;
	i >> obj.year;
	return i;
}







void Teacher::set_firstName() {
	take_input("Enter the First Name: ", this->firstName, "name");
}// set_firstName() ends here...

void Teacher::set_lastName() {
	take_input("Enter the Last Name: ", this->lastName, "name");
} // set_lastName() ends here...

void Teacher::set_email() {
	take_input("Enter the email@: ", this->email,"email");
} // set_email() ends here..

void Teacher::set_joiningDate() {
	std::cout << "=------<< Date of Joining >>------=" << std::endl;
	int day;
	int month;
	int year;
	take_input("Enter the Day: ",day , 1, 31);
	take_input("Enter the Month: ", month, 1, 12);
	take_input("Enter they Year: ", year, 2000, 2100);
	this->joiningDate.setday(day);
	this->joiningDate.setmonth(month);
	this->joiningDate.setyear(year);
	std::cout << "=-----<< ---------------- >>------=" << std::endl;
}
void Teacher::set_username()
{
	take_input("Enter Username: ", this->username, "mix");
}
//set_joiningDate() ends here..

void Teacher::set_password() {
	take_input("Enter Password: ", this->password, "password");
} // set_password() ends here..

void Teacher::set_confirmPassword() {
	while (this->confirmPassword != this->password) {
		take_input("Confirm Password: ", this->confirmPassword,"password");
		if (this->confirmPassword == this->password) {
			std::cout << "=-----<< Password Saved >>------=" << std::endl;
		}
		else {
			take_input("Confirm Password AGAIN/Does not Match: ", this->confirmPassword);
		}
	}
} // set_confirmPassword() ends here..

void Teacher::set_cnic() {
	take_input("Enter the CNIC: ", this->cnic, "cnic");
}

void Teacher::set_gender() {
	std::cout << "=----<< Gender >>-----=" << std::endl;
	std::cout << "Press 1-=>Male\nPress 2=->Female\nPress 3=->Others" << std::endl;
	int choice = 0; take_input("Enter the respective number : ", choice, 1, 3);
	if (choice == 1) { this->gender = "Male"; }
	else if (choice == 2) { this->gender = "Female"; }
	else if (choice == 3) {
		this->gender = "Others";
	}
	std::cin.ignore();

}

void Teacher::set_qualification() {
	take_input("Enter Qualification: ", this->qualification, "name");
}

void Teacher::set_contactNo() {
	take_input("Enter Contact Number (03**-*******): ", this->contactNo, "phone");
}

void Teacher::set_dob() { // date of birth
	std::cout << "=------<< Date of Birth >>------=" << std::endl;
	int day;
	int month;
	int year;
	take_input("Enter the Day: ", day, 1, 31);
	take_input("Enter the Month: ", month, 1, 12);
	take_input("Enter they Year: ", year, 1900, 2100);
	this->dob.setday(day);
	this->dob.setmonth(month);
	this->dob.setyear(year);
	std::cout << "=-----<< ---------------- >>------=" << std::endl;
	std::cin.ignore();
} // set_dob ends here...

void Teacher::set_address() {
	take_input("Enter Address: ", this->address, "address");
}

void Teacher::set_salary() {
	take_input("Enter Salary : ", this->salary, (long)1, (long)999999999);
}

///////////////////////////////

std::string Teacher::get_firstName() const {
	return this->firstName;
}

std::string Teacher::get_lastName() const {
	return this->lastName;
}

std::string Teacher::get_email() const {
	return this->email;
}

std::string Teacher::get_username() const
{
	return this->username;
}

std::string Teacher::get_password() const {
	return this->password;
}

std::string Teacher::get_confirmPassword() const {
	return this->confirmPassword;
}

std::string Teacher::get_cnic() const {
	return this->cnic;
}

std::string Teacher::get_gender() const {
	return this->gender;
}

std::string Teacher::get_qualification() const {
	return this->qualification;
}

std::string Teacher::get_contactNo() const {
	return this->contactNo;
}

Date Teacher::get_dob() const {
	return dob;
}

std::string Teacher::get_address() const {
	return this->address;
}

long int Teacher::get_salary() const {
	return this->salary;
}



///////////////////////////////////////
void Teacher::writeTeacher(Teacher *ptr, const int Size) {
	std::fstream file;
	file.open("Teacher.txt", std::ios::out);
	Date saveDate;
	if (file.is_open()) {
		for (int i = 0; i < Size; i++) {
			saveDate = ptr[i].get_dob();
			file << ptr[i].get_firstName() << "," << ptr[i].get_lastName() << ",";
			file << ptr[i].get_email() << "," << ptr[i].get_username() << "," << ptr[i].get_password() << ",";
			file << ptr[i].get_confirmPassword() << "," << ptr[i].get_cnic() << ",";
			file << ptr[i].get_gender() << ",";
			file << ptr[i].get_qualification() << "," << ptr[i].get_contactNo() << ",";
			file << ptr[i].get_address() << ",";
			file << saveDate.getday() << " " << saveDate.getmonth() << " " << saveDate.getyear() << " ";
			file << ptr[i].get_salary() <<std::endl;

		} // for loop ends here...
		file.close();
	}
	else {
		std::cout << "Unable to Open file" << std::endl;
	}
}

Teacher* Teacher::readTeacher(Teacher *ptr, int &Size) { // size=0

	std::fstream file;
	file.open("Teacher.txt", std::ios::in);
	Date saveDate;
	Teacher obj;
	int day;
	int month;
	int year;
	if (file.is_open()) {

		while (!file.eof()) {
			std::getline(file, obj.firstName, ',');
			std::getline(file, obj.lastName, ',');
			std::getline(file, obj.email, ',');
			std::getline(file, obj.username, ',');
			std::getline(file, obj.password, ',');
			std::getline(file, obj.confirmPassword, ',');
			std::getline(file, obj.cnic, ',');
			std::getline(file, obj.gender, ',');
			std::getline(file, obj.qualification, ',');
			std::getline(file, obj.contactNo, ',');
			std::getline(file, obj.address,',');
			file >> day >> month >> year;
			file >> obj.salary;
			saveDate.setday(day);
			saveDate.setmonth(month);
			saveDate.setyear(year);
			std::string trash;
			std::getline(file,trash);
			
			obj.dob = saveDate;
			if (!file.eof()) {
				ptr = increase(ptr, Size);
				ptr[Size] = obj;
				++Size;
			}
			else {
				break;

			}
		}
		
		return ptr;
	}
	else {
		std::cout << "Unable to Open file" << std::endl;
	}

}

void Teacher::input_data() {
	std::cin.ignore();
	this->set_firstName();
	this->set_lastName();
	this->set_email();
	this->set_password();
	this->set_confirmPassword();
	this->set_cnic();
	this->set_gender();
	this->set_qualification();
	this->set_contactNo();
	this->set_dob();
	this->set_address();
	this->set_salary();

}

void Teacher::update_at()
{
	std::cout << "Press 1=-> Update Address" << std::endl;
	std::cout << "Press 2=-> Update Contact Number" << std::endl;
	std::cout << "Press 3=-> Update Qualification" << std::endl;
	std::cout << "Press 4=-> Update Salary" << std::endl;
	std::cout << "Press 5=-> Update All" << std::endl;
	std::cout << "Press 6=-> Exit" << std::endl;
	int choice; take_input("Enter the respective number: ", choice, 1, 6);
	std::cin.ignore();
	if (choice == 1) {
		this->set_address();
	}
	else if (choice == 2) {
		this->set_contactNo();
	}
	else if (choice == 3) {
		this->set_qualification();
	}
	else if (choice == 4) {
		this->set_salary();
	}
	else if (choice == 5) {
		this->set_address();
		this->set_contactNo();
		this->set_qualification();
		this->set_salary();
	}


}

void Teacher::assign_Course(std::string PC, std::string CN, std::string CC, int classno)
{
	this->myCourses = increase(this->myCourses, this->total_myCourses);
	myCourses[this->total_myCourses].parentCourse = PC;
	myCourses[this->total_myCourses].courseName = CN;
	myCourses[this->total_myCourses].courseCode = CC;
	myCourses[this->total_myCourses].Class = classno;
	++this->total_myCourses;
}

void Teacher::viewMyCourses() {
	if (this->total_myCourses != 0) {
		std::cout << "\t\tMr." << this->get_firstName() + " " + this->get_lastName()  << std::endl;
		std::cout << "\n\n\t\t <<---== List of Courses assigned to you ==----->> " << std::endl;
		for (int i = 0; i < this->total_myCourses; i++) {
			std::cout << "\t\t#" << i << "\t" << this->myCourses[i].courseName << std::endl;
		}
	}
	else {
		notification_console();
		std::cout << "\n\n\tNo Courses Alloted" << std::endl;
		system("pause");
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}


login* login::loadUsers(login *ptr, int &Size, std::string filename)
{
	std::fstream file;
	file.open(filename.c_str(), std::ios::in);
	login obj;
	if (file.is_open()) {

		while (!file.eof()) {
			std::getline(file, obj.username, ',');
			std::getline(file, obj.password);
			if (file.eof()) {
				break; 
			} else {
				ptr = increase(ptr, Size);
				ptr[Size] = obj;
				++Size;
			}
		}
		return ptr;
	}
	else {
		std::cout << "Unable to Open file" << std::endl;
		return ptr;
	}
}

bool login::Trylogin(std::string user, std::string pass)
{
	if (this->username == user && this->password == pass) {
		return true;
	}
	else {
		return false;
	}
}







///////////////////////////////////////////////////////////////////////////


string SpaceControl(string &name) {
	int count = 0;
	for (int i = 0; i < name.length(); i++) {
		if (name[i] == ' ')
			count++;
		else
			break;
	}
	name.erase(0, count);
	return name;
}
bool Number(string str) {
	for (int i = 0; i < str.length(); i++)
		if (str[i] >= '0'&&str[i] <= '9')
			return false;
	return true;
}
bool Alphabet(string str) {
	for (int i = 0; i < str.length(); i++)
		if (str[i] < '0' || str[i] > '9')
			return false;
	return true;
}
string ValidNumber(string str) {
	getline(cin, str);
	while (str == "")
		getline(cin, str);
	while (Number(str) == false)
	{
		cout << "Invalid Entry!" << endl;
		cout << "Enter Again: ";
		getline(cin, str);
		while (str == "")
			getline(cin, str);
	}
	return str;
}
string ValidAlphabet(string str)
{
	getline(cin, str);
	while (str == "")
		getline(cin, str);
	while (Alphabet(str) == false)
	{
		cout << "Invalid Entry!" << endl;
		cout << "Enter Again: ";
		getline(cin, str);
		while (str == "")
			getline(cin, str);
	}
	return str;
}

string Input(string str)
{
	getline(cin, str);
	while (str == "")
		getline(cin, str);
	return str;
}
template <class T>
T* ResizeInc(T *ptr, int size)
{
	T* newptr;
	newptr = new T[size + 1];
	for (int i = 0; i < size; i++)
	{
		newptr[i] = ptr[i];
	}
	delete[]ptr;
	return newptr;
}
template <class T>
T* ResizeDec(T *ptr, int size)
{
	T* newptr;
	newptr = new T[size - 1];
	for (int i = 0; i < size - 1; i++)
	{
		newptr[i] = ptr[i];
	}
	delete[]ptr;
	return newptr;
}
template <class T>
T *Del(T *ptr, int size, int ind)
{
	T *newptr;
	newptr = new T[size - 1];
	for (int i = 0; i < size - 1; i++)
	{
		if (i < ind)
			newptr[i] = ptr[i];
		if (i >= ind)
			newptr[i] = ptr[i + 1];
	}
	delete[]ptr;
	return newptr;
}


void Student::setfirst_name(string first_name) {
	this->first_name = first_name;
}
string Student::getfirst_name()const {
	return first_name;
}
void Student::setlast_name(string last_name) {
	this->last_name = last_name;
}
string Student::getlast_name()const {
	return last_name;
}
void Student::setclass_number(int class_number) {
	this->class_number = class_number;
}
int Student::getclass_number()const {
	return class_number;
}
void Student::setroll_number(string roll_number) {
	this->roll_number = roll_number;
}
string Student::getroll_number()const {
	return roll_number;
}
void Student::setdate(Date date) {
	this->date = date;
}
Date Student::getdate()const {
	return date;
}
void Student::setgender(char gender) {
	this->gender = gender;
}
char Student::getgender()const {
	return gender;
}
void Student::setphone_number(string phone_number) {
	this->phone_number = phone_number;
}
string Student::getphone_number()const {
	return phone_number;
}
void Student::setfather_name(string father_name) {
	this->father_name = father_name;
}
string Student::getfather_name()const {
	return father_name;
}
void Student::setfathers_profession(string fathers_profession) {
	this->fathers_profession = fathers_profession;
}
string Student::getfathers_profession()const {
	return fathers_profession;
}
void Student::setparent_contact_number(string parent_contact_number) {
	this->parents_contact_number = parent_contact_number;
}
string Student::getparent_contact_number()const {
	return parents_contact_number;
}
void Student::setfee_submitted(bool fee_submitted) {
	this->fee_submitted = fee_submitted;
}
bool Student::getfee_submitted()const {
	return fee_submitted;
}
void Student::setblood_group(string blood_group) {
	this->blood_group = blood_group;
}
string Student::getblood_group()const {
	return blood_group;
}
void Student::setaddress(string address) {
	this->address = address;
}
string Student::getaddress()const {
	return address;
}
Course::Course() {}
//Setter's Getter's
void Course::SetParentCourse(string parent_course) {
	this->parent_course = parent_course;
}
string Course::GetParentCourse()const {
	return parent_course;
}
void Course::SetCourseCode(string course_code) {
	this->course_code = course_code;
}
string Course::GetCourseCode()const {
	return course_code;
}
void Course::SetCourseName(string course_name) {
	this->course_name = course_name;
}
string Course::GetCourseName()const {
	return course_name;
}
void Course::SetClassNumber(int class_number) {
	this->class_number = class_number;
}
int Course::GetClassNumber()const {
	return class_number;
}

Course* Course::readCourse_forAssigning(Course *ptr, int &Size)
{
		std::fstream file;
		file.open("Course.txt", std::ios::in);
		
	    Course obj;
		if (file.is_open()) {
	
			while (!file.eof()) {

				file >> obj.class_number;
				std::getline(file, obj.course_code, ',');
				std::getline(file, obj.parent_course,',');
				std::getline(file, obj.course_name);
				ptr = increase(ptr, Size);
				ptr[Size] = obj;
				++Size;
				if (file.eof()) {
					break;
				}

			}
			return ptr;
		}
		else {
			std::cout << "Unable to Open file" << std::endl;
			return ptr;
		}
}

Student *Read(ifstream &fin, Student *ptr, int &size, int count)
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
	int fee_submitted;
	string blood_group;
	string address;
	delete[]ptr;
	ptr = NULL;
	ptr = new Student[size];
	fin.open("Student.txt");
	if (!fin)
		cout << "File cannot be opened!" << endl;
	else
	{
		while (!fin.eof())
		{
			if (count == size)
			{
				ptr = ResizeInc(ptr, size);
				size++;
			}
			getline(fin, last_name, ',');
			getline(fin, first_name, ',');
			fin >> class_number;
			fin >> roll_number;
			fin >> date;
			fin >> gender;
			fin >> phone_number;
			getline(fin, father_name, ',');
			getline(fin, fathers_profession, ',');
			fin >> parents_contact_number;
			fin >> fee_submitted;
			fin >> blood_group;
			getline(fin, address);
			ptr[count].setfirst_name(first_name);
			ptr[count].setlast_name(last_name);
			ptr[count].setclass_number(class_number);
			ptr[count].setdate(date);
			ptr[count].setroll_number(roll_number);
			ptr[count].setgender(gender);
			ptr[count].setphone_number(phone_number);
			ptr[count].setfather_name(father_name);
			ptr[count].setfathers_profession(fathers_profession);
			ptr[count].setparent_contact_number(parents_contact_number);
			ptr[count].setfee_submitted(fee_submitted);
			ptr[count].setblood_group(blood_group);
			ptr[count].setaddress(address);
			count++;
		}
		count = count - 2;
		ptr = ResizeDec(ptr, size);
		size--;
	}
	fin.close();
	//Now Data Read from the File
	return ptr;
}
Course *ReadCourse(ifstream &fin, Course *ptr, int &size, int count)
{
	string parent_course;
	string course_code;
	string course_name;
	int class_number;
	ptr = NULL;
	ptr = new Course[size];
	fin.open("Course.txt");
	if (!fin)
		cout << "File cannot be opened!" << endl;
	else
	{
		while (!fin.eof())
		{
			if (count == size)
			{
				ptr = ResizeInc(ptr, size);
				size++;
			}
			fin >> class_number;
			getline(fin, course_code, ',');
			getline(fin, parent_course, ',');
			getline(fin, course_name);
			ptr[count].SetClassNumber(class_number);
			ptr[count].SetCourseCode(course_code);
			ptr[count].SetParentCourse(parent_course);
			ptr[count].SetCourseName(course_name);
			count++;
		}
		count = count - 2;
		ptr = ResizeDec(ptr, size);
		size--;
	}
	fin.close();
	//Now Data Read from the File
	return ptr;
}
CourseMarks::CourseMarks() {
	total_marks_mid1 = 0;
	total_marks_mid2 = 0;
	total_marks_final = 0;
	obtained_marks_final = 0;
	obtained_marks_mid2 = 0;
	obtained_marks_mid1 = 0;
}
void CourseMarks::SetCourseName(string course_name) {
	this->course_name = course_name;
}
string CourseMarks::GetCourseName()const {
	return course_name;
}


void CourseMarks::SetTotalMarksMid1(int total_marks) {
	this->total_marks_mid1 = total_marks;
}
int CourseMarks::GetTotalMarksMid1()const {
	return total_marks_mid1;
}
void CourseMarks::SetTotalMarksMid2(int total_marks) {
	this->total_marks_mid2 = total_marks;
}
int CourseMarks::GetTotalMarksMid2()const {
	return total_marks_mid2;
}

void CourseMarks::SetTotalMarksFinal(int total_marks) {
	this->total_marks_final = total_marks;
}
int CourseMarks::GetTotalMarksFinal()const {
	return total_marks_final;
}



void CourseMarks::SetObtainedMarksMid1(int obtained_marks) {
	this->obtained_marks_mid1 = obtained_marks;
}
int CourseMarks::GetObtainedMarksMid1()const {
	return obtained_marks_mid1;
}

void CourseMarks::SetObtainedMarksMid2(int obtained_marks) {
	this->obtained_marks_mid2 = obtained_marks;
}
int CourseMarks::GetObtainedMarksMid2()const {
	return obtained_marks_mid2;
}

void CourseMarks::SetObtainedMarksFinal(int obtained_marks) {
	this->obtained_marks_final = obtained_marks;
}
int CourseMarks::GetObtainedMarksFinal()const {
	return obtained_marks_final;
}


//Pass And Fail Method

bool CourseMarks::Status(double threshold, double mid1_weightage, double mid2_weightage, double final_weightage)
{
	double obtained_weightage = 0;
	mid1_weightage = obtained_marks_mid1*mid1_weightage / 100;
	mid2_weightage = obtained_marks_mid2*mid2_weightage / 100;
	final_weightage = obtained_marks_final*final_weightage / 100;
	obtained_weightage = mid1_weightage + mid2_weightage + final_weightage;
	if (obtained_weightage >= threshold)
		return true;
	else
		return false;
}
StudentModule::StudentModule() {
	course_size = 0;
	course = new CourseMarks[course_size];
}
void StudentModule::SetRollNumber(string roll_number) {
	this->roll_number = roll_number;
}
string StudentModule::GetRollNumber()const {
	return roll_number;
}
void StudentModule::SetClassNumber(int class_number) {
	this->class_number = class_number;
}
int StudentModule::GetClassNumber()const {
	return class_number;
}
//Course's Functions
void StudentModule::AddCourse(CourseMarks obj) {
	this->course = ResizeInc(this->course, course_size);
	this->course[this->course_size++] = obj;
}
CourseMarks StudentModule::GetCourse(int ind)const {
	return this->course[ind];
}
void StudentModule::SetCourseSize(int course_size) {
	this->course_size = course_size;
}
int StudentModule::GetCourseSize()const {
	return course_size;
}
void StudentModule::SetCourse(CourseMarks obj, int ind) {
	course[ind] = obj;
}

void WriteCourseMarks(ofstream &fout, StudentModule *ptr, const int size) {
	if (!fout)
		cout << "File cannot be opened!" << endl;
	else
	{
		for (int i = 0; i < size; i++)
		{
			fout << ptr[i].GetRollNumber() << " " << ptr[i].GetClassNumber();
			for (int j = 0; j < ptr[i].GetCourseSize(); j++) {
				fout << ",";
				fout << SpaceControl(ptr[i].GetCourse(j).GetCourseName()) << "-";
				fout << ptr[i].GetCourse(j).GetTotalMarksMid1() << " ";
				fout << ptr[i].GetCourse(j).GetObtainedMarksMid1() << " ";
				fout << ptr[i].GetCourse(j).GetTotalMarksMid2() << " ";
				fout << ptr[i].GetCourse(j).GetObtainedMarksMid2() << " ";
				fout << ptr[i].GetCourse(j).GetTotalMarksFinal() << " ";
				fout << ptr[i].GetCourse(j).GetObtainedMarksFinal() << " ";
			}
			fout << endl;
		}
	}
	fout.close();
}
void Write(ofstream &fout, Student *ptr, const int size)
{
	if (!fout)
		cout << "File cannot be opened!" << endl;
	else
	{
		for (int i = 0; i < size; i++)
		{
			fout << ptr[i].getlast_name() << "," << ptr[i].getfirst_name() << ",";
			fout << ptr[i].getclass_number() << " " << ptr[i].getroll_number() << " ";
			fout << ptr[i].getdate() << " " << ptr[i].getgender() << " " << ptr[i].getphone_number();
			fout << " " << ptr[i].getfather_name() << "," << ptr[i].getfathers_profession();
			fout << "," << ptr[i].getparent_contact_number() << " " << ptr[i].getfee_submitted() << " ";
			fout << ptr[i].getblood_group() << " " << ptr[i].getaddress() << endl;
		}
	}
	fout.close();
}
void WriteCourse(ofstream &fout, Course *ptr, const int size)
{
	if (!fout)
		cout << "File cannot be opened!" << endl;
	else
	{
		for (int i = 0; i < size; i++)
		{
			fout << ptr[i].GetClassNumber() << " " << ptr[i].GetCourseCode() << ",";
			fout << ptr[i].GetParentCourse() << "," << ptr[i].GetCourseName();
			fout << endl;
		}
	}
	fout.close();
}
Admin::Admin() {
	student_size = 0;
	this->course_size = 0;
	this->total_number_teachers = 0;
	//this->total_number_courses = 0;
	this->total_adminUsers = 0;
	this->total_studentUsers = 0;
}
Admin::Admin(const Admin & obj)
{
	// idk what we should write here
	//wait 
	
}
//Student's Functions
void Admin::AddStudent(Student obj) {
	this->student = ResizeInc(this->student, student_size);
	this->student[this->student_size++] = obj;
}
Student Admin::getStudent(int ind)const {
	return this->student[ind];
}
void Admin::setstudent_size(int student_size1) {
	this->student_size = student_size1;
}
int Admin::getstudent_size()const {
	return student_size;
}
void Admin::setStudent(Student obj, int ind) {
	student[ind] = obj;
}
void Admin::FileRead() {
	student = NULL;
	this->student_size = 0;
	int count = 0;
	student = Read(fin, student, student_size, count);
}
void Admin::WriteFile(ofstream &fout) {
	Write(fout, student, this->student_size);
}
//Course's Functions
void Admin::AddCourse(Course obj) {
	this->course = ResizeInc(this->course, course_size);
	this->course[this->course_size++] = obj;
}
Course Admin::GetCourse(int ind)const {
	return this->course[ind];
}
void Admin::SetCourseSize(int course_size) {
	this->course_size = course_size;
}
int Admin::GetCourseSize()const {
	return course_size;
}
void Admin::SetCourse(Course obj, int ind) {
	course[ind] = obj;
}
void Admin::FileReadCourse() {
	course = NULL;
	this->course_size = 0;
	int count = 0;
	course = ReadCourse(fin, course, course_size, count);
}
void Admin::WriteFileCourse(ofstream &fout) {
	WriteCourse(fout, course, this->course_size);
}
//Protoypes Starting

void Display() {
	Admin admin;
	admin.FileRead();
	if (admin.getstudent_size() >= 1)
	{
		cout << "\n\nList of All Students:\n\n";
		for (int i = 0; i < admin.getstudent_size(); i++) {
			cout << "\n\n\nStudent number " << i + 1 << ":\n\n";
			cout << "First Name: " << admin.getStudent(i).getfirst_name() << endl;
			cout << "Last Name: " << admin.getStudent(i).getlast_name() << endl;
			cout << "Roll No: " << admin.getStudent(i).getroll_number() << endl;
			cout << "Class Number: " << admin.getStudent(i).getclass_number() << endl;
			cout << "Gender: " << admin.getStudent(i).getgender() << endl;
			cout << "Registration Date: " << admin.getStudent(i).getdate() << endl;
			cout << "Phone Number: " << admin.getStudent(i).getphone_number() << endl;
			cout << "Father's/Guardian's Name: " << admin.getStudent(i).getfather_name() << endl;
			cout << "Father's Profession: " << admin.getStudent(i).getfathers_profession() << endl;
			cout << "Parent Contact Number: " << admin.getStudent(i).getparent_contact_number() << endl;
			cout << "Fee Status: ";
			if (admin.getStudent(i).getfee_submitted() == true)
				cout << "Fee is Submitted!" << endl;
			else
				cout << "Fee is not Submitted!" << endl;
			cout << "Blood Group: " << admin.getStudent(i).getblood_group() << endl;
			cout << "Address: " << admin.getStudent(i).getaddress() << endl;
		}
	}
	else
	{
		cout << "\n\nSorry!\nCurrently No Students are present!\n" << endl;
	}
}


void DisplayCourse() {
	Admin admin;
	admin.FileReadCourse();
	if (admin.GetCourseSize() >= 1) {
		cout << "\n\nList of All Courses:\n\n";
		for (int i = 0; i < admin.GetCourseSize(); i++) {

			cout << "Offered to Class No.: " << admin.GetCourse(i).GetClassNumber() << "\t";
			cout << "Course-Code: " << admin.GetCourse(i).GetCourseCode() << "\t";
			cout << "Parent-Course: " << admin.GetCourse(i).GetParentCourse() << "\t\t";
			cout << "Course-Name: " << admin.GetCourse(i).GetCourseName() << endl;

		}
	}
	else
	{
		cout << "\n\nSorry!\nCurrently No Courses are present!\n" << endl;
	}
}

StudentModule* MarksUpdate(StudentModule *new_data, int &size, string ind, std::string control="admin",std::string specifiedCourse="NULL") {
	//Check Size
	bool found = false;
	string roll_number;
	for (int i = 0; i < size; i++) {
		if (new_data[i].GetClassNumber() == stoi(ind)) {
			found = true;
			break;
		}
	}
	bool cond = false;
	if (found == true) {
		for (int i = 0; i < size; i++)
			if (new_data[i].GetClassNumber() == stoi(ind))
				cout << "\tRoll Number: " << new_data[i].GetRollNumber() << endl;
		cout << endl << endl;
		cout << "\tEnter The Respective Roll Number to Update His Marks: ";
		cin >> roll_number; // can crash here.....
		int index = 0;
		for (int i = 0; i < size; i++) {
			if (new_data[i].GetRollNumber() == roll_number) {
				cond = true;
				index = i; // got the kid who was entered
				break;
			}
		}
		int choice = 0;
		int total_marks = 0;
		int obtained_marks = 0;
		int teachermatchedcourse = 0;
		CourseMarks obj;
		if (cond == true) {

			if (control == "admin") { // updated 15th june
				if (new_data[index].GetCourseSize() > 0)
					cout << "\tEnter The Respective Number to Update Marks: " << endl;
				for (int i = 0; i < new_data[index].GetCourseSize(); i++) {
					cout << "\tPress " << i + 1 << "---To Update " << new_data[index].GetCourse(i).GetCourseName() << endl;
				}
				take_input("Enter the Respective Number: ", choice, 1, new_data[index].GetCourseSize());
			}

			if (control == "teacher") { // updated 15th june

				if (new_data[index].GetCourseSize() > 0) {
					for (int i = 0; i < new_data[index].GetCourseSize(); i++) {
						if (" "+new_data[index].GetCourse(i).GetCourseName() == specifiedCourse) {
							teachermatchedcourse = i;
						}
					}
				}
			}

			choice--;
			int paper;
			    cout << "\t\t=--<< Upload/Update Marks >>--=" << endl;
				cout << "\t\tPress 1---For Mid 1" << endl;
				cout << "\t\tPress 2---For Mid 2" << endl;
				cout << "\t\tPress 3---For Final" << endl;
				take_input("\t\tEnter the Respective Number: ", paper, 1, 3);
				cout << "\t\tEnter total Marks: ";
				cin >> total_marks;
				cout << "\t\tEnter Obtained Marks: ";
				cin >> obtained_marks;

				if (control == "admin") {
					obj.SetCourseName(new_data[index].GetCourse(choice).GetCourseName()); // fix it
				} else if (control=="teacher") {
					obj.SetCourseName(new_data[index].GetCourse(teachermatchedcourse).GetCourseName()); // fix it
					choice = teachermatchedcourse;
				}


				if (paper == 1) {
					obj.SetTotalMarksMid1(total_marks);
					obj.SetObtainedMarksMid1(obtained_marks);
					new_data[index].SetCourse(obj, choice);
				}
				else if (paper == 2) {
					obj.SetTotalMarksMid2(total_marks);
					obj.SetObtainedMarksMid2(obtained_marks);
					new_data[index].SetCourse(obj, choice);
				}
				else if (paper == 3) {
					obj.SetTotalMarksFinal(total_marks);
					obj.SetObtainedMarksFinal(obtained_marks);
					new_data[index].SetCourse(obj, choice);
				}
		}
		else {
			notification_console();
			cout << "\n\t\tRoll Number not Found!" << endl;
		}
	}
	else {
		notification_console();
		cout << "\n\t\tSorry No Students are Present in this Class!" << endl;
	}
	return new_data;
}
void MarksView(StudentModule *new_data, int &size, string ind) {
	//Check Size
	bool found = false;
	string roll_number;
	for (int i = 0; i < size; i++) {
		if (new_data[i].GetClassNumber() == stoi(ind)) {
			found = true;
			break;
		}
	}
	bool cond = false;
	if (found == true) {
		for (int i = 0; i < size; i++)
			if (new_data[i].GetClassNumber() == stoi(ind))
				cout << "Roll Number: " << new_data[i].GetRollNumber() << endl;
		cout << endl << endl;
		cout << "Enter The Respective Roll Number to See His Marks: ";
		cin >> roll_number;
		int index = 0;
		for (int i = 0; i < size; i++) {
			if (new_data[i].GetRollNumber() == roll_number) {
				cond = true;
				index = i;
				break;
			}
		}
		int choice = 0;
		if (cond == true) {
			if (new_data[index].GetCourseSize() > 0)
				cout << "Enter The Respective Number to See Marks: " << endl;
			for (int i = 0; i < new_data[index].GetCourseSize(); i++)
				cout << "Press " << i + 1 << "---To See " << new_data[index].GetCourse(i).GetCourseName() << endl;
			take_input("Enter the Respective Number: ", choice, 1, new_data[index].GetCourseSize());
			choice--;
			int paper;
				cout << "Press 1---to See Mid1 Marks" << endl;
				cout << "Press 2---to See Mid2 Marks" << endl;
				cout << "Press 3---to See Final Marks" << endl;
				take_input("Enter the Respective Number: ", paper, 1, 3);
				cout << "Course Name: ";
				cout << new_data[index].GetCourse(choice).GetCourseName() << endl;

				if (paper == 1) {
					cout << "Total Marks: ";

					cout << new_data[index].GetCourse(choice).GetTotalMarksMid1() << endl;
					cout << "Obtained Marks: ";
					cout << new_data[index].GetCourse(choice).GetObtainedMarksMid1() << endl;

				}
				else if (paper == 2) {
					cout << "Total Marks: ";

					cout << new_data[index].GetCourse(choice).GetTotalMarksMid2() << endl;
					cout << "Obtained Marks: ";
					cout << new_data[index].GetCourse(choice).GetObtainedMarksMid2() << endl;

				}
				else if (paper == 3) {
					cout << "Total Marks: ";

					cout << new_data[index].GetCourse(choice).GetTotalMarksFinal() << endl;
					cout << "Obtained Marks: ";
					cout << new_data[index].GetCourse(choice).GetObtainedMarksFinal() << endl;

				}
		}
		else {
			cout << "Roll Number not Found!" << endl;
		}
	}
	else {
		cout << "Sorry No Students are Present in this Class!" << endl;
	}
}

StudentModule *FileReadStudentCourses(StudentModule *file, int &sizefile) {
	ifstream fin;
	fin.open("StudentCourseMarks.txt");
	int countfile = 0;
	int classNo = 0;
	int now = 0;

	char buffer[200];
	string reader = "";
	if (!fin)
		cout << "File cannot be opened!" << endl;
	else {
		while (!fin.eof())
		{
			file = ResizeInc(file, sizefile);
			sizefile++;


			fin.getline(buffer, 200);
			now = 0;
			countfile = 0;

			//Used for counting String
			for (int i = 0; buffer[i] != '\0'; i++)
			{
				if (buffer[i] == ',')
					countfile++;
			}

			for (int i = 0; buffer[i] != '\n' && buffer[i] != ','; now++, i++)
			{
				if (buffer[i] == ' ')
				{
					file[sizefile - 1].SetRollNumber(reader);
					reader = "";
				}
				else {
					reader = reader + buffer[i];
				}
			}
			now++;
			file[sizefile - 1].SetClassNumber(stoi(reader));
			reader = "";

			//Reading of Courses Marks
			if (countfile > 0)
			{
				for (int z = 0; z < countfile; z++)
				{
					CourseMarks* obj = new CourseMarks();

					for (int i = now; buffer[i] != '-'; now++, i++)
						reader = reader + buffer[i];

					obj->SetCourseName(reader);
					reader = "";
					now++;

					for (int i = now; buffer[i] != ' '; now++, i++)
						reader = reader + buffer[i];

					obj->SetTotalMarksMid1(stoi(reader));
					reader = "";
					now++;

					for (int i = now; buffer[i] != ' '; now++, i++)
						reader = reader + buffer[i];

					obj->SetObtainedMarksMid1(stoi(reader));
					reader = "";
					now++;

					for (int i = now; buffer[i] != ' '; now++, i++)
						reader = reader + buffer[i];

					obj->SetTotalMarksMid2(stoi(reader));
					reader = "";
					now++;

					for (int i = now; buffer[i] != ' '; now++, i++)
						reader = reader + buffer[i];

					obj->SetObtainedMarksMid2(stoi(reader));
					reader = "";
					now++;

					for (int i = now; buffer[i] != ' '; now++, i++)
						reader = reader + buffer[i];

					obj->SetTotalMarksFinal(stoi(reader));
					reader = "";
					now++;

					for (int i = now; buffer[i] != ',' && buffer[i] != '\n'; now++, i++)
						reader = reader + buffer[i];

					obj->SetObtainedMarksFinal(stoi(reader));
					reader = "";
					now++;

					file[sizefile - 1].AddCourse(*obj);
				}
			}
		}
	}
	return file;
}

void ListClass(string &ind) {
	cout << "=====>>>> List of All Classes <<<<=====" << endl;
	cout << "Press 1---for Class Number 1" << endl;
	cout << "Press 2---for Class Number 2" << endl;
	cout << "Press 3---for Class Number 3" << endl;
	cout << "Press 4---for Class Number 4" << endl;
	cout << "Press 5---for Class Number 5" << endl;
	cout << "Press 6---for Class Number 6" << endl;
	cout << "Press 7---for Class Number 7" << endl;
	cout << "Press 8---for Class Number 8" << endl;
	cout << "Press 9---for Class Number 9" << endl;
	cout << "Press 10--for Class Number 10" << endl;
	cin >> ind;
	while (stoi(ind)<1 || stoi(ind)>10) {
		cout << "Invalid Entry!" << endl;
		cout << "Enter Again: ";
		cin >> ind;
	}
}

StudentModule* FillingNewData(StudentModule *new_data, Admin &admin, int &size) {
	int count = 0;
	for (int i = 0; i < admin.getstudent_size(); i++) {
		//Name is Written
		//Now Courses
		CourseMarks course;
		count = 0;
		if (i == size) {
			new_data = ResizeInc(new_data, size);
			size++;
		}
		new_data[i].SetRollNumber(admin.getStudent(i).getroll_number());
		new_data[i].SetClassNumber(admin.getStudent(i).getclass_number());
		for (int j = 0; j < admin.GetCourseSize(); j++) {
			if (admin.getStudent(i).getclass_number() == admin.GetCourse(j).GetClassNumber()) {
				course.SetCourseName(admin.GetCourse(j).GetCourseName());
				new_data[i].AddCourse(course);
			}
		}
	}
	return new_data;
}
StudentModule* FillingPreviousMarks(StudentModule *new_data, StudentModule *file, int &sizefile) {
	string loop = "";
	for (int i = 0; i < sizefile - 1; i++) {
		if (new_data[i].GetRollNumber() == file[i].GetRollNumber()) {
			for (int j = 0; j < file[i].GetCourseSize(); j++) {
				loop = new_data[i].GetCourse(j).GetCourseName();
				loop.erase(loop.begin());
				if (loop == file[i].GetCourse(j).GetCourseName()) {
					new_data[i].SetCourse(file[i].GetCourse(j), j);
				}
			}
		}
	}
	return new_data;
}
StudentModule *ViewAndUpdateMarks(StudentModule *new_data, int &size, string &ind) {
	Admin admin;
	admin.FileRead();
	admin.FileReadCourse();
	int sizefile = 0;
	StudentModule *file = NULL;
	file = new StudentModule[sizefile];
	file = FileReadStudentCourses(file, sizefile);
	ofstream fout;
	new_data = FillingNewData(new_data, admin, size);
	new_data = FillingPreviousMarks(new_data, file, sizefile);
	return new_data;
}



/////////////////////////////////////////////////////
void AddNewStudent() {
	Admin admin;
	admin.FileRead();
	ofstream fout;
	Student student;
	Date date;
	time_t Obj;
	string first_name;
	string last_name;
	int class_number;
	string classno;
	string roll_number;
	char gender;
	string phone_number;
	string father_name;
	string fathers_profession;
	string parents_contact_number;
	int fee_submitted;
	string blood_group;
	string address;
	cout << "Enter First Name: ";
	first_name = ValidNumber(first_name);
	cout << "Enter Last Name: ";
	last_name = ValidNumber(last_name);
	cout << "Enter Class Number: ";
	classno = ValidAlphabet(classno);
	class_number = stoi(classno);
	cout << "Enter Gender(M/F):\n";
	cout << "Press M---for Male\n";
	cout << "Press F---for Female\n";
	cin >> gender;
	gender = toupper(gender);
	while (gender != 'M' && gender != 'F'&& gender != 'm'&& gender != 'f') {
		cout << "Invalid Entry!" << endl;
		cout << "Enter Again: ";
		cin >> gender;
	}
	cin.ignore();
	cout << "Enter Phone Number: ";
	phone_number = ValidAlphabet(phone_number);
	cout << "Enter Father's/Guardian's Name: ";
	father_name = ValidNumber(father_name);
	cout << "Enter Father's Profession: ";
	fathers_profession = ValidNumber(fathers_profession);
	cout << "Enter Parents Contact Number: ";
	parents_contact_number = ValidAlphabet(parents_contact_number);
	int fee;
	cout << "Enter Fee Submitted: " << endl;
	cout << "Press 1---if Fee is Submitted" << endl;
	cout << "Press 2---if Fee is not Submitted" << endl;
	take_input("Enter the Resprective Number: ", fee, 1, 2);
	if (fee == 1)
		fee_submitted = 1;
	else
		fee_submitted = 0;
	cout << "Enter Blood Group: ";
	cin.ignore();
	cin >> blood_group;
	while (blood_group.length() != 3 && blood_group.length() != 2) {
		cout << "Invalid Entry!" << endl;
		cout << "Enter Again: ";
		cin >> blood_group;
	}
	cout << "Enter Address: ";
	address = Input(address);
	//Roll Number Code Starts from Here
	int roll = 1;
	bool found = false;
	if (admin.getstudent_size() >= 1)
	{
		for (int i = admin.getstudent_size() - 1; i >= 0; i--) {
			if (admin.getStudent(i).getclass_number() == class_number)
			{
				roll = stoi(admin.getStudent(i).getroll_number());
				found = true;
				break;
			}
		}
	}
	if (found == true)
	{
		roll++;
		roll_number = to_string(roll);
		if (roll_number.length() == 4) {
			roll_number = "0" + roll_number;
		}
	}
	else
	{
		roll_number = to_string(class_number);
		if (roll_number.length() == 1) {
			roll_number = "0" + roll_number;
		}
		string number;
		number = to_string(roll);
		if (number.length() == 1) {
			number = "00" + number;
		}
		else if (number.length() == 2) {
			number = "0" + number;
		}
		roll_number = roll_number + number;
	}

	//Roll Number Code Ends Here

	//Date Obj Creation From the System
	struct tm StandardObj;
	Obj = time(NULL);
	StandardObj = *localtime(&Obj);
	date.setday(static_cast<int>(StandardObj.tm_mday));
	date.setmonth(static_cast<int>(StandardObj.tm_mon + 1));
	date.setyear(static_cast<int>(StandardObj.tm_year + 1900));
	//Student Obj creation
	student.setfirst_name(first_name);
	student.setlast_name(last_name);
	student.setclass_number(class_number);
	student.setroll_number(roll_number);
	student.setgender(gender);
	student.setphone_number(phone_number);
	student.setfather_name(father_name);
	student.setfathers_profession(fathers_profession);
	student.setparent_contact_number(parents_contact_number);
	student.setfee_submitted(fee_submitted);
	student.setblood_group(blood_group);
	student.setaddress(address);
	student.setdate(date);
	//Now Student as an Admin Object Creating
	admin.AddStudent(student);
	fout.open("Student.txt");
	admin.WriteFile(fout);
	//////////////////
	string password = "";
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		int random_number = rand() % 123;
		if ((random_number >= 65 && random_number <= 90) || (random_number >= 48 && random_number <= 57) || (random_number >= 97 && random_number <= 122)) {
			password += char(random_number);
		}
		else {
			--i;
		}
	}
	for (int i = 0; i < password.length(); i++) {
		password[i] = toupper(password[i]);
	}
	fout.close();
	fout.open("StudentUsers.txt", ios::app);
	fout << roll_number << ",";
	fout << password << endl;
}
void AddNewCourse() {
	Admin admin;
	ofstream fout;
	Course course;
	//Addition of Course
	string parent_course;
	string course_name;
	int class_number;
	cout << "Enter Parent Course Name: ";
	parent_course = ValidNumber(parent_course);
	string course_code = "";
	srand(time(NULL));
	for (int i = 0; i < 7; i++) {
		int random_number = rand() % 123;
		if ((random_number >= 65 && random_number <= 90) || (random_number >= 48 && random_number <= 57) || (random_number >= 97 && random_number <= 122)) {
			course_code += char(random_number);
		}
		else {
			--i;
		}
	}
	for (int i = 0; i < course_code.length(); i++) {
		course_code[i] = toupper(course_code[i]);
	}
	cout << "Enter Course Name: ";
	course_name = ValidNumber(course_name);
	cout << "Enter Class Number in which you want to add the Course: ";
	cin >> class_number;
	course.SetClassNumber(class_number);
	course.SetCourseCode(course_code);
	course.SetCourseName(course_name);
	course.SetParentCourse(parent_course);
	admin.AddCourse(course);
	fout.open("Course.txt", ios::app);
	admin.WriteFileCourse(fout);
}
void EditStudentDetails() {
	Admin admin;
	ofstream fout;
	string first_name;
	string last_name;
	string phone_number;
	int fee_submitted;
	string address;
	Student student;
	Display();
	int ind = -1;
	string search_roll_number;
	cout << "\n\nEnter roll number to Edit his Details: ";
	cin >> search_roll_number;
	for (int i = 0; i < admin.getstudent_size(); i++) {
		if (admin.getStudent(i).getroll_number() == search_roll_number)
			ind = i;
	}
	if (ind > -1) {
		cout << "Enter Updated First Name: ";
		first_name = ValidNumber(first_name);
		cout << "Enter Updated Last Name: ";
		last_name = ValidNumber(last_name);
		cout << "Enter Updated Phone Number: ";
		cin >> phone_number;

		cout << "Enter Updated Fee Submitted:\n";
		int fee;
		cout << "Press 1---if Fee is Submitted" << endl;
		cout << "Press 2---if Fee is not Submitted" << endl;
		take_input("Enter the Respective Number: ", fee, 1, 2);
		if (fee == 1)
			fee_submitted = 1;
		else
			fee_submitted = 0;
		cout << "Enter updated Address: ";
		address = Input(address);
		//Getting previous Student Object
		student = admin.getStudent(ind);
		//Now replcing its data members with updated content
		student.setfirst_name(first_name);
		student.setlast_name(last_name);
		student.setaddress(address);
		student.setphone_number(phone_number);
		student.setfee_submitted(fee_submitted);
		admin.setStudent(student, ind);
		fout.open("Student.txt");
		admin.WriteFile(fout);
	}
	else {
		cout << "Roll Number does not Exist!" << endl;
	}
}
void ViewStudentMarks() {
	StudentModule *new_data = NULL;
	int size = 0;
	string ind = "";
	ofstream fout;
	new_data = ViewAndUpdateMarks(new_data, size, ind);
	ListClass(ind);
	MarksView(new_data, size, ind);
	//Now  Previous Data is in ptr which StudentModule pointer
	fout.open("StudentCourseMarks.txt");
	WriteCourseMarks(fout, new_data, size);

}
void UpdateStudentMarks()
{

	StudentModule *new_data = NULL;
	int size = 0;
	string ind = "";
	new_data = ViewAndUpdateMarks(new_data, size, ind);
	ListClass(ind);
	ofstream fout;
	new_data = MarksUpdate(new_data, size, ind);
	//Now  Previous Data is in ptr which StudentModule pointer
	fout.open("StudentCourseMarks.txt");
	WriteCourseMarks(fout, new_data, size);
}
void ViewFeeStatus() {
	Admin admin;
	admin.FileRead();

	if (admin.getstudent_size() > 0)
	{
		cout << "\n\nList of All Students:\n\n";
		for (int i = 0; i < admin.getstudent_size(); i++) {
			cout << "\n\n\nStudent number " << i + 1 << ":\n\n";
			cout << "Name: " << admin.getStudent(i).getfirst_name();
			cout << " " << admin.getStudent(i).getlast_name() << endl;
			cout << "Roll No: " << admin.getStudent(i).getroll_number() << endl;
			if (admin.getStudent(i).getfee_submitted() == true)
				cout << "Fee is Submitted!" << endl;
			else
				cout << "Fee is not Submitted!" << endl;
		}
	}
	else
		cout << "Sorry!\nNo Students available right now!" << endl;

}

template <typename T>
std::string NumberToString(T Number)
{
	std::ostringstream ss;
	ss << Number;
	return ss.str();
}


int countsession() {
	int readnumber;
	fstream file;
	file.open("sessioncount.txt", std::ios::in);
	if (file.is_open()) {
		while (!file.eof())
		{
			file >> readnumber;
			if (file.eof()) {
				break;
			}
		}
	}
	file.close();
	fstream filerewrite;
	filerewrite.open("sessioncount.txt", std::ios::out);
	if (file.is_open()) {
		filerewrite << readnumber + 1;
	} 
	filerewrite.close();
	return readnumber;
}

void rewritecountsession(int readnumber) {

	fstream file;
	file.open("sessioncount.txt", std::ios::out);
	if (file.is_open()) {
		file << readnumber + 1 << endl;
	}
	file.close();
}






bool StudentModule::GetStatus()const {
	return status;
}
//Pass And Fail Method

void StudentModule::SetStatus(Promotion promote)
{
	bool perform = false;
	float obtained_weightage = 0;
	for (int i = 0; i < course_size; i++) {
		obtained_weightage += course[i].GetObtainedMarksMid1()*promote.GetMid1Weightage() / course[i].GetTotalMarksMid1();
		obtained_weightage += course[i].GetObtainedMarksMid2()*promote.GetMid2Weightage() / course[i].GetTotalMarksMid2();
		obtained_weightage += course[i].GetObtainedMarksFinal()*promote.GetFinalWeightage() / course[i].GetTotalMarksFinal();
		if (obtained_weightage < promote.GetThreshold()) {
			this->status = 0;
			perform = true;
			break;
		}
	}
	if (perform == false) {
		status = 1;
	}
}



void Admin::SetStudentPointer(int ind) {
	this->student = Del(this->student, student_size--, ind);
}




//////////////////////////////////////////////////
Promotion::Promotion() {
	mid1_weightage = 25;
	mid2_weightage = 25;
	final_weightage = 50;
	threshold = 33;
}
void Promotion::SetMid1Weightage(float mid1_weightage) {
	this->mid1_weightage = mid1_weightage;
}
void Promotion::SetMid2Weightage(float mid2_weightage) {
	this->mid2_weightage = mid2_weightage;
}
void Promotion::SetFinalWeightage(float final_weightage) {
	this->final_weightage = final_weightage;
}
float Promotion::GetMid1Weightage()const {
	return mid1_weightage;
}
float Promotion::GetMid2Weightage()const {
	return mid2_weightage;
}
float Promotion::GetFinalWeightage()const {
	return final_weightage;
}
void Promotion::SetThreshold(float threshold) {
	this->threshold = threshold;
}
float Promotion::GetThreshold()const {
	return threshold;
}






void StudentPromotion(void) {

	Admin admin;
	admin.FileRead();
	StudentModule *new_data = NULL;
	int size = 0;
	string ind = "";
	new_data = ViewAndUpdateMarks(new_data, size, ind);
	cout << "\n\n\tPress 1 -> To Change the Weightage" << endl;
	cout << "\n\n\tPress 2 -> To Stick with the Previous Weightages" << endl;
	int choice = 0;
	Promotion promote;
	take_input("\n\tEnter the Respective Number :> ", choice, 1, 2);
	if (choice == 1) {
		int weightage = 0;
		while (1) {
			int opt;
			cout << "\n\t Current Weightages are:\n";
			cout << "\tMid 1 Weightage :> " << promote.GetMid1Weightage() << endl;
			cout << "\tMid 2 Weightage :> " << promote.GetMid2Weightage() << endl;
			cout << "\tFinal Weightage :> " << promote.GetFinalWeightage() << endl;
			cout << "\tThreshold :> " << promote.GetThreshold() << endl;


			cout << "\n\n\tPress 1 -> To Change Mid1 Weightage" << endl;
			cout << "\tPress 2 -> To Change Mid2 Weightage" << endl;
			cout << "\tPress 3 -> To Change Final Weightage" << endl;
			cout << "\tPress 4 -> To Change Threshold" << endl;
			cout << "\tPress 5 -> To Exit" << endl;

			take_input("Enter the Respective Number :> ", opt, 1, 5);
			if (opt == 1) {
				take_input("Enter Mid 1 Weightage :> ", weightage, 0, 99);
				promote.SetMid1Weightage(weightage);
			}
			else if (opt == 2) {
				take_input("Enter Mid 2 Weightage :> ", weightage, 0, 99);
				promote.SetMid2Weightage(weightage);
			}
			else if (opt == 3) {
				take_input("Enter Final Weightage :> ", weightage, 0, 99);
				promote.SetFinalWeightage(weightage);
			}
			else if (opt == 4) {
				take_input("Enter Threshold Weightage :> ", weightage, 0, 99);
				promote.SetThreshold(weightage);
			}
			else if (opt == 5) {
				if (promote.GetFinalWeightage() + promote.GetMid1Weightage() + promote.GetMid2Weightage() == 100) {
					break;
				}
				else {

					cout << "Weightage don't Equal to 100!" << endl;
					cout << "You must Equal it to 100 in order to continue" << endl;
				}

			}
		}
	}
	for (int i = 0; i < size; i++) {
		new_data[i].SetStatus(promote);
	}
	////////////////////////////////////////////////////////

	ifstream fin;
	ofstream fout;
	string pass = "";
	string filename = "";
	fin.open("RecordFileNames.txt");
	if (!fin) {
		cout << "File cannot be opened!" << endl;
	}
	else
	{
		while (!fin.eof()) {
			getline(fin, filename, ',');
			if (fin.eof())
				break;
		}
		pass = filename;
	}
	///filename
	fin.close();
	if (filename == "") {
		filename = "Record Session 1";
		fout.open("RecordFileNames.txt");
		fout << filename;
		fout.close();
	}
	else
	{
		//filename=Error loading string
		string session = "";
		for (int i = 0; i < pass.length(); i++) {
			if (pass[i] >= 48 && pass[i] <= 57)
				session = session + pass[i];
		}
		//filename = "";
		string random = "";
		random = "Record Session ";
		int next = stoi(session);
		next++;
		random = random + to_string(next);
		fout.open("Record File Names.txt");
		fout << random;
		fout.close();
	}
	//Now Data should be written in filename whose extension you should add
	filename = filename + ".txt";
	fout.open(filename);
	if (!fout)
		cout << "File cannot be opened!" << endl;
	else
	{
		for (int i = 0; i < admin.getstudent_size(); i++) {
			fout << admin.getStudent(i).getlast_name();
			fout << ",";
			fout << admin.getStudent(i).getfirst_name() << ",";
			fout << admin.getStudent(i).getclass_number() << " ";
			fout << admin.getStudent(i).getroll_number() << " ";
			fout << admin.getStudent(i).getgender() << " ";
			fout << admin.getStudent(i).getphone_number();
			int ind = -1;
			for (int k = 0; k < admin.getstudent_size(); k++) {
				if (admin.getStudent(k).getroll_number() == new_data[k].GetRollNumber())
				{
					ind = i;
					break;
				}
			}

			for (int j = 0; j < new_data[ind].GetCourseSize(); j++) {

				fout << ",";
				fout << new_data[ind].GetCourse(j).GetCourseName() << "-";
				fout << new_data[ind].GetCourse(j).GetTotalMarksMid1() << " ";
				fout << new_data[ind].GetCourse(j).GetObtainedMarksMid1() << " ";
				fout << new_data[ind].GetCourse(j).GetTotalMarksMid2() << " ";
				fout << new_data[ind].GetCourse(j).GetObtainedMarksMid2() << " ";
				fout << new_data[ind].GetCourse(j).GetTotalMarksFinal() << " ";
				fout << new_data[ind].GetCourse(j).GetObtainedMarksFinal() << " ";
			}
			if (new_data[ind].GetStatus() == 1)
				fout << "Pass";
			else
				fout << "Fail";
			fout << endl;
		}
	}
	//Now all Data has been written in the Record File
	//Perform operations in working file
	//Now we have to Renew the Working Files


	//Keep in Mind we have to also Renew the Student Logins

	for (int i = 0; i < admin.getstudent_size() - 1; i++) {
		for (int j = i + 1; j < admin.getstudent_size(); j++) {
			if (admin.getStudent(i).getroll_number() == new_data[j].GetRollNumber()) {
				if (new_data[j].GetStatus() == 1)
					admin.getStudent(i).setclass_number(admin.getStudent(i).getclass_number() + 1);
			}
		}
	}
	//Now Class Number has been Increased!!

	/*

	//Now we have to assign Roll Numbers to each and every member ...!!
	string roll_number = "";
	int class_number = 0;
	for (int i = 0; i < admin.getstudent_size(); i++) {
	//Roll Number Code Starts from Here

	///////////////////////////
	int roll = 1;
	bool found = false;
	if (admin.getstudent_size() >= 1)
	{

	}
	////////////////////////////////////////////
	if (found == true)
	{
	roll++;
	roll_number = to_string(roll);
	if (roll_number.length() == 4) {
	roll_number = "0" + roll_number;
	}
	}
	else
	{
	roll_number = to_string(class_number);
	if (roll_number.length() == 1) {
	roll_number = "0" + roll_number;
	}
	string number;
	number = to_string(roll);
	if (number.length() == 1) {
	number = "00" + number;
	}
	else if (number.length() == 2) {
	number = "0" + number;
	}
	roll_number = roll_number + number;
	}

	admin.getStudent(i).setroll_number(roll_number);
	//Roll Number Code Ends Here
	}
	*/

	//Deleting Indexes where class number 11 is stored
	for (int i = 0; i < admin.getstudent_size(); i++) {
		if (admin.getStudent(i).getclass_number() == 11) {
			admin.SetStudentPointer(i);
		}
	}
	fout.open("Student.txt");
	fout.clear();
	admin.WriteFile(fout);

	admin.FileReadCourse();

	fout.open("StudentCourseMarks.txt");
	if (!fout)
		cout << "File cannot be opened!" << endl;
	else
	{
		for (int i = 0; i < admin.getstudent_size(); i++) {
			fout << admin.getStudent(i).getroll_number() << " ";
			fout << admin.getStudent(i).getclass_number();
			for (int j = 0;j<admin.GetCourseSize();j++) {
				if (admin.getStudent(i).getclass_number() == admin.GetCourse(j).GetClassNumber()) {
					fout << ",";
					fout << admin.GetCourse(j).GetCourseName() << "-";
					fout << "0 0 0 0 0 0 ";
				}
			}
			fout << endl;
		}
	}
	fout.close();
	//Now Assign Courses in the Courses.txt

	//admin.load_Teacher();
	//admin.resetteacher();

}








	int teacher_menu(Admin &ptr,int index) { // updated 15th june,2020
		system("cls");
		SMS_console();
		teacherportal_console();
		std::cout << "\tUser Signed in : " << ptr.get_Teacher_Username(index) << "\tSession : Active " << std::endl;// added 15th june 5:23 pm
		//std::cout << "=-------------<< Teacher Portal >>--------------=" << std::endl;
		std::cout << "\tPress 1- View Asssigned Courses" << std::endl;
		std::cout << "\tPress 2- Update Marks of a Student" << std::endl;
		std::cout << "\tPress 3- Change Password" << std::endl;
		std::cout << "\tPress 4- Exit" << std::endl; int opt;
		std::cout << "\t=----------------------------------------------=" << std::endl;
		take_input("\tEnter the respective Number : ", opt, 1, 4);
		return opt;
	}

	void updateMarks_Students_viaTeaherPortal(int index, Admin &ptr) {
		int coursecount = ptr.get_SpecifiedTeacherCourseCount(index); // checking if course count > 0
		if (coursecount > 0) {
			ptr.viewSpecifiedTeacherCourses(index);
			int courseindex;
			take_input("\t\tPick The Course : [Enter Respective No. ] =->  ", courseindex, 0, ptr.get_SpecifiedTeacherCourseCount(index) - 1);

			int localCourseClass = ptr.get_SpecifiedTeacherCourseClass(index, courseindex);

			StudentModule *new_data = NULL;
			int size = 0;
			string ind = "";
			new_data = ViewAndUpdateMarks(new_data, size, ind);
			ofstream fout;
			ind = NumberToString(localCourseClass);

			new_data = MarksUpdate(new_data, size, ind, "teacher", ptr.get_SpecifiedTeacherCourseName(index, courseindex));
			//Now  Previous Data is in ptr which StudentModule pointer
			fout.open("StudentCourseMarks.txt");
			WriteCourseMarks(fout, new_data, size);
		} else {
			notification_console();
			std::cout << "\t\tNo Courses Alloted Yet" << std::endl;	
		}

	}




	bool check_Login(int &index, Admin &ptr) {

		std::string username, password;
		std::cin.ignore();
		take_input("\t\t\tEnter the Username: ", username, "name");
		std::cin.ignore();
		take_input("\t\t\tEnter the Passowrd: ", password, "password");
		std::cin.ignore();

		for (int i = 0; i < ptr.get_totalTeacherUsers(); i++) {

			if (username == ptr.get_Teacher_Username(i) && password == ptr.get_Teacher_Password(i)) {
				index = i;
				return true;
			}
		}
		return false;

	}


	void TeacherPortal(Admin &ptr) {


		system("cls");
		SMS_console();
		teacherportal_console();
		int index = -1;

		bool loginStatus = check_Login(index, ptr);

		if (loginStatus == true && index >= 0) {

			bool stop_ctrl_teacher_menu = false;
			while (stop_ctrl_teacher_menu != true) {
				system("cls");
				
				int teacher_menu_value = teacher_menu(ptr,index); // value ranges from 1 to 5
				switch (teacher_menu_value)
				{
				case 1:
					system("cls");
					teacherportal_console();
					viewcourses_console();
					ptr.viewSpecifiedTeacherCourses(index);
					break;
				case 2:
					system("cls");
					teacherportal_console();
					updateMarks_Students_viaTeaherPortal(index, ptr);
					break;

				case 3:
					system("cls");
					teacherportal_console();
					ptr.change_SpecifiedTeacherPassword(index);
					break;
				case 4:
					stop_ctrl_teacher_menu = true;
					notification_console();
					std::cout << "Logging off the System" << std::endl;
					//Sleep(3000);
					break;
				default:
					break;
				}

				system("pause");
			}

		}
		else { // if login failed 
			notification_console();
			std::cout << "\tInvalid Login Details " << std::endl;
			system("pause");
		}

	}


