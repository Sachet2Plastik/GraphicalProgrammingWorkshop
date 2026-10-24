#pragma once

class Exercise {
public:
    virtual ~Exercise() = default;

    virtual void init() = 0;
    virtual void render() = 0;
};