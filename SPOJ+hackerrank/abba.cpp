# include <string.h>
# include <string>
# include <iostream>
# include <cstdio>

using namespace std;

class ABBA{
    
    public:
        string canObtain(string initial, string target)
      {
        int length = target.length(); 
        char Initial[initial.length()+1];    
        char Target[length+1];
        int i;
            for(i=0;i<length;i++)
                Target[i] = target.at(i); 
            Target[i] = '\0';
            for(i=0;i<initial.length();i++)
                Initial[i] = initial.at(i);
            Initial[i] = '\0';

            for(i=length-1;i>=0;i--)
            {
                if(strlen(Target)==strlen(Initial))
                {
                    if(strcmp(Initial,Target)==0)
                        return "possible";
                    else
                        return "Impossible";
                }
            
                else if(Target[i]=='A')
                {
                    Target[i] = '\0';
                }
            
                else if(Target[i]=='B')
                {
                    Target[i] = '\0';
                    strcpy(Target,Reverse(Target));
                }
            }    
        return "Impossible";
        }
   char *Reverse(char *str)
   {
    int i;
    char *rev = (char*)malloc(strlen(str)*sizeof(char));

    for(i=0;i<strlen(str);i++)
    {
        rev[i] = str[strlen(str)-1-i];
    }

    rev[i] = '\0';
    return rev;
   }
    
};