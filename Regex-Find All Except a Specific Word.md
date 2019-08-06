# Find All Except a Specific Word

    Solution
    A negative lookahead can help you rule out specific words, and is key to this next regex:

    \b(?!cat\b)\w+
    
    Regex options: Case insensitive
    Regex flavors: .NET, Java, JavaScript, PCRE, Perl, Python, Ruby
    
https://www.oreilly.com/library/view/regular-expressions-cookbook/9781449327453/ch05s04.html
