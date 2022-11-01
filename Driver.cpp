#include "Header.h"

void display_readme(void);
int main_menu();
int admin_menu();
int student_menu();

void DisplayName(Admin &admin, int &ind);
void ViewAssessmentMarks(string &user);

int main(void) {

	display_readme();
	Admin obj;
	obj.load_Teacher(); // loads all teacher.txt data into program
	obj.load_teacherUsers();
	obj.load_AdminUsers(); // load all adminUsers into program

	//////////////////////////
	obj.load_studentUsers();
	string user = "";
	bool stp_ctrl_student = false;
	//////////////////////////
	std::string filename;
	int count;
	bool stp_ctrl = false;
	bool loginStatus = false;
	bool stp_ctrl_admin = false;

	while (stp_ctrl != true) {
		system("cls");
		bool stp_ctrl_admin = false;
		int main_menu_value = main_menu(); // value ranging from 1 to 4 
		switch (main_menu_value)
		{
		case 1:
			stp_ctrl_admin = false;
			loginStatus = obj.login_AdminUser();
			if (loginStatus == false) {
				stp_ctrl_admin = true;
				std::cout << "\tNotfication!\nlogin credentials Invalid" << std::endl;
				system("pause");
			} // this will stop from loading the menu below
			while (stp_ctrl_admin != true)
			{
				int admin_menu_value = admin_menu(); // value 1 to 5 
				switch (admin_menu_value)
				{
				case 1:
					
					system("cls");
					adminportal();
					addteacher_console();
					obj.add_teacher_viaInput();
					break;
				case 2:
					system("cls");
					adminportal();
					viewteachers_console();
					obj.view_allTeachers();
					break;
				case 3:
					system("cls");
					adminportal();
					obj.updateTeacher();
					break;
				case 4:
					obj.reset_Teachers("Teacher_courses.txt",true);
					break;
				case 5:
					system("cls");
					adminportal();
					assigncourse_console();
					obj.assignCourse();
					break;
				case 6:
					system("cls");
					adminportal();
					obj.view_allTeachers_Details();
					break;
				case 7:
					system("cls");
					adminportal();
					obj.add_AdminUser_viaInput();
					break;
				case 8:
					system("cls");
					adminportal();
					addstudnet_console();
					AddNewStudent();
					break;
				case 9:
					system("cls");
					adminportal();
					addcourse_console();
					AddNewCourse();
					break;
				case 10:
					EditStudentDetails();
					break;
				case 11:
					Display();
					break;
				case 12:
					system("cls");
					adminportal();
					viewcourses_console();
					DisplayCourse();
					break;
				case 13:
					ViewStudentMarks();
					break;
				case 14:
					UpdateStudentMarks();
					break;
				case 15:
					ViewFeeStatus();
					break;
				case 16:
					//stp_ctrl_admin = true;
					count = countsession();
					filename = "Teacher_coursesSession" + NumberToString(count)+".txt";
					obj.reset_Teachers(filename.c_str(),false);
					rewritecountsession(count);
					StudentPromotion();
					break;
				case 17:
					stp_ctrl_admin = true;
					break;
				default:
					break;
				} // swtich admin menu ends here....
				system("pause");
			} // stp_ctrl_admin ends here...while loop

			break;
		case 2:
			stp_ctrl_student = false;
			user="";
			loginStatus = obj.login_StudentUser(user);
			if (loginStatus == false) {
				stp_ctrl_student = true;
				std::cout << "\tNotfication!\nlogin credentials Invalid" << std::endl;
				system("pause");
			} // this will stop from loading the menu below
			while (stp_ctrl_student != true)
			{
				Admin admin;
				admin.FileRead();
				int ind = -1;
				for (int i = 0; i < admin.getstudent_size(); i++) {
					if (admin.getStudent(i).getroll_number() == user) {
						ind = i;
						break;
					}
				}
				DisplayName(admin,ind);
				int main_menu_value = student_menu();
				if (main_menu_value == 1) {
						//View Assessment Marks
					ViewAssessmentMarks(user);
				}
				else if (main_menu_value == 2)
				{
					if (admin.getStudent(ind).getfee_submitted() == 1)
						cout << "\n\tYou have Submitted your Fee!\n";
					else
						cout << "\n\tYour Fee is missing!\n";
					system("pause");
				}
				else if (main_menu_value == 3) {
					stp_ctrl_student = true;
				}
			}
			break;
		case 3:
				TeacherPortal(obj);
			break;

		case 4:
			stp_ctrl = true;
			break;
		default:
			std::cout << "This is a Demo version ~ only admin login works" << std::endl;
			break;
		} // main switch ends here...
	} // while stop control ends here...
} // main ends here...

int main_menu() {
	system("cls");
	SMS_console();
	loginportal();
	//std::cout << "=------<< School Management System >>----------=" << std::endl;
	std::cout << "\tPress 1- Login as Admin" << std::endl;
	std::cout << "\tPress 2- Login as Student" << std::endl;
	std::cout << "\tPress 3- Login as Teacher" << std::endl;
	std::cout << "\tPress 4- Exit" << std::endl; int opt;
	std::cout << "=----------------------------------------------=" << std::endl;
	take_input("\tEnter the respective Number : ", opt, 1, 4);
	return opt;
}
int admin_menu() {
	system("cls");
	SMS_console();
	adminportal();
	//std::cout << "=-------------<< Admin Portal >>--------------=" << std::endl;
	std::cout << "\tPress 1-  Add new Teacher" << std::endl;
	std::cout << "\tPress 2-  View all Teacher" << std::endl;
	std::cout << "\tPress 3-  Update Teacher info" << std::endl;
	std::cout << "\tPress 4-  Reset Teachers Courses" << std::endl;
	std::cout << "\tPress 5-  Assign Course to Teacher" << std::endl;
	std::cout << "\tPress 6-  View All Teachers Details" << std::endl;
	std::cout << "\tPress 7-  Add New Admin User" << std::endl;
	////////////////////////////////////////////////////////////////
	std::cout << "\tPress 8-  Add New Student" << std::endl;
	std::cout << "\tPress 9-  Add Course to Class" << std::endl;
	std::cout << "\tPress 10- Edit Student Details" << std::endl;
	std::cout << "\tPress 11- View all Students" << std::endl;
	std::cout << "\tPress 12- View All Courses" << std::endl;
	std::cout << "\tPress 13- View Student Marks" << std::endl;
	std::cout << "\tPress 14- Update Student Marks" << std::endl;
	std::cout << "\tPress 15- View Fee Status" << std::endl;
	std::cout << "\tPress 16- End Session" << std::endl;
	std::cout << "\tPress 17- Exit" << std::endl; 
	int opt;
	std::cout << "=----------------------------------------------=" << std::endl;
	take_input("\tEnter the respective Number : ", opt, 1, 17);
	return opt;
}
//////////////////////////////////////////
int student_menu() {
	cout << endl;
	system("cls");
	SMS_console();
	studentportal_console();
	std::cout << "=-------------<< Student Portal >>--------------=" << std::endl;
	std::cout << "\tPress 1-  To View Assessment Marks" << std::endl;
	std::cout << "\tPress 2-  View Fee Status" << std::endl;
	std::cout << "\tPress 3-  Exit" << std::endl;
	int opt;
	std::cout << "=----------------------------------------------=" << std::endl;
	take_input("\tEnter the respective Number : ", opt, 1, 3);
	return opt;
}

//////////////////////////////////////////

void display_readme() {
	std::fstream file;
	file.open("readme.txt", std::ios::in);
	std::string display;
	if (file.is_open()) {

		while (!file.eof())
		{
			std::getline(file, display);
			std::cout << display << std::endl;
			if (file.eof())
				break;
		}
	}	else {
		std::cout << "Unable to Open readme.txt" << std::endl;
	}
	system("pause");
	system("cls");
	//std::cout << std::endl;
	
}
void ViewAssessmentMarks(string &user) {
	Admin admin;
	admin.FileRead();
	StudentModule *new_data = NULL;
	int size = 0;
	string ind = "";
	ofstream fout;
	new_data = ViewAndUpdateMarks(new_data, size, ind);
	//Now Viewing Marks
	int index = -1;
	for (int i = 0; i < admin.getstudent_size(); i++) {
		if (new_data[i].GetRollNumber() == user) {
			index = i;
			break;
		}
	}
	int choice = -1;
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
	system("pause");
}
void DisplayName(Admin &admin,int &ind) {

	system("cls");
	cout << "-------------->> Welcome <<---------------\n" << endl;
	if (admin.getStudent(ind).getgender() == 'M')
		cout << "\t Mr. ";
	else
		cout << "\t Mrs. ";
	cout << admin.getStudent(ind).getfirst_name() + " " + admin.getStudent(ind).getlast_name();
	cout << endl;
	cout << endl;
	cout << "=------------------------------------------=\n\n";
	cout << "----------->> Roll number: " << admin.getStudent(ind).getroll_number() << "--------\n";
	cout << endl;

}