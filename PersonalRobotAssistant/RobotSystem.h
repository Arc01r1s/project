#pragma once
#ifndef ROBOT_SYSTEM_H
#define ROBOT_SYSTEM_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

/// �κ� ���� �߻� Ŭ����
class RobotAssistant {
protected:
    string name; ///< �κ��� �̸�
    int id;      ///< �κ� ID

public:
    RobotAssistant(const string& name, int id);
    virtual ~RobotAssistant();

    virtual void introduce() const = 0;      ///< �κ� �Ұ�
    virtual void saveState(ofstream& outFile) const = 0; ///< ���� ����
    virtual void loadState(ifstream& inFile) = 0;        ///< ���� �ε�

    int getId() const;                       ///< �κ� ID ��ȯ
    string getName() const;                  ///< �κ� �̸� ��ȯ

    friend ostream& operator<<(ostream& os, const RobotAssistant& robot);
};

/// �ǰ� ���� �κ�
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

/// �۾� ���� �κ�
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

/// ���׸� ������ ���� Ŭ����
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
