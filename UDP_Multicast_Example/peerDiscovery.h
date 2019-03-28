/*
 *  Copyright (C) 2014-2019 Savoir-faire Linux Inc.
 *  Author(s) : Mingrui Zhang <mingrui.zhang@savoirfairelinux.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include "dhtrunner.h"

#ifdef _WIN32
#include <Winsock2.h> // before Windows.h, else Winsock 1 conflict
#include <Ws2tcpip.h> // needed for ip_mreq definition for multicast
#include <Windows.h>
#else
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#endif

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 

#include <string>

namespace dht {

class OPENDHT_PUBLIC PeerDiscovery
{
public:

    PeerDiscovery(int domain, in_port_t port, char *multicast_ip_group_address);
    ~PeerDiscovery();

    /**
     * Send socket procudure start - one time sender
    */
    void Sender_oneTimeShoot(dht::InfoHash nodeId, in_port_t port_to_send);
    
    /**
     * Send socket procudure start - Loop send
    */
    void Sender_Loop(dht::InfoHash nodeId, in_port_t port_to_send);

    /**
     * Listener socket procudure start - one time Listen
    */
    void Listener_oneTimeShoot();

    /**
     * Listener socket procudure start - Loop Listen
    */
    void Listener_Loop();

    /**
     * Binary Converters
    */
    static void inttolitend(uint32_t x, uint8_t *lit_int) {
        lit_int[0] = (uint8_t)(x >>  0);
        lit_int[1] = (uint8_t)(x >>  8);
    }

    static uint32_t litendtoint(uint8_t *lit_int) {
        return (uint32_t)lit_int[0] <<  0
            | (uint32_t)lit_int[1] <<  8;
    }

    /**
     * Getter and Setters
    */
    struct sockaddr_in6 get_v6add(){

        return m_addr_ipv6;

    }
    struct sockaddr_in get_v4add(){

        return m_addr_ipv4;

    }
    dht::InfoHash get_node_id_received(){

        return m_node_id_received;

    }
    int get_port_received(){

        return m_port_received;

    }
    void continue_to_run_setter(bool continue_to_run){

        m_continue_to_run = continue_to_run;

    }
    
private:
    
    int m_domain;
    int m_sockfd;
    u_int m_opt;
    struct sockaddr_in m_addr_ipv4;
    struct sockaddr_in6 m_addr_ipv6;
    struct ip_mreq m_config_ipv4;
    struct ipv6_mreq m_config_ipv6;
    socklen_t m_addrlen;
    char* m_multicast_ip_group_address;
    int m_port;

    std::thread m_running;
    bool m_continue_to_run;

    //Data to export - Listener Socket Only
    dht::InfoHash m_node_id_received;
    int m_port_received;
    std::vector<NodeExport> m_node_vec;

    /**
     * Multicast Socket Initialization, accept IPV4, IPV6 
    */
    void initialize_socket();

    /**
     * Multicast Socket Option Initialization, aim to allow multiple sockets to use the same PORT number 
     * listen used only
    */
    void initialize_socketopt();

    /**
     * Socket Address Structure Initialization for both Listener
    */
    void initialize_sockaddr_Listener();

    /**
     * Socket Address Structure Initialization for both Sender 
    */
    void initialize_sockaddr_Sender();

    /**
     * Configure the listener to be insterested in joining the IP multicast group
    */
    void mcast_join();

    /**
     * send messages
    */
    void m_sendto(uint8_t *buf,size_t &buf_size);

    /**
     * send messages
    */
    void m_recvfrom(uint8_t *buf,size_t &buf_size);

#ifdef _WIN32
    WSADATA wsaData;
#endif

};

}
