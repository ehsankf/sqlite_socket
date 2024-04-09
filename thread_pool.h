#pragma once

#include <map>
#include <set>

#include "tools.h"

namespace tpt {

class Pollable: public RefCounted {
protected:

    virtual ~Pollable() {
    }

public:

    enum {
        READ = 0x1, WRITE = 0x2
    };

    virtual int fd() = 0;
    virtual int poll_mode() = 0;
    virtual void handle_read() = 0;
    virtual void handle_write() = 0;
    virtual void handle_error() = 0;
};

class PollMgr: public RefCounted {

    class PollThread;

    PollThread* poll_threads_;
    int n_;

protected:

    // RefCounted object uses protected dtor to prevent accidental deletion
    ~PollMgr();

public:

    PollMgr(int n_threads = 1);

    void add(Pollable*);
    void remove(Pollable*);
    void update_mode(Pollable*, int new_mode);
};

}
