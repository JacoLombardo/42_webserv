# webserv

webserv is a 42 School project that implements an HTTP/1.1 server in C++98. It serves static files, handles CGI scripts, and uses a configuration file (nginx-style) to define servers, ports, and behavior.

## Overview

The goal is to build a multi-server HTTP daemon that can handle GET, POST, and DELETE, serve static content, run CGI (e.g. PHP, Python), and manage concurrent connections with non-blocking I/O (epoll on Linux).

## Composition

- **src/HttpServer/** — server core, connections, request/response lifecycle
- **src/ConfigParser/** — parses config file, server/location directives
- **src/RequestParser/** — HTTP request parsing (line, headers, body)
- **src/CGI/** — CGI handler and execution
- **src/Logger/** — logging
- **includes/** — Webserv.hpp, Types.hpp
- **www/** — default static files and error pages
- **cgi-bin/** — sample PHP and Python scripts
- **config_example/** — example configuration

## Features

- **HTTP/1.1** — GET, POST, DELETE (and others per config)
- **Static file serving** — configurable document roots
- **CGI support** — PHP, Python, etc.
- **Config file** — nginx-style (listen, server_name, location, root, error_page)
- **Concurrent connections** — epoll, non-blocking I/O
- **Custom error pages** — 400, 401, 403, 404, 405, 413
- **Chunked transfer** — request/response

## Technology

- C++98
- Linux epoll
- No external dependencies beyond standard library

## Setup

Build:

```bash
make
```

Run:

```bash
./webserv [config_file]
```

Example:

```bash
./webserv config_example/basic.conf
```

Then open `http://localhost:PORT/` in a browser or use `curl`.

## Configuration

See `config_example/basic.conf` and `ConfigurationGuide.md` for server blocks, locations, root, error pages, and CGI setup.

## Makefile targets

| Target   | Description              |
|----------|--------------------------|
| `all`    | Build `webserv`          |
| `clean`  | Remove object files      |
| `fclean` | Remove objects and binary |
| `re`     | Fclean then rebuild      |

## Notes

- C++98 only
- Linux required (epoll)
- Subject typically requires handling of specific HTTP features and config directives
