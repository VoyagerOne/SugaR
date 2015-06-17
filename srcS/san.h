/*
# SugaR, a UCI chess playing engine derived from Stockfish

# Copyright (C) 2008-2015 Marco Costalba, Joona Kiiski, Tord Romstad

# SugaR is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

#
# SugaR is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef NOTATION_H_INCLUDED
#define NOTATION_H_INCLUDED

#include <string>
#include <fstream>
#include "types.h"

class Position;

const std::string move_to_san(const Position& pos, Move m);
std::string pretty_pv(Position& pos, int depth, Value score, int64_t msecs);

struct Log : public std::ofstream {
    Log(const std::string& f = "log.txt") : std::ofstream(f.c_str(), std::ios::out | std::ios::app) {}
    ~Log() {
        if (is_open()) close();
    }
};

#endif // #ifndef NOTATION_H_INCLUDED
