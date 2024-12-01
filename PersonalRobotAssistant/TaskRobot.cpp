#include "RobotSystem.h"

/// TaskRobot ������
TaskRobot::TaskRobot(const string& name, int id) : RobotAssistant(name, id) {}

/// TaskRobot �Ҹ���
TaskRobot::~TaskRobot() {}

/// �κ� �Ұ�
void TaskRobot::introduce() const {
    cout << "�ȳ��ϼ���! ���� �۾� ���� �κ� " << name << "�Դϴ�." << endl;
}

/// �۾� �߰�
void TaskRobot::addTask(const string& task) {
    tasks.push_back(task);
}

/// �۾� ��� ���
void TaskRobot::showTasks() const {
    cout << "�۾� ���:" << endl;
    for (const auto& task : tasks) {
        cout << "- " << task << endl;
    }
}

/// �۾� ���� ����
void TaskRobot::saveState(ofstream& outFile) const {
    outFile << "TaskRobot " << id << " " << name << " " << tasks.size();
    for (const auto& task : tasks) {
        outFile << " " << task;
    }
    outFile << endl;
}

/// �۾� ���� �ε�
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
