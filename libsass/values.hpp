#include <string>
#include <sstream>
#include <cstring>

#ifndef SASS_PRELEXER_INCLUDED
#include "prelexer.hpp"
#endif

namespace Sass {
  using std::string;
  
  struct Token {
    const char* begin;
    const char* end;

    // Token();
    // Token(const char* begin, const char* end);
    
    size_t length() const
    { return end - begin; }

    inline operator string() const
    { return string(begin, end - begin); }
    
    string to_string() const
    { return string(begin, end - begin); }

    string unquote() const;
    void unquote_to_stream(std::stringstream& buf) const;
    
    bool operator<(const Token& rhs) const;
    bool operator==(const Token& rhs) const;
    
    operator bool()
    { return begin && end && begin >= end; }
    
    static Token make()
    {
      Token t;
      t.begin = 0;
      t.end = 0;
      return t;
    }
    
    static Token make(const char* s)
    {
      Token t;
      t.begin = s;
      t.end = s + std::strlen(s);
      return t;
    }
    
    static Token make(const char* b, const char* e)
    {
      Token t;
      t.begin = b;
      t.end = e;
      return t;
    }
    
    
  };
  
  struct Dimension {
    double numeric_value;
    const char* unit;
  };
}