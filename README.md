# KDO C++ Library

A C++98 library developed during my studies at École 42, providing robust tools for BNF parsing and TCP network communication.

## Features

**BNF Parser**: Complete parser with intuitive syntax using operator overloading for grammar composition. Supports alternatives (`|`), concatenation (`&`), repetition (`*`), and named sub-expression search.

**TCP Classes**: TcpServer with multi-client management and broadcast, TcpClient with stream operators (`<<`, `>>`), complete error handling.

**Utilities**: Pre-C++17 string_view implementation, State management system, type conversion templates, string manipulation functions.

## Installation

```bash
git clone https://github.com/kodokaii/kdo_cpplib.git
cd kdo_cpplib
make
```

## Usage Examples

### BNF Parser - Number Parser (like atoi)

```cpp
#include "kdo_cpplib.hpp"

static BNFVar numberParser(void)
{
    BNFVar      whitespace("whitespace", BNFRange('\t', '\r') | ' ');
    BNFRange    digit("digit", '0', '9');
    BNFVar      sign("sign", BNFChar('+') | BNFChar('-'));
    BNFVar      number("number", *whitespace & !sign & ~digit);

    return (number);
}

int atoiBNF(std::string &str)
{
    static BNFVar parser = numberParser();
    int number = 0;

    if (parser.parse(str) == EXIT_SUCCESS) {
        BNFFind nums = parser.find("digit");
        for (const auto &n : nums) {
            number = number * 10 + (n[0] - '0');
        }
        BNFFind sign = parser.find("sign");
        if (!sign.empty() && sign[0] == "-") {
            number = -number;
        }
    }
    return (number);
}
```

### TCP Server

```cpp
#include "kdo_cpplib.hpp"

int main()
{
    TcpServer server("8080");

    if (!server.isConnected()) {
        std::cerr << "Server connection error" << std::endl;
        return 1;
    }

    while (true) {
        TcpClient const *client;

        if (server.accept(client) == EXIT_SUCCESS) {
            std::cout << "New client connected" << std::endl;
            server.broadcast("New client connected!\n");
        }
    }

    return 0;
}
```

### TCP Client

```cpp
#include "kdo_cpplib.hpp"

int main()
{
    TcpClient client("127.0.0.1", "8080");

    if (!client.isConnected()) {
        std::cerr << "Connection failed" << std::endl;
        return 1;
    }

    client << "Hello Server!\n";

    std::string response;
    client >> response;

    std::cout << "Response: " << response << std::endl;

    return 0;
}
```

## BNF Operators

- `|` : Alternatives (logical or)
- `&` : Concatenation (sequence)
- `*` : Repetition 0 or more
- `!` : Optional (0 or 1)
- `~` : One or more
- `^n` : Exact n repetitions

## Technical Specifications

- **Standard**: C++98 (École 42 constraint)
- **Compilation**: `c++ -Wall -Wextra -Werror -std=c++98`
- **Dependencies**: None (STL only)
- **Platform**: Linux/Unix

---

Developed during my studies at École 42
