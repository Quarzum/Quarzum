#pragma once
#include "../Quarzum.h"
namespace tokens
{
    enum TokenType {
        id          = 0,
        // Keywords
        int_k       = 1,
        num_k       = 2,
        str_k       = 3,
        char_k      = 4,
        bool_k      = 5,
        any_k       = 6,
        return_k    = 7,
        function_k  = 8,
        enum_k      = 9,
        const_k     = 10,
        exit_k      = 11,
        out_k       = 12,
        input_k     = 13,
        struct_k    = 14,
        if_k        = 15,
        else_k      = 16,
        for_k       = 17,
        foreach_k   = 18,
        while_k     = 19,
        do_k        = 20,
        break_k     = 21,
        continue_k  = 22,
        repeat_k    = 23,
        try_k       = 24,
        catch_k     = 25,
        finally_k   = 26,
        throw_k     = 27,
        module_k    = 28,
        import_k    = 29,
        class_k     = 30,
        public_k    = 31,
        private_k   = 32,
        uint_k      = 33,
        short_k     = 34,
        long_k      = 35,
        byte_k      = 36,
        async_k     = 37,
        await_k     = 38,
        operator_k  = 39,
        in_k        = 40,
        // Symbols
        eq          = 41,
        left_par    = 42,
        right_par   = 43,
        not_bit     = 44,
        and_bit     = 45,
        or_bit      = 46,
        xor_bit     = 47,
        not_s       = 48,
        and_s       = 49,
        or_s        = 50,
        xor_s       = 51,
        point       = 52,
        comma       = 53,
        plus        = 54,
        minus       = 55,
        prod        = 56,
        division    = 57,
        power       = 58,
        left_cb     = 59,
        right_cb    = 60,
        left_sb     = 61,
        right_sb    = 62,
        semicolon   = 63,
        greater     = 64,
        less        = 65,
        is_equal    = 66,
        greater_eq  = 67,
        less_eq     = 68,
        remainder   = 69,
        plus_eq     = 70,
        plus_unary  = 71,
        minus_eq    = 72,
        minus_unary = 73,
        prod_eq     = 74,
        div_eq      = 75,
        rem_eq      = 76,
        pow_eq      = 77,
        // Literals
        int_lit     = 78,
        num_lit     = 79,
        str_lit     = 80,
        bool_lit    = 81,
        char_lit    = 82,
        byte_lit    = 83,
        uint_lit    = 84
    };

    // A Token is the basic unit of recognition of the lexer
    struct Token{
        TokenType type;
        qstring value;
    };

        /**
     * An object that stores a list of inmutable Tokens.
    */
    class TokenList{
        public:
            /**
             * Adds a new Token to the TokenList.
             * @param t The new Token's type.
             * @param v The new Token's value.
            */
            void addToken(TokenType t, qstring v) noexcept{
                tokens.push_back({t,v});
            }
            /**
             * Adds a new Token to the TokenList.
             * @param t The new Token.
            */
            void addToken(Token t) noexcept{
                tokens.push_back(t);
            }
            /**
             * Returns an specified Token without deleting it.
             * @param n The index of the target Token.
             * @return The Token with index n inside the list.
            */
            const inline Token get(size_t n) noexcept{
                if(n > size()){
                    return {};
                }
                return tokens.at(n);
            }
            /**
             * @return The size of the TokenList.
            */
            inline size_t size() noexcept{
                return tokens.size();
            }

            TokenList divide(size_t from = 0, size_t to = 1){
                TokenList result;
                for (size_t i = from; i < to; i++)
                {
                    result.addToken(get(i));
                }
                return result;
            }

            void toString(){
                for (size_t i = 0; i < tokens.size(); i++)
                {
                    cout <<  tokens.at(i).type << " - " << tokens.at(i).value.value << "\n";
                }
                
            }
        private:
            vector<Token> tokens;
    };
} 
