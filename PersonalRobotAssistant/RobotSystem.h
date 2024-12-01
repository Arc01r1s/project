#pragma once
#ifndef ROBOT_SYSTEM_H
#define ROBOT_SYSTEM_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

/// 로봇 비서의 추상 클래스
class RobotAssistant {
protected:
    string name; ///< 로봇의 이름
    int id;      ///< 로봇 ID

public:
    RobotAssistant(const string& name, int id);
    virtual ~RobotAssistant();

    virtual void introduce() const = 0;      ///< 로봇 소개
    virtual void saveState(ofstream& outFile) const = 0; ///< 상태 저장
    virtual void loadState(ifstream& inFile) = 0;        ///< 상태 로드

    int getId() const;                       ///< 로봇 ID 반환
    string getName() const;                  ///< 로봇 이름 반환

    friend ostream& operator<<(ostream& os, const RobotAssistant& robot);
};

/// 건강 관리 로봇
class HealthRobot : public RobotAssistant {
private:
    int heartRate;
    int steps;

public:
    HealthRobot(const string& name, int id);
    virtual ~HealthRobot();

    void introduce() const override;
    void updateHealth(int heartRate, int steps);
    void saveState(ofstream& outFile) const override;
    void loadState(ifstream& inFile) override;
    void displayHealth() const;
};

/// 작업 관리 로봇
class TaskRobot : public RobotAssistant {
private:
    vector<string> tasks;

public:
    TaskRobot(const string& name, int id);
    virtual ~TaskRobot();

    void introduce() const override;
    void addTask(const string& task);
    void showTasks() const;
    void saveState(ofstream& outFile) const override;
    void loadState(ifstream& inFile) override;
};

/// 제네릭 데이터 저장 클래스
template <typename T>
class DataStorage {
private:
    vector<T> data;

public:
    void addData(const T& item) {
        data.push_back(item);
    }

    void displayAll() const {
        for (const auto& item : data) {
            cout << item << endl;
        }
    }
};

#endif // ROBOT_SYSTEM_H
