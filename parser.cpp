#include <iostream>
#include <cstdarg>
#include "parser.h"

using namespace std;

static Token *token = nullptr;
static int VA_LIST_TERMINATOR = -1;

Parser::Parser(const string &rawData) : rawData(rawData) {
    scanner = new Scanner(rawData);
}

Parser::~Parser() = default;

const string &Parser::getRawData() const {
    return rawData;
}

void Parser::setRawData(const string &rawData) {
    Parser::rawData = rawData;
}

const void Parser::parse_program() const {
    parse_vars();
    parse_block();

    return;
}

const void Parser::parse_block() const {
    if (currentToken() == KEYWORD_BEGIN) {
        consumeToken();

        parse_vars();
        parse_stats();

        if (currentToken() == KEYWORD_END) {
            consumeToken();

            return;
        } else {
            reportError(KEYWORD_END, VA_LIST_TERMINATOR);
        }
    } else {
        reportError(KEYWORD_BEGIN, VA_LIST_TERMINATOR);
    }
}

const void Parser::parse_vars() const {
    if (currentToken() == KEYWORD_VAR) {
        consumeToken();

        if (currentToken() == IDENTIFIER) {
            consumeToken();

            parse_mvars();

            return;
        } else {
            reportError(IDENTIFIER, VA_LIST_TERMINATOR);
        }
    } else {
        return;
    }
}

const void Parser::parse_mvars() const {
    if (currentToken() == DELIMITER_PERIOD) {
        consumeToken();

        return;
    } else if (currentToken() == DELIMITER_COMMA) {
        consumeToken();

        if (currentToken() == IDENTIFIER) {
            consumeToken();

            parse_mvars();

            return;
        } else {
            reportError(IDENTIFIER, VA_LIST_TERMINATOR);
        }
    } else {
        reportError(DELIMITER_PERIOD, DELIMITER_COMMA, VA_LIST_TERMINATOR);
    }
}

const void Parser::parse_expr() const {
    parse_M();

    if (currentToken() == OPERATOR_PLUS) {
        consumeToken();

        parse_expr();

        return;
    } else if (currentToken() == OPERATOR_MINUS) {
        consumeToken();

        parse_expr();

        return;
    } else {
        return;
    }
}

const void Parser::parse_M() const {
    parse_F();

    if (currentToken() == OPERATOR_PERCENT) {
        consumeToken();

        parse_M();

        return;
    } else if (currentToken() == OPERATOR_ASTERISK) {
        consumeToken();

        parse_M();

        return;
    } else {
        return;
    }
}

const void Parser::parse_F() const {
    if (currentToken() == DELIMITER_LEFT_PARENTHESIS) {
        consumeToken();

        parse_F();

        if (currentToken() == DELIMITER_RIGHT_PARENTHESIS) {
            consumeToken();

            return;
        } else {
            reportError(DELIMITER_RIGHT_PARENTHESIS, VA_LIST_TERMINATOR);
        }
    } else {
        parse_R();
    }
}

const void Parser::parse_R() const {
    if (currentToken() == DELIMITER_LEFT_SQUARE_BRACKET) {
        consumeToken();

        parse_expr();

        if (currentToken() == DELIMITER_RIGHT_SQUARE_BRACKET) {
            consumeToken();

            return;
        } else {
            reportError(DELIMITER_RIGHT_SQUARE_BRACKET, VA_LIST_TERMINATOR);
        }
    } else if (currentToken() == IDENTIFIER) {
        consumeToken();

        return;
    } else if (currentToken() == INTEGER) {
        consumeToken();

        return;
    } else {
        reportError(DELIMITER_LEFT_SQUARE_BRACKET, IDENTIFIER, INTEGER, VA_LIST_TERMINATOR);
    }
}

const void Parser::parse_stats() const {
    parse_stat();
    parse_mStat();

    return;
}

const void Parser::parse_mStat() const {
    if (currentToken() == KEYWORD_INPUT || currentToken() == KEYWORD_OUTPUT || currentToken() == KEYWORD_BEGIN || currentToken() == KEYWORD_CHECK || currentToken() == KEYWORD_LOOP || currentToken() == IDENTIFIER) {
        parse_stat();
        parse_mStat();
    } else {
        return;
    }
}

const void Parser::parse_stat() const {
    if (currentToken() == KEYWORD_INPUT) {
        parse_in();

        return;
    } else if (currentToken() == KEYWORD_OUTPUT) {
        parse_out();

        return;
    } else if (currentToken() == KEYWORD_BEGIN) {
        parse_block();

        return;
    } else if (currentToken() == KEYWORD_CHECK) {
        parse_if();

        return;
    } else if (currentToken() == KEYWORD_LOOP) {
        parse_loop();

        return;
    } else if (currentToken() == IDENTIFIER) {
        parse_assign();

        return;
    } else {
        reportError(KEYWORD_INPUT, KEYWORD_OUTPUT, KEYWORD_BEGIN, KEYWORD_CHECK, KEYWORD_LOOP, IDENTIFIER, VA_LIST_TERMINATOR);
    }
}

const void Parser::parse_in() const {
    if (currentToken() == KEYWORD_INPUT) {
        consumeToken();

        if (currentToken() == IDENTIFIER) {
            consumeToken();

            if (currentToken() == DELIMITER_SEMICOLON) {
                consumeToken();

                return;
            } else {
                reportError(DELIMITER_SEMICOLON, VA_LIST_TERMINATOR);
            }
        } else {
            reportError(IDENTIFIER, VA_LIST_TERMINATOR);
        }
    } else {
        reportError(KEYWORD_INPUT, VA_LIST_TERMINATOR);
    }
}

const void Parser::parse_out() const {
    if (currentToken() == KEYWORD_OUTPUT) {
        consumeToken();

        parse_expr();

        if (currentToken() == DELIMITER_SEMICOLON) {
            consumeToken();

            return;
        } else {
            reportError(DELIMITER_SEMICOLON, VA_LIST_TERMINATOR);
        }
    } else {
        reportError(KEYWORD_OUTPUT, VA_LIST_TERMINATOR);
    }
}

const void Parser::parse_if() const {
    if (currentToken() == KEYWORD_CHECK) {
        consumeToken();

        if (currentToken() == DELIMITER_LEFT_SQUARE_BRACKET) {
            consumeToken();

            parse_expr();
            parse_RO();
            parse_expr();

            if (currentToken() == DELIMITER_RIGHT_SQUARE_BRACKET) {
                consumeToken();

                parse_stat();

                return;
            } else {
                reportError(DELIMITER_RIGHT_SQUARE_BRACKET, VA_LIST_TERMINATOR);
            }
        } else {
            reportError(DELIMITER_LEFT_SQUARE_BRACKET, VA_LIST_TERMINATOR);
        }
    } else {
        reportError(KEYWORD_CHECK, VA_LIST_TERMINATOR);
    }
}

const void Parser::parse_loop() const {
    if (currentToken() == KEYWORD_LOOP) {
        consumeToken();

        if (currentToken() == DELIMITER_LEFT_SQUARE_BRACKET) {
            consumeToken();

            parse_expr();
            parse_RO();
            parse_expr();

            if (currentToken() == DELIMITER_RIGHT_SQUARE_BRACKET) {
                consumeToken();

                parse_stat();

                return;
            } else {
                reportError(DELIMITER_RIGHT_SQUARE_BRACKET, VA_LIST_TERMINATOR);
            }
        } else {
            reportError(DELIMITER_LEFT_SQUARE_BRACKET, VA_LIST_TERMINATOR);
        }
    } else {
        reportError(KEYWORD_LOOP, VA_LIST_TERMINATOR);
    }
}

const void Parser::parse_assign() const {
    if (currentToken() == IDENTIFIER) {
        consumeToken();

        if (currentToken() == OPERATOR_COLON) {
            consumeToken();

            parse_expr();

            if (currentToken() == DELIMITER_SEMICOLON) {
                consumeToken();

                return;
            } else {
                reportError(DELIMITER_SEMICOLON, VA_LIST_TERMINATOR);
            }
        } else {
            reportError(OPERATOR_COLON, VA_LIST_TERMINATOR);
        }
    } else {
        reportError(IDENTIFIER, VA_LIST_TERMINATOR);
    }
}

const void Parser::parse_RO() const {
    if (currentToken() == OPERATOR_LESS_THAN) {
        consumeToken();

        return;
    } else if (currentToken() == OPERATOR_LESS_THAN_OR_EQUAL_TO) {
        consumeToken();

        return;
    } else if (currentToken() == OPERATOR_GREATER_THAN) {
        consumeToken();

        return;
    } else if (currentToken() == OPERATOR_GREATER_THAN_OR_EQUAL_TO) {
        consumeToken();

        return;
    } else if (currentToken() == OPERATOR_DOUBLE_EQUALS) {
        consumeToken();

        return;
    } else if (currentToken() == OPERATOR_EXCLAMATION_POINT_EQUALS) {
        consumeToken();

        return;
    } else {
        reportError(OPERATOR_LESS_THAN, OPERATOR_LESS_THAN_OR_EQUAL_TO, OPERATOR_GREATER_THAN, OPERATOR_GREATER_THAN_OR_EQUAL_TO, OPERATOR_DOUBLE_EQUALS, OPERATOR_EXCLAMATION_POINT_EQUALS, VA_LIST_TERMINATOR);
    }
}

const void Parser::parse() const {
    consumeToken();

    parse_program();

    if (currentToken() == END_OF_FILE) {
        cout << "Parsing completed successfully.\n";
    } else {
        reportError(END_OF_FILE, -1);
    }

    return;
}

const void Parser::reportError(TOKEN_IDENTIFIER expectedToken, ...) const {
    string listOfExpectedTokens;

    va_list va_list;
    va_start(va_list, expectedToken);

    while (expectedToken != VA_LIST_TERMINATOR) {
        listOfExpectedTokens += "\"" + TOKEN_IDENTIFIER_TO_TOKEN_NAME_MAP.at(expectedToken) + "\" or ";
        expectedToken = static_cast<TOKEN_IDENTIFIER>(va_arg(va_list, int));
    }

    listOfExpectedTokens = listOfExpectedTokens.substr(0, listOfExpectedTokens.length() - 4);

    cerr << "PARSE ERROR: Got token \"" << TOKEN_IDENTIFIER_TO_TOKEN_NAME_MAP.at(currentToken()) << "\" where " << listOfExpectedTokens << " was expected on line \"" << scanner->getCurrentLineNumber() << "\".\n";
    exit(1);
}

const void Parser::consumeToken() const {
    token = scanner->getNextToken();
}

const TOKEN_IDENTIFIER Parser::currentToken() const {
    return token->getTokenIdentifier();
}