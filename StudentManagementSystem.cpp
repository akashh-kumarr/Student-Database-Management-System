#include<iostream>
#include<fstream>
#include<iomanip>
#include <unistd.h>
#include <thread>
#include <chrono>
#include <cmath>

using namespace std;


class Student
{
   int RollNumber;
   char Name[100];
   int P_MARKS , C_MARKS , M_MARKS , L1_MARKS, L2_MARKS, CS_MARKS;
   double Percentage;
   char grade;
   void Calculate();
   public :
      void getData();
      void DisplayData();
      int NextRollNumber() const;
};

void Student::getData()
{
   std::cout << "\nRoll Number              : "; 
   std::cin  >> RollNumber;
   std::cout << "Student Name               : ";
   std::cin  >> Name ;
   std::cout << "Marks in Physics           : ";
   std::cin  >> P_MARKS;
   std::cout << "Marks in Chemistry         : ";
   std::cin  >> C_MARKS;
   std::cout << "Marks in Mathematics       : "; 
   std::cin  >> M_MARKS;
   std::cout << "Marks in Language 'A'      : ";
   std::cin  >> L1_MARKS;
   std::cout << "Marks in Language 'B'      : ";
   std::cin  >> L2_MARKS;
   std::cout << "Marks in Computer Science  : ";
   std::cin  >> CS_MARKS;
}

void Student::DisplayData()
{
   std::cout << "\nRoll Number                : " << RollNumber; 
   std::cout << "\nStudent Name               : " << Name;
   std::cout << "\nMarks in Physics           : " << P_MARKS;
   std::cout << "\nMarks in Chemistry         : " << C_MARKS;
   std::cout << "\nMarks in Mathematics       : " << M_MARKS; 
   std::cout << "\nMarks in Language 'A'      : " << L1_MARKS;
   std::cout << "\nMarks in Language 'B'      : " << L2_MARKS;
   std::cout << "\nMarks in Computer Science  : " << CS_MARKS;
}

int Student::NextRollNumber() const
{
   return RollNumber;
}

void _0_();
void _1_();
void _10_();
void _11_();
void _100_();
void _111_();
void _1000_();
int _0101_();

void _0_()
{
   Student student;
   std::ofstream DataFile;
   DataFile.open("StudentData.dat", std::ios::binary|std::ios::app);
   student.getData();
   DataFile.write(reinterpret_cast<char *>(&student), sizeof(Student));
   DataFile.close();
   std::cout << "Record Added Successfully";
   std::cin.ignore();
   std::cin.get();
}

void _1_()
{
   system("clear");
   Student student;
   std::ifstream DataFile;
   DataFile.open("StudentData.dat", std::ios::binary);
   if(!DataFile)
   {
      std::cout << "File_Error [1011]    : Data File is missing from your System !" << std::endl ;
      std::cin.ignore();
      std::cin.get();
      return;
   }
   while(DataFile.read(reinterpret_cast<char *>(&student), sizeof(Student)))
   {
      student.DisplayData();
      std::cout << std::endl << "------------------------------------------------------------------" << std::endl;
   }
   DataFile.close();
   std::cout << "\nPress 'Enter' to continue ...\n" << std::endl;
   std::cin.ignore();
   std::cin.get();
}

void _10_(int INPUT_ROLLNUMBER)
{
   Student student;
   system("clear");
   std::ifstream DataFile;
   DataFile.open("StudentData.dat");
   bool Needle = false;
   if(!DataFile)
   {
      std::cout << "\nFile_Error [1011]    : Data File is missing from your System !" << std::endl;
      std::cout << "Hit 'Enter' to continue ..." << std::endl;
      std::cin.ignore();
      std::cin.get();
      _0101_();
   }
   while(DataFile.read(reinterpret_cast<char*>(&student), sizeof(Student)))
   {
      if(student.NextRollNumber() == INPUT_ROLLNUMBER)
      {
         student.DisplayData();
         Needle = true;
      }
   }
   DataFile.close();
   if(Needle == false)
   {
      std::cout << "Error : Roll Number " << INPUT_ROLLNUMBER << " does not exists in your School DataBase";
      std::cout << "\n\nEnter New  Roll Number to find  (also use['00'] to get back to Home Menu) : ";
      std::cin >> INPUT_ROLLNUMBER;
      if(INPUT_ROLLNUMBER == 00)
      {
         _0101_();
      }
      else
      {
         _10_(INPUT_ROLLNUMBER);
      }
      
   }
   std::cout << "\nHit 'Enter' to continue\n";
   std::cin.ignore();
   std::cin.get();
}

void _100_(int INPUT_ROLLNUMBER)
{
   Student st;
	std::ifstream inFile;
	inFile.open("StudentData.dat",std::ios::binary);
	if(!inFile)
	{
		std::cout<<"File_Error [1011]    : Data File is missing from your System !";
		std::cin.ignore();
	   std::cin.get();
		return;
	}
	std::ofstream outFile;
	outFile.open("Temp.dat",std::ios::out);
	inFile.seekg(0,std::ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(Student)))
	{
		if(st.NextRollNumber()!=INPUT_ROLLNUMBER)
		{
			outFile.write(reinterpret_cast<char *> (&st), sizeof(Student));
		}
	}
   std::cout << "Data of Roll Number " << INPUT_ROLLNUMBER << " is deleted succesfully from your DataBase .";
   std::cout << "\nHit 'Enter' to contiue ...";
	std::cin.ignore();
	std::cin.get();
	outFile.close();
	inFile.close();
	remove("StudentData.dat");
	rename("Temp.dat","StudentData.dat");
}

void _11_(int INPUT_ROLLNUMBER)
{
   _10_(INPUT_ROLLNUMBER);
   _100_(INPUT_ROLLNUMBER);
   _0_();
}

void PROGRESS_BAR(int time, const std::string &message, char symbol)
{
    std::string progress_bar;
    const double progress_level = 1.42;

    std::cout << message << "\n";

    for (double percentage = 0; percentage <= 100; percentage += progress_level)
    {
        progress_bar.insert(0, 1, symbol);
        std::cout << "\r [" << std::ceil(percentage) << '%' << "] " << progress_bar;
        std::this_thread::sleep_for(std::chrono::milliseconds(time));       
    }
    std::cout << "\n\n";
}
int _0101_()
{
   int CodeEntry_0101;
   int RollNumberToFind;
   int RollNumberToDelete;
   int RollNumberToModify;
   std::string Exit_Confirmation;
   system("clear");
   std::cout << std::endl << std::endl;
   std::cout << "\t+--------------------- HOME  MENU ---------------------+" << std::endl;
   std::cout << "\t|                                                      |" << std::endl;
   std::cout << "\t|    0.   Add New Record                               |" << std::endl;//done
   std::cout << "\t|    1.   Display All Record                           |" << std::endl;//done
   std::cout << "\t|   10.   Search for a Student                         |" << std::endl;//done
   std::cout << "\t|   11.   Modify Student Record                        |" << std::endl;//done
   std::cout << "\t|  100.   Delete a Student Record                      |" << std::endl;//done
   std::cout << "\t|  111.   Restart Application                          |" << std::endl;
   std::cout << "\t| 1000.   Exit                                         |" << std::endl;
   std::cout << "\t|                                                      |" << std::endl;
   std::cout << "\t+------------------------------------------------------|" << std::endl << std::endl;
   
   std::cout << "Code@Entry ~$  ";
   std::cin  >> CodeEntry_0101;
   switch(CodeEntry_0101)
   {
      case 0:
         system("clear");
         _0_();
         _0101_();
         break;
      case 1:
         system("clear");
         _1_();
         _0101_();
         break;
      case 10:
         system("clear");
         std::cout << "\nEnter Roll Number : ";
         std::cin  >> RollNumberToFind;
         _10_(RollNumberToFind);
         _0101_();
         break;
      case 11:
         system("clear");
         std::cout << "\nEnter Roll Number to Modify : ";
         std::cin >> RollNumberToModify;
         _11_(RollNumberToModify);
         _0101_();
         break;
      case 100:
         system("clear");
         std::cout << "\nEnter Roll Number : ";
         std::cin >> RollNumberToDelete;
         _100_(RollNumberToDelete);
         _0101_();
         break;
      case 111:
         _111_();
         break;
      case 1000:
         std::cout << "\nDo you want to exit [yes/no] :  ";
         std::cin >> Exit_Confirmation;
         if(Exit_Confirmation == "yes" || Exit_Confirmation == "YES" || Exit_Confirmation == "Yes")
         {
            PROGRESS_BAR(20, "Exiting ... ", '#');
            sleep(4);
            std::cout << "\nExit with code [0] ... \n\n";
            return 0;
         }
         if(Exit_Confirmation == "No" || Exit_Confirmation == "no" || Exit_Confirmation == "NO")
         {
            _0101_();
         }
         else
         {
            std::cout << "Entry_Error [10001]     :  '" << Exit_Confirmation << " is not a option !";
            std::cout << "\nTry Again ...";
            _0101_();
         }
         break;
      default :
         std::cout << "\nCode_Error [00110] :      " <<  CodeEntry_0101 << " is not a code !" ;
   }
}

void _111_()
{
   system("clear");
   PROGRESS_BAR(30, "Message [10011]  : Initialization ", '#');
   PROGRESS_BAR(20, "Message [01101]  : Compiling Codes", '#');
   PROGRESS_BAR(30, "Message [10100]  : Running Codes  ", '#');
   sleep(3);
   _0101_();
}

int main()
{
   _111_();
}


/*

0101 - Home
1100 - Special Codes 

*/
