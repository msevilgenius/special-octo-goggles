#pragma once

namespace faces{

class Face{
    public:
        virtual ~Face() {}
        virtual void Start();
        virtual void Update(*events, const Uint32 time);
};




}