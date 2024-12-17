# Moose

**Designed and developed by** [Luqman](https://theluqmn.github.io/) | **First** C++ project!

Moose is a simple bank management system written in C++. It includes basic functionalities such as creating accounts, depositing and withdrawing money, balance checking, transaction history, transferring money, and a simple payment interface. Uses SQLite3 for data storage.

> [!WARNING]
> This project is still in **active** development.

## Features

Below are the features planned for this project. Everything needs to be implemented before I consider this project complete. Rate of progress is roughly a feature per day.

- [ ] Accounts
  - [x] Opening acccounts - 15/12/2024
  - [x] Closing accounts - 17/12/2024
  - [ ] Interest rates
  - [ ] Update information
  - [ ] Account overview
  - [ ] Find, get and list accounts
- [ ] Transactions
  - [x] Deposits - 18/12/2024
  - [ ] Withdrawals
  - [ ] Fund transfer (between accounts)
  - [ ] Payment interface
  - [ ] Fetch transaction history
- [ ] Security
  - [ ] Session token
  - [ ] Password hashing and salting
- [ ] API
  - [ ] REST setup
  - [ ] User API
  - [ ] Developer API

> [!NOTE]
> All the features listed above includes a terminal interface which I use for testing purposes.

Other than banking-related features, this project also has a bash script (`run.bash`) that simplifies the compilation process.

## Installation

1. Clone the repository
2. Ensure sqlite3 is installed in your system
3. Run `bash run.bash` to compile all files and run the program

## Usage

Run the program and follow the prompts.

- Use `help` to get a list of available commands
- Run `quit` to exit the program

## Known Issues

- accountExists() function does not work properly, returns 0 even though the account exists. The function also does not check for account type.

## Stack

- Language: C++
- Database: SQLite3
