// Copyright 2022 UNN-IASR
#include "Automata.h"
#include <gtest/gtest.h>

class ATest : public ::testing::Test {
 protected:
    Automata automata;

    void SetUp() override {
        automata.on();
    }
};

TEST_F(ATest, 1) {
    Automata newAutomata;
    EXPECT_EQ(newAutomata.getState(), STATES::OFF);
}

TEST_F(ATest, 2) {
    EXPECT_EQ(automata.getState(), STATES::WAIT);
}

TEST_F(ATest, 3) {
    automata.coin(50);
    EXPECT_EQ(automata.getState(), STATES::ACCEPT);
}

TEST_F(ATest, 4) {
    EXPECT_NO_THROW(automata.getMenu());
}

TEST_F(ATest, 5) {
    automata.coin(100);
    automata.choice(2);
    EXPECT_EQ(automata.getState(), STATES::WAIT);
}

TEST_F(ATest, 6) {
    automata.coin(10);
    EXPECT_FALSE(automata.check(1));
}

TEST_F(ATest, 7) {
    automata.coin(50);
    automata.cancel();
    EXPECT_EQ(automata.getState(), STATES::WAIT);
}

TEST_F(ATest, 8) {
    automata.coin(100);
    automata.choice(1);
    EXPECT_EQ(automata.getState(), STATES::WAIT);
}

TEST_F(ATest, 9) {
    automata.coin(100);
    automata.choice(1);
    EXPECT_EQ(automata.getState(), STATES::WAIT);
}

TEST_F(ATest, 10) {
    automata.choice(1);
    EXPECT_NE(automata.getState(), STATES::COOK);
}
