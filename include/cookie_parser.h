#ifndef COOKIES_PARSER_H
#define COOKIES_PARSER_H

#include <list>
class CookieParser {
 protected:
  /**
     move the pointer to the first non-space char in string
     TODO it shouldn't be defined here.
  */
 inline const char* skip_space(const char* cur_str)
{
	while (isspace(*cur_str))
      cur_str++;

	return cur_str;
}

 public:
	const char *str;
	const char* nam_end;
    const char* val_start;
    const char* val_end;

    /**
     * This function parses the starting name/value pair from the cookie string.
     * The syntax is simply: <name token> [ '=' <value token> ] with possible
     * spaces between tokens and '='. However spaces in the value token is also
     * allowed. See bug 174 for a description why. 
     * Defined in RFC 2965. 
     * Return the rest of the cookie string or NULL if we reached the end.
     * Rise exception in case of disaster
     */
    const char *parse_a_cookie(const char* raw_cookie);

    /**
       TODO: Make a constructor that calls the parse_cookie function
    */

};

#endif
