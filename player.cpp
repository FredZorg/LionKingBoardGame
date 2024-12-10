#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "player.h"

Player::Player() {
    _playerName = "";
    _lionName = "";
    _stamina = 100;
    _strength = 100;
    _wisdom = 100;
    _advisorName = "";
    _advisorAbility = "";
    _age = 0;
}
Player::Player(string playerName, string name, int pride_points, int strength, int stamina, int wisdom) {
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
string Player :: getPlayerName() {
    return _playerName;
}
string Player :: getLionName() {
    return _lionName;
}
int Player :: getStrength() {
    return _strength;
}
int Player :: getStamina() {
    return _stamina;
}
int Player :: getWisdom() {
    return _wisdom;
}
int Player :: getPridePoints() {
    return _pride_points;
}
int Player :: getAge() {
    return _age;
}

string Player :: getAdvisorName() {
    return _advisorName;
}

string Player :: getAdvisorAbility() {
    return _advisorAbility;
}

// setters (should i error check?)
void Player :: setAdvisorAbility(string advisorAbility) {
    _advisorAbility = advisorAbility;
}
void Player :: setAge(int age) {
    _age = age;
}
void Player :: setPlayerName(string playerName) {
    _playerName = playerName;
}
void Player :: setLionName(string name) {
    _lionName = name;
}
void Player :: setStrength(int strength) {
    _strength = strength;
}
void Player :: setStamina(int stamina) {
    _stamina = stamina;
}
void Player :: setWisdom(int wisdom) {
    _wisdom = wisdom;
}
void Player :: setPridePoints (int pride_points) {
    _pride_points = pride_points;
}
void Player :: setAdvisorName (string name) {
    _advisorName = name;
}
void Player :: addStrength(int strength) {
    if ((_strength + strength) < 100){
        _strength = 100;
        return;
    } else {
        _strength += strength;
    }
}
void Player :: addStamina(int stamina) {
    if ((_stamina + stamina) < 100){
        _stamina = 100;
        return;
    } else {
        _stamina += stamina;
    }
}
void Player :: addWisdom(int wisdom) {
    if ((_wisdom + wisdom) < 100){
        _wisdom = 100;
        return;
    } else {
        _wisdom += wisdom;
    }

