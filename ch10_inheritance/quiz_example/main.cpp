#include <iostream>

using namespace std;

class Question {
    public:
    Question(string text, int points){
        isCorrect = false;
        this->text = text;
        this->points = points;
    }
    
    int getPoints() const {
        if(isCorrect)
            return points;
        else
            return 0;
    }
    
    protected:
    bool isCorrect;
    string text;
    int points;
};

class TrueFalseQuestion : public Question {
    public:
    TrueFalseQuestion(string text, int points, bool correctAnswer) : 
        Question(text, points) {
        this->correctAnswer = correctAnswer;
    }
    
    void askQuestion(){
        cout << "True or False:" << endl;
        cout << text << endl;
        cout << "Enter T or F: " << endl;
        char answer; bool boolAnswer;
        cin >> answer;
        boolAnswer = answer == 'T' ? true : false;
        isCorrect = boolAnswer == correctAnswer;  
    }
    
    private:
    bool correctAnswer;
};

class ShortAnswerQuestion : public Question {
    public:
    ShortAnswerQuestion(string text, int points, string correctAnswer) : 
        Question(text, points) {
        this->correctAnswer = correctAnswer;
    }
    
    void askQuestion(){
        cout << "Short Answer:" << endl;
        cout << text << endl;
        cout << "Enter answer in all lowercase: " << endl;
        string answer;
        cin >> answer;
        isCorrect = answer == correctAnswer;  
    }
    
    private:
    string correctAnswer;
};

int main(){
    
    TrueFalseQuestion q1("Is the sky blue?", 10, true);
    ShortAnswerQuestion q2("What language is taught in ECGR 2104?", 10, "c++");
    
    q1.askQuestion();
    q2.askQuestion();
    
    cout << "You scored: " << q1.getPoints() + q2.getPoints() << endl;
    
    return 0;
}