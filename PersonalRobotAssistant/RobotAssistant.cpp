#include "RobotSystem.h"

/// RobotAssistant 생성자
RobotAssistant::RobotAssistant(const string& name, int id) : name(name), id(id) {}

/// RobotAssistant 소멸자
RobotAssistant::~RobotAssistant() {}

/// 로봇 ID 반환
int RobotAssistant::getId() const {
    return id;
}

/// 로봇 이름 반환
string RobotAssistant::getName() const {
    return name;
}

/// 출력 연산자 중복
ostream& operator<<(ostream& os, const RobotAssistant& robot) {
    os << "로봇 이름: " << robot.name << ", ID: " << robot.id;
    return os;
}
