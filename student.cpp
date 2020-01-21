//test

/*
 * this is an example of a class definition, some testing
 * and what it does.
 * Author : Khalid.
 * Course : CSCI161.
 * Date : 19/01/2020.
*/

#include <iostream>
using namespace std;
/* 
 * A Student is a simple object that got rollno, mathmarks and engmarks.
*/
  class Student{
    private:
// The private attributes
      int mathmarks;
      int engmarks;
      int rollno;
    public:
// The constructor
      Student(int roll = 0, int math = 0, int eng = 0 ){
        rollno = math;
        mathmarks = eng;
        engmarks = roll;
      }
// The destructor
      ~Student(){}
// The copy constructor
      Student(const Student & stu){};
// Updating the Math.
      void setMathmarks(int math){
        if(math > 0)
          mathmarks = math;
      }
// Updating the Eng
      void setEngmarks(int eng){
        if(eng > 0)
          engmarks = eng;
      }
// Updating the Roll no.
      void setRollno(int roll){
        if(roll > 0)
          rollno = roll;
      }
// Return the math marks of the student.
      int getMathmarks(){return mathmarks;}
// Return the eng marks of the student.
      int getEngmarks(){return engmarks;}
// Return the roll number of the student.
      int getRollno(){return rollno;}
/*
 * Return the member function
*/
// Return the total marks of the student. 
      int Totalmarks(){return mathmarks + engmarks;}
// Return the grade of the student.
      char Grade(){
        int Average;
          Average = (Totalmarks()/2);
          if(Average <= 100)
            return 'A';
          else if(Average < 80)
            return 'B';
          else if(Average < 60)
            return 'C';
          else
            return 'D';

      }
/*
 * non-member friend operator overload functions
*/
// Overloads the cout operator so that a single student can be printed.
// This is not a member funtion, but is implemented within the class
// to demonstrate that it can be done.
      friend ostream & operator << (ostream &out, Student &stu){
          out << "Student roll no:" <<stu.rollno <<" math marks: " <<stu.mathmarks << " eng marks " 
          << stu.engmarks << endl;
          return out;
      }
// Overloads the equivalence operator, so that a rectangle can be compared
// to another to check for equivalence.
      friend bool operator ==(const Student &s1, const Student &s2){
          return s1.rollno == s2.rollno;
      }
  };       
/*
 * A main function that is used to test the funtionality of the class.
 * return 0 if the funtion completes.
*/
int main() {
//testing the constructor
    Student sd1(77, 69, 1002);

// testing the member funtions and cout operator.
    cout <<"sd1 is "<< sd1 <<endl;
    int totalmarks = sd1.Totalmarks();
    cout << "totalmarks is " << totalmarks << endl;
    char grade = sd1.Grade();
    cout << "Grade is "<< grade<<endl;
// testing the default constructor
    Student sd2;
    cout <<"The default one is "<< sd2 <<endl;
// testing the equivalence operator.
    if(sd1 == sd2)
      cout <<"The students are the same"<<endl;
    else
      cout <<"The students are not the same"<<endl;
// test the setters and getters
    cout <<"Changing the attributes of "<<sd2<<endl;
    sd2.setMathmarks(sd1.getMathmarks());
    sd2.setEngmarks(sd1.getEngmarks());
    sd2.setRollno(sd1.getRollno());
    cout<<"New version is "<<sd2<<endl;
// testing what happens when we only provide one value for the Student.
    Student sd3(5);
    cout << "sd3 is "<<sd3<<endl;
    Student sd4;
    sd4 = sd1;
    cout <<"sd4 is "<<sd4<<endl;
//change sd1.
    sd1.setRollno(1999);
    sd1.setMathmarks(78);
    sd1.setEngmarks(81);
    cout<<"sd1 is "<<sd1<<endl;
    cout<<"while sd4 is still "<<sd4<<endl;

   return 0;
}

