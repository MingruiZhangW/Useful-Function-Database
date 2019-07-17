# Get the current calendar time
    #include <ctime>
    #include <iostream>
    auto time = std::time(nullptr);
    auto date = std::ctime(&time);
    
https://en.cppreference.com/w/cpp/chrono/c/time
