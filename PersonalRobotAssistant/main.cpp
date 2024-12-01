#include "RobotSystem.h"

int main() {
    // 객체 배열과 포인터 활용
    vector<RobotAssistant*> robots;

    // 로봇 추가
    robots.push_back(new HealthRobot("HealthBot", 1));
    robots.push_back(new TaskRobot("TaskBot", 2));

    // 로봇 소개
    for (const auto& robot : robots) {
        robot->introduce();
    }

    // 건강 로봇 기능 테스트
    HealthRobot* healthRobot = dynamic_cast<HealthRobot*>(robots[0]);
    if (healthRobot) {
        healthRobot->updateHealth(80, 5000);
        healthRobot->displayHealth();
    }

    // 작업 로봇 기능 테스트
    TaskRobot* taskRobot = dynamic_cast<TaskRobot*>(robots[1]);
    if (taskRobot) {
        taskRobot->addTask("컴프실 과제");
        taskRobot->addTask("저녁 약속");
        taskRobot->showTasks();
    }

    // 상태 저장
    ofstream outFile("robot_state.txt");
    for (const auto& robot : robots) {
        robot->saveState(outFile);
    }
    outFile.close();

    // 상태 로드
    ifstream inFile("robot_state.txt");
    vector<RobotAssistant*> loadedRobots;
    string type;
    while (inFile >> type) {
        if (type == "HealthRobot") {
            HealthRobot* r = new HealthRobot("", 0);
            r->loadState(inFile);
            loadedRobots.push_back(r);
        }
        else if (type == "TaskRobot") {
            TaskRobot* r = new TaskRobot("", 0);
            r->loadState(inFile);
            loadedRobots.push_back(r);
        }
    }
    inFile.close();

    // 로드된 로봇 출력
    for (const auto& robot : loadedRobots) {
        robot->introduce();
    }

    // 메모리 해제
    for (auto& robot : robots) {
        delete robot;
    }
    for (auto& robot : loadedRobots) {
        delete robot;
    }

    return 0;
}
