# DependencyVisualizer

**DependencyVisualizer** is a C++ command-line application designed to analyze and visualize package dependency graphs using the Maven repository format.

The project is developed as part of a coursework assignment.

## Overview

The application retrieves package metadata from Maven repositories, analyzes direct and transitive dependencies, and builds a dependency graph.

The main goal is to implement dependency analysis independently, without using existing package managers or third-party libraries that automatically retrieve package dependencies.

## Features

Planned functionality:

- Read application settings from a CSV configuration file.
- Validate user-defined parameters.
- Retrieve Maven POM files from remote repositories.
- Parse XML metadata and extract direct dependencies.
- Build a dependency graph using recursive Depth-First Search (DFS).
- Limit dependency analysis by the specified depth.
- Filter packages by name.
- Detect and handle cyclic dependencies.
- Support a local test repository.
- Display package loading order.
- Generate dependency graph diagrams in PlantUML format.

## Configuration

Application parameters are stored in a CSV file.

The following settings are supported:

| Parameter | Description |
|---|---|
| `package` | Name and coordinates of the package to analyze |
| `repository` | Maven repository URL or local test repository path |
| `test_mode` | Enables or disables test repository mode |
| `max_depth` | Maximum dependency analysis depth |
| `filter` | Substring used to filter package names |

## Technologies

- **Language:** C++17
- **IDE:** Microsoft Visual Studio
- **XML parsing:** pugixml
- **Version control:** Git
- **Diagram generation:** PlantUML

## Project Structure

```text
DependencyVisualizer/
│
├── config/
│   └── config.csv
│
├── src/
│
├── tests/
│
├── .gitignore
└── README.md
```

## Development Stages

| Stage | Description | Status |
|---|---|---|
| 1 | Configuration and CLI prototype | In progress |
| 2 | Retrieving direct Maven dependencies | Planned |
| 3 | Dependency graph construction and analysis | Planned |
| 4 | Additional graph operations | Planned |
| 5 | Dependency graph visualization | Planned |

## Build

The project is intended to be built using Microsoft Visual Studio with C++17 support.

Build instructions will be added after the initial implementation.

## License

This project is developed for educational purposes.