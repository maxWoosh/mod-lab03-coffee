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

TEST(ATest, 1) {
    Automata newAutomata;
    EXPECT_EQ(newAutomata.getState(), STATES::OFF);
}

TEST(ATest, 2) {
    EXPECT_EQ(automata.getState(), STATES::WAIT);
}

TEST(ATest, 3) {
    automata.coin(100);
    EXPECT_EQ(automata.getState(), STATES::ACCEPT);
}

TEST(ATest, 4) {
    EXPECT_NO_THROW(automata.getMenu());
}

TEST(ATest, 5) {
    automata.coin(200);
    automata.choice(2);
    EXPECT_EQ(automata.getState(), STATES::WAIT);
}

TEST(ATest, 6) {
    automata.coin(20);
    EXPECT_FALSE(automata.check(1));
}

TEST(ATest, 7) {
    automata.coin(100);
    automata.cancel();
    EXPECT_EQ(automata.getState(), STATES::WAIT);
}

TEST(ATest, 8) {
    automata.coin(200);
    automata.choice(1);
    EXPECT_EQ(automata.getState(), STATES::WAIT);
}

TEST(ATest, 9) {
    automata.coin(200);
    automata.choice(1);
    EXPECT_EQ(automata.getState(), STATES::WAIT);
}

TEST(ATest, 10) {
    automata.choice(1);
    EXPECT_NE(automata.getState(), STATES::COOK);
}
