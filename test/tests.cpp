// Copyright 2022 UNN-IASR
#include "Automata.h"
#include <gtest/gtest.h>

class AutomataTest : public ::testing::Test {
protected:
    Automata automata;

    void SetUp() override {
        automata.on();
    }
};

TEST_F(AutomataTest, IsInitiallyOff) {
    Automata newAutomata;
    EXPECT_EQ(newAutomata.getState(), STATES::OFF);
}

TEST_F(AutomataTest, TurnsOn) {
    EXPECT_EQ(automata.getState(), STATES::WAIT);
}

TEST_F(AutomataTest, AcceptsCoins) {
    automata.coin(100);
    EXPECT_EQ(automata.getState(), STATES::ACCEPT);
}

TEST_F(AutomataTest, CanReadMenu) {
    EXPECT_NO_THROW(automata.getMenu());
}

TEST_F(AutomataTest, MakesSelection) {
    automata.coin(200);
    automata.choice(2);
    EXPECT_EQ(automata.getState(), STATES::WAIT);
}

TEST_F(AutomataTest, ChecksSufficientFunds) {
    automata.coin(20);
    EXPECT_FALSE(automata.check(1));
}

TEST_F(AutomataTest, CancelsTransaction) {
    automata.coin(100);
    automata.cancel();
    EXPECT_EQ(automata.getState(), STATES::WAIT);
}

TEST_F(AutomataTest, CooksDrink) {
    automata.coin(200);
    automata.choice(1);
    EXPECT_EQ(automata.getState(), STATES::WAIT);
}

TEST_F(AutomataTest, FinishesTransaction) {
    automata.coin(200);
    automata.choice(1);
    EXPECT_EQ(automata.getState(), STATES::WAIT);
}

TEST_F(AutomataTest, DoesNotCookWithoutFunds) {
    automata.choice(1);
    EXPECT_NE(automata.getState(), STATES::COOK);
}
