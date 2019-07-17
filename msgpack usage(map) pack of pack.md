
        std::map<std::string, msgpack::sbuffer> messages;
        messages["dht"] = std::move(sbuf);
        msgpack::packer<msgpack::sbuffer> pk(&buffer);

        pk.pack_map(messages.size());
        for (const auto& m : messages) {
            //first element of map 
            pk.pack(m.first);
            //second not as a sbuffer, but as buffer data written in new buf
            buffer.write(m.second.data(), m.second.size());
        }

- Unpacking<br>

        msgpack::object_handle oh = msgpack::unpack(buffer.data(), buffer.size());
        msgpack::object obj = oh.get();
        
        if (obj.type != msgpack::type::MAP)
            throw msgpack::type_error();
        for (unsigned i = 0; i < obj.via.map.size; i++) {
            auto& o = obj.via.map.ptr[i];
            if (o.key.type != msgpack::type::STR)
                continue;
            auto key = o.key.as<std::string>();
            std::cout<<key<<std::endl;
            //cb(key, o.value)

            auto v = o.val.as<NodeInsertionPack>();
            std::cout<< v.nodeid <<std::endl;

        }
