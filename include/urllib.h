#ifndef _URLLIB_H
#define _URLLIB_H

#include "common.h"

namespace urllib {

class Request {
    std::string m_uri;
    std::string m_host;
    std::string m_path;
    std::string m_data;

    // for now we're just doing http, but still
    std::string m_proto;
    std::map<std::string, std::string> m_headers;

public:
    Request(const std::string &uri, const std::string &data = "");
    ~Request();
    void addheader(const std::string &key, const std::string &value);
    std::map<std::string, std::string> headers() { return m_headers; }
    std::string data() { return m_data; }
    std::string host() { return m_host; }
    std::string path() { return m_path; }
};

std::string urlencode_str(const std::string &input);
std::string urlencode(std::map<std::string,std::string> &argmap);
std::string urlopen(const Request &req);

};
#endif 
