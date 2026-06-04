#pragma once

#include <iostream>
#include <unordered_set>

#include "m416_skins.h"

namespace skin_tables {

// Runtime validator for M416 tables; call in debug builds to catch bad data.
inline bool validateM416Tables(std::ostream &out = std::cerr) {
    bool ok = true;
    auto check = [&](const char *name, const auto &arr) {
        std::unordered_set<int> seen;
        for (auto value : arr) {
            if (value <= 0) {
                out << "[skin validate] " << name << " contains non-positive id " << value << "\n";
                ok = false;
            }
            if (!seen.insert(value).second) {
                out << "[skin validate] " << name << " duplicate id " << value << "\n";
                ok = false;
            }
        }
    };

    check("M4161", M4161);
    check("M4162", M4162);
    check("M4163", M4163);
    check("M4164", M4164);
    check("M416flash", M416flash);
    check("M416compe", M416compe);
    check("M416silent", M416silent);
    check("M416reddot", M416reddot);
    check("M416holo", M416holo);
    check("M416x2", M416x2);
    check("M416x3", M416x3);
    check("M416x4", M416x4);
    check("M416x6", M416x6);
    check("M416quickMag", M416quickMag);
    check("M416extendedMag", M416extendedMag);
    check("M416quickNextended", M416quickNextended);
    check("M416stock", M416stock);
    check("M416verical", M416verical);
    check("M416angle", M416angle);
    check("M416lightgrip", M416lightgrip);
    check("M416pink", M416pink);
    check("M416lazer", M416lazer);
    check("M416thumb", M416thumb);

    return ok;
}

}  // namespace skin_tables
