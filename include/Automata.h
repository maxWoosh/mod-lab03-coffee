// Copyright 2022 UNN-IASR
#pragma once
#include <string>
#include <vector>

enum class STATES {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK
};

class Automata {
 private:
    int cash;
    std::vector<std::string> menu;
    std::vector<int> price;
    STATES state;

 public:
    Automata();
    void on();
    void off();
    void coin(int Money);
    void getMenu();
    STATES getState();
    void choice(int Num);
    bool check(int Num);
    void cancel();
    void cook(int Num);
    void finish();
};
