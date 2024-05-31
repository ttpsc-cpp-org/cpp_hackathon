# Github Copilot Hackathon - C++

## Use Case: 

Your team was assigned to maintain a legacy application, written and forgotten long time ago. The application helps florist shop to maintain their stock, control prices and define policies of how the value of the stock changes over time.
You were told that application was poorly maintained, so you were given some time to make yourself comfortable with it. The plan is to modernize it and expand its functionalities, so make sure you spend the initial preparation time effectively.


## Pre-requisite:

1.	OS: Ubuntu 22.10 (WSL is fine as well)
2.	Required C++ tools/packages:

    a.	gcc

    b.	CMake

    c.	ConanIO v1.64 

    d.	Gcov

    e.	LCov

    f.	GCovr

    g.	IDE (VSCode (?))

    h.	ninja-build
    

## Workflow:

### Working on this repository:
1. Clone this repository.
2. Invoke `./prepare.sh` script to prepare necessary conan packages.
3. Use `./build.sh` or direct cmake commands to build and run tests.

### Working on challenges:
1. Use branch with name *team/*<your_team_name> as your trunk.
2. Associated Github Action should reflect your progess:
    a. On initial run, it may fail due to unit test coverage threshold set:

            
            - name: Generate a code coverage report
              (...)
                  fail-under-line: 75%
    As you progress, the pipeline should become green.
3. Make sure that your Github Actions workflows reflect your progress - add, them, modify them, store necessary artifacts as a proof of progress.


## Challenges:

To be added soon!