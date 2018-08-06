/******************************************************************
 * Class Name:  Benefit
 * Class Description:
 * The Benefit class implements the following UML class diagram:
  ---------------------------------------
        Benefit
        ---------------------------------------
        -healthInsurance: string
        -lifeInsurance: double
        -vacation: int
        ---------------------------------------
        +Benefit()
        +Benefit(in healthInsurance: String, in lifeInsurance: double, in vacation: int
        +displayBenefits(): string
        +getHealthInsurance(): String
        +setHealthInsurance(in insurance: string): void
        +getLifeInsurance(): double
        +setLifeInsurance(in insurance: double) void
        +getVacation(): int
        +setVacation(in vacation: int) void
        ---------------------------------------
***********************************************************************/

#include <iostream>
#include <string>
#include <stdlib.h> 
#include <iomanip>

using namespace std;

const double MIN_SALARY = 50000;
const double MAX_SALARY = 250000;
const int MAX_DEPENDENTS = 10;
const int MIN_DEPENDENTS = 0;
const char DEFAULT_GENDER = 'N'; //N stands for not identified
const int NUMBER_WEEKS = 52;

class Benefit 
{
    private:
string healthInsurance;
double lifeInsurance;
int vacation;

    public:
Benefit()
{
this->healthInsurance = "not provided";
this->lifeInsurance = 0;
this->vacation = 14;
}
Benefit(string healthInsurance, double lifeInsurance, int vacation)
{
this->healthInsurance = healthInsurance;
this->lifeInsurance = lifeInsurance;
this->vacation = vacation;
}
Benefit(Benefit &mybenefit)
{   
this->healthInsurance = mybenefit.healthInsurance;
this->lifeInsurance = mybenefit.lifeInsurance;
this->vacation = mybenefit.vacation;
}
string getHealthInsurance()
{
return healthInsurance;
}
void setHealthInsurance(string healthInsurance)
{
this->healthInsurance = healthInsurance;
}
double getLifeInsurance()
{
return lifeInsurance;
}
void setLifeInsurance(double lifeInsurance)
{
this->lifeInsurance = lifeInsurance;
}
int getVacation()
{
return vacation;
}
void setVacation(int vacation)
{
this->vacation = vacation;
}
void displayBenefits()
{
cout<<"\nBenefit Information\n";
cout<<"____________________________________________________________\n";
cout<<"Health Insurance:\t" << healthInsurance << "\n";
cout<<"Life Insurance:\t\t" << lifeInsurance << "\n";
cout<<"Vacation:\t\t" << vacation << " days\n";

}

};

/******************************************************************
 * 
 * Class Name:  Employee
 * Class Description:
 * The employee class implements the following UML class diagram:
  ---------------------------------------
        Employee 
        ---------------------------------------
        -firstName: string
        -lastName: string
        -gender: char
        -dependents int
        -annualSalary double
        -static numEmployees int
        -benefits Benefits
        ---------------------------------------
        +Employee()
        +getBenefits Benefits
        +setBenefits(in benefits: Benefits) void
        +calculatePay() double
        +static getNumberEmployees int
        +displayEmployee() void
        +getFirstName() string
        +setFirstName(in name: string) void
        +getLastName() string
        +setLastName(in name: string) void
        +getGender(): char
        +setGender(in gen: char) void
        +getDependents() int
        +setDependents(in dep: int) void
        +setDependents(in dep: string) void
        getAnnualSalary() double
        setAnnualSalary(in sal: double) void
        setAnnualSalary(in sal: string) void
        ---------------------------------------
***********************************************************************/

class iEmployee 
{   
    public:
virtual double calculatePay()=0;

};

class Employee : public iEmployee
{ //declare static variable accessible, which is accessible by all objects of the class
    static int numEmployees;

    protected:
string firstName;
string lastName;
char gender;
int dependents;
double annualSalary; 

//declare a benefits object
Benefit benefits;

    public:

Employee():benefits()//default constructor
{
firstName = "";
lastName = "";
gender = 'N';
dependents = 0;
annualSalary = 50000;
//each time a constructor is called, increment the the class level numEmployees variable
this->numEmployees += 1;
//Instantiate the Benefits object
//benefits();
}
//create a parameterized construct, not required and shown only for demonstration
Employee(string firstName, string lastName, char gender, int dependents, double salary, Benefit mybenefits):benefits(mybenefits)
{
//use the THIS keyword to distinguish between the class attributes and the parameters
this->firstName = firstName;
this->lastName = lastName;
this->gender = gender;
this->dependents = dependents;
this->annualSalary = salary;
//each time a constructor is called, increment the the class level numEmployees variable
this->numEmployees += 1;

}

Employee(string firstName, string lastName, char gender, int dependents, Benefit mybenefits):benefits(mybenefits)
{
//use the THIS keyword to distinguish between the class attributes and the parameters
this->firstName = firstName;
this->lastName = lastName;
this->gender = gender;
this->dependents = dependents;
//each time a constructor is called, increment the the class level numEmployees variable
this->numEmployees += 1;

}

//create the accessors and mutators for the benefit object
Benefit getBenefits()
{
return benefits;
}
void setBenefits(Benefit benefits)
{
this->benefits = benefits;
}

//a static method that returns the number of employee object that are created
static int getNumberEmployees()
{
return numEmployees;
}

//Accessors and mutators, one for each class attribute
string getFirstName()
{
return firstName;
}
void setFirstName(string name)
{
firstName = name;
}
string getLastName()
{
return lastName;
}
void setLastName(string name)
{
lastName = name;
}
char getGender()
{
return gender;
}
void setGender(char gen)
{
switch (gen)
{
case 'f':case 'F': case 'M':case 'm':
gender = gen;
break;
default:
gender = DEFAULT_GENDER;
}
}
int getDependents()
{
return dependents;
}
void setDependents(int dep)
{
if (dep >= MIN_DEPENDENTS && dep <= MAX_DEPENDENTS)
{
dependents = dep;
}
else if (dep < MIN_DEPENDENTS)
{
dep = MIN_DEPENDENTS;
}
else
{
dependents = MAX_DEPENDENTS;
}
}
double getAnnualSalary()
{
return annualSalary;
}
void setAnnualSalary(double salary)
{
if (salary >= MIN_SALARY && salary <= MAX_SALARY)
{
annualSalary = salary;
}
else if (salary < MIN_SALARY)
{
annualSalary = MIN_SALARY;
}
else
{
annualSalary = MAX_SALARY;
}
}
double calculatePay()
{
return annualSalary/NUMBER_WEEKS;
}
void displayEmployee()
{
cout<<"Employee Information\n";
cout<<"____________________________________________________________\n";
cout<<"Name: \t\t" <<firstName << " " << lastName << "\n";
cout<<"Gender:\t\t" << gender << "\n";
cout<<"Dependents: \t" << dependents << "\n";
cout<<"Annual Salary:\t" << setprecision(2)<<showpoint<<fixed<<annualSalary << "\n";
cout<<"Weekly Salary:\t" << setprecision(2)<<showpoint<<fixed<<calculatePay()<<"\n";

//show the benefits
this->benefits.displayBenefits();

}
};

int Employee::numEmployees=0;//supply initial value to static data members


/******************************************************************
 * 
 * Class Name:  Hourly
 * Class Description:
 * The Salaried class implements the following UML class diagram:
  ---------------------------------------
        Hourly extends Employee
        ---------------------------------------
        #wage double
        #hours double
        #category string
        ---------------------------------------
        +Hourly()
        +Hourly(in fname: string, in lname: string, in gen: char, in dep: int, in wage: double, in hours, in ben: Benefits)
        +Hourly(in wage: double, in hours: double, in category: string
        +calculatePay() double
        +setAnnualSalary void
        +displayEmployee void 
        ---------------------------------------
        It is assumed that each class attribute has appropriate
        getter and setter methods created
***********************************************************************/

    const double MIN_HOURS = 0;
const double MAX_HOURS = 50;
const double MIN_WAGE = 10;
const double MAX_WAGE = 50;
const int WORK_WEEKS = 50;

class Hourly :public Employee
{
protected:
    double wage;
double hours;
string category;

public:
    Hourly():Employee()
{

}
Hourly(string firstName, string lastName, char gender, int dependents, double wage, double hours, Benefit benefits, string category)
                     : Employee(firstName, lastName, gender, dependents, benefits)
{
//no employee constructor with correct arguments, either create a new constructor or set the attributes individually
//use the properties instead of the attributes to ensure all data is valid
setWage(wage);
setHours(hours);
setCategory(category);
setAnnualSalary(wage, hours);
}
Hourly(double wage, double hours, string category):Employee()//ensure the inherited fields are initialized
{
setWage(wage);
setHours(hours);
setCategory(category);
}
double getWage()
{
return wage;
}
void setWage(double wage)
{
if (wage >= MIN_WAGE && wage <= MAX_WAGE)
{
this->wage = wage;
}
else if (wage < MIN_WAGE)
{
this->wage = MIN_WAGE;
}
else
{
this->wage = MAX_WAGE;
}
}
double getHours()
{
return hours;
}
void setHours(double hours)
{
if (hours > MIN_HOURS && hours < MAX_HOURS)
{
this->hours = hours;
}
else if (hours <= MIN_HOURS)
{
this->hours = MIN_HOURS;
}
else
{
this->hours = MAX_HOURS;
}
}
string getCategory()
{
return category;
}
void setCategory(string category)
{
if (category.compare("temporary")==0)
{
this->category = category;
}
else if (category.compare("part time")==0)
{
this->category = category;
}
else if (category.compare("full time")==0)
{
this->category = category;
}
else
{
this->category = "Unknown";
}
}
double calculatePay()
{
return wage * hours;
}
void setAnnualSalary(double wage, double hours)
{
Employee::setAnnualSalary(calculatePay() * WORK_WEEKS);
}

void displayEmployee()
{
setAnnualSalary(wage, hours);
Employee::displayEmployee();
cout<<"Hourly Employee\n";
cout<<"Category:\t\t" << category << "\n";
cout<<"Wage:\t\t\t" << wage << "\n";
cout<<"Hours:\t\t\t" << hours << "\n";

}
};


/******************************************************************
 * 
 * Class Name:  Salaried
 * Class Description:
 * The Salaried class implements the following UML class diagram:
  ---------------------------------------
        Salaried extends Employee
        ---------------------------------------
        #managementLevel int
        ---------------------------------------
        +Salaried()
        +Salaried(in fname: string, in lname: string, in gen: char, in dep: int, in sal: double, in ben: Benefits)
        +Salaried(in sal: double)
        +calculatePay() double
        +displayEmployee() void 
        ---------------------------------------
        It is assumed that each class attribute has appropriate
        getter and setter methods created
***********************************************************************/
    const int MIN_MANAGEMENT_LEVEL = 0;
const int MAX_MANAGEMENT_LEVEL = 3;
const double BONUS_PERCENT = .10; 
class Salaried :public Employee
{
protected:
        int managementLevel; 
public:
    Salaried():Employee()//initial the common employee attributes
{
managementLevel = MIN_MANAGEMENT_LEVEL;
}
Salaried(string firstName, string lastName, char gender, int dependents, double salary, 
Benefit benefits, int manLevel)
               :Employee(firstName, lastName, gender, dependents, salary, benefits)
{
setManagementLevel(manLevel);  //use the property to ensure valid data in the managementLevel attribute
}
Salaried(double salary, int manLevel):Employee()
{
Employee::setAnnualSalary(salary);  //use the super class property to ensure valid data in the annual salary
setManagementLevel(manLevel);
}
void setManagementLevel(int manLevel)
{
if (manLevel >= MIN_MANAGEMENT_LEVEL && manLevel <= MAX_MANAGEMENT_LEVEL)
{
managementLevel = manLevel;
}
else
{
managementLevel = MIN_MANAGEMENT_LEVEL;
}
}
int getManagementLevel()
{ 
return managementLevel;
}
double calculatePay()
{
return Employee::calculatePay() * (1 + (managementLevel*BONUS_PERCENT));
}
void displayEmployee()
{
Employee::displayEmployee();
cout<<"Salaried Employee\n";
cout<<"Management level:\t" << managementLevel;

} 
};


void DisplayApplicationInformation()
{  cout<<"Welcome to your inheritance lab\n";      
}

void DisplayDivider(string message)
{cout<<"\n*************** " + message + " *********************\n";}

string GetInput( string message)
{ string mystring;
  cout<<"Please enter your "<<message;
  getline(cin, mystring);
  return mystring;
}

void TerminateApplication()
{ cout<<"\nThe end of lab.\n";}