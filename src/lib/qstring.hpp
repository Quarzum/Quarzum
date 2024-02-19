typedef unsigned int uint;
/**
 * A dynamic array of char made with the necessary methods to develop Quarzum with them.
*/
class qstring{
    public:
        char* value;
        qstring(char* input){
            capacity = 0;
            for (; input[capacity]; capacity++){}
            value = new char[capacity];
            for (uint i = 0; input[i]; i++)
            {
                value[i] = input[i];
            }
        }

        qstring(uint c = 0){
            capacity = c;
            value = new char[c];
        }

        char operator[](uint i){
            return value[i];
        }

        qstring operator=(char* input){
            for (uint i = 0; i < capacity; i++)
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
            uint l = this->length();
            uint space = l + extend.length();
            char* result = new char[space];
            for(int i = 0; value[i]; i++){
                result[i] = value[i];
            }
            for(int i = 0; extend[i]; i++){
                result[l + i] = extend[i];
            }
            return qstring(result);
        }

        bool operator==(qstring target){
            uint finish = 0;
            if(target.length() > this->length()){
                finish = target.length();
            }
            else{
                finish = length();
            }
            
            for (uint i = 0; i < finish; i++)
            {
                if(target[i] != value[i]){
                    return false;
                }
            }
            return true;
            
        }
        /**
         * @return The length of the qstring.
        */
        int length(){
            uint length = 0;
            for (; value[length]; length++){}
            return length;
        }
        /**
         * Converts all the characters of the qstring into null characters.
        */
        void clear(){
            for(uint i = 0; value[i]; i++){
                value[i] = 0;
            }
        }
        /**
         * Compares if a qstring ends with a determinated sequence of characters.
         * @param ending The text to be compared.
         * @return true if the qstring ends with the ending, false otherwise.
        */
        bool endsWith(char* ending){
            uint l= 0;
            for(; ending[l]; l++){}
            for (uint i = 0; i < l; i++)
            {
                if(value[i + length() - l] != ending[i]){
                    return false;
                }

            }
            return true;
            
        }
    private:
        uint capacity;      
};