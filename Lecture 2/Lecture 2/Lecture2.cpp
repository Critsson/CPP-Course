#include <iostream>
#include <vector>
#include <fstream>

class Student {

	std::string m_first = "First";
	std::string m_last = "Last";
	int m_id = 0;
	float m_avg = 0;

public:

	Student() {}

	Student(std::string first, std::string last, int id, float avg) : m_first(first), m_last(last), m_id(id), m_avg(avg) {

	}

	int getAvg() {
		return m_avg;
	}

	int getId() {
		return m_id;
	}

	std::string getFirst() {
		return m_first;
	}

	std::string getLast() {
		return m_last;
	}

	void print() const {
		std::cout << m_first + " " << m_last << std::endl;
		std::cout << "Student Id: " << m_id << std::endl;
		std::cout << "Average: " << m_avg << std::endl;
	}
};


class Course {

	std::string m_name = "Course";
	std::vector<Student> m_students;

public:

	Course() {}

	Course(const std::string& name) : m_name(name) {

	}

	void addStudent(const Student& s) {
		m_students.push_back(s);
	}

	const std::vector<Student>& getStudents() const {
		return m_students;
	}

	void print() const {

		for (const Student& s : m_students) {
			s.print();
		}
	}

	const std::string& getCourseName() const {
		return m_name;
	}

	void loadFromFile(const std::string& filename) {

	}

};

int main(int argc, char* argv[]) {
	

	Student s2("Chris", "Gao", 1, 90.1);
	Student s3("Chris", "Gao", 1, 90.1);
	Student s4("Chris", "Gao", 1, 90.1);
	Student s5("Chris", "Gao", 1, 90.1);
	
	Course comp4300("COMP 4300");

	comp4300.addStudent(s2);
	comp4300.addStudent(s3);
	comp4300.addStudent(s4);
	comp4300.addStudent(s5);

	comp4300.print();

	return 0;
}