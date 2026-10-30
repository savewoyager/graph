
#include <iostream>
#include "config.h"
using namespace std;
int main()
{
    Config config;
    cout << "========== TEST 1: Correct configuration ==========\n";
    load_config("config/config.csv", config);
    cout << "========== CONFIGURATION ==========\n\n";
    cout << "Package: " << config.package << '\n';
    cout << "Repository: " << config.repository << '\n';
    cout << "Test mode: " << (config.test_mode ? "true" : "false") << '\n';
    cout << "Max depth: " << config.max_depth << '\n';
    cout << "Filter: " << config.filter << '\n';
    cout << "\n===================================\n";
    cout << "\n========== TEST 2: Negative max_depth ==========\n";
    load_config("config/err_depth_neg.csv", config);
    cout << "\n========== TEST 3: String max_depth ==========\n";
    load_config("config/err_depth_str.csv", config);
    cout << "\n========== TEST 4: Invalid max_depth suffix ==========\n";
    load_config("config/err_depth_suffx.csv", config);
    cout << "\n========== TEST 5: Invalid test_mode ==========\n";
    load_config("config/err_test_mode.csv", config);
    return 0;
}
