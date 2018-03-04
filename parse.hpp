/* ollieberzs 2018
** parse.hpp
** parsing oca tokens into AST
*/

#pragma once

#include <string>
#include <vector>
#include <memory>

#include "common.hpp"

OCA_BEGIN

enum class Indent { SAME, MORE, LESS, ANY };

struct Expression
{
    std::string type;
    std::string val;
    ExprPtr left;
    ExprPtr right;

    Expression(const std::string& type, const std::string& val);
    void print(uint indent = 0);
};

struct Parser
{
    std::string path;
    std::vector<Token> tokens;
    std::vector<ExprPtr> cache;
    uint index;
    uint indent;

    Parser(std::vector<Token>& ts, const std::string& path);

    Token& get();
    bool checkIndent(Indent ind);

    std::vector<ExprPtr> parse();

    bool expr();
    bool set();
    bool call();
    bool access();
    bool oper();
    bool block();
    bool keyword();
    bool file();

    bool string();
    bool integer();
    bool floatnum();
    bool boolean();

    bool value();
    bool name();
    bool lit(const std::string& t);

    void error(const std::string& message);
};

OCA_END
