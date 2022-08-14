// Timothy G. Day

#include "main.h"
#include "data_client/url_builder.h"

int main() {
  std::cout << "Input a date: ";

  string input;
  std::cin >> input;

  Url_Builder base;
  base.add_filter("record_date", "eq", input);

  std::cout << base.make_request()["data"][0].toStyledString() << std::endl;

  return 0;
}
