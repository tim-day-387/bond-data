// Timothy G. Day

#include "url_builder.h"
#include "data_client.h"

Url_Builder::Url_Builder() {
  link = "https://api.fiscaldata.treasury.gov/services/api/fiscal_service/v2/accounting/od/avg_interest_rates";
}

void Url_Builder::add_filter(string field, string compare_string, string value) {
  if(link.find("?filter=") == std::string::npos) {
    link = link + "?filter=";
  } else {
    link = link + ",";
  }

  link = link + field + ":" + compare_string + ":" + value;
}

Json::Value Url_Builder::make_request() {
  return perform_request(link);
}
