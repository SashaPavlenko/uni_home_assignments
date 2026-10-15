#include <string>
#include <tuple>

#pragma once

std::string readFile(const std::string& fileName);
std::tuple<int, int> getRH(const std::string& subs, int k = 2);