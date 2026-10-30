
#include "config.h"
#include <set>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
bool validate_package(const std::string& package)
{
    size_t first = package.find(':');

    if (first == std::string::npos)
        return false;

    size_t second = package.find(':', first + 1);

    if (second == std::string::npos)
        return false;

    if (package.find(':', second + 1) != std::string::npos)
        return false;

    std::string group_id = package.substr(0, first);
    std::string artifact_id = package.substr(first + 1, second - first - 1);
    std::string version = package.substr(second + 1);

    return !group_id.empty() &&
        !artifact_id.empty() &&
        !version.empty();
}
bool validate_repository(const std::string& repository, bool test_mode)
{
    if (repository.empty())
        return false;

    if (test_mode)
        return true;

    return repository.find("https://") == 0 ||
        repository.find("http://") == 0;
}
bool load_config(const std::string& filename, Config& config)
{
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cout << "Error: cannot open configuration file.\n";
        return false;
    }

    std::set<std::string> found_parameters;

    std::vector<std::string> required_parameters =
    {
        "package",
        "repository",
        "test_mode",
        "max_depth",
        "filter"
    };

    std::string line;

    // Пропускаем заголовок CSV
    std::getline(file, line);

    while (std::getline(file, line))
    {
        std::stringstream ss(line);

        std::string parameter;
        std::string value;

        if (!std::getline(ss, parameter, ','))
        {
            std::cout << "Error: invalid CSV format\n";
            return false;
        }
        if (line.find(',') == std::string::npos)
        {
            std::cout << "Error: invalid CSV format\n";
            return false;
        }

        std::getline(ss, value);

        if (found_parameters.count(parameter))
        {
            std::cout << "Error: duplicate parameter: " << parameter << '\n';
            return false;
        }

        found_parameters.insert(parameter);

        if (std::find(required_parameters.begin(),
            required_parameters.end(),
            parameter) == required_parameters.end())
        {
            std::cout << "Error: unknown parameter: " << parameter << '\n';
            return false;
        }

        if (parameter == "package")
        {
            if (!validate_package(value))
            {
                std::cout << "Error: invalid package coordinates\n";
                return false;
            }

            config.package = value;
        }

        else if (parameter == "repository")
        {
            config.repository = value;
        }

        else if (parameter == "test_mode")
        {
            if (value != "true" && value != "false")
            {
                std::cout << "Error: test_mode must be true or false\n";
                return false;
            }

            config.test_mode = (value == "true");
        }

        else if (parameter == "max_depth")
        {
            try
            {
                size_t pos;
                int depth = std::stoi(value, &pos);

                if (pos != value.size() || depth < 0)
                {
                    std::cout << "Error: max_depth must be a non-negative integer\n";
                    return false;
                }

                config.max_depth = depth;
            }
            catch (...)
            {
                std::cout << "Error: max_depth must be an integer\n";
                return false;
            }
        }

        else if (parameter == "filter")
            config.filter = value;
    }
    for (const auto& parameter : required_parameters)
    {
        if (!found_parameters.count(parameter))
        {
            std::cout << "Error: missing parameter: " << parameter << '\n';
            return false;
        }
    }

    if (!validate_repository(config.repository, config.test_mode))
    {
        std::cout << "Error: invalid repository\n";
        return false;
    }

    return true;
}