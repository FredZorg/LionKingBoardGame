//Abey Saleh and Fred Zordgrager Group Project
#include <string>
#include "player.h"

using namespace std;

//0 is cubTraining 1 is to the pride
Player::Player() {
    _playerName = "";
    _pride_points = 20000;
    _lionName = "";
    _stamina = 100;
    _strength = 100;
    _wisdom = 100;
    _advisorName = "E";
    _advisorAbility = "E";
    _advisorAscii = "E";
    _lionAscii = "E";
    _age = 0;
    _choice = 0;
    gameIsDone = false;
    extraTurn = false;
    blueCounter = 0;
    pinkCounter = 0;
    brownCounter = 0;
    purpleCounter = 0;
    greenCounter = 0;
    redCounter = 0;
}

Player::Player(string playerName, string name, int pride_points, int strength, int stamina, int wisdom, std::string lionAscii, std::string advisorAscii) {
    playerName = "E";
    _advisorName = "E";
    _advisorAbility = "E";
    extraTurn = false;
    blueCounter = 0;
    pinkCounter = 0;
    brownCounter = 0;
    purpleCounter = 0;
    greenCounter = 0;
    redCounter = 0;
    _playerName = playerName;
    _lionName = name;
    _advisorAscii = advisorAscii;
    _lionAscii = lionAscii;
    _pride_points = 20000;
    _choice = 0;
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
int Player::getRedOccurrences(){
    return redCounter;
}
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
int Player::getChoice(){
    return _choice;
}

string Player :: getAdvisorName() {
    return _advisorName;
}

string Player :: getAdvisorAbility() {
    return _advisorAbility;
}

bool Player::getGameIsDone(){
    return gameIsDone;
}

void Player::setExtraTurn(bool thing){
    extraTurn = thing;
}

// setters (should i error check?)
void Player::setGameIsDone(bool duh){
    gameIsDone = duh;
}
void Player::setChoice(int choice){
    _choice = choice;
}
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
}
void Player::addPridePoints(int pride) {
    _pride_points += pride;
}
int Player :: getBlueOccurrences() {
    return blueCounter;
}
int Player :: getPinkOccurrences() {
    return pinkCounter;
}
int Player :: getBrownOccurrences() {
    return brownCounter;
}
int Player :: getPurpleOccurrences() {
    return purpleCounter;
}
int Player :: getGreenOccurrences() {
    return greenCounter;
}
void Player :: addGreenCounter(Player player) {
    greenCounter++;
}
void Player :: addPurpleCounter(Player player) {
    purpleCounter++;
}
void Player :: addBrownCounter(Player player) {
    brownCounter++;
}
void Player :: addPinkCounter(Player player) {
    pinkCounter++;
}
void Player :: addBlueCounter(Player player) {
    blueCounter++;
}

void Player::addRedCounter(Player player){
    redCounter++;
}

bool Player::getExtraTurn(){
    return extraTurn;
}
