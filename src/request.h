#pragma once

#include "namespace.h"

BEGIN_EXPRESS_NAMESPACE

class Routes;
class Route;

struct RequestDefaultSettings
{
    /// @brief
    static constexpr int MaxHeaders = 10;
};

//template <class _Settings = ResponseDefaultSettings>
class Request
{
public:
//    typedef _Settings Settings;

    String version_{};

    String uri_{};

    /// @brief
    const EthernetClient &client_;

    /// @brief This property holds a reference to the instance of the Express application that is using the middleware.
    /// @return
 //   const express &app_;

    /// @brief 
    Route*  route_ = nullptr;

public:
    /// @brief Contains a string corresponding to the HTTP method of the request: GET, POST, PUT, and so on.
    Method method;

    /// @brief Contains the hostname derived from the Host HTTP header
    String hostname{};

    /// @brief A Boolean property that is true if a TLS connection is established.
    ///  Equivalent to: (req.protocol === 'https')
    bool secure{};

    /// @brief
    String body{};

    /// @brief Contains the remote IP address of the request.
    IPAddress ip{};

    /// @brief
    dictionary<String, String, 10> headers{}; // TODO: max using Settings

    /// @brief Contains the path part of the request URL.
    String path{};

    /// @brief Contains the request protocol string: either http or (for TLS requests) https.
    String protocol{};

    /// @brief
    dictionary<String, String, 10> query{}; // TODO: max using Settings

    /// @brief This property is an object containing properties mapped to the named route “parameters”.
    /// For example, if you have the route /user/:name, then the “name” property is available as
    //  req.params[name]
    params_t params{};

public: /* Methods*/
    /// @brief Constructor
    Request(EthernetClient &client)
	    : client_(client), method(Method::UNDEFINED)
    {
    }

    /// @brief Checks if the specified content types are acceptable, based on the request’s Accept HTTP
    /// header field. The method returns the best match, or if none of the specified content types is
    /// acceptable, returns false (in which case, the application should respond with 406 "Not Acceptable").
    auto accepts(const String& types) -> bool
    {
        return false;
    }

    /// @brief Returns the specified HTTP request header field (case-insensitive match).
    /// @param field
    /// @return
    auto get(const String& field) -> String
    {
        for (auto [key, header] : headers)
        {
            if (field.equalsIgnoreCase(key))
                return header;
        }
        return "";
    }

};

//typedef Request<> response;

END_EXPRESS_NAMESPACE
