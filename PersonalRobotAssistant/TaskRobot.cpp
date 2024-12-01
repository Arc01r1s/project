#include "RobotSystem.h"

/// TaskRobot 생성자
TaskRobot::TaskRobot(const string& name, int id) : RobotAssistant(name, id) {}

/// TaskRobot 소멸자
TaskRobot::~TaskRobot() {}

/// 로봇 소개
void TaskRobot::introduce() const {
    cout << "안녕하세요! 저는 작업 관리 로봇 " << name << "입니다." << endl;
}

/// 작업 추가
void TaskRobot::addTask(const string& task) {
    tasks.push_back(task);
}

/// 작업 목록 출력
void TaskRobot::showTasks() const {
    cout << "작업 목록:" << endl;
    for (const auto& task : tasks) {
        cout << "- " << task << endl;
    }
}

/// 작업 상태 저장
void TaskRobot::saveState(ofstream& outFile) const {
    outFile << "TaskRobot " << id << " " << name << " " << tasks.size();
    for (const auto& task : tasks) {
        outFile << " " << task;
    }
    outFile << endl;
}

/// 작업 상태 로드
void TaskRobot::loadState(ifstream& inFile) {
    size_t taskCount;
    inFile >> name >> taskCount;
    tasks.clear();
    for (size_t i = 0; i < taskCount; ++i) {
        string task;
        inFile >> task;
        tasks.push_back(task);
    }
}
