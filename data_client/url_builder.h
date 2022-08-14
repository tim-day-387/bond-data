// Timothy G. Day

#include <string>

#include <jsoncpp/json/json.h>

using namespace std;

class Url_Builder {
  public:
    string link;
  
    Url_Builder();
    void add_filter(string field, string compare_string, string value);
    Json::Value make_request();
};
