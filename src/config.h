#pragma once

#include <string>

struct Config
{
    std::string package;
    std::string repository;
    bool test_mode = false;
    int max_depth = -1;
    std::string filter;
};

bool load_config(const std::string& filename, Config& config);