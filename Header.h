#pragma once
#ifndef Header_h
#define Header_h
#include<fstream>
using namespace std;

class Address  // aggregated in person
{
public:
    string streetNo;
    string town;
    string city;

    Address();
    Address(string, string, string);
    ~Address();
    string getStreet(), getTown(), getCity();
    void getAddress();
    void returnAddress();
};

class Person
{
protected:
    string t_id;
    string s_id;
    string firstName;
    string lastName;
    string gender;
    string contactNo;
    string department;
    char bloodGroup;
    string feeStatus;
    string qualification;
    string registration_date;
    string course[2];
    Address* PtrAdd;
    string section[2];
    string sr;
public:
    Person();
    Person(string, string, string, string, string, string, char, string, string, string);
    ~Person();

    //setters

    void setTeacherCourses(ofstream&);
    void getCourses();
    string get_StudentID();
    string get_first_name();
    string get_last_name();
    string get_contact_no();
    string get_gender();
    string get_dept();
    char get_bloodGrp();
    string get_feestatus();
    string get_qualification_student();
    string get_qualification_teacher();
    string get_regDate();
    string get_TID();

    // Setters

    void set_bloodgrp();
    void set_feestat();
    void set_qualification_student();
    void set_qualification_teacher();
    void set_regDate();
    void set_first_name();
    void set_last_name();
    void set_contact_no();
    void set_gender();
    void set_dept();
    void set_address();
    void set_st_id(string&);
    void set_t_id(string&);

    void display_info_student();
    void display_info_teacher();
};


class User : public Person
{
protected:
    string username;
    string password;
public:
    User();
    User(string, string);
    ~User();

};



class Administrator : virtual protected User
{
private:
    string adminUsername = "admin";
    string adminPassword = "admin";
    ofstream fileIn;
    ifstream fileOut;


public:
    Administrator();
    Administrator(string, string);

    void ADMINchoice();
    void assignCredentials();
    void ADMINsignIN(string&, string&);

    //==================== Add New =======================

    void addNewStudent(string&);
    void addNewTeacher(string&);

    //==================== view Student =======================

    void viewStudent(ifstream&);
    void viewAllStudents(ifstream&);

    //==================== view Teacher =======================

    void viewTeacher(ifstream&);
    void viewAllTeachers(ifstream&);

    //==================== Delete Student =======================

    void deleteStudentData(ofstream&, ifstream&);
    void deleteStudentPriv(ofstream&, ifstream&, string&);


    //==================== Delete Teacher ========================

    void deleteTeacherData(ofstream&, ifstream&);
    void deleteTeacherPriv(ofstream&, ifstream&, string&);

    //==================== Edit Student =======================

    void editStudentDetails(ofstream&, ifstream&);
    void editStudentPrivDetails(ofstream&, ifstream&, string&, string&);

    //==================== Edit Teacher ========================

    void editTeacherDetails(ofstream&, ifstream&);
    void editTeacherPrivDetails(ofstream&, ifstream&, string&, string&);

    // below remaining ones 

    void AssignShcedule();


    ~Administrator();

};

class Teacher : virtual protected User
{
public:
    Teacher();
    Teacher(string, string);
    ~Teacher();

    bool TeacherAssignCredentials();

    // Other functions
    void attendence();
    void showTeacherChoice();
    void viewTProfile();
    void Shcedule();
    void uploadEvaluations();
    friend class Student;
};

class Student : virtual protected User
{
    /*
protected:
    string* PtrCourse;*/

    string coursesSt[3];
    ofstream fout;
    ifstream fin;
public:
    Student();
    Student(string, string);
    ~Student();

    bool StudentAssignCredentials();

    void setCourses();


    // Other functions
    void studentShowChoice();
    void SelectStChoice(char&);
    void viewStProfile()const;
    void SeeCourses();
    void seeAttendence();
    void showEvaluations();
    friend class Teacher;
};

class Login : protected Student, Teacher, Administrator {

public:
    char Choice();
    void login(char&);
};


char logo();
void start();
void MAIN();
bool isLeapYear(int );
bool isValidDate(int , int , int );


#endif // !Header_h