#ifndef APPLICATION_H
#define APPLICATION_H


class Application
{
public:
    Application();
    ~Application();
    void run();

    virtual void appDidFinishLaunching() = 0;
};

#endif // APPLICATION_H
