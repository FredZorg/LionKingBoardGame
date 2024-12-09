#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Player {
private:
    string _playerName, _lionName, _advisorName;
    int _strength, _stamina, _wisdom, _pride_points, _age;

public:
// constructors
    Player() {
        _playerName = "";
        _lionName = "";
        _stamina = 100;
        _strength = 100;
        _wisdom = 100;
        _advisorName = "";
        _age = 0;
    }
    Player(string playerName, string name, int pride_points, int strength, int stamina, int wisdom) {
        _playerName = playerName;
        _lionName = name;
        _pride_points = 0;
        if (stamina >= 100 && stamina <= 1000) {
            _stamina = stamina;
        }
        else {
            _stamina = 100;
        }
        if (strength >= 100 && strength <= 1000) {
            _strength = strength;
        }
        else {
            _strength = 100;
        }
        if (wisdom >= 100 && wisdom <= 1000) {
            _wisdom = wisdom;
        }
        else {
            _wisdom = 100;
        }
    }

    // getters
    string getPlayerName() {
        return _playerName;
    }
    string getLionName() {
        return _lionName;
    }
    int getStrength() {
        return _strength;
    }
    int getStamina() {
        return _stamina;
    }
    int getWisdom() {
        return _wisdom;
    }
    int getPridePoints() {
        return _pride_points;
    }
    int getAge() {
        return _age;
    }
    string getAdviosrName() {
        return _advisorName;
    }

    // setters (should i error check?)
    void setAge(int age) {
        _age = age;
    }
    void setPlayerName(string playerName) {
        _playerName = playerName;
    }
    void setLionName(string name) {
        _lionName = name;
    }
    void setStrength(int strength) {
        _strength = strength;
    }
    void setStamina(int stamina) {
        _stamina = stamina;
    }
    void setWisdom(int wisdom) {
        _wisdom = wisdom;
    }
    void setPridePoints (int pride_points) {
        _pride_points = pride_points;
    }
    void setAdvisorName (string name) {
        _advisorName = name;
    }

};
