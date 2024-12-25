# Moose

**Designed and developed by** [Luqman](https://theluqmn.github.io/)

Moose is a simple bank management system written in Rust. It includes a REST API for clients to perform various operations such as creating accounts, making transactions, and managing their accounts. Designed to be integrated with various projects and services that may require a backend for managing accounts and transactions. This is also my first Rust project. ORiginally written in C++ and migrated to Rust.

The original C++ version is available at this [release](https://github.com/TheLuqmn/Moose/releases/tag/v0.1.cpp). Note that it barely works.

> [!WARNING]
> This project is still in **active** development. Currently transitioning from C++ to Rust.

## To-do

Below are the features planned for this project. Everything needs to be implemented before I consider this project complete. Rate of progress varies, as I am working on several projects at once.

- [ ] accounts
  - [x] create accounts
    - [x] checking
    - [x] savings
  - [x] get account details
  - [ ] update account details
  - [ ] delete accounts
- [ ] transactions
  - [ ] deposit
  - [ ] withdraw
  - [ ] transfer
- [ ] backend
  - [x] actix-web setup
  - [x] sqlite setup
  - [ ] logging setup

### State of the project

In active development.

## Development

### Stack

- Language: Rust
- Framework: Actix Web
- Database: SQLite3

Developed in a Fedora environment I daily drive. Optimised for Linux/Unix.

### How it works

At the core of the project is a REST API built using Actix Web. All the endpoints are inside the `src/routes` directory. The logic for these endpoints are located inside the `src/functions` directory and are called from the routes. Input validations happen inside the the `src/routes` directory and returns a corresponding HTTP status code.
