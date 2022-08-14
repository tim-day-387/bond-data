// Timothy G. Day

#include <curl/curl.h>
#include <jsoncpp/json/json.h>

#include "data_client.h"

namespace {
  std::size_t callback(const char* in, std::size_t size, std::size_t num, std::string* out) {
    const std::size_t totalBytes(size * num);
    out->append(in, totalBytes);
    
    return totalBytes;
  }
}

Json::Value perform_request(string given_url) {
  const std::string url(given_url);

  CURL* curl = curl_easy_init();

  curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
  curl_easy_setopt(curl, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);
  curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);
  curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

  long httpCode(0);
  std::unique_ptr<std::string> httpData(new std::string());

  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());

  curl_easy_perform(curl);
  curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
  curl_easy_cleanup(curl);

  Json::Value jsonData;
  Json::Reader jsonReader;

  jsonReader.parse(*httpData.get(), jsonData);

  return jsonData;
}
