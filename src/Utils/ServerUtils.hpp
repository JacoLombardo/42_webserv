/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerUtils.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 19:03:21 by htharrau          #+#    #+#             */
/*   Updated: 2025/08/20 12:17:23 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ServerUtils.hpp
#ifndef SERVERUTILS_HPP
#define SERVERUTILS_HPP

#include <string>
#include "src/HttpServer/Structs/WebServer.hpp"
#include "src/HttpServer/Structs/Connection.hpp"
#include "src/HttpServer/Structs/Response.hpp"
#include "src/HttpServer/HttpServer.hpp"

std::string getExtensionForMime(const std::string &path);
std::string detectContentTypeLocal(const std::string &path);
std::string getExtension(const std::string &path);
std::string detectContentType(const std::string &path);
bool isPrefixMatch(const std::string &uri, LocConfig &loc);
LocConfig *findBestMatch(const std::string &uri, std::vector<LocConfig> &locations);

#endif
