#include "RobotSystem.h"

/// HealthRobot 생성자
HealthRobot::HealthRobot(const string& name, int id)
    : RobotAssistant(name, id), heartRate(0), steps(0) {}

/// HealthRobot 소멸자
HealthRobot::~HealthRobot() {}

/// 로봇 소개
void HealthRobot::introduce() const {
    cout << "안녕하세요! 저는 건강 관리 로봇 " << name << "입니다." << endl;
}

/// 건강 상태 업데이트
void HealthRobot::updateHealth(int heartRate, int steps) {
    this->heartRate = heartRate;
    this->steps = steps;
}

/// 건강 상태 저장
void HealthRobot::saveState(ofstream& outFile) const {
    outFile << "HealthRobot " << id << " " << name << " " << heartRate << " " << steps << endl;
}

/// 건강 상태 로드
void HealthRobot::loadState(ifstream& inFile) {
    inFile >> name >> heartRate >> steps;
}

/// 건강 상태 출력
void HealthRobot::displayHealth() const {
    cout << "현재 심박수: " << heartRate << " BPM, 걸음 수: " << steps << " 걸음" << endl;
}
