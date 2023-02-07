/*
 * SPDX-License-Identifier: GPL-3.0-only
 * MuseScore-CLA-applies
 *
 * MuseScore
 * Music Composition & Notation
 *
 * Copyright (C) 2023 MuseScore BVBA and others
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <gtest/gtest.h>

#include "types/fraction.h"

#include "types/constants.h"

using namespace mu::engraving;

class Engraving_FractionTests : public ::testing::Test
{
};

TEST_F(Engraving_FractionTests, toTicks) {
    Fraction f_4(1, 4);
    Fraction f_32(1, 32);
    Fraction f_256(1, 256);

    EXPECT_EQ(f_4.ticks(), Constants::division);
    EXPECT_EQ(f_32.ticks(), Constants::division / 8);
    EXPECT_EQ(f_256.ticks(), Constants::division / 64);//7.5);
}

//TEST_F(Engraving_FractionTests, fromTicks) {
//}

//TEST_F(Engraving_FractionTests, ticksRoundTrip) {
//}
