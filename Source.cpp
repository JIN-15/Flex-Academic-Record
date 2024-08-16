#include <iostream>
#include <stdio.h>
#include "Header.h"
#include <fstream>
#include <string>
#include <Windows.h>
#include <iomanip>
#include <cstring>
#include <regex>

HANDLE clr = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;

int STID = 1000, TID = 9000;



string mainUserName;
char choice;
void ID_Check()
{
    string firstName, lastName, s_id, feeStatus, contactNo, registration_date, qualification;
    ifstream fin;
    fin.open("studentPriv.txt", ios::app);
    while (fin >> firstName >> lastName >> s_id >> feeStatus >> contactNo
        >> registration_date)
    { 
        STID = stoi(s_id.substr(s_id.find('-') + 1));
        
    }
    fin.close();
    firstName = lastName = s_id = feeStatus = contactNo = registration_date = qualification = "";
    fin.open("teacherPriv.txt", ios::app);
    while (fin >> firstName >> lastName >> s_id >> contactNo >> qualification)
    {
        TID = stoi(s_id.substr(s_id.find('-') + 1));
        
    }
    fin.close();

}

//user Class's Member functions


User::User() :username(""), password(""), Person() {}
User::User(string userN, string pass) :username(userN), password(pass), Person() {}
User::~User() {};

//address Class's Member functions


Address::Address() :streetNo(""), town(""), city("") {}
Address::Address(string stNo, string twn, string cty)
{
    this->streetNo = stNo;
    this->town = twn;
    this->city = cty;
}
Address::~Address() {};

string Address::getStreet() { return streetNo; }
string Address::getTown() { return town; }
string Address::getCity() { return city; }

void Address::getAddress()
{
    cout << " Street :" << getStreet() ;
    cout << ", Town:" << getTown() ;
    cout << ", City:" << getCity();
}

void Address::returnAddress()
{
    getStreet();
    getTown();
    getCity();
}


//Defintion of Person Class's Member functions

Person::Person() :firstName(""), lastName(""), gender(""), contactNo(""), department(""), s_id("")
, bloodGroup('\0'), feeStatus(""), qualification(""), registration_date("") {}
Person::Person(string first_name, string last_name, string contact_no, string gender, string depart
    , string id, char bg, string feestat, string qualification, string dateReg)
{
    this->firstName = first_name;
    this->lastName = last_name;
    this->contactNo = contact_no;
    this->gender = gender;
    this->department = depart;
    this->s_id = id;
    bloodGroup = bg;
    feeStatus = feestat;
    this->qualification = qualification;
    registration_date = dateReg;
}
Person::~Person() { delete PtrAdd; };

// Getters

string Person::get_first_name() { return firstName; }

string Person::get_last_name() { return lastName; }

string Person::get_contact_no() { return contactNo; }

string Person::get_gender() { return gender; }

string Person::get_dept() { return department; }

char Person::get_bloodGrp() { return bloodGroup; }

string Person::get_feestatus() { return feeStatus; }

string Person::get_qualification_student() { return qualification; }

string Person::get_qualification_teacher() { return qualification; }

string Person::get_regDate() { return registration_date; }

string Person::get_StudentID() { return s_id; }

string Person::get_TID() { return t_id; }

void Person::getCourses()
{
    for (int i = 0; i < 2; ++i)
    {
        cout << "\t| ";
        cout << "Course No. " << i + 1 << " : " << course[i] << " ==> Section : " << section[i] << endl;
    }
}

// Setters
void Person::set_first_name()
{
    string firstN;
    int checkTemp = 0;

    cout << "\n---------------\nEnter first name : ";
    do
    {
        checkTemp += 1;
        if (checkTemp != 1)
        {
            cout << "\tIncorrect Input !!\n\t You can only Enter chracters from A-Z. \"So, Try Again \" \n";
            system("pause");
        }
        cin >> firstN;
        this->firstName = firstN;

    } while (!(regex_match(firstName, regex("^[A-Za-z]+$"))));
}


void Person::set_last_name()
{
    string lastN;
    int checkTemp = 0;

    cout << "\n---------------\nEnter Last name : ";
    do
    {
        checkTemp += 1;
        if (checkTemp != 1)
        {
            cout << "\tIncorrect Input !!\n\t You can only Enter chracters from A-Z. \"So, Try Again \" \n";
            system("pause");
        }
        cin >> lastN;
        this->lastName = lastN;

    } while (!(regex_match(firstName, regex("^[A-Za-z]+$"))));
}

void Person::set_contact_no()
{
    string contactNo, temp;
    cout << "\n---------------\nEnter contact # : ";
    cin >> temp;
    contactNo = "(+92)_" + temp;
    this->contactNo = contactNo;
}

void Person::set_gender()
{
    string gender;
    int checkTemp = 0;

    cout << "\n---------------\nEnter your Gender : ";
    do 
    {
        checkTemp += 1;
        if (checkTemp != 1)
        {
            cout << "\tIncorrect Input !! \n\tYou can only Enter ( male OR female ). \"So, Try Again \" \n";
            system("pause");
        }
        cin >> gender;
    } while (gender != "male" && gender != "female");
    this->gender = gender;
}

void Person::set_dept()
{
    string depart;
    int checkTemp = 0;
    cout << "\n---------------\nEnter your department Name from -> (CS, SE, EE, BBA, AI, OR 'A and F' ) : ";
    do
    {
        checkTemp += 1;
        if (checkTemp != 1)
        {
            cout << "\n\tIncorrect Input !! \n\tYou can only Enter ( CS, SE, EE, BBA, AI, OR 'A and F' ). \"So, Try Again \" \n";
            system("pause");
        }
        cin >> depart;
    } while ((depart != "CS" && depart != "cs") && (depart != "SE" && depart != "se")&& (depart != "EE" && depart != "ee") && 
        (depart != "AI" && depart != "ai") && (depart != "BBA" && depart != "bba") && (depart != "A and F" && depart != "a and f"));
    
    this->department = depart;
    return;
}

void Person::set_address()
{
    string city, town, street;
    cout << "\n---------------\nEnter Your Permanent Address : \n";
    cout << "Enter your city : ";
    cin >> city;
    cout << "Enter your town : ";
    cin >> town;
    cout << "Enter your street : ";
    cin >> street;
    PtrAdd = new Address(street, town, city);
}


void Person::set_bloodgrp()
{
    char bg;
    int checkTemp = 0;
    cout << "\n---------------\nEnter your blood group -> (A, O, B): \n";
    do 
    {
        checkTemp += 1;
        if (checkTemp != 1)
        {
            cout << "\tIncorrect Input !! \n\tYou can only Enter ( A, B, O ). \"So, Try Again \" \n";
            system("pause");
        }
        cin >> bg;
    } while ((bg != 'A' && bg != 'a') && (bg != 'B' && bg != 'b') && (bg != 'O' && bg != 'o'));
    bloodGroup = bg;
    return;
}

void Person::set_feestat()
{
    string ch;
    cout << "\n---------------\nEnter your Fee Status (paid/not-paid)\nEnter 'paid' for PAID STATUS else any Chracter \n";
    cin >> ch;
    feeStatus = (ch == "paid" ? "paid" : "unpaid");
    return;
}

void Person::set_qualification_student()
{
    char ch;
    cout << "\n---------------\nChoose your qualification : \n";
    cout << "'m' for (Matriculation) OR (A-Level)  <------ OR ------>  Any other chracter for (Intermediate)-> *FSC / ICS / ICOM / O-Level*\n";
    cin >> ch;
    qualification = (ch == ('m'||'M') ? "Matriculation" : "Intermediate");
    return;
}

void Person::set_qualification_teacher()
{
    char ch;
    cout << "\n---------------\nChoose your qualification : \n";
    cout << "'b' for -> (Bachelors)  <------ OR ------>  "
        << "\n'm' For -> (Masters / M.Phil) <------ OR ------> "
        <<  "\nAny other chracter for \"P.H.D\" -> (Doctorate)\n";
    cin >> ch;
    qualification = (ch == ('b'||'B') ? "Bachelors-(BS)" : ch == ('m'||'M') ? "Masters-(M.Phil)" : "Doctorate-(PHD)");
    return;
}

void Person::set_regDate()
{
    
    int day, month, year;

    // Take input from user
    cout << "\n---------------\nEnter a Registeration Date : \n";
    cout << "Enter Day : ";
    cin >> day;
    cout << "Enter Month : ";
    cin >> month;
    cout << "Enter Year : ";
    cin >> year;
    // Validate the date
    if (!(isValidDate(day, month, year))) 
    {
        cout << "Invalid date entered!" << endl;
        system("pause");
        set_regDate();
    }
    registration_date = to_string(day) + "-" + to_string(month) + "-" + to_string(year);
    return;
}


void Person::set_st_id(string& de)
{
    STID += 1;
    int checkTemp = 0;
    cout << "\n-----------------------\nAssign Section to Student \"A, B, C, D\" : ";
    do
    {
        checkTemp += 1;
        if (checkTemp != 1)
        {
            cout << "\tIncorrect Input !! \n\tYou can only Enter (A, B, C, D). \"So, Try Again \" \n";
            system("pause");
        }
        cin >> this->section[0];
    } while (section[0] != "A" && section[0] != "B" && section[0] != "C" && section[0] != "D");

    if (department == "cs" || department == "CS") {
        s_id = "22CS-" + to_string(STID);
    }
    else if (department == "se" || department == "SE") {
        s_id = "22SE-" + to_string(STID);
    }
    else if (department == "ee" || department == "EE") {
        s_id = "22EE-" + to_string(STID);
    }
    else if (department == "bba" || department == "BBA") {
        s_id = "22BBA-" + to_string(STID);
    }
    else if (department == "ai" || department == "AI") {
        s_id = "22AI-" + to_string(STID);
    }
    else if (department == "a and f" || department == "A and F") {
        s_id = "22AF-" + to_string(STID);
    }

    ofstream out;
    out.open("studentUsername.txt", ios::app);
    if (!out)
    {
        cout << "StdentUsername.txt File cannot be opened \n";
        exit(0);
    }
    string temp = to_string(STID) + "NUCES";
    out << s_id << " " << temp << endl;
    out.close();
}

void Person::set_t_id(string& de)
{
    TID += 1;
    if (department == "cs" || department == "CS") {
        t_id = "CS-" + to_string(TID);
    }
    else if (department == "se" || department == "SE") {
        t_id = "SE-" + to_string(TID);
    }
    else if (department == "bba" || department == "BBA") {
        t_id = "BBA-" + to_string(TID);
    }
    else if (department == "ee" || department == "EE") {
        t_id = "EE-" + to_string(TID);
    }
    else if (department == "ai" || department == "AI") {
        t_id = "AI-" + to_string(TID);
    }
    else if (department == "a and f" || department == "A and F") {
        t_id = "AF-" + to_string(TID);
    }
    ofstream out;
    out.open("teacherUsername.txt", ios::app);
    if (!out)
    {
        cout << "teacherUsername.txt File cannot be opened \n";
        exit(0);
    }
    string temp = to_string(TID) + "NUCES";
    out << t_id << " " << temp << endl;
    out.close();
}

void Person::setTeacherCourses(ofstream& in)
{
    
    string arr[2];
    string choice;
    system("cls");
    SetConsoleTextAttribute(clr, 11);
    cout << "\n______________________________________________\nSelect Courses for Teacher (Must Select 2) : \n";
    cout << "\t\n---------------------------------------------\n";
    cout << "\t1): Programming Fundamnetals (PF) \n\t2): Object Oriented Programming (OOP) \n\t3): Data Structure And Algorithm (DSA) \n" <<
        "\t4): Data Bases (DB) \n\t5): Business Analytics (DA) \n\t6): Digital Logic Design (DLD) \n\t7): Linear Circuit Analysis (LCA) \n" <<
        "\t8): Communication and Presentation Skills (CPS) \n\t9): Technical Business Writing \n";
    cout << "\t\n---------------------------------------------\n";
    SetConsoleTextAttribute(clr, 7);
    for (int i = 0; i < 2; ++i)
    {
        int checkForInvalid1 = 0;
        cout << "Select course No. " << i + 1 << " : ";
        do
        {
            checkForInvalid1 += 1;
            if (checkForInvalid1 != 1)
            {
                cout << "\n\tInvalid input !! Enter Again <-\n\n";
                system("pause");
            }
            cin >> choice;

        } while (choice < "1" && choice > "9");
        if (choice == "1")
        {
            this->course[i] = "Programming_Fundamnetals->(PF)";
            in << " Programming_Fundamnetals->(PF)";
        }
        else if (choice == "2")
        {
            this->course[i] = "Object_Oriented_Programming->(OOP)";
            in << " Object_Oriented_Programming->(OOP)";
        }
        else if (choice == "3")
        {
            this->course[i] = "Data_Structure_And_Algorithm->(DSA)";
            in << " Data_Structure_And_Algorithm->(DSA)";
        }
        else if (choice == "4")
        {
            this->course[i] = "Data_Bases->(DB)";
            in << " Data_Bases->(DB)";
        }
        else if (choice == "5")
        {
            this->course[i] = "Business_Analytics->(DA)";
            in << " Business_Analytics->(DA)";
        }
        else if (choice == "6")
        {
            this->course[i] = "Digital_Logic_Design->(DLD) ";
            in << " Digital_Logic_Design->(DLD)";
        }
        else if (choice == "7")
        {
            this->course[i] = "Linear_Circuit_Analysis->(LCA)";
            in << " Linear_Circuit_Analysis->(LCA)";
        }
        else if (choice == "8")
        {
            this->course[i] = "Communication_and_Presentation_Skills->(CPS)";
            in << " Communication_and_Presentation_Skills->(CPS)";
        }
        else if (choice == "9")
        {
            this->course[i] = "Technical_Business_Writing->(TBW)";
            in << " Technical_Business_Writing->(TBW)";
        }
        cout << "Select Class For Teacher \"A, B, C, D\" course No. " << i + 1 << " : ";
        cin >> section[i];
    }
    in << endl;

}

void Person::display_info_student()
{
    system("cls");
    SetConsoleTextAttribute(clr, 10);
    cout << "\n\t\tDATA OF STUDENT\n";
    cout << "\t|-----------------------------------|\n";
    cout << "\t| Name : \t" << get_first_name() << " " << get_last_name() << endl;
    cout << "\t| Gender : \t" << get_gender() << endl;
    cout << "\t| Student ID : \t" << get_StudentID() << endl;
    cout << "\t| Department : \t" << get_dept() << endl;
    cout << "\t| Section : \t" << section[0] << endl;
    cout << "\t| Contact # \t" << get_contact_no() << endl;
    cout << "\t| Address => \t"; PtrAdd->getAddress(); cout <<  endl;
    cout << "\t| Blood Group :   " << get_bloodGrp() <<  endl;
    cout << "\t| Qualification :   " << get_qualification_student() << endl;
    cout << "\t| Fee Status : \t" << get_feestatus() <<  endl;
    cout << "\t| Registration date : \t" << get_regDate() << endl;
    cout << "\t|-----------------------------------|\n\n";
    SetConsoleTextAttribute(clr, 7);
}

void Person::display_info_teacher()
{
    system("cls");
    SetConsoleTextAttribute(clr, 10);
    cout << "\n\t\tDATA OF TEACHER\n";
    cout << "\t|-----------------------------------|\n";
    cout << "\t| Name : \t" << get_first_name() << " " << get_last_name() << endl;
    cout << "\t| Gender : \t" << get_gender() << endl;
    cout << "\t| Teacher ID : \t" << get_TID() << endl;
    cout << "\t| Department : \t" << get_dept() << endl;
    cout << "\t| Contact # \t" << get_contact_no() << endl;
    cout << "\t| Address => \t"; PtrAdd->getAddress(); cout << endl;
    cout << "\t| Qualification :   " << get_qualification_teacher() << endl;
    cout << "\t| Registration date : \t" << get_regDate() << endl;
     getCourses();
    cout << "\t|-----------------------------------|\n\n";
    SetConsoleTextAttribute(clr, 7);
}




// admin funcitons definations----------------------



Administrator::Administrator() : adminUsername("admin"), adminPassword("admin"), User() {};
Administrator::Administrator(string user, string pass) {
    user = username;
    pass = password;
}


void Administrator::assignCredentials()
{
    string userName, passWord;
    cout << "Enter your UserName : ";
    cin >> userName;
    cout << "Enter Passsword : ";
    cin >> passWord;
    ADMINsignIN(userName, passWord);
}

void Administrator::ADMINsignIN(string& u, string& p)
{
    if ((u == adminUsername) && (p == adminPassword)) 
    {
        return;
    }
    else 
    {
        cout << "\n\tWrong UserName OR Password for Admin !! \n Enter again  ! \n";
        assignCredentials();
    }
}

void Administrator::ADMINchoice()
{
    int checkForInvalid1 = 0;
    ID_Check();
    string choice; 
    system("cls");
    int z = 2;
    system("Color 0F");
    while (z > 0)
    {
        system("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tLoading ";
        for (int k = 0; k < 4; ++k)
        {
            cout << "-";
            Sleep(200);
        }
        z--;
    }
    system("cls");
    SetConsoleTextAttribute(clr, 11);
    cout << "\n\t -------------------------\n\t|\t\t\t  |\n\t| Login successful !      |\n\t| Welcome to ADMIN-FLEX   |\n\t|\t\t\t  |\n\t|-------------------------|\n";

    cout << "\n\t----------------------------\n\t|\t\t\t   |\n\t| Now, What you want\t   |\n\t| Enter your choice !\t   |\n\t|\t\t\t   |\n";
    cout << "\t| 1): Add new Student\t   |\n\t| 2): Add new Teacher\t   |\n\t| 3): view student \t   |\n\t| 4): view Teacher\t   |\n"
        << "\t| 5): view all students\t   |\n\t| 6): view all teachers\t   |\n\t| 7): delete student\t   |\n" <<
        "\t| 8): delete teacher\t   |\n" << "\t| 9): Edit Student Detail  |\n\t| 10): Edit teacher Detail |\n\t| 0): EXIT \t\t   |\n\t|\t\t\t "<<
        "  |\n\t----------------------------\n";
    SetConsoleTextAttribute(clr, 7);
    do 
    {
        checkForInvalid1 += 1;
        if (checkForInvalid1 != 1)
        {
            cout << "\n\tInvalid input !! Enter Again <-\n\n";
            system("pause");
        }
        cin >> choice;
    } while (!(regex_match(choice, regex("^([0-9]|10)$"))));

    if (choice == "1")
        addNewStudent(choice);
    else if (choice == "2")
        addNewTeacher(choice);
    else if (choice == "3")
        viewStudent(fileOut);
    else if (choice == "4")
        viewTeacher(fileOut);
    else if (choice == "5")
        viewAllStudents(fileOut);
    else if (choice == "6")
        viewAllTeachers(fileOut);
    else if (choice == "7")
        deleteStudentData(fileIn, fileOut);
    else if (choice == "8")
        deleteTeacherData(fileIn, fileOut);
    else if (choice == "9")
        editStudentDetails(fileIn, fileOut);
    else if (choice == "10")
        editTeacherDetails(fileIn, fileOut);
    else if (choice == "0")
    {
        MAIN();
    }
    system("pause");
    ADMINchoice();
}



void Administrator::addNewStudent(string& ch)
{
    fileIn.open("StudentData.txt", ios::app); //this file contains all data of student 
    if (!fileIn.is_open()) 
    {
        cout << "StudentData.txt file opening failed ! \n";
        exit(0);
    }
    else 
    {
        //input & Set all Data ................

        set_first_name();
        set_last_name();
        set_dept();
        set_contact_no();
        set_regDate();
        set_gender();
        set_address();
        set_bloodgrp();
        set_feestat();
        set_qualification_student();
        set_st_id(department);

        
        system("pause");

        fileIn << firstName << ' ' << lastName << ' '
            << department << ' '
            << contactNo << ' '
            << section[0] << ' '
            << gender << ' '
            << PtrAdd->getCity() << ' ' << PtrAdd->getTown() << ' ' << PtrAdd->getStreet()
            << ' ' << bloodGroup << ' ' << feeStatus << ' ' << qualification << ' '
            << registration_date << " " << s_id << endl;
        system("cls");
        SetConsoleTextAttribute(clr, 74);
        cout << "\n\n\n\n\n\t\t|-----------------------------------|";
        SetConsoleTextAttribute(clr, 74);
        cout << "\n\t\t| Student Registerd Successfully !! |";
        SetConsoleTextAttribute(clr, 74);
        cout << "\n\t\t|-----------------------------------|\n\n\t\t\t\t";
        for (int g = 0; g < 5; ++g)
        {

            cout << "-";
            Sleep(500);
        }
        system("pause");
        system("Color 0F");
        system("cls");
        display_info_student();
    }
    fileIn.close();

    //taking private data to other file

    fileIn.open("StudentPriv.txt", ios::app);
    if (!fileIn.is_open()) {
        cout << "\tStudentPriv.txt File opening failed !\n";
        exit(0);
    }
    fileIn << firstName << " " << lastName << " " << s_id << " " << feeStatus << " " <<
        contactNo << " " << registration_date << endl;
    fileIn.close();

    fileIn.open("StudentIdSection.txt", ios::app);
    if (!fileIn.is_open()) 
    {
        cout << "\tStudentIdSection.txt File opening failed !\n";
        exit(0);
    }
    fileIn << s_id << " " << section[0] << endl;
    fileIn.close();

}

void Administrator::addNewTeacher(string& ch)
{
    fileIn.open("teacherData.txt", ios::app); //this file contains all data of student 
    if (!fileIn.is_open()) 
    {
        cout << "\n\tteacher.txt file opening failed ! \n";
        exit(0);
    }
    else 
    {
        set_first_name();
        set_last_name();
        set_dept();
        set_contact_no();
        set_regDate();
        set_gender();
        set_address();
        set_qualification_teacher();
        set_t_id(department);


        fileIn << firstName << ' ' << lastName << ' '
            << department << " "
            << contactNo << " "
            << gender << " "
            << PtrAdd->getCity() << " " << PtrAdd->getTown() << " " << PtrAdd->getStreet()
            << " " << qualification << " " << registration_date << " " << t_id;

        setTeacherCourses(fileIn);
        AssignShcedule();

        system("cls");
        SetConsoleTextAttribute(clr, 74);
        cout << "\n\n\n\n\n\t\t|-----------------------------------|";
        SetConsoleTextAttribute(clr, 74);
        cout << "\n\t\t| Teacher Registerd Successfully !! |";
        SetConsoleTextAttribute(clr, 74);
        cout << "\n\t\t|-----------------------------------|\n\n\t\t\t\t";
        for (int g = 0; g < 5; ++g)
        {

            cout << "-";
            Sleep(500);
        }
        system("pause");
        system("Color 0F");
        system("cls");
        display_info_teacher();
    }
    fileIn.close();

    //taking private data to other file

    ofstream TPfile;
    TPfile.open("teacherPriv.txt", ios::app);
    if (!TPfile.is_open()) 
    {
        cout << "teacherPriv.txt File opening failed ! \n";
        exit(0);
    }
    TPfile << firstName << " " << lastName << " " << t_id << " " << contactNo << " "
        << qualification << registration_date << endl;
    TPfile.close();
    ofstream fout;
    fout.open("TeacherClassData.txt", ios::app);
    if (!fout)
    {
        cout << "TeacherClassData.txt Opening Failed !!\n";
        exit(0);
    }
    fout << t_id << " " << firstName << " " << lastName << " " << course[0]
        << " " << section[0] << " " << course[1] << " " << section[1] << endl;
    fout.close();
}


void Administrator::viewStudent(ifstream& outFile)
{
    outFile.open("StudentPriv.txt", ios::app);
    string ID;
    cout << "Enter ID of Student you want to Find  : ";
    cin >> ID;
    Administrator ad;
    bool found = false;
    while (outFile >> ad.firstName >> ad.lastName >> ad.s_id >> ad.feeStatus >> ad.contactNo
        >> ad.registration_date) 
    {
        if (ad.s_id == ID) 
        {
            SetConsoleTextAttribute(clr, 11);
            found = true;
            cout << "\n\t\tDATA OF STUDENT\n";
            cout << "\t|-----------------------------------|\n";
            cout << "\t| Name : \t" << ad.firstName << " " << ad.lastName << endl;
            cout << "\t| Contact # \t" << ad.contactNo << endl;
            cout << "\t| Student ID : \t" << ad.s_id << endl;
            cout << "\t| Student ID : \t" << ad.s_id << endl;
            cout << "\t| Fee Status : \t" << ad.feeStatus << endl;
            cout << "\t| Registration date : \t" << ad.registration_date << endl;
            cout << "\t|-----------------------------------|\n\n";
            SetConsoleTextAttribute(clr, 10);
            cout << "\n_________________________\n";

            SetConsoleTextAttribute(clr, 7);
            break;
        }
    }
    if (found == false)
        cout << "Student Not Registered Yet (OR Record not found) OF ID " << ID << " !\n";
    outFile.close();
}

void Administrator::viewTeacher(ifstream& outFile)
{
    outFile.open("teacherPriv.txt", ios::app);
    string ID;
    cout << "Enter ID of Teacher you want to Find  : ";
    cin >> ID;
    bool found = false;
    Administrator ad;
    while (outFile >> ad.firstName >> ad.lastName >> ad.t_id >> ad.contactNo >> ad.qualification) {
        if (ad.t_id == ID) {
            found = true;
            SetConsoleTextAttribute(clr, 11);
            cout << "\n\t\tDATA OF TEACHER\n";
            cout << "\t|-----------------------------------|\n";
            cout << "\t| Name : \t" << ad.firstName << " " << ad.lastName << endl;
            cout << "\t| Contact # \t" << ad.contactNo << endl;
            cout << "\t| Student ID : \t" << ad.t_id << endl;
            cout << "\t| Qualification : \t" << ad.qualification << endl;
            cout << "\t|-----------------------------------|\n\n";
            cin.ignore();

            SetConsoleTextAttribute(clr, 4);
            cout << "\n___________________________________\n";

            SetConsoleTextAttribute(clr, 7);
            break;
        }
    }
    if (found == false)
        cout << "Teacher Not Registered Yet (OR Record not found) OF ID " << ID << " !\n";
    outFile.close();
}

void Administrator::viewAllStudents(ifstream& outFile)
{
    outFile.open("StudentPriv.txt", ios::app);
    Administrator ad;
    int i = 0;
    while (outFile >> ad.firstName >> ad.lastName >> ad.s_id >> ad.feeStatus >> ad.contactNo
        >> ad.registration_date) 
    {
        i += 1;
        SetConsoleTextAttribute(clr, 11);
        cout << "\n\t\tDATA OF STUDENT NO. "<< i << " \n";
        cout << "\t|-----------------------------------|\n";
        cout << "\t| Name : \t" << ad.firstName << " " << ad.lastName << endl;
        cout << "\t| Contact # \t" << ad.contactNo << endl;
        cout << "\t| Student ID : \t" << ad.s_id << endl;
        cout << "\t| Fee Status : \t" << ad.feeStatus << endl;
        cout << "\t| Registration date : \t" << ad.registration_date << endl;
        cout << "\t|-----------------------------------|\n\n";
        SetConsoleTextAttribute(clr, 7);
        
    }
    outFile.close();
}

void Administrator::viewAllTeachers(ifstream& outFile)
{
    outFile.open("teacherPriv.txt", ios::app);
    Administrator ad;
    int i = 0;
    while (outFile >> ad.firstName >> ad.lastName >> ad.t_id >> ad.contactNo >> ad.qualification) {
        i += 1;

        SetConsoleTextAttribute(clr, 10);
        cout << "\n\t\tDATA OF TEACHER NO. " << i << " \n";
        cout << "\t|-----------------------------------|\n";
        cout << "\t| Name : \t" << ad.firstName << " " << ad.lastName << endl;
        cout << "\t| Contact # \t" << ad.contactNo << endl;
        cout << "\t| Student ID : \t" << ad.t_id << endl;
        cout << "\t| Qualification : \t" << ad.qualification << endl;
        cout << "\t|-----------------------------------|\n\n";

        SetConsoleTextAttribute(clr, 7);
        cout << "\n_________________________________\n";
    }
    outFile.close();
}

void Administrator::deleteStudentData(ofstream& outFile, ifstream& inFile)
{
    ifstream fin;
    ofstream fout;
    Address ad;
    fin.open("StudentData.txt");
    if (!fin)
    {
        cout << "StudentData.txt Opening Failed !!\n";
        return;
    }
    fout.open("newfile.txt", ios::app);
    if (!fout)
    {
        cout << "StudentData.txt Opening Failed !!\n";
        return;
    }
    string id;
    bool check = false;
    cout << "Enter ID of Student You want to Delete  : ";
    cin >> id;
    while (fin >> firstName >> lastName >> department >> contactNo >> section[0] >> gender
        >> ad.city >> ad.town >> ad.streetNo >> bloodGroup >> feeStatus >> qualification
        >> registration_date >> s_id)
    {
        if (id == s_id) 
        {
            check = true;
            continue;
        }
        else 
        {
            fout << firstName << " " << lastName << " " << department << " " << contactNo << " " << section[0] << " " << gender
                << " " << ad.city << " " << ad.town << " " << ad.streetNo << " " << bloodGroup << " "
                << feeStatus << " " << qualification << " " << registration_date << " " << s_id << endl;
        }
    }

    SetConsoleTextAttribute(clr, 11);
    if (check == true)
        cout << "Record of Student Deleted Successfully ! ==> ID (" << id << ") \n ";
    else
    {
        cout << "Student Not Registered Yet (OR Record not found) OF ID " << id << " !\n";
    }

    SetConsoleTextAttribute(clr, 7);
    fin.close();
    fout.close();
    remove("StudentData.txt");
    rename("newfile.txt", "StudentData.txt");
    deleteStudentPriv(fout, fin, id);
}

void Administrator::deleteStudentPriv(ofstream& outFile, ifstream& inFile, string& id)
{
    inFile.open("StudentPriv.txt");
    outFile.open("Newfile.txt", ios::app);
    bool check = false;
    while (inFile >> firstName >> lastName >> s_id >> feeStatus >> contactNo >> registration_date)
    {
        if (id == s_id) 
        {
            check = true;
            continue;
        }
        else 
        {
            outFile << firstName << " " << lastName << " " << s_id << " " << feeStatus << " " <<
                contactNo << " " << registration_date << endl;
        }
    }
    system("cls");
    SetConsoleTextAttribute(clr, 11);
    if (check == true)
        cout << "\n==========================================\nRecord of Student Deleted Successfully from studentPriv.txt (also) ! ==> ID (" << id << ") \n==========================================\n ";
    else
    {
        cout << "\n==========================================\nStudent Not Registered Yet (OR Record not found) from studentPriv.txt OF ID " << id << " !\n==========================================\n";
    }

    SetConsoleTextAttribute(clr, 7);
    inFile.close();
    outFile.close();
    remove("StudentPriv.txt");
    rename("Newfile.txt", "StudentPriv.txt");
}

void Administrator::deleteTeacherData(ofstream& outFile, ifstream& inFile)
{
    Address ad;
    inFile.open("teacherData.txt");
    outFile.open("New.txt", ios::app);
    string id;
    bool check = false;
    cout << "enter the id : ";
    cin >> id;
    while (inFile >> firstName >> lastName >> department >> contactNo >> gender >> ad.city
        >> ad.town >> ad.streetNo >> qualification >> registration_date >> t_id >> course[0] >> course[1])
    {
        if (id != t_id) {
            outFile << firstName << " " << lastName << " " << department << " " << contactNo << " "
                << gender << " " << ad.city << " " << ad.town << " " << ad.streetNo << " " << qualification
                << " " << registration_date << " " << t_id << course[0] << course[1] << endl;
        }
        else 
        {
            check = true;
            continue;
        }
    }
    if (check == true)
        cout << "\n==========================================\nRecord of Teacher Deleted Successfully ! ==> ID (" << id << ") \n==========================================\n ";
    else
        cout << "\n==========================================\nTeacher Not Registered Yet (OR Record not found) OF ID " << id << " ! \n==========================================\n";
    inFile.close();
    outFile.close();
    remove("TeacherData.txt");
    rename("New.txt", "TeacherData.txt");
    deleteTeacherPriv(outFile, inFile, id);
}

void Administrator::deleteTeacherPriv(ofstream& outFile, ifstream& inFile, string& id)
{
    Address ad;
    inFile.open("teacherPriv.txt");
    outFile.open("Newfile.txt", ios::app);
    bool check = false;
    while (inFile >> firstName >> lastName >> t_id >> contactNo >> qualification >> registration_date)
    {
        if (id == t_id) 
        {
            check = true;
            continue;
        }
        else {
            outFile << firstName << " " << lastName << " " << t_id << " " <<
                contactNo << " " << qualification << " " << registration_date << endl;
        }
    }
    system("cls");
    if (check == true)
        cout << "\n==========================================\nRecord of Student Deleted Successfully from teacherPriv.txt (also) ! ==> ID (" << id << ") \n==========================================\n ";
    else
        cout << "\n==========================================\nStudent Not Registered Yet (OR Record not found) from teacherPriv.txt OF ID " << id << " ! \n==========================================\n";
    inFile.close();
    outFile.close();
    remove("teacherPriv.txt");
    rename("Newfile.txt", "teacherPriv.txt");
}

void Administrator::editStudentDetails(ofstream& outFile, ifstream& inFile)
{
    Address ad;
    inFile.open("StudentData.txt");
    outFile.open("newfile.txt", ios::app);
    string id;
    char choice;
    bool check = false;
    cout << "\nEnter the Student ID : ";
    cin >> id;
    while (inFile >> firstName >> lastName >> department >> contactNo >> section[0] >> gender
        >> ad.city >> ad.town >> ad.streetNo >> bloodGroup >> feeStatus >> qualification
        >> registration_date >> s_id)
    {
        if (id == s_id) 
        {
            while (1)
            {
                system("cls");
                int checkTemp = 0;
                SetConsoleTextAttribute(clr, 11);
                cout << "\n\t\tDATA OF STUDENT ID \n";
                cout << "\t|-----------------------------------|\n";
                cout << "\t| Name : \t" << firstName << " " << lastName << endl;
                cout << "\t| Student ID : \t" << s_id << endl;
                cout << "\t| Fee Status : \t" << feeStatus << endl;
                cout << "\t| Contact # : \t" << contactNo << endl;
                cout << "\t| Registration date : \t" << registration_date << endl;
                cout << "\t| Address : \t" << ad.town << " " << ad.streetNo << " , " << ad.city << endl;
                cout << "\t|-----------------------------------|\n\n";
                cout << "\n---------------------------------\nWhich attributes do you want to change ? \n"
                    << "1)- Department\n " << "2)- contact # \n" << "3)- Address \n-----------------------------\n";
                SetConsoleTextAttribute(clr, 7);
                do
                {
                    checkTemp += 1;
                    if (checkTemp != 1)
                    {
                        cout << "\tIncorrect Input !! \n\tYou can only Enter ( 1, 2, 3 ). \"So, Try Again \" \n";
                        system("pause");
                    }
                    cin >> choice;
                } while (choice > 3 && choice < 1);
                if (choice == '1') {
                    cout << "Enter new department : ";
                    cin >> department;
                }
                else if (choice == '2') {
                    cout << "Enter new contact number : ";
                    cin >> contactNo;
                }
                else if (choice == '3')
                {
                    cout << "Enter New Address : \n";
                    cout << "Enter city : ";
                    cin >> ad.city;
                    cout << "Enter town : ";
                    cin >> ad.town;
                    cout << "Enter street : ";
                    cin >> ad.streetNo;
                }
                check = true;
                char temp;
                cout << "\nDo you want to change any thing else ? ( Enter '1' for \"Yes\" otherwise any character) \n";
                cin >> temp;
                if (temp == '1')
                    continue;
                else
                    break;
            }
        }
        outFile << firstName << " " << lastName << " " << department << " " << contactNo << " " << section[0] << " " << gender
            << " " << ad.city << " " << ad.town << " " << ad.streetNo << " " << bloodGroup << " "
            << feeStatus << " " << qualification << " " << registration_date << " " << s_id << endl;
    }
    system("cls");
    SetConsoleTextAttribute(clr, 11);
    if (check == true)
        cout << "\n==========================================\nRecord of Student UPDATED Successfully  ==> ID (" << id << ") \n==========================================\n ";
    else
        cout << "\n==========================================\nStudent Not Registered Yet (OR Record not found) OF ID " << id << " ! \n==========================================\n";
    inFile.close();
    outFile.close();

    SetConsoleTextAttribute(clr, 7);
    remove("StudentData.txt");
    rename("newfile.txt", "StudentData.txt");
    editStudentPrivDetails(outFile, inFile, id, contactNo);
}

void Administrator::editStudentPrivDetails(ofstream& outFile, ifstream& inFile, string& id, string& c)
{
    Address ad;
    inFile.open("StudentPriv.txt");
    outFile.open("newfile.txt", ios::app);
    bool check = false;
    while (inFile >> firstName >> lastName >> s_id >> feeStatus >> contactNo >> registration_date)
    {
        if (id == s_id)
        {
            check = true;
            outFile << firstName << " " << lastName << " " << s_id << " " << feeStatus << " " <<
                c << " " << registration_date << endl;
        }
        else
        {
            outFile << firstName << " " << lastName << " " << s_id << " " << feeStatus << " " <<
                contactNo << " " << registration_date << endl;
        }
    }
    system("cls");
    SetConsoleTextAttribute(clr, 11);
    if (check == true)
        cout << "\n==========================================\nRecord of Student UPDATED Successfully from StudentPriv.txt (also) ! ==> ID (" << id << ") \n==========================================\n ";
    else
        cout << "\n==========================================\nStudent Not Registered Yet (OR Record not found) from StudentPriv.txt OF ID " << id << " ! \n==========================================\n";
    inFile.close();
    outFile.close();
    SetConsoleTextAttribute(clr, 7);
    remove("StudentPriv.txt");
    rename("newfile.txt", "StudentPriv.txt");

}

void Administrator::editTeacherDetails(ofstream& outFile, ifstream& inFile)
{
    Address ad;
    string id;
    char choice;
    bool check = false;

    inFile.open("teacherData.txt");
    outFile.open("newfile.txt", ios::app);

    cout << "Enter the Id of Student : ";
    cin >> id;

    while (inFile >> firstName >> lastName >> department >> contactNo >> gender >> ad.city
        >> ad.town >> ad.streetNo >> qualification >> registration_date >> t_id >> course[0] >> course[1])
    {
        if (id == t_id) 
        {
            while (1)
            {
                system("cls");
                SetConsoleTextAttribute(clr, 11);
                int checkTemp = 0;
                cout << "\n\t\tDATA OF TECAHER \n";
                cout << "\t|-----------------------------------|\n";
                cout << "\t| Name : \t" << firstName << " " << lastName << endl;
                cout << "\t| Student ID : \t" << s_id << endl;
                cout << "\t| Fee Status : \t" << feeStatus << endl;
                cout << "\t| Contact # : \t" << contactNo << endl;
                cout << "\t| Registration date : \t" << registration_date << endl;
                cout << "\t| Address : \t" << ad.town << " " << ad.streetNo << " , " << ad.city << endl;
                cout << "\t|-----------------------------------|\n\n";
                cout << "\n---------------------------------\nWhich attributes do you want to change ? \n"
                    << "1)- Department\n " << "2)- contact # \n" << "3)- Address \n-----------------------------\n";
                SetConsoleTextAttribute(clr, 7);
                do
                {
                    checkTemp += 1;
                    if (checkTemp != 1)
                    {
                        cout << "\tIncorrect Input !! \n\tYou can only Enter ( 1, 2, 3 ). \"So, Try Again \" \n";
                        system("pause");
                    }
                    cin >> choice;
                } while (choice > 3 && choice < 1);
                if (choice == '1') {
                    cout << "Enter new department : ";
                    cin >> department;
                }
                else if (choice == '2') {
                    cout << "Enter new contact number : ";
                    cin >> contactNo;
                }
                else if (choice == '3')
                {
                    cout << "Enter New Address : \n";
                    cout << "Enter city : ";
                    cin >> ad.city;
                    cout << "Enter town : ";
                    cin >> ad.town;
                    cout << "Enter street : ";
                    cin >> ad.streetNo;
                }
                check = true;
                char temp;

                SetConsoleTextAttribute(clr, 4);
                cout << "\nDo you want to change any thing else ? ( Enter '1' for \"Yes\" otherwise any character) \n";
                cin >> temp;

                SetConsoleTextAttribute(clr, 7);
                if (temp == '1')
                    continue;
                else
                    break;

            }
        }
        outFile << firstName << " " << lastName << " " << department << " " << contactNo << " "
            << gender << " " << ad.city << " " << ad.town << " " << ad.streetNo << " " << qualification
            << " " << registration_date << " " << t_id << course[0] << course[1] << endl;
    }
    system("cls");
    if (check == true)
        cout << "\n==========================================\nRecord of Teacher UPDATED Successfully  ==> ID (" << id << ") \n==========================================\n ";
    else
        cout << "\n==========================================\nTeacher Not Registered Yet (OR Record not found) OF ID " << id << " ! \n==========================================\n";
    inFile.close();
    outFile.close();
    remove("teacherData.txt");
    rename("newfile.txt", "teacherData.txt");

    editTeacherPrivDetails(outFile, inFile, id, contactNo);
}

void Administrator::editTeacherPrivDetails(ofstream& outFile, ifstream& inFile, string& id, string& c)
{
    Address ad;
    bool check = false;

    inFile.open("teacherPriv.txt");
    outFile.open("newfile.txt", ios::app);

    while (inFile >> firstName >> lastName >> t_id >> contactNo >> qualification >> registration_date)
    {
        if (id == t_id)
        {
            check = true;
            outFile << firstName << " " << lastName << " " << t_id << " " <<
                c << " " << qualification << " " << registration_date << endl;
        }
        else
        {
            outFile << firstName << " " << lastName << " " << t_id << " " <<
                contactNo << " " << qualification << " " << registration_date << endl;
        }
    }
    system("cls");
    if (check == true)
        cout << "\n\n==========================================\nRecord of Teacher UPDATED Successfully from teacherPriv.txt (also) ! ==> ID (" << id << ") \n==========================================\n ";
    else
        cout << "\n\n==========================================\nTeacher Not Registered Yet (OR Record not found) from teacherPriv.txt OF ID " << id << " ! \n==========================================\n";

    inFile.close();
    outFile.close();
    remove("teacherPriv.txt");
    rename("newfile.txt", "teacherPriv.txt");
}

void Administrator::AssignShcedule()
{
    string day, time;
    ofstream fout;
    fout.open("shcedule.txt", ios::app);
    if (!fout)
    {
        cout << "shcedule.txt Opening Failed !!\n";
        return;
    }
    cout << "\n\t---------------------------------------";
    cout << "\n\t\tAssign Shcedule";
    cout << "\n\tTeacher can teach 2 classes a week per subject ";
    cout << "\n\tTeacher has Following courses : \n";
    fout << t_id;
    for (int i = 0; i < 2; ++i)
    {
        cout << "\n------------------------------\nAssign Shecdule of Course -> " << this->course[i] << "  ==> Section : " << this->section[i] << "\n";
        for (int j = 0; j < 2; ++j)
        {
            cout << "\nEnter Day \t=> ( Monday, Tuesday, Wednesday, Thursday, Friday ) \n";
            cin >> day;
            cout << "Enter Time : ";
            cin >> time;
            fout << " " << day << " " << time;
        }
    }
    fout << endl;
    fout.close();
}
Administrator::~Administrator() {};


//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------



//Defintion of Teacher Class's Member functions

Teacher::Teacher() : User() {}
Teacher::~Teacher() {};

Teacher::Teacher(string username, string password) : User(username, password) {}

//  Other Functions

void Teacher::showTeacherChoice()
{
    system("cls"); 
    int z = 2;
    system("Color 0F");
    while (z > 0)
    {
        system("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tLoading ";
        for (int k = 0; k < 4; ++k)
        {
            cout << "-";
            Sleep(300);
        }
        z--;
    }
    system("cls");
    char choice;
    int checkForInvalid1 = 0;
    cout << "\n\t -------------------------\n\t|\t\t\t  |\n\t| Login successful !      |\n\t| Welcome to TEACHER-FLEX |\n\t|\t\t\t  |\n\t|-------------------------|\n";

    cout << "\n\t----------------------------\n\t|\t\t\t   |\n\t| Now, What you want\t   |\n\t| Enter your choice !\t   |\n\t|\t\t\t   |\n";
    cout << "\t| 1): Profile \t\t   |\n\t| 2): Upload Attendence    |\n\t| 3): Update Evaluation    |\n\t| 4): Schedule of Lectures |\n"
        << "\t| 0): EXIT\t\t   |\n\t| \t\t\t    |\n\t----------------------------\n";
    do
    {
        checkForInvalid1 += 1;
        if (checkForInvalid1 != 1)
        {
            cout << "\n\tInvalid input !! Enter Again <-\n\n";
            system("pause");
        }
        cin >> choice;
    } while (choice > 6 && choice < 0);

    if (choice == '1')
    {
        viewTProfile();
    }
    else if (choice == '2')
    {
        attendence();
        system("pause");
    }
    else if (choice == '3')
    {
        uploadEvaluations();

    }
    else if (choice == '4')
    {
        Shcedule();
    }
    else if (choice == '0')
    {
        system("cls");
        MAIN();
    }
    system("cls");
    showTeacherChoice();
}

void Teacher::Shcedule()
{
    system("cls");
    string idt, ST[8];
    string corse[7];
    ifstream st, st2;
    st.open("shcedule.txt");
    if (!st)
    {
        cout << "shcedule.txt Opening Failed !\n";
        exit(0);
    }
    while (st >> idt >> ST[0] >> ST[1] >> ST[2] >> ST[3] >> ST[4] >> ST[5] >> ST[6] >> ST[7])
    {
        if (idt == t_id)
        {
            st2.open("TeacherClassData.txt");
            if (!st2)
            {
                cout << "TeacherClassData.txt Opening Failed !\n";
                exit(0);
            }
            while (st2 >> corse[0] >> corse[1] >> corse[2] >> corse[3] >> corse[4] >> corse[5] >> corse[6])
            {
                if (corse[0] == t_id)
                {
                    system("cls");
                    system("Color F1");
                    SetConsoleTextAttribute(clr, 7);
                    cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t Loading ";
                    for (int g = 0; g < 5; ++g)
                    {
                        cout << "-";
                        Sleep(500);
                    }
                    system("cls");
                    SetConsoleTextAttribute(clr, 12);
                    cout << "\n\t\t\t------------------------------------------\n"
                        << "\t\t\t\t Shcedule Teacher Classes !!";
                    cout << "\n\t\t\t------------------------------------------\n\n";
                    cout << setw(30) << "Courses" << setw(40) << "Day" << setw(20) << "Time" << endl;
                    cout << setw(50) << corse[3] << setw(20) << ST[0] << setw(20) << ST[1] << endl;
                    cout << setw(50) << corse[3] << setw(20) << ST[2] << setw(20) << ST[3] << endl;
                    cout << setw(50) << corse[5] << setw(20) << ST[4] << setw(20) << ST[5] << endl;
                    cout << setw(50) << corse[5] << setw(20) << ST[6] << setw(20) << ST[7] << endl;
                    cout << "\n\t\t<------------------------------------------>\n";
                    system("pause");
                    break;
                }
            }
            st2.close();
            break;
        }
    }
    st.close();

}

void Teacher::uploadEvaluations()
{
    char subjChoice, sectionChoice;
    string t_id, s_id, sec;
    string attStor[50];
    string teacherClassDataRead[4];
    ifstream fin, fin2, fin1;
    ofstream fout, fout1;


    fin.open("TeacherClassData.txt");
    if (!fin) 
    {
        cout << "file opening failed !!! \n";
        exit(0);
    }
    while (!fin.eof())
    {
        //teacher data reading
        fin >> t_id >> firstName >> lastName >> teacherClassDataRead[0] >> teacherClassDataRead[1]
            >> teacherClassDataRead[2] >> teacherClassDataRead[3];
        if (this->t_id == t_id)
        {
            //subject choice

            system("cls");
            int checkTemp = 0;
            SetConsoleTextAttribute(clr, 11);
            cout << "\n\t------------------------------------------------\n";
            cout << "\n\tUpload Attendence \n";
            cout << "\nYou Teach the following 2 courses \n";
            cout << "1): Corse No. 1 " << teacherClassDataRead[0] << "  ===> Section : " << teacherClassDataRead[1];
            cout << "\n2): Corse No. 2 " << teacherClassDataRead[2] << "  ===> Section : " << teacherClassDataRead[3] << endl;
            cout << "Which class OR course you want to UPLOAD Attendence : ";
            do
            {
                checkTemp += 1;
                if (checkTemp != 1)
                {
                    cout << "\tIncorrect Input !! \n\tYou can only Enter ( 1, 2 ). \"So, Try Again \" \n";
                    system("pause");
                }
                cin >> subjChoice;
            } while (subjChoice != '1' && subjChoice != '2');

            SetConsoleTextAttribute(clr, 7);


            if (subjChoice == '1')
            {
                //attendance file
                string str[20];
                string::size_type pos = teacherClassDataRead[0].find(')');
                string temp1 = teacherClassDataRead[0].substr(teacherClassDataRead[0].find('('), pos);
                string a = t_id + temp1 + teacherClassDataRead[1];

               

                //grade file ---------------------------------------------
                
                fin2.open(a + ".txt");
                if (!fin2)
                {
                    cout << a + ".txt Opening Failed OR You have no student Registered Yet ---!\n";
                    return;
                }
                int i = 0;
                while (getline(fin2, str[i]))
                {
                    i++;
                }
                fin2.close();

                string st;
                fout.open(a + "Eval.txt");

                SetConsoleTextAttribute(clr, 7);

                int quiz, mid, assignment, final;
                char grade;
                int sum = 0;
                fout << "User ID" << "        Total Abs." << "        Quizes" << "        Assignments" << "        Mid" << "        Final" << "        Obtained Abs." << "        Grade" << endl;
                for (int k = 1; k < i; ++k)
                {
                    string::size_type posTemp = str[k].find(' ');

                    SetConsoleTextAttribute(clr, 11);
                    cout << "\n--------------------------\n";
                    cout << "Enter Evaluations of " << str[k].substr(0, posTemp) << " \n";
                    cout << "Total Absolutes Marks : 100\n";
                    cout << "Enter quiz marks out of 10 : ";
                    cin >> quiz;
                    cout << "Enter assignment marks out of 10 : ";
                    cin >> assignment;
                    cout << "Enter mid-term marks out of 30 : ";
                    cin >> mid;
                    cout << "Enter Obtained Final marks out of 50: ";
                    cin >> final;
                    cout << "Enter Grade : ";
                    cin >> grade;
                    cout << "\n-----------------------------\n";
                    SetConsoleTextAttribute(clr, 7);

                    sum = quiz + assignment + mid + final;

                    fout << str[k].substr(0, posTemp) << "        100                " << quiz << "                " << assignment << "             "
                        << mid << "           " << final << "          " << sum << "                " << grade
                        << endl;
                }
                fout.close();
//                system(a + "Eval.txt");
            }
            else if (subjChoice == '2')
            {
                string str[20];
                string::size_type pos = teacherClassDataRead[2].find(')');
                string temp1 = teacherClassDataRead[2].substr(teacherClassDataRead[2].find('('), pos);
                string b = t_id + temp1 + teacherClassDataRead[3];

                //grade file ---------------------------------------------
                
                fin2.open(b + ".txt");
                if (!fin2)
                {
                    cout << b + ".txt Opening Failed OR You have no student Registered Yet ---!\n";
                    return;
                }
                int i = 0;
                while (getline(fin2, str[i]))
                {
                    i++;
                }
                fin2.close();

                string st;
                fout.open(b + "Eval.txt");

                int quiz, mid, assignment, final;
                int sum = 0;
                fout << "User ID" << "        Total Abs." << "        Quizes" << "        Assignments" << "        Mid" << "        Obtained Abs." << "        Grade" << endl;
                for (int k = 1; k < i; ++k)
                {
                    string::size_type posTemp = str[k].find(' ');
                    SetConsoleTextAttribute(clr, 11);
                    cout << "\n--------------------------\n";
                    cout << "Enter Evaluations of " << str[k].substr(0, posTemp) << " \n";
                    cout << "Total Absolutes Marks : 100";
                    cout << "Enter quiz marks : ";
                    cin >> quiz;
                    cout << "Enter assignment marks : ";
                    cin >> assignment;
                    cout << "Enter mid-term marks : ";
                    cin >> mid;
                    cout << "Enter Obtained Final marks : ";
                    cin >> final;
                    cout << "\n--------------------------\n";
                    SetConsoleTextAttribute(clr, 7);
                    sum = quiz + assignment + mid + final;

                    fout << str[k].substr(0, posTemp) << "        100        " << quiz << "        " << assignment << "        " << mid << "        " << final
                        << endl;
                }
                fout.close();
            }
            break;
        }
    }
    fin.close();

}
void Teacher::viewTProfile()
{
    system("cls");
    string idt, a, b, c;
    ifstream st;
    Teacher stu;
    st.open("teacherData.txt");
    if (!st)
    {
        cout << "teacherData.txt Opening Failed !\n";
        exit(0);
    }
    while (st >> stu.firstName >> stu.lastName >> stu.department >> stu.contactNo >> stu.gender >> a
        >> b >> c >> stu.qualification >> stu.registration_date >> idt >> stu.course[0] >> stu.course[1])
    {
        if (idt == t_id)
        {
            system("cls");
            system("Color F1");
            SetConsoleTextAttribute(clr, 7);
            cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t Loading ";
            for (int g = 0; g < 5; ++g)
            {
                cout << "-";
                Sleep(500);
            }
            system("cls");
            SetConsoleTextAttribute(clr, 11);
            cout << "\n\t------------------------------------------\n"
                 << "\t\t Teacher Profile!!";
            cout << "\n\t------------------------------------------\n\n";
            cout << "\t| Name  =  " << stu.firstName << " " << stu.lastName << endl;
            cout << "\t| Student ID  =  " << t_id << endl;
            cout << "\t| Department  =  " << stu.department << endl;
            cout << "\t| Contact No.  =  " << stu.contactNo << endl;
            cout << "\t| Gender  =  " << stu.gender << endl;
            cout << "\t| Courses Teacher  =  " << stu.course[0] << "  <-AND->  " << stu.course[1] << endl;
            cout << "\t| Address  =  " << a << " " << b << " " << c; cout << endl;
            cout << "\t| Qualification   =  " << stu.qualification << endl;
            cout << "\t| Reisteration Date   =  " << stu.registration_date << endl;
            cout << "\n\t------------------------------------------\n";
            system("pause");
            break;
        }
    }
    st.close();
}

bool Teacher::TeacherAssignCredentials()
{
    ifstream Tfile;
    bool checkUser = false;
    Tfile.open("teacherUsername.txt", ios::app);
    if (!Tfile.is_open())
    {
        cout << "File opening failed ! \n";
        exit(0);
    }
    string userName, passWord;
    cout << "Enter your UserName : ";
    cin >> userName;
    cout << "Enter passsword : ";
    cin >> passWord;
    string a, b;
    while (Tfile >> a >> b)
    {
        if (a == userName && b == passWord)
        {
            Tfile.close();
            this->t_id = userName;
            return true;
        }
        else
            checkUser = false;
    }
    if (checkUser == false)
    {
        Tfile.close();
        return false;
    }
}

void Teacher::attendence()
{
    ifstream fin;
    ifstream finSt, finC;
    ofstream fout;
    string temp[2];
    string str[4];
    string idF, date;
    fin.open("TeacherClassData.txt");
    if (!fin) 
    {
        cout << "TeacherClassData.txt Opening Failed !\n";
        exit(0);
    }
    while (fin >> idF >> firstName >> lastName >> course[0] >> section[0] >> course[1] >> section[1])
    {
        if (t_id == idF)
        {
            system("cls");
            int checkTemp = 0;
            SetConsoleTextAttribute(clr, 11);
            cout << "\n\t------------------------------------------------\n";
            cout << "\n\tUpload Attendence \n";
            cout << "\nYou Teach the following 2 courses \n";
            cout << "1): Corse No. 1 " << course[0] << "  ===> Section : " << section[0];
            cout << "\n2): Corse No. 2 " << course[1] << "  ===> Section : " << section[1] << endl; 
            cout << "Which class OR course you want to UPLOAD Attendence : ";
            char bg;
            do
            {
                checkTemp += 1;
                if (checkTemp != 1)
                {
                    cout << "\tIncorrect Input !! \n\tYou can only Enter ( 1, 2 ). \"So, Try Again \" \n";
                    system("pause");
                }
                cin >> bg;
            } while (bg != '1' && bg != '2');

            SetConsoleTextAttribute(clr, 7);

            
            if (bg == '1')
            {
                string::size_type pos = course[0].find(')');
                string temp1 = course[0].substr(course[0].find('('), pos);
                string a = t_id + temp1 + section[0];
                string TempAtt[30];
                ofstream open;
               
                ifstream attRead;
                string ReadAttendence;
                attRead.open(a + ".txt");
                SetConsoleTextAttribute(clr, 4);
                if (!attRead)
                {
                    open.open(a + ".txt");

                    if (!open)
                    {
                        cout << a + ".txt Opening Failed OR You have no student Registered Yet ---!\n";
                        return;
                    }
                    open.close();
                    cout << a + ".txt Opening Failed OR You have no student Registered Yet ---!\n";
                    return;

                }
                SetConsoleTextAttribute(clr, 7);
                int z = 0;
                while (getline(attRead, ReadAttendence))
                {
                    TempAtt[z] = ReadAttendence.substr(ReadAttendence.find(' '));
                    z++;
                }
                attRead.close();

                fout.open(a + ".txt");
                fout << "UserID " << TempAtt[0] << endl;
                if (!fout)
                {
                    cout << a + ".txt Opening Failed ---!\n";
                    exit(0);
                }

                finSt.open("StudentIdSection.txt");
                if (!finSt)
                {
                    cout << "StudentIdSection.txt Opening Failed !\n";
                    exit(0);
                }

                int in = 1;
                while (finSt >> temp[0] >> temp[1])
                {
                    if (temp[1] == section[0])
                    {
                        finC.open("StudentCourses.txt");

                        while (finC >> str[0] >> str[1] >> str[2] >> str[3])
                        {
                            if ((str[1] == course[0] || str[2] == course[0] || str[2] == course[0]) && (temp[0] == str[0]))
                            {
                                fout << str[0] << TempAtt[in] << endl;
                                in++;
                                break;
                            }
                        }
                        finC.close();
                    }
                }
                fout.close();
                finSt.close();
                checkTemp = 0;
    //=====================================================================================================
                string ForLoad[20];
                int i = 0;
                int r = 0;
                char Att;
                ifstream ifT, tempRead;
                string IDShow;
                ofstream tempOf;

                tempRead.open(a + ".txt");
                if (!tempRead)
                {
                    cout << a + ".txt Opening Failed ---!\n";
                    exit(0);
                }
                while (getline(tempRead, ForLoad[r]))
                {
                    r++;
                }
                if (r == 1)
                {
                    cout << "You have no students of this Course !\n";
                    return;
                }
                tempRead.close();

                int COUNT = 1;

                SetConsoleTextAttribute(clr, 11);
                cout << "\n------------------------------------------\nEnter date of Attendence : ";  cin.ignore();
                getline(cin, date);
                cout << "\n\t---------------------------------------\n";
                cout << "Enter \"P\" -> (Present), \t __ \"A\" -> (Absent), \t __ \"L\" -> (Late) :  \n";

                tempOf.open(a + ".txt");
                if (!tempOf)
                {
                    cout << a + ".txt Opening Failed  !\n";
                    exit(0);
                }
                tempOf << ForLoad[0] << setw(10) << date << endl;
                while (COUNT < r)
                {
                   /* if (i == 0)
                        ForLoad[0] = ForLoad[0] + "\t\t" + date;*/
                    string::size_type posTemp = ForLoad[COUNT].find(' ');
                    cout << "Enter Attendence of Roll No. " << ForLoad[COUNT].substr(0, posTemp) << " : ";
                    checkTemp = 0;
                    do
                    {
                        checkTemp += 1;
                        if (checkTemp != 1)
                        {
                            cout << "\tIncorrect Input !! \n\tYou can only Enter ( A, P, L ). \"So, Try Again \" \n";
                            system("pause");
                        }
                        cin >> Att;

                    } while ((Att != 'A' && Att != 'a') && (Att != 'L' && Att != 'l') && (Att != 'P' && Att != 'p'));
                    SetConsoleTextAttribute(clr, 15);

                    tempOf << ForLoad[COUNT] << setw(10) <<  Att << endl;
                    COUNT++;

                    /*if (i != 0)
                        ForLoad[i] = ForLoad[i] + "\t" + Att;*/
                }

                tempOf.close();
                int c = 0;
                ifT.close();
            }
    //------------------------------------------------------------------------------------
            else if (bg == '2')
            {
                string::size_type pos = course[1].find(')');
                string temp1 = course[1].substr(course[1].find('('), pos);
                string b = t_id + temp1 + section[1];
                string TempAtt[30];
                ifstream attRead;
                ofstream open;
                string ReadAttendence;

                attRead.open(b + ".txt");
                if (!attRead)
                {
                    cout << b + ".txt Opening Failed OR You have no student Registered Yet ---!\n";
                    open.open(b + ".txt");
                    if (!open)
                    {
                        cout << b + ".txt Opening Failed ---!\n"; \
                            return;
                    }
                    open.close();
                    exit(0);
                }
                int z = 0;

                while (getline(attRead, ReadAttendence))
                {
                    TempAtt[z] = ReadAttendence.substr(ReadAttendence.find(' '));
                    z++;
                }
                attRead.close();

                fout.open(b + ".txt");
                fout << "UserID " << TempAtt[0] << endl;
                if (!fout)
                {
                    cout << b + ".txt Opening Failed ---!\n";
                    exit(0);
                }

                finSt.open("StudentIdSection.txt");
                if (!finSt)
                {
                    cout << "StudentIdSection.txt Opening Failed !\n";
                    exit(0);
                }
                int in = 1;
                while (finSt >> temp[0] >> temp[1])
                {
                    if (temp[1] == section[1])
                    {
                        finC.open("StudentCourses.txt");

                        while (finC >> str[0] >> str[1] >> str[2] >> str[3])
                        {
                            if ((str[1] == course[1] || str[2] == course[1] || str[2] == course[1]) && (temp[0] == str[0]))
                            {
                                fout << str[0] << TempAtt[in] << endl;
                                in++;
                                break;
                            }
                        }
                        finC.close();
                    }
                }
                fout.close();
                finSt.close();
                checkTemp = 0;
        //=====================================================================================================
                string ForLoad[20];
                int i = 0;
                int r = 0;
                char Att;
                ifstream ifT, tempRead;
                string IDShow;
                ofstream tempOf;

                tempRead.open(b + ".txt");
                if (!tempRead)
                {
                    cout << b + ".txt Opening Failed ---!\n";
                    exit(0);
                }
                while (getline(tempRead, ForLoad[r]))
                {
                    r++;
                }

                if (r == 1)
                {
                    cout << "You have no students of this Course !\n";
                    return;
                }
                tempRead.close();

                int COUNT = 1;
                cout << "\n------------------------------------------\nEnter date of Attendence : ";  cin.ignore();
                getline(cin, date);
                cout << "\n\t---------------------------------------\n";
                cout << "Enter \"P\" -> (Present), \t __ \"A\" -> (Absent), \t __ \"L\" -> (Late) :  \n";

                tempOf.open(b + ".txt");
                if (!tempOf)
                {
                    cout << b + ".txt Opening Failed  !\n";
                    exit(0);
                }
                tempOf << ForLoad[0] << setw(10) << date << endl;
                while (COUNT < r)
                {
                    /* if (i == 0)
                         ForLoad[0] = ForLoad[0] + "\t\t" + date;*/
                    string::size_type posTemp = ForLoad[COUNT].find(' ');
                    cout << "Enter Attendence of Roll No. " << ForLoad[COUNT].substr(0, posTemp) << " : ";
                    checkTemp = 0;
                    do
                    {
                        checkTemp += 1;
                        if (checkTemp != 1)
                        {
                            cout << "\tIncorrect Input !! \n\tYou can only Enter ( A, P, L ). \"So, Try Again \" \n";
                            system("pause");
                        }
                        cin >> Att;

                    } while ((Att != 'A' && Att != 'a') && (Att != 'L' && Att != 'l') && (Att != 'P' && Att != 'p'));

                    tempOf << ForLoad[COUNT] << setw(10) << Att << endl;
                    COUNT++;

                    /*if (i != 0)
                        ForLoad[i] = ForLoad[i] + "\t" + Att;*/
                }

                tempOf.close();
                int c = 0;
                ifT.close();
            }

            break;
        }

    }

    fin.close();
}

//===================================================================================================================


Student::Student() : User() {}
Student::~Student() {};

Student::Student(string username, string password) : User(username, password) {}

bool Student::StudentAssignCredentials()
{
    ifstream Sfile;
    bool checkUser = false;
    Sfile.open("studentUsername.txt", ios::app);
    if (!Sfile.is_open())
    {
        cout << "file opening failed ! \n";
        exit(0);
    }
    string userName, passWord;
    cout << "Enter your UserName : ";
    cin >> userName;
    cout << "Enter passsword : ";
    cin >> passWord;
    string a, b;
    while (Sfile >> a >> b)
    {
        if (a == userName && b == passWord)
        {
            Sfile.close();
            this->s_id = userName;
            return true;
        }
        else
            checkUser = false;
    }
    if (checkUser == false)
    {
        Sfile.close();
        return false;
    }
}

void Student::studentShowChoice()
{
    char choice;
    int checkForInvalid1 = 0;
    system("cls");
    int z = 2;
    system("Color 0F");
    while (z > 0)
    {
        system("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tLoading ";
        for (int k = 0; k < 4; ++k)
        {
            cout << "-";
            Sleep(300);
        }
        z--;
    }
    system("cls");

    SetConsoleTextAttribute(clr, 3);
    cout << "\n\t -------------------------\n\t|\t\t\t  |\n\t| Login successful !      |\n\t| Welcome to STUDENT-FLEX   |\n\t|\t\t\t  |\n\t|-------------------------|\n";

    cout << "\n\t----------------------------\n\t|\t\t\t   |\n\t| Now, What you want\t   |\n\t| Enter your choice !\t   |\n\t|\t\t\t   |\n";
    cout << "\t| 1): Profile \t\t   |\n\t| 2): Attendence \t   |\n\t| 3): Evaluation \t    |\n\t| 4): See Courses Registered  |\n\t| 5): Register courses     |\n"
         << "\t| 0): EXIT\t\t   | \n\t| \t\t\t   | \n\t----------------------------\n";
    do
    {
        checkForInvalid1 += 1;
        if (checkForInvalid1 != 1)
        {
            cout << "\n\tInvalid input !! Enter Again <-\n\n";
            system("pause");
        }
        cin >> choice;
    } while (choice > 7 && choice < 0);

    SetConsoleTextAttribute(clr, 15);
    SelectStChoice(choice);
}

void Student::SelectStChoice(char& ch)
{
    if (ch == '1')
    {
        viewStProfile();
    }
    else if (ch == '2')
    {
        seeAttendence();
    }
    else if (ch == '3')
    {
        showEvaluations();
    }
    else if (ch == '4')
    {
        SeeCourses();
    }
    else if (ch == '5')
    {
        setCourses();
    }
    else
    {
        MAIN();
    }
    system("pause");
    studentShowChoice();
}

void Student::showEvaluations()
{
    ifstream attendee;
    string a, b;
    string temp;
    string course[4];
    attendee.open("StudentIdSection.txt");
    if (!attendee)
    {
        cout << "StudentIdSection.txt Opening Failed !\n";
        exit(0);
    }
    while (attendee >> a >> b)
    {
        if (s_id == a)
        {
            break;
        }
    }
    attendee.close();

    attendee.open("StudentCourses.txt");
    if (!attendee)
    {
        cout << "StudentCourses.txt Opening Failed !\n";
        exit(0);
    }
    while (attendee >> course[0] >> course[1] >> course[2] >> course[3])
    {
        if (s_id == course[0])
        {
            break;
        }
    }
    attendee.close();
    ifstream open;
    string x, y;
    string read1, read2;

    while (1)
    {
        system("cls");
        cout << "\n\t-------------> Courses <------------\n";
        cout << "\t1): Course No. 1 = " << course[1] << endl;
        cout << "\t2): Course No. 2 = " << course[2] << endl;
        cout << "\t3): Course No. 3 = " << course[3] << endl;
        cout << "\t0): EXIT = " << endl;
        cout << "\n\t------------------------------------\n";
        cout << "\nEnter Course you Want to see your Attendence : ";
        char t;
        int checkForInvalid1 = 0;
        do
        {
            checkForInvalid1 += 1;
            if (checkForInvalid1 != 1)
            {
                cout << "\n\tInvalid input !! Enter Again <-\n\n";
                system("pause");
            }
            cin >> t;
        } while (t > 3 && t < 0);

        if (t == '1')
        {
            ifstream teach;
            string data[6];
            teach.open("TeacherClassData.txt");
            if (!teach)
            {
                cout << y + "You have not Attended any Lecture ! \n" << endl;
                system("pause");
                continue;
            }
            while (teach >> data[0] >> data[1] >> temp >> data[2] >> data[3] >> data[4] >> data[5])
            {
                if (data[2] == course[1] || data[4] == course[1])
                {
                    break;
                }
            }
            teach.close();
            string::size_type pos = course[1].find(')');
            x = course[1].substr(course[1].find('('), pos);
            y = data[0] + x + b;
            open.open(y + "Eval.txt");
            if (!open)
            {
                cout << y + "You have not Attended any Lecture ! \n" << endl;
                system("pause");
                continue;
            }
            int cn = 0;
            while (getline(open, read1))
            {
                if (cn == 0)
                {
                    cout << read1 << endl;
                    cn = 10;
                }
                string::size_type p = read1.find(' ');

                if (read1.substr(0, p) == course[0])
                {
                    cout << read1 << endl;
                }

            }

            open.close();
        }
        else if (t == '2')
        {
            ifstream teach;
            string data[6];
            teach.open("TeacherClassData.txt");
            if (!teach)
            {
                cout << y + " You have not Attended any Lecture ! \n" << endl;
                system("pause");
                continue;
            }
            while (teach >> data[0] >> data[1] >> temp >> data[2] >> data[3] >> data[4] >> data[5])
            {
                if (data[2] == course[2] || data[4] == course[2])
                {
                    break;
                }
            }
            teach.close();
            string::size_type pos = course[2].find(')');
            x = course[2].substr(course[2].find('('), pos);
            y = data[0] + x + b;
            open.open(y + "Eval.txt");
            if (!open)
            {
                cout << y + " You have not Attended any Lecture ! \n" << endl;
                system("pause");
                continue;
            }

            int cn = 0;
            while (getline(open, read1))
            {
                if (cn == 0)
                {
                    cout << read1 << endl;
                    cn = 10;
                }
                string::size_type p = read1.find(' ');

                if (read1.substr(0, p) == course[0])
                {
                    cout << read1 << endl;
                }

            }
            open.close();
        }
        else if (t == '3')
        {
            ifstream teach;
            string data[6];
            teach.open("TeacherClassData.txt");
            if (!teach)
            {
                cout << y + " You have not Attended any Lecture ! \n" << endl;
                system("pause");
                continue;
            }
            while (teach >> data[0] >> data[1] >> data[2] >> data[3] >> data[4] >> data[5])
            {
                if (data[2] == course[3] || data[4] == course[3])
                {
                    break;
                }
            }
            teach.close();
            string::size_type pos = course[3].find(')');
            x = course[3].substr(course[3].find('('), pos);
            y = data[0] + x + b;
            open.open(y + "Eval.txt");
            if (!open)
            {
                cout << y + "You have not Attended any Lecture ! \n" << endl;
                system("pause");
                continue;
            }
            int cn = 0;
            while (getline(open, read1))
            {
                if (cn == 0)
                {
                    cout << read1 << endl;
                    cn = 10;
                }
                string::size_type p = read1.find(' ');

                if (read1.substr(0, p) == course[0])
                {
                    cout << read1 << endl;
                }

            }

            open.close();
        }
        else
        {
            studentShowChoice();
        }
        system("pause");
    }

}

void Student::seeAttendence()
{
    ifstream attendee;
    string a, b;
    string temp;
    string course[4];
    attendee.open("StudentIdSection.txt");
    if (!attendee)
    {
        cout << "StudentIdSection.txt Opening Failed !\n";
        exit(0);
    }
    while (attendee >> a >> b)
    {
        if (s_id == a)
        {
            break;
        }
    }
    attendee.close();

    attendee.open("StudentCourses.txt");
    if (!attendee)
    {
        cout << "StudentCourses.txt Opening Failed !\n";
        exit(0);
    }
    while (attendee >> course[0] >> course[1] >> course[2] >> course[3])
    {
        if (s_id == course[0])
        {
            break;
        }
    }
    attendee.close();
    ifstream open;
    string x, y;
    string read1, read2;
   
    while (1)
    {
        system("cls");
        SetConsoleTextAttribute(clr, 3);
        cout << "\n\t-------------> Courses <------------\n";
        cout << "\t1): Course No. 1 = " << course[1] << endl;
        cout << "\t2): Course No. 2 = " << course[2] << endl;
        cout << "\t3): Course No. 3 = " << course[3] << endl;
        cout << "\t0): EXIT = "  << endl;
        cout << "\n\t------------------------------------\n";
        cout << "\nEnter Course you Want to see your Attendence : ";
        char t;
        int checkForInvalid1 = 0;
        do
        {
            checkForInvalid1 += 1;
            if (checkForInvalid1 != 1)
            {
                cout << "\n\tInvalid input !! Enter Again <-\n\n";
                system("pause");
            }
            cin >> t;
        } while (t > 3 && t < 0);
        SetConsoleTextAttribute(clr, 15);

        if (t == '1')
        {
            ifstream teach;
            string data[6];
            teach.open("TeacherClassData.txt");
            if (!teach)
            {
                cout << y + "You have not Attended any Lecture ! \n" << endl;
                system("pause");
                continue;
            }
            while (teach >> data[0] >> data[1] >> temp >> data[2] >> data[3] >> data[4] >> data[5])
            {
                if (data[2] == course[1] || data[4] == course[1])
                {
                    break;
                }
            }
            teach.close();
            string::size_type pos = course[1].find(')');
            x = course[1].substr(course[1].find('('), pos);
            y = data[0] + x + b;
            open.open(y + ".txt");
            if (!open)
            {
                cout << y + "You have not Attended any Lecture ! \n" << endl;
                system("pause");
                continue;
            }
            int cn = 0;
            while (getline(open, read1))
            {
                if (cn == 0)
                {
                    cout << read1 << endl;
                    cn = 10;
                }
                string::size_type p = read1.find(' ');

                if (read1.substr(0, p) == course[0])
                {
                    cout << read1 << endl;
                }

            }

            open.close();
        }
        else if (t == '2')
        {
            ifstream teach;
            string data[6];
            teach.open("TeacherClassData.txt");
            if (!teach)
            {
                cout << y + " You have not Attended any Lecture ! \n" << endl;
                system("pause");
                continue;
            }
            while (teach >> data[0] >> data[1] >> temp >> data[2] >> data[3] >> data[4] >> data[5])
            {
                if (data[2] == course[2] || data[4] == course[2])
                {
                    break;
                }
            }
            teach.close();
            string::size_type pos = course[2].find(')');
            x = course[2].substr(course[2].find('('), pos);
            y = data[0] + x + b;
            open.open(y + ".txt");
            if (!open)
            {
                cout << y + " You have not Attended any Lecture ! \n" << endl;
                system("pause");
                continue;
            }

            int cn = 0;
            while (getline(open, read1))
            {
                if (cn == 0)
                {
                    cout << read1 << endl;
                    cn = 10;
                }
                string::size_type p = read1.find(' ');

                if (read1.substr(0, p) == course[0])
                {
                    cout << read1 << endl;
                }

            }
            open.close();
        }
        else if (t == '3')
        {
            ifstream teach;
            string data[6];
            teach.open("TeacherClassData.txt");
            if (!teach)
            {
                cout << y + " You have not Attended any Lecture ! \n" << endl;
                system("pause");
                continue;
            }
            while (teach >> data[0] >> data[1] >> data[2] >> data[3] >> data[4] >> data[5])
            {
                if (data[2] == course[3] || data[4] == course[3])
                {
                    break;
                }
            }
            teach.close();
            string::size_type pos = course[3].find(')');
            x = course[3].substr(course[3].find('('), pos);
            y = data[0] + x + b;
            open.open(y + ".txt");
            if (!open)
            {
                cout << y + "You have not Attended any Lecture ! \n" << endl;
                system("pause");
                continue;
            }
            int cn = 0;
            while (getline(open, read1))
            {
                if (cn == 0)
                {
                    cout << read1 << endl;
                    cn = 10;
                }
                string::size_type p = read1.find(' ');

                if (read1.substr(0, p) == course[0])
                {
                    cout << read1 << endl;
                }

            }

            open.close();
        }
        else
        {
            studentShowChoice();
        }
        system("pause");
    }
}
void Student::SeeCourses()
{
    ifstream course;
    string dta[4];
    course.open("StudentCourses.txt");
    if (!course)
    {
        cout << "StudentCourses.txt Opening Failed !\n";
        exit(0);
    }
    while (course >> dta[0] >> dta[1] >> dta[2] >> dta[3])
    {
        if (dta[0] == s_id)
        {
            system("cls");
            SetConsoleTextAttribute(clr, 11);
            cout << "\n\t------------------------------------------\n\t\tRegistered Courses !!\n";
            cout << "\n\t------------------------------------------\n";
            cout << "\t| Course No. 1  =  " << dta[1] << endl;
            cout << "\t| Course No. 2  =  " << dta[2] << endl;
            cout << "\t| Course No. 3  =  " << dta[3] << endl;
            cout << "\n\t------------------------------------------\n";

            SetConsoleTextAttribute(clr, 7);
            break;

        }
    }
}

void Student::setCourses()
{
    ofstream in;
    in.open("StudentCourses.txt", ios::app);
    if (!in)
    {
        cout << "StudentCourses.txt Opening Failed !\n";
        exit(0);
    }
    in << s_id << " ";
    string choice;
    SetConsoleTextAttribute(clr, 11);
    cout << "\n______________________________________________\nSelect Courses for Teacher (Must Select 2) : \n";
    cout << "\t\n---------------------------------------------\n";
    cout << "\t1): Programming Fundamnetals (PF) \n\t2): Object Oriented Programming (OOP) \n\t3): Data Structure And Algorithm (DSA) \n" <<
        "\t4): Data Bases (DB) \n\t5): Business Analytics (DA) \n\t6): Digital Logic Design (DLD) \n\t7): Linear Circuit Analysis (LCA) \n" <<
        "\t8): Communication and Presentation Skills (CPS) \n\t9): Technical Business Writing \n";
    cout << "\t\n---------------------------------------------\n";

    SetConsoleTextAttribute(clr, 15);
    for (int i = 0; i < 3; ++i)
    {
        int checkForInvalid1 = 0;
        cout << "Select course No. " << i + 1 << " : ";
        do
        {
            checkForInvalid1 += 1;
            if (checkForInvalid1 != 1)
            {
                cout << "\n\tInvalid input !! Enter Again <-\n\n";
                system("pause");
            }
            cin >> choice;

        } while (choice < "1" && choice > "9");

        if (choice == "1")
        {
            this->coursesSt[i] = "Programming_Fundamnetals->(PF)";
            in << " Programming_Fundamnetals->(PF)";
        }
        else if (choice == "2")
        {
            this->coursesSt[i] = "Object_Oriented_Programming->(OOP)";
            in << " Object_Oriented_Programming->(OOP)";
        }
        else if (choice == "3")
        {
            this->coursesSt[i] = "Data_Structure_And_Algorithm->(DSA)";
            in << " Data_Structure_And_Algorithm->(DSA)";
        }
        else if (choice == "4")
        {
            this->coursesSt[i] = "Data_Bases->(DB)";
            in << " Data_Bases->(DB)";
        }
        else if (choice == "5")
        {
            this->coursesSt[i] = "Business_Analytics->(DA)";
            in << " Business_Analytics->(DA)";
        }
        else if (choice == "6")
        {
            this->coursesSt[i] = "Digital_Logic_Design->(DLD) ";
            in << " Digital_Logic_Design->(DLD)";
        }
        else if (choice == "7")
        {
            this->coursesSt[i] = "Linear_Circuit_Analysis->(LCA)";
            in << " Linear_Circuit_Analysis->(LCA)";
        }
        else if (choice == "8")
        {
            this->coursesSt[i] = "Communication_and_Presentation_Skills->(CPS)";
            in << " Communication_and_Presentation_Skills->(CPS)";
        }
        else if (choice == "9")
        {
            this->coursesSt[i] = "Technical_Business_Writing->(TBW)";
            in << " Technical_Business_Writing->(TBW)";
        }

    }
    in << endl;
    in.close();
}

void Student::viewStProfile() const
{
    system("cls");
    string idt, a, b, c;
    ifstream st;
    Student stu;
    st.open("StudentData.txt");
    if (!st)
    {
        cout << "StudentData.txt Opening Failed !\n";
        exit(0);
    }
    while (st >> stu.firstName >> stu.lastName >> stu.department >> stu.contactNo >> stu.section[0] >> stu.gender >> a
        >> b >> c >> stu.bloodGroup >> stu.feeStatus >> stu.qualification >> stu.registration_date >> idt)
    {
        if (idt == s_id)
        {

            SetConsoleTextAttribute(clr, 3);
            cout << "\n\t------------------------------------------\n\t\t Student Profile!!\n";
            cout << "\n\t------------------------------------------\n";
            cout << "\t| Name  =  " << stu.firstName << " " << stu.lastName << endl;
            cout << "\t| Student ID  =  " << s_id << endl;
            cout << "\t| Department  =  " << stu.department << endl;
            cout << "\t| Blood Group  =  " << stu.bloodGroup << endl;
            cout << "\t| Contact No.  =  " << stu.contactNo << endl;
            cout << "\t| Gender  =  " << stu.gender << endl;
            cout << "\t| Fee Status  =  " << stu.feeStatus << endl;
            cout << "\t| Address  =  " << a << " " << b << " " << c; cout << endl;
            cout << "\t| Qualification   =  " << stu.qualification << endl;
            cout << "\t| Reisteration Date   =  " << stu.registration_date << endl;
            cout << "\t| Section   =  " << stu.section[0] << endl;
            cout << "\n\t------------------------------------------\n";

            SetConsoleTextAttribute(clr, 7);
            break;
        }
    }
    st.close();
}


//============================================================================================



char Login::Choice()
{
    system("cls");
    cout << setw(50);

    SetConsoleTextAttribute(clr, 10);
    cout << "\n\t)-->> WELCOME TO FLEX-MANAGEMENT SYSTEM <<--(\n\t __________________________________\n";
    cout << "\t|\t\t\t\t   |\n\t| Enter your choice for LogIn\t   |\n\t|\t\t\t\t   |\n";
    cout << "\t| -> \"A\" OR \"a\" for Administration |\n\t| -> \"S\" OR \"s\" for Student \t   |\n\t| -> \"T\" OR \"t\" for Teacher \t   |\n\t| -> \"0\" For EXIT \t\t   |";
    cout << "\n\t------------------------------------\n";

    SetConsoleTextAttribute(clr, 15);
    cin >> choice;
    return choice;
}
void Login::login(char& ch)
{
    if ((ch == 'a') || (ch == 'A'))
    {
        assignCredentials();
        ADMINchoice();
    }
    else if ((ch == 't') || (ch == 'T'))
    {
        if (TeacherAssignCredentials())
        {
            showTeacherChoice();
        }
        else
        {
            cout << "\n\tInvalid input !! Enter Again <-\n\n";
            system("pause");
            MAIN();
        }
    }
    else if ((ch == 's') || (ch == 'S'))
    {
        if (StudentAssignCredentials())
        {
            studentShowChoice();
        }
        else
        {
            cout << "\n\tInvalid input !! Enter Again <-\n\n";
            system("pause");
            MAIN();
        }
    }
    else
    {
        start();
    }

}



//===========================================================================================================
// EXTRA FUNCTION


char logo()
{
    system("cls");	
    char temp = '2';
    SetConsoleTextAttribute(clr, 4);
    cout << "\n\t\t\t--------------------------------------------------------------\n";
    cout << "\t\t\t\t\t   ******   WELCOME  ******\n";
    cout << "\n\t\t\t\t\t     ";
    for (int i = 0; i < 20; ++i)
    {
        cout << "-";
        Sleep(50);
    }
    cout << endl;
//    system("Color F0");
    SetConsoleTextAttribute(clr, 11);
    cout << "\n\t ____________________________________________________________";
    cout << "\n\t|  \t\t\t\t\t\t\t     |\n\t|    _________    _ \t       __________    __       __     |";
    cout << "\n\t|   |  _______|  | |\t      |  ________|   \\ \\     / /     |";
    cout << "\n\t|   | |          | |\t      | |\t      \\ \\\   / /      |";
    cout << "\n\t|   | |_______   | |\t      | |________      \\ \\ / /       |";
    cout << "\n\t|   |  _______|  | |\t      |  ________|     / / \\ \\       |";
    cout << "\n\t|   | |\t         | |   \t      | |\t      / /   \\ \\      |";
    cout << "\n\t|   | |\t         | |_______   | |________    / /     \\ \\     |";
    cout << "\n\t|   |_|\t         |_________|  |__________|  /_/       \\_\\    |";
    cout << "\n\t|____________________________________________________________|\n";
    SetConsoleTextAttribute(clr, 7);
    cout << "\n\n\t-> Enter Choice \n\n";
    cout << "\t1): Start \n";
    cout << "\t0): EXIT\n\t";
    cin >> temp;
    return temp;
}
void start()
{
    char i = ' ';
    if (logo() == '1')
    {
        int z = 2;
        system("Color 0F");
        SetConsoleTextAttribute(clr, 11);
        while (z > 0)
        {
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tLoading ";
            for (int k = 0; k < 4; ++k)
            {
                cout << "-";
                Sleep(300);
            }
            z--;
        }
        SetConsoleTextAttribute(clr, 15);
        MAIN();
    }
    else
    {
        cout << "\n\t____________________ EXIT __________________\n\n\n";
        exit(0);
    }
}

void MAIN()
{
    int checkForInvalid = 0;
    system("cls");
    Login log;
    char temp;
    do
    {
        checkForInvalid += 1;
        if (checkForInvalid != 1)
        {
            cout << "\n\tInvalid input !! Enter Again <-\n\n";
            system("pause");
        }
        temp = log.Choice();

    } while ((temp != 'a' && temp != 'A') && (temp != 's' && temp != 'S') && (temp != 't' && temp != 'T') && temp != '0');

    log.login(temp);
}

bool isLeapYear(int year) 
{
    // Check if a year is a leap year
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(int day, int month, int year) 
{
    // Check if a date is valid
    if (month < 1 || month > 12 || year < 0) 
    {
        return false;
    }

    int maxDays = 31;

    if (month == 4 || month == 6 || month == 9 || month == 11) 
    {
        maxDays = 30;
    }
    else if (month == 2) 
    {
        if (isLeapYear(year)) 
        {
            maxDays = 29;
        }
        else {
            maxDays = 28;
        }
    }

    return (day >= 1 && day <= maxDays);
}