# Std::unique_ptr with Deleter

    struct ctx {
        ctx(pjsip_auth_clt_sess* auth) : auth_sess(auth, &pjsip_auth_clt_deinit) {}
        std::weak_ptr<SIPAccount> acc;
        std::string to;
        uint64_t id;
        std::unique_ptr<pjsip_auth_clt_sess, decltype(&pjsip_auth_clt_deinit)> auth_sess;
    };
    // Set input token into callback
    std::unique_ptr<ctx> t{ new ctx(new pjsip_auth_clt_sess) };
    t->acc = shared();
    t->to = to;
    t->id = id;
    
https://en.cppreference.com/w/cpp/memory/unique_ptr
https://stackoverflow.com/questions/19053351/how-do-i-use-a-custom-deleter-with-a-stdunique-ptr-member
