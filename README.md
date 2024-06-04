# Github Copilot Hackathon - C++

## Use Case: 

Your team was assigned to maintain a legacy application, written and forgotten long time ago. The application helps florist shop to maintain their stock, control prices and define policies of how the value of the stock changes over time.
You were told that application was poorly maintained, so you were given some time to make yourself comfortable with it. The plan is to modernize it and expand its functionalities, so make sure you spend the initial preparation time effectively.


## Pre-requisite:

### Environment preparation:
1.	Log-in to your lab virtual machine using credentials provided.
2.	Run PowerShell as Administrator.
3.  Enable WSL2 and install Ubuntu machine. [Instructions](https://docs.microsoft.com/en-us/windows/wsl/install). 
    TL;DR:
    ```powershell
    1. 
    dism.exe /online /enable-feature /featurename:Microsoft-Windows-Subsystem-Linux /all /norestart
    2.
    dism.exe /online /enable-feature /featurename:VirtualMachinePlatform /all /norestart
    3.
    wsl --set-default-version 2
    4. 
    wsl --install -d Ubuntu
    5. Restart machine
    shutdown /r /t 0
    ```
    Wait for the machine to restart.
4.	Generate ssh key and add it to your Github account. [Instructions](https://docs.github.com/en/github/authenticating-to-github/connecting-to-github-with-ssh)
5.  Clone hackathon repository to your wsl environment using ssh:
    ```
    git clone git@github.com:copworkshop/cpp_hackathon.git
    cd cpp_hackathon
    ```
6.  Run `./bootstrap.sh' script to install necessary tools and dependencies.
7.  Activate Python Virtual Env using `source venv/bin/activate` command.
    ```
    NOTE: You must activate the virtual environment each time you open a new terminal.
    ```
8.  Run `./prepare.sh` script to prepare necessary conan packages.
9.  Use `./build.sh` or direct cmake commands to build and run tests.



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

