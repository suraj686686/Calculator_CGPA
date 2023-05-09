#include <iostream>
using namespace std;
class Course {
    private:
        string name;
        int credits;
        float grade;
    public:
	//constructor of a class
        Course() {}
	
        Course(string n, int c, float g) {
            name = n;
            credits = c;
            grade = g;
        }
        string getName() {
            return name;
        }
        int getCredits() {
            return credits;
        }
        float getGrade() {
            return grade;
        }
};
//calculation cgpa
class CGPA {
    private:
        int numCourses;
        Course *courses;
    public:
        CGPA(int n) {
            numCourses = n;
            courses = new Course[numCourses]{}; //initialize with empty curly braces to avoid the error
        }
        void setCourse(int i, string n, int c, float g) {
            courses[i] = Course(n, c, g);
        }
        float getCGPA() {
            float totalCredits = 0;
            float totalGradePoints = 0;
            for (int i = 0; i < numCourses; i++) {
                totalCredits += courses[i].getCredits();
                totalGradePoints += courses[i].getCredits() * courses[i].getGrade();
            }
            return totalGradePoints / totalCredits;
        }
};
int main() {
    int n;
    cout << "Enter number of courses: ";
    cin >> n;
    CGPA cgpa(n);
    string name;
    int credits;
    float grade;
    for (int i = 0; i < n; i++) {
        cout << "Enter name of course " << i + 1 << ": ";
        cin >> name;
        cout << "Enter number of credits for course " << i + 1 << ": ";
        cin >> credits;
        cout << "Enter grade for course " << i + 1 << ": ";
        cin >> grade;
        cgpa.setCourse(i, name, credits, grade);
    }
    cout << "Your CGPA is: " << cgpa.getCGPA() << endl;
    return 0;
}
