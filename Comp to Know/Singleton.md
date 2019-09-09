# Singleton

1. [First: Static Duration Variables](https://www.learncpp.com/cpp-tutorial/43-static-duration-variables/):<br>

```static int s_value = 1; // static duration via static keyword.  This line is only executed once.```

2. Singleton Example

Double Checking: https://preshing.com/20130930/double-checked-locking-is-fixed-in-cpp11/

Static Instance: https://gist.github.com/pazdera/1098119

     * Example of a singleton design pattern.                                        
     * Copyright (C) 2011 Radek Pazdera                                              
     * This program is free software: you can redistribute it and/or modify          
     * it under the terms of the GNU General Public License as published by          
     * the Free Software Foundation, either version 3 of the License, or             
     * (at your option) any later version.                                           
     * This program is distributed in the hope that it will be useful,               
     * but WITHOUT ANY WARRANTY; without even the implied warranty of                
     * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                  
     * GNU General Public License for more details.                                  
     * You should have received a copy of the GNU General Public License             
     * along with this program. If not, see <http://www.gnu.org/licenses/>.          
     */
    #include <iostream>                                                              

    class Singleton                                                                  
    {                                                                                
        private:                                                                     
            /* Private constructor to prevent instancing. */                         
            Singleton();                                                             

        public:                                                                      
            /* Static access method. */                                              
            static Singleton* getInstance();                                         
    };                                                                               

    Singleton* Singleton::getInstance()                                              
    {                                                                                
        static Singleton instance;                                                   

        return &instance;                                                            
    }                                                                                

    Singleton::Singleton()                                                           
    {}                                                                               

    int main()                                                                       
    {                                                                                
        //new Singleton(); // Won't work                                             
        Singleton* s = Singleton::getInstance(); // Ok                               
        Singleton* r = Singleton::getInstance();                                     

        /* The addresses will be the same. */                                        
        std::cout << s << std::endl;                                                 
        std::cout << r << std::endl;                                                 
    }
