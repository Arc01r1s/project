#include "RobotSystem.h"

/// RobotAssistant ������
RobotAssistant::RobotAssistant(const string& name, int id) : name(name), id(id) {}

/// RobotAssistant �Ҹ���
RobotAssistant::~RobotAssistant() {}

/// �κ� ID ��ȯ
int RobotAssistant::getId() const {
    return id;
}

/// �κ� �̸� ��ȯ
string RobotAssistant::getName() const {
    return name;
}

/// ��� ������ �ߺ�
ostream& operator<<(ostream& os, const RobotAssistant& robot) {
    os << "�κ� �̸�: " << robot.name << ", ID: " << robot.id;
    return os;
}
