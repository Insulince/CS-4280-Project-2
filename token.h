#ifndef P1_TOKEN_H
#define P1_TOKEN_H

#include <string>

enum TOKEN_IDENTIFIER {
    END_OF_FILE, //Indicates the end of the file has been reached.
    IDENTIFIER, //Conforms to the regex (JavaScript notation) "/^[a-zA-Z]{1}[a-zA-Z0-9]{0,7}$/".
    INTEGER, //Conforms to the regex (JavaScript notation) "/^[0-9]{1,8}$/".
    KEYWORD_BEGIN, //"Begin"
    KEYWORD_END, //"End"
    KEYWORD_CHECK, //"Check"
    KEYWORD_LOOP, //"Loop"
    KEYWORD_VOID, //"Void"
    KEYWORD_VAR, //"Var"
    KEYWORD_RETURN, //"Return"
    KEYWORD_INPUT, //"Input"
    KEYWORD_OUTPUT, //"Output"
    KEYWORD_PROGRAM, //"Program"
    OPERATOR_EQUALS, //"="
    OPERATOR_LESS_THAN, //"<"
    OPERATOR_LESS_THAN_OR_EQUAL_TO, //"<="
    OPERATOR_GREATER_THAN, //">"
    OPERATOR_GREATER_THAN_OR_EQUAL_TO, //">="
    ILLEGAL_EXCLAMATION_POINT, //"!"
    OPERATOR_EXCLAMATION_POINT_EQUALS, //"!="
    OPERATOR_DOUBLE_EQUALS, //"=="
    OPERATOR_COLON, //":"
    OPERATOR_PLUS, //"+"
    OPERATOR_MINUS, //"-"
    OPERATOR_ASTERISK, //"*"
    OPERATOR_FORWARD_SLASH, //"/"
    OPERATOR_AMPERSAND, //"&"
    OPERATOR_PERCENT, //"%"
    DELIMITER_PERIOD, //"."
    DELIMITER_LEFT_PARENTHESIS, //"("
    DELIMITER_RIGHT_PARENTHESIS, //")"
    DELIMITER_LEFT_CURLY_BRACE, //"{"
    DELIMITER_RIGHT_CURLY_BRACE, //"}"
    DELIMITER_LEFT_SQUARE_BRACKET, //"["
    DELIMITER_RIGHT_SQUARE_BRACKET, //"]"
    DELIMITER_COMMA, //","
    DELIMITER_SEMICOLON //";"
};

extern const std::string END_OF_FILE_TOKEN_NAME;
extern const std::string IDENTIFIER_TOKEN_NAME;
extern const std::string INTEGER_TOKEN_NAME;
extern const std::string KEYWORD_BEGIN_TOKEN_NAME;
extern const std::string KEYWORD_END_TOKEN_NAME;
extern const std::string KEYWORD_CHECK_TOKEN_NAME;
extern const std::string KEYWORD_LOOP_TOKEN_NAME;
extern const std::string KEYWORD_VOID_TOKEN_NAME;
extern const std::string KEYWORD_VAR_TOKEN_NAME;
extern const std::string KEYWORD_RETURN_TOKEN_NAME;
extern const std::string KEYWORD_INPUT_TOKEN_NAME;
extern const std::string KEYWORD_OUTPUT_TOKEN_NAME;
extern const std::string KEYWORD_PROGRAM_TOKEN_NAME;
extern const std::string OPERATOR_EQUALS_TOKEN_NAME;
extern const std::string OPERATOR_LESS_THAN_TOKEN_NAME;
extern const std::string OPERATOR_LESS_THAN_OR_EQUAL_TO_TOKEN_NAME;
extern const std::string OPERATOR_GREATER_THAN_TOKEN_NAME;
extern const std::string OPERATOR_GREATER_THAN_OR_EQUAL_TO_TOKEN_NAME;
extern const std::string ILLEGAL_EXCLAMATION_POINT_TOKEN_NAME;
extern const std::string OPERATOR_EXCLAMATION_POINT_EQUALS_TOKEN_NAME;
extern const std::string OPERATOR_DOUBLE_EQUALS_TOKEN_NAME;
extern const std::string OPERATOR_COLON_TOKEN_NAME;
extern const std::string OPERATOR_PLUS_TOKEN_NAME;
extern const std::string OPERATOR_MINUS_TOKEN_NAME;
extern const std::string OPERATOR_ASTERISK_TOKEN_NAME;
extern const std::string OPERATOR_FORWARD_SLASH_TOKEN_NAME;
extern const std::string OPERATOR_AMPERSAND_TOKEN_NAME;
extern const std::string OPERATOR_PERCENT_TOKEN_NAME;
extern const std::string DELIMITER_PERIOD_TOKEN_NAME;
extern const std::string DELIMITER_LEFT_PARENTHESIS_TOKEN_NAME;
extern const std::string DELIMITER_RIGHT_PARENTHESIS_TOKEN_NAME;
extern const std::string DELIMITER_LEFT_CURLY_BRACE_TOKEN_NAME;
extern const std::string DELIMITER_RIGHT_CURLY_BRACE_TOKEN_NAME;
extern const std::string DELIMITER_LEFT_SQUARE_BRACKET_TOKEN_NAME;
extern const std::string DELIMITER_RIGHT_SQUARE_BRACKET_TOKEN_NAME;
extern const std::string DELIMITER_COMMA_TOKEN_NAME;
extern const std::string DELIMITER_SEMICOLON_TOKEN_NAME;

extern const std::map<const TOKEN_IDENTIFIER, const std::string> TOKEN_IDENTIFIER_TO_TOKEN_NAME_MAP;

extern const std::string KEYWORD_LITERAL_BEGIN;
extern const std::string KEYWORD_LITERAL_END;
extern const std::string KEYWORD_LITERAL_CHECK;
extern const std::string KEYWORD_LITERAL_LOOP;
extern const std::string KEYWORD_LITERAL_VOID;
extern const std::string KEYWORD_LITERAL_VAR;
extern const std::string KEYWORD_LITERAL_RETURN;
extern const std::string KEYWORD_LITERAL_INPUT;
extern const std::string KEYWORD_LITERAL_OUTPUT;
extern const std::string KEYWORD_LITERAL_PROGRAM;

extern const std::map<const std::string, const TOKEN_IDENTIFIER> KEYWORD_LITERAL_TO_KEYWORD_TOKEN_IDENTIFIER_MAP;

class Token {
private:
    const TOKEN_IDENTIFIER tokenIdentifier;
    const std::string value;
    const std::string lineNumber;
public:
    Token(const TOKEN_IDENTIFIER tokenIdentifier, const std::string value, const std::string lineNumber);

    ~Token();

    const TOKEN_IDENTIFIER getTokenIdentifier() const;

    const std::string &getValue() const;

    const std::string &getLineNumber() const;

    const std::string toString() const;
};

#endif //P1_TOKEN_H
