class qstring{
    public:
        char* value;
        qstring(char* input){
            capacity = 0;
            for (; input[capacity]; capacity++){}
            value = new char[capacity];
            for (int i = 0; input[i]; i++)
            {
                value[i] = input[i];
            }
        }

        qstring(int c = 0){
            capacity = c;
            value = new char[c];
        }

        char operator[](int i){
            return value[i];
        }

        qstring operator=(char* input){
            for (int i = 0; i < capacity; i++)
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
            int l = this->length();
            int space = l + extend.length();
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
            int finish = 0;
            if(target.length() > this->length()){
                finish = target.length();
            }
            else{
                finish = length();
            }
            
            for (int i = 0; i < finish; i++)
            {
                if(target[i] != value[i]){
                    return false;
                }
            }
            return true;
            
        }

        int length(){
            int i = 0;
            for (; value[i]; i++){}
            return i;
        }

        int size(){
            return capacity;
        }

        void clear(){
            for(int i = 0; value[i]; i++){
                value[i] = 0;
            }
        }
    private:
        int capacity;
        
};