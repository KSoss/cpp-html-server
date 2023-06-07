#include <httplib.h>
#include <iostream>

int main(void)
{
    using namespace httplib;

    int port = 8080;

    Server svr;

    //Gets a simple string
    svr.Get("/get", [](const Request& req, Response& res) {
        res.set_content("Hello World.", "text/plain");
    });

    //JSON version
    svr.Get("/jget", [](const Request& req, Response& res) {
    std::string json = R"({"message": "Hello World."})";
    res.set_content(json, "application/json");
    });

    svr.Post("/post", [](const Request& req, Response& res) {
        res.set_content("World has been made", "text/plain");
    });

    svr.Put("/put", [](const Request& req, Response& res) {
        res.set_content("World has been edited", "text/plain");
    });

    svr.Delete("/delete", [](const Request& req, Response& res) {
        res.set_content("World has been deleted", "text/plain");
    });


    std::cout << "Server listening on port " << port << std::endl;
    svr.listen("0.0.0.0", port);

    return 0;
}
