#include <iostream>
#include <string>

#define EMPTY ""





template<unsigned int T>
class Hash
{

    struct myString
    {
    std::string name;
    myString* next;
    };

    myString arr[T];
    public:

        Hash()
        {
            for(myString& i : arr)
            {
                i.next = nullptr;
            }
        }

        int hash_funct(std::string word) const
        {
            return word.length();
        }

        void addr_collision(std::string word)
        {
            while(arr[hash_funct(word)].next != nullptr)
            {
                arr[hash_funct(word)].next = arr[hash_funct(word)].next->next;
            }
            arr[hash_funct(word)].next = new myString;
            arr[hash_funct(word)].next->name = word;
            arr[hash_funct(word)].next->next = nullptr;
            

        }

        void insert_to_hash(std::string word)
        {
            if(arr[hash_funct(word)].name != EMPTY)
            {
                addr_collision(word);
                return;
            }

            arr[hash_funct(word)].name = word;
        }

        void display_hash()
        {
            for(auto& i : arr)
            {
                static int count = 0;
                std::cout<<"index: "<< count << " " << i.name << std::endl;
                while(i.next != nullptr)
                {
                    std::cout<<"collude: "<< count << " " << i.next->name << std::endl;
                    i.next = i.next->next;
                }
                ++count;
            }
        }
};


int main()
{
    Hash<10> h1;
    h1.insert_to_hash("Hamed");
    h1.insert_to_hash("Khaled");
    h1.insert_to_hash("Rahill");
    h1.insert_to_hash("AAAAAA");
    h1.display_hash();  

   // myString m1;
    //(m1.next)->next->next->next
}