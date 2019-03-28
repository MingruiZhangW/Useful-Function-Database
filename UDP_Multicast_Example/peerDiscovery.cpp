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

#include "peerDiscovery.h"

namespace dht {

PeerDiscovery::PeerDiscovery(int domain, in_port_t port, char *multicast_ip_group_address){

    m_domain = domain;
    m_port = port;
    m_multicast_ip_group_address = multicast_ip_group_address;
    m_continue_to_run = true;

}

void
PeerDiscovery::initialize_socket(){

#ifdef _WIN32
    // Initialize Windows Socket API with given VERSION.
    if (WSAStartup(0x0101, &wsaData)) {
        perror("WSAStartup");
        exit(EXIT_FAILURE);
    }
#endif

    switch (m_domain)
    {
        case AF_INET:

            m_sockfd = socket(AF_INET, SOCK_DGRAM, 0);
            if (m_sockfd < 0) {
                perror("Socket Creation Error_initialize_socket");
                exit(EXIT_FAILURE);
            }
            break;
    
        case AF_INET6:

            m_sockfd = socket(AF_INET6, SOCK_DGRAM, 0);
            if (m_sockfd < 0) {
                perror("Socket Creation Error_initialize_socket");
                exit(EXIT_FAILURE);
            }
            break;
        
        default:

            fprintf(stderr, "Unknown Communication Domain");
            exit(EXIT_FAILURE);
            break;

    }

}

void
PeerDiscovery::initialize_socketopt(){

    m_opt = 1;

    if (
        setsockopt(
            m_sockfd, SOL_SOCKET, SO_REUSEADDR|SO_REUSEPORT, (char*) &m_opt, sizeof(m_opt)
        ) < 0
    ){
       perror("Reusing ADDR failed_initialize_socketopt");
       exit(EXIT_FAILURE);
    }

}

void
PeerDiscovery::initialize_sockaddr_Listener(){

    switch (m_domain)
    {
        case AF_INET:
            // set up destination address
            bzero(&m_addr_ipv4,sizeof(m_addr_ipv4));
            m_addr_ipv4.sin_family = AF_INET;
            m_addr_ipv4.sin_addr.s_addr = htonl(INADDR_ANY); // differs from sender
            m_addr_ipv4.sin_port = htons(m_port);
            break;

        case AF_INET6:

            bzero(&m_addr_ipv6,sizeof(m_addr_ipv6));
            m_addr_ipv6.sin6_family = AF_INET6;
            m_addr_ipv6.sin6_addr = in6addr_any; // differs from sender
            m_addr_ipv6.sin6_port = htons(m_port);
            break;

    }

}

void
PeerDiscovery::initialize_sockaddr_Sender(){

    switch (m_domain)
    {
        case AF_INET:

            bzero(&m_addr_ipv4, sizeof(m_addr_ipv4));
            m_addr_ipv4.sin_family = AF_INET;
            m_addr_ipv4.sin_addr.s_addr = inet_addr(m_multicast_ip_group_address);
            m_addr_ipv4.sin_port = htons(m_port);
            break;

        case AF_INET6:

            bzero(&m_addr_ipv6,sizeof(m_addr_ipv6));
            m_addr_ipv6.sin6_family = AF_INET6;
            m_addr_ipv6.sin6_port = htons(m_port);
            if(inet_pton(AF_INET6,m_multicast_ip_group_address,&m_addr_ipv6.sin6_addr) <= 0){

                perror("inet_pton_initialize_sockaddr");
                exit(EXIT_FAILURE);

            }
            break;
            
    }
    

}

void
PeerDiscovery::mcast_join(){

    switch (m_domain)
    {
        case AF_INET:

            // bind to receive address
            if (bind(m_sockfd, (struct sockaddr*) &m_addr_ipv4, sizeof(m_addr_ipv4)) < 0) {

                perror("bind_mcast_join");
                exit(EXIT_FAILURE);
            }
            // config the listener to be interested in joining in the multicast group
            m_config_ipv4.imr_multiaddr.s_addr = inet_addr(m_multicast_ip_group_address);
            m_config_ipv4.imr_interface.s_addr = htonl(INADDR_ANY);

            if (
                setsockopt(
                    m_sockfd, IPPROTO_IP, IP_ADD_MEMBERSHIP, (char*) &m_config_ipv4, sizeof(m_config_ipv4)
                ) < 0
            ){
                perror("Setsockopt_mcast_join");
                exit(EXIT_FAILURE);
            }

            break;
    
        case AF_INET6:
            // bind to receive address
            if (bind(m_sockfd, (struct sockaddr*) &m_addr_ipv6, sizeof(m_addr_ipv6)) < 0) {

                perror("bind_mcast_join");
                exit(EXIT_FAILURE);

            }

            m_config_ipv6.ipv6mr_interface = 0;
            inet_pton(AF_INET6, m_multicast_ip_group_address, &m_config_ipv6.ipv6mr_multiaddr);
            if (

                setsockopt(m_sockfd, IPPROTO_IPV6, IPV6_ADD_MEMBERSHIP, &m_config_ipv6, sizeof(m_config_ipv6)) < 0

            ){
                perror("setsockopt_mcast_join");
                exit(EXIT_FAILURE);
            }

            break;

    }       

}

void
PeerDiscovery::m_sendto(uint8_t *buf,size_t &buf_size){

    switch (m_domain)
    {
        case AF_INET:{

            int nbytes_ipv4 = sendto(
                m_sockfd,
                buf,
                buf_size,
                0,
                (struct sockaddr*) &m_addr_ipv4,
                sizeof(m_addr_ipv4)
            );
            if (nbytes_ipv4 < 0) {

                perror("sendto_m_sendto");
                exit(EXIT_FAILURE);

            }
        }
            break;

        case AF_INET6:{

            int nbytes_ipv6 = sendto(
                m_sockfd,
                buf,
                buf_size,
                0,
                (struct sockaddr*) &m_addr_ipv6,
                sizeof(m_addr_ipv6)
            );
            if (nbytes_ipv6 < 0) {

                perror("sendto_m_sendto");
                exit(EXIT_FAILURE);

            }
        }
            break;
    }

}

void
PeerDiscovery::m_recvfrom(uint8_t *buf,size_t &buf_size){

    switch (m_domain)
    {
        case AF_INET:{

            m_addrlen = sizeof(m_addr_ipv4);
            int nbytes_ipv4 = recvfrom(
                m_sockfd,
                buf,
                buf_size,
                0,
                (struct sockaddr *) &m_addr_ipv4,
                &m_addrlen
            );
            if (nbytes_ipv4 < 0) {
                perror("recvfrom_m_recvfrom");
                exit(EXIT_FAILURE);
            }
        }
            break;

        case AF_INET6:{

            m_addrlen = sizeof(m_addr_ipv6);
            int nbytes_ipv6 = recvfrom(
                m_sockfd,
                buf,
                buf_size,
                0,
                (struct sockaddr *) &m_addr_ipv6,
                &m_addrlen
            );
            if (nbytes_ipv6 < 0) {
                perror("recvfrom_m_recvfrom");
                exit(EXIT_FAILURE);
            }
        }
            break;

    }

}

void
PeerDiscovery::Sender_oneTimeShoot(dht::InfoHash nodeId, in_port_t port_to_send){

    //Set up for Sender
    this->initialize_socket();
    this->initialize_sockaddr_Sender();

    //Setup for send data
    uint8_t data_send[22];
    uint8_t *x = nodeId.data();

    size_t data_send_size = 22;
    int port_node = port_to_send;
    uint8_t port_node_binary[2];
    PeerDiscovery::inttolitend(port_node,port_node_binary);

    //Copy Node id and node port
    memcpy (data_send, x, 20);
    data_send[20] = port_node_binary[0];
    data_send[21] = port_node_binary[1];

    this->m_sendto(data_send,data_send_size);

}

void
PeerDiscovery::Listener_oneTimeShoot(){

    this->initialize_socket();
    this->initialize_socketopt();
    this->initialize_sockaddr_Listener();
    this->mcast_join();

    size_t data_receive_size = 22;
    uint8_t data_receive[22];
    this->m_recvfrom(data_receive,data_receive_size);

    uint8_t data_infohash[20];
    uint8_t data_port[2];

    memcpy (data_infohash, data_receive, 20);
    data_port[0] = data_receive[20];
    data_port[1] = data_receive[21];

    m_port_received = PeerDiscovery::litendtoint(data_port);
    m_node_id_received = dht::InfoHash(data_infohash, 20);

}

void
PeerDiscovery::Sender_Loop(dht::InfoHash nodeId, in_port_t port_to_send){

    //Set up for Sender
    this->initialize_socket();
    this->initialize_sockaddr_Sender();

    //Setup for send data
    uint8_t data_send[22];
    uint8_t *x = nodeId.data();

    size_t data_send_size = 22;
    int port_node = port_to_send;
    uint8_t port_node_binary[2];
    PeerDiscovery::inttolitend(port_node,port_node_binary);

    //Copy Node id and node port
    memcpy (data_send, x, 20);
    data_send[20] = port_node_binary[0];
    data_send[21] = port_node_binary[1];

    m_running = std::thread([&,this]{

        while(m_continue_to_run){
            
            std::cout<<this->m_port<<std::endl;
            this->m_sendto(data_send,data_send_size);
            sleep(3);

        }
    
    });

    m_running.join();

}

void 
PeerDiscovery::Listener_Loop(){

    this->initialize_socket();
    this->initialize_socketopt();
    this->initialize_sockaddr_Listener();
    this->mcast_join();

    m_running = std::thread([&,this]{

        while(m_continue_to_run){
            
            size_t data_receive_size = 22;
            uint8_t data_receive[22];

            this->m_recvfrom(data_receive,data_receive_size);

            uint8_t data_infohash[20];
            uint8_t data_port[2];

            memcpy (data_infohash, data_receive, 20);
            data_port[0] = data_receive[20];
            data_port[1] = data_receive[21];

            m_port_received = PeerDiscovery::litendtoint(data_port);
            m_node_id_received = dht::InfoHash(data_infohash, 20);

            NodeExport new_nodeexport;
            new_nodeexport.id = m_node_id_received;
            switch (m_domain)
            {
                case AF_INET:
                    
                    mempcpy(&new_nodeexport.ss,&m_addr_ipv4,sizeof(m_addr_ipv4));
                    new_nodeexport.sslen = sizeof(m_addr_ipv4);
                    break;
            
                case AF_INET6:

                    mempcpy(&new_nodeexport.ss,&m_addr_ipv6,sizeof(m_addr_ipv6));
                    new_nodeexport.sslen = sizeof(m_addr_ipv6);
                    break;
            }
            m_node_vec.push_back(new_nodeexport);
            
            //bootstrap(m_node_vec);

            m_node_vec.clear();
            std::cout<<m_port_received<<std::endl;
            sleep(1);

        }
    
    });
    m_running.join();

}

PeerDiscovery::~PeerDiscovery()
{

#ifdef _WIN32
    WSACleanup();
#endif

}

}
