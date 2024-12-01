#include "RobotSystem.h"

/// HealthRobot ������
HealthRobot::HealthRobot(const string& name, int id)
    : RobotAssistant(name, id), heartRate(0), steps(0) {}

/// HealthRobot �Ҹ���
HealthRobot::~HealthRobot() {}

/// �κ� �Ұ�
void HealthRobot::introduce() const {
    cout << "�ȳ��ϼ���! ���� �ǰ� ���� �κ� " << name << "�Դϴ�." << endl;
}

/// �ǰ� ���� ������Ʈ
void HealthRobot::updateHealth(int heartRate, int steps) {
    this->heartRate = heartRate;
    this->steps = steps;
}

/// �ǰ� ���� ����
void HealthRobot::saveState(ofstream& outFile) const {
    outFile << "HealthRobot " << id << " " << name << " " << heartRate << " " << steps << endl;
}

/// �ǰ� ���� �ε�
void HealthRobot::loadState(ifstream& inFile) {
    inFile >> name >> heartRate >> steps;
}

/// �ǰ� ���� ���
void HealthRobot::displayHealth() const {
    cout << "���� �ɹڼ�: " << heartRate << " BPM, ���� ��: " << steps << " ����" << endl;
}
