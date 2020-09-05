#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Person
    {
    public:
	Person(){};	
    Person(string name, int age):m_name(name), m_age(age)
    {        
    }
	virtual void getdata() = 0;
	virtual void putdata() = 0;
    protected:
    string m_name;
    int m_age;    
};

class Professor : public Person
    {
    public:
	Professor(){m_currID = ++m_SequenceID;}	
    Professor(string name, int age, int publications):Person(name, age), m_publications(publications)
    {     
    }
	void getdata();
	void putdata();
    private:
    int m_publications;
	 int m_currID;
	static int m_SequenceID;
};

int Professor::m_SequenceID = 0;

void Professor::getdata()
{
	cin >> m_name >> m_age >> m_publications; 
}

void Professor::putdata()
{
	cout << m_name << " " << m_age << " " << m_publications << " " << m_currID << endl;
}

class Student : public Person
    {
    public:
	Student(){m_currID = ++m_SequenceID;}	
    Student(string name, int age, int *marks): Person(name, age), m_marks(marks)
    {        
    }
	void getdata();
	void putdata();
    private:
    int *m_marks;
	int m_currID;
	static int m_SequenceID;
};

int Student::m_SequenceID = 0;

void Student::getdata()
{
	cin >> m_name >> m_age;
	m_marks = new int[6];
	for(int i = 0; i < 6; i++)
		cin >> m_marks[i];
}

void Student::putdata()
{
	int sum = 0;
	for(int i = 0; i < 6; i++)
		sum = sum + m_marks[i];
	cout << m_name << " " << m_age << " " << sum << " " << m_currID << endl; 	
}

int main()
{
	int numInputs;
	int personType;
	cin >> numInputs;
	
	vector<Person *> ListPersons;
	Person *ptrPerson = NULL;
	for(int i = 0; i < numInputs; i++)
	{
		cin >> personType;
		if(personType == 1)   // Professor
		{
			ptrPerson = new Professor();
		}
		else  // Student
		{
			ptrPerson = new Student();
		}
		ptrPerson->getdata();
		ListPersons.push_back(ptrPerson);
	}

	for(int i = 0; i < numInputs; i++)
	{
		ListPersons[i]->putdata();
	}
	return 0;
}