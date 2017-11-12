#ifndef P2_PARSER_H
#define P2_PARSER_H

#include "token.h"
#include "scanner.h"

/* CONTEXT-FREE GRAMMAR:
 * <program>	-> <vars> <block>
 * <block> 		-> Begin <vars> <stats> End
 * <vars> 		-> empty | Var Identifier <mvars>
 * <mvars> 		-> . | , Identifier <mvars>
 * <expr> 		-> <M> + <expr> | <M> - <expr> | <M>
 * <M> 			-> <F> % <M> | <F> * <M> | <F>
 * <F> 			-> (<F>) | <R>
 * <R>  		-> [<expr>] | Identifier | Number
 * <stats> 		-> <stat> <mStat>
 * <mStat> 		-> empty | <stat> <mStat>
 * <stat> 		-> <in> | <out> | <block> | <if> | <loop> | <assign>
 * <in> 		-> Input Identifier;
 * <out> 		-> Output <expr>;
 * <if> 		-> Check [<expr> <RO> <expr>] <stat>
 * <loop> 		-> Loop [<expr> <RO> <expr>] <stat>
 * <assign> 	-> Identifier: <expr>;
 * <RO> 		-> < | <= | > | >= | == | !=
 * */

class Parser {
private:
    std::string rawData;
    Scanner *scanner;
public:
    explicit Parser(const std::string &rawData);

    ~Parser();

    const std::string &getRawData() const;

    void setRawData(const std::string &rawData);

    const void parse() const;

    const void parse_program() const;

    const void parse_block() const;

    const void parse_vars() const;

    const void parse_mvars() const;

    const void parse_expr() const;

    const void parse_M() const;

    const void parse_F() const;

    const void parse_R() const;

    const void parse_stats() const;

    const void parse_mStat() const;

    const void parse_stat() const;

    const void parse_in() const;

    const void parse_out() const;

    const void parse_if() const;

    const void parse_loop() const;

    const void parse_assign() const;

    const void parse_RO() const;

    const void reportError(TOKEN_IDENTIFIER expectedToken, ...) const;

    const void consumeToken() const;

    const TOKEN_IDENTIFIER currentToken() const;
};

#endif //P2_PARSER_H
