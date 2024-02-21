#pragma once
/**
 * A dynamic array of char made with the necessary methods to develop Quarzum with them.
*/
class qstring{
    public:
        char* value;
        qstring(const char* input){
            capacity = 0;
            for (; input[capacity]; capacity++){}
            value = new char[capacity];
            for (size_t i = 0; input[i]; i++)
            {
                value[i] = input[i];
            }
        }

        qstring(size_t c = 0){
            capacity = c;
            value = new char[c];
        }

        char operator[](size_t i){
            return value[i];
        }

        void operator=(char* input){
            for (size_t i = 0; i < capacity; i++)
            {
                if(input[i] && value[i]){
                    value[i] = input[i];
                }
                else{
                    value[i] = 0;
                }
            }
            
            value = input;
        }

        qstring operator+(qstring extend){
            size_t l = length();
            size_t space = l + extend.length();
            char* result = new char[space];
            for(int i = 0; value[i]; i++){
                result[i] = value[i];
            }
            for(int i = 0; extend[i]; i++){
                result[l + i] = extend[i];
            }
            return qstring(result);
        }

        void operator+=(qstring extend){
            if(length() + extend.length() > capacity){
                reAlloc(capacity + capacity/2);
            }
            for (size_t i = 0; i < extend.length(); i++)
            {
                value[i + length()] = extend[i];
            }
            
        }

        void operator+=(const char* extend){
            size_t l = 0;
            for(;extend[l];l++){}
            if(length() + l > capacity){
                reAlloc(capacity + capacity/2);
            }
            for (size_t i = 0; i < l; i++)
            {
                value[i + length()] = extend[i];
            }
            
        }

        bool operator==(qstring target){
            size_t finish = 0;
            if(target.length() > length()){
                finish = target.length();
            }
            else{
                finish = length();
            }
            
            for (size_t i = 0; i < finish; i++)
            {
                if(target[i] != value[i]){
                    return false;
                }
            }
            return true;
            
        }

        char at(size_t n){
            return value[n];
        }
        /**
         * @return The length of the qstring.
        */
        constexpr size_t length() const{
            size_t length = 0;
            for (; value[length]; length++){}
            return length;
        }
        /**
         * Converts all the characters of the qstring into null characters.
        */
        void clear(){
            for(size_t i = 0; value[i]; i++){
                value[i] = 0;
            }
        }
        /**
         * Compares if a qstring ends with a determinated sequence of characters.
         * @param ending The text to be compared.
         * @return true if the qstring ends with the ending, false otherwise.
        */
        constexpr bool endsWith(const char* ending) const{
            size_t l= 0;
            for(; ending[l]; l++){}
            for (size_t i = 0; i < l; i++)
            {
                if(value[i + length() - l] != ending[i]){
                    return false;
                }

            }
            return true;
            
        }

        void pop(){
            value[length() - 1] = 0;
        }
    private:
        size_t capacity;  

        void reAlloc(const size_t newCapacity){
            char* newValue = new char[newCapacity];
            for(int i = 0; value[i]; i++){
                newValue[i] = value[i];
            }
            delete[] value;
            value = newValue;
            capacity = newCapacity;
        }    
};