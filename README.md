# Moose

**Designed and developed by** [Luqman](https://theluqmn.github.io/)

Moose is a simple bank management system written in Rust. It includes a REST API for clients to perform various operations such as creating accounts, making transactions, and managing their accounts.
Designed to be integrated with various projects and services that may require a backend for managing accounts and transactions.
This is also my first Rust project. Originally written in C++ and migrated to Rust.

The original C++ version is available at this [release](https://github.com/TheLuqmn/Moose/releases/tag/v0.1.cpp). Note that it barely works.

> [!WARNING]
> This project is still in **active** development.

## To-do

- [ ] accounts
  - [x] create accounts - 25/12/2024
    - [x] checking
    - [x] savings
  - [x] check account exists - 25/12/2024
  - [ ] update account details
  - [ ] delete accounts
- [ ] transactions
  - [ ] deposit
  - [ ] withdraw
  - [ ] transfer
- [ ] backend
  - [x] actix-web setup - 25/12/2024
  - [x] sqlite setup - 25/12/2024
  - [ ] logging setup
- [ ] security and authentication
  - [ ] cookies
  - [ ] session management
  - [ ] token authentication

### State of the project

In active development. Rate of progress varies, as I am also working on other projects for 2024/2025 High Seas.

## Development

### Stack

- Language: Rust
- Framework: Actix Web
- Database: SQLite3

Developed in a Fedora environment I daily drive. Optimised for Linux/Unix.

### How it works

At the core of the project is a REST API built using Actix Web. All the endpoints are inside the `src/routes` directory. The logic for these endpoints are located inside the `src/functions` directory and are called from the routes. Input validations happen inside the the `src/routes` directory and returns a corresponding HTTP status code.
