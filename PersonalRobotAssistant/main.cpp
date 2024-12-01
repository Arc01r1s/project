#include "RobotSystem.h"

int main() {
    // ��ü �迭�� ������ Ȱ��
    vector<RobotAssistant*> robots;

    // �κ� �߰�
    robots.push_back(new HealthRobot("HealthBot", 1));
    robots.push_back(new TaskRobot("TaskBot", 2));

    // �κ� �Ұ�
    for (const auto& robot : robots) {
        robot->introduce();
    }

    // �ǰ� �κ� ��� �׽�Ʈ
    HealthRobot* healthRobot = dynamic_cast<HealthRobot*>(robots[0]);
    if (healthRobot) {
        healthRobot->updateHealth(80, 5000);
        healthRobot->displayHealth();
    }

    // �۾� �κ� ��� �׽�Ʈ
    TaskRobot* taskRobot = dynamic_cast<TaskRobot*>(robots[1]);
    if (taskRobot) {
        taskRobot->addTask("������ ����");
        taskRobot->addTask("���� ���");
        taskRobot->showTasks();
    }

    // ���� ����
    ofstream outFile("robot_state.txt");
    for (const auto& robot : robots) {
        robot->saveState(outFile);
    }
    outFile.close();

    // ���� �ε�
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

    // �ε�� �κ� ���
    for (const auto& robot : loadedRobots) {
        robot->introduce();
    }

    // �޸� ����
    for (auto& robot : robots) {
        delete robot;
    }
    for (auto& robot : loadedRobots) {
        delete robot;
    }

    return 0;
}
