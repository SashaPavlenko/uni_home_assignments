#include <string>
#pragma once

bool is_numeric(const std::string& s);

std::string readFile(const std::string& fileName);

void set_ATS(ATS arr[], string filename);

int compareMyType(const void* a, const void* b);